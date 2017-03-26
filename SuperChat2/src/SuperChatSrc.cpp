
/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2013 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

/************************************************************************
 * LOGICAL_NAME:    HelloWorldDataSubscriber.cpp
 * FUNCTION:        OpenSplice HelloWorld example code.
 * MODULE:          HelloWorld for the C++ programming language.
 * DATE             September 2010.
 ************************************************************************
 *
 * This file contains the implementation for the 'HelloWorldDataSubscriber' executable.
 *
 ***/
//This file was Modified by Tyler Gustaf on 3/24/17
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "DDSEntityManager.h"
#include "ccpp_SuperChat.h"
#include "os.h"


using namespace DDS;
using namespace SuperChat;

#define MESSAGE_SIZE_MAX 144
#define CHATROOM_NAME_MAX 25
#define NICK_SIZE_MAX 8
#define CHATROOMS_MAX 10
#define USER_UPDATE_PERIOD 2.5

struct Chatroom
{
  // an integer representing the checkroom index.
  unsigned long chatroom_idx;
  // name of the chatroom
  char chatroom_name[CHATROOM_NAME_MAX];
  
};

struct User
{
  // users nickname
  char nick[NICK_SIZE_MAX];
  // unique identifier for a user.  contents TBD.
  unsigned long long uuid;
  // an integer representing the checkroom index. 
  unsigned long chatroom_idx;
  // Previouse time heard from
  long double lastHeard;
  // User's online status
  bool online;
};

vector<User> listOfUsers;
vector<Chatroom> listOfChatrooms;
User localUser;

int numOfUsers = 0;
bool RUNNING = 1;

void *sub(void* trash)
{
  os_time delay_2ms = { 0, 2000000 };
  os_time delay_200ms = { 0, 200000000 };
  messageSeq messageList;
  chatroomSeq chatroomList;
  userSeq userList;
  SampleInfoSeq infoSeq;

  DDSEntityManager messageMgr;
  DDSEntityManager CRmanager;
  DDSEntityManager userManager;

  // create domain participant
  messageMgr.createParticipant("SuperChat message");
  CRmanager.createParticipant("SuperChat chatroom");
  userManager.createParticipant("SuperChat user");

  //create type
  messageTypeSupport_var messageTS = new messageTypeSupport();
  messageMgr.registerType(messageTS.in());

  chatroomTypeSupport_var chatroomTS = new chatroomTypeSupport();
  CRmanager.registerType(chatroomTS.in());

  userTypeSupport_var userTS = new userTypeSupport();
  userManager.registerType(userTS.in());

  //create Topic
  char messagetopic_name[] = "SuperChat_message";
  messageMgr.createTopic(messagetopic_name);
  char chatroomtopic_name[] = "SuperChat_chatroom";
  CRmanager.createTopic(chatroomtopic_name);
  char usertopic_name[] = "SuperChat_user";
  userManager.createTopic(usertopic_name);

  //create Subscriber
  messageMgr.createSubscriber();
  CRmanager.createSubscriber();
  userManager.createSubscriber();

  // create DataReader
  messageMgr.createReader();
  CRmanager.createReader();
  userManager.createReader();

  DataReader_var messagereader = messageMgr.getReader();
  DataReader_var chatroomreader = CRmanager.getReader();
  DataReader_var userreader = userManager.getReader();

  messageDataReader_var messageReader = messageDataReader::_narrow(messagereader.in());
  checkHandle(messageReader.in(), "messageDataReader::_narrow");
  chatroomDataReader_var chatroomReader = chatroomDataReader::_narrow(chatroomreader.in());
  checkHandle(chatroomReader.in(), "chatroomDataReader::_narrow");
  userDataReader_var userReader = userDataReader::_narrow(userreader.in());
  checkHandle(userReader.in(), "userDataReader::_narrow");

  cout << "=== [Subscriber] Ready ..." << endl;

  ReturnCode_t status =  - 1;
  
  while (RUNNING) // We dont want the example to run indefinitely
  {
    status = messageReader->take(messageList, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "messageDataReader::take");
    for (DDS::ULong j = 0; j < messageList.length(); j++)
    {
      //cout << "=== [Subscriber] message received :" << endl;
      for(int i = 0; i < numOfUsers; i++)
      {
        if(listOfUsers[i].uuid == messageList[j].uuid)
        {
          cout << listOfUsers[i].nick <<": ";
          cout << messageList[j].message;
          break;
        }
      }
    }
    status = messageReader->return_loan(messageList, infoSeq);
    checkStatus(status, "messageDataReader::return_loan");

    status = chatroomReader->take(chatroomList, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "chatroomDataReader::take");
    for (DDS::ULong j = 0; j < chatroomList.length(); j++)
    {
      if(chatroomList[j].chatroom_idx != 1)
      {
        strncpy(listOfChatrooms[chatroomList[j].chatroom_idx - 1].chatroom_name, chatroomList[j].chatroom_name, CHATROOM_NAME_MAX);
      }
      cout << "=== [Subscriber] chatroom received :" << endl;
      cout << "    CR_idx : " <<chatroomList[j].chatroom_idx <<endl;
      cout << "    CR Name : " << chatroomList[j].chatroom_name << endl;
      
    }
    status = chatroomReader->return_loan(chatroomList, infoSeq);
    checkStatus(status, "chatroomDataReader::return_loan");

    os_nanoSleep(delay_200ms);
  }

  os_nanoSleep(delay_2ms);

  //cleanup
  messageMgr.deleteReader();
  messageMgr.deleteSubscriber();
  messageMgr.deleteTopic();
  messageMgr.deleteParticipant();

  CRmanager.deleteReader();
  CRmanager.deleteSubscriber();
  CRmanager.deleteTopic();
  CRmanager.deleteParticipant();

  userManager.deleteReader();
  userManager.deleteSubscriber();
  userManager.deleteTopic();
  userManager.deleteParticipant();

  return 0;
}

void *pub(void* trash)
{
  int j = 0;
  char input[MESSAGE_SIZE_MAX];

  ReturnCode_t status;
  DDSEntityManager messageMgr;
  DDSEntityManager CRmanager;

  // create domain participant
  messageMgr.createParticipant("SuperChat message");
  CRmanager.createParticipant("SuperChat chatroom");

  //create type
  messageTypeSupport_var messageTS = new messageTypeSupport();
  messageMgr.registerType(messageTS.in());

  chatroomTypeSupport_var chatroomTS = new chatroomTypeSupport();
  CRmanager.registerType(chatroomTS.in());

  //create Topic
  char messagetopic_name[] = "SuperChat_message";
  messageMgr.createTopic(messagetopic_name);
  char chatroomtopic_name[] = "SuperChat_chatroom";
  CRmanager.createTopic(chatroomtopic_name);

  //create Publisher
  messageMgr.createPublisher();
  CRmanager.createPublisher();

  // create DataWriter :
  // If autodispose_unregistered_instances is set to true (default value),
  // you will have to start the subscriber before the publisher
  bool autodispose_unregistered_instances = false;
  messageMgr.createWriter(autodispose_unregistered_instances);
  CRmanager.createWriter(autodispose_unregistered_instances);

  // Publish Events
  DataWriter_var messagewriter = messageMgr.getWriter();
  DataWriter_var chatroomwriter = CRmanager.getWriter();

  messageDataWriter_var messageWriter = messageDataWriter::_narrow(messagewriter.in());
  chatroomDataWriter_var chatroomWriter = chatroomDataWriter::_narrow(chatroomwriter.in());

  message messageInstance; /* Example on Stack */
  chatroom chatroomInstance;

  messageInstance.uuid = 1007;
  messageInstance.cksum = 5;
  messageInstance.chatroom_idx = 9;

  chatroomInstance.chatroom_idx = 3;
  chatroomInstance.chatroom_name[0] = 'Z';

  //Publish Chatroom and User information
  //status = chatroomWriter->write(chatroomInstance, DDS::HANDLE_NIL);
  //checkStatus(status, "chatroomDataWriter::write");

  cout << "===[Publisher] Ready ..." <<endl;
  while(RUNNING)
  {
    j = 0;
    //Loop to get characters from input
    do
    {
       cin.get(input[j]);
       j++;
    }while(j < MESSAGE_SIZE_MAX && (char)input[j-1] != '\n');

    if(input[0] == '5')
    {
      cin >> chatroomInstance.chatroom_idx;
      j = 0;
      //Loop to get characters from input
      cin.get();
      do
      {
        cin.get(input[j]);
        j++;
      }while(j < CHATROOM_NAME_MAX && (char)input[j-1] != '\n');

    strncpy(chatroomInstance.chatroom_name, input, CHATROOM_NAME_MAX);
    status = chatroomWriter->write(chatroomInstance, DDS::HANDLE_NIL);
    checkStatus(status, "chatroomDataWriter::write");
    }
    else if(input[0] == '0')
    {
      RUNNING = 0;
    }
    else
    {

      strncpy(messageInstance.message, input, MESSAGE_SIZE_MAX);
      messageInstance.uuid = localUser.uuid;

      status = messageWriter->write(messageInstance, DDS::HANDLE_NIL);
      checkStatus(status, "messageDataWriter::write");
    }

    memset(input, 0, MESSAGE_SIZE_MAX);
    
  }

  /* Remove the DataWriters */
  messageMgr.deleteWriter();
  CRmanager.deleteWriter();

  /* Remove the Publisher. */
  messageMgr.deletePublisher();
  CRmanager.deletePublisher();

  /* Remove the Topics. */
  messageMgr.deleteTopic();
  CRmanager.deleteTopic();

  /* Remove Participant. */
  messageMgr.deleteParticipant();
  CRmanager.deleteParticipant();

  return 0;
}

void *sendUserInfo(void* trash)
{
  ReturnCode_t status;
  userSeq userList;
  SampleInfoSeq infoSeq;

  DDSEntityManager userManagerP;
  //Create Participant
  userManagerP.createParticipant("SuperChat user");
  //Create TypeSupport
  userTypeSupport_var userTS = new userTypeSupport();
  userManagerP.registerType(userTS.in());
  //Create Topic
  char usertopic_name[] = "SuperChat_user";
  userManagerP.createTopic(usertopic_name);
  //Create Publisher
  userManagerP.createPublisher();
  // create DataWriter :
  // If autodispose_unregistered_instances is set to true (default value),
  // you will have to start the subscriber before the publisher
  bool autodispose_unregistered_instances = false;
  userManagerP.createWriter(autodispose_unregistered_instances);
  //Create Data Writer
  DataWriter_var userwriter = userManagerP.getWriter();
  userDataWriter_var userWriter = userDataWriter::_narrow(userwriter.in());
  user userInstance;

  while(RUNNING)
  {
    /*for(int i = 0; i < NICK_SIZE_MAX; i++)
    {
      userInstance.nick[i] = localUser.nick[i];
    }*/
    strncpy(userInstance.nick, localUser.nick, NICK_SIZE_MAX);
    userInstance.chatroom_idx = localUser.chatroom_idx;
    userInstance.uuid = localUser.uuid;

    status = userWriter->write(userInstance, DDS::HANDLE_NIL);
    checkStatus(status, "userDataWriter::write");

    sleep(USER_UPDATE_PERIOD);
  }

  //Cleanup
  userManagerP.deleteWriter();
  userManagerP.deletePublisher();
  userManagerP.deleteTopic();
  userManagerP.deleteParticipant();


}

void *watchUsers(void* trash)
{
  os_time delay_2ms = { 0, 2000000 };
  os_time delay_200ms = { 0, 200000000 };
  int check = 0;
  bool match = 0;
  long double timeWatchingUsers = 0;

  ReturnCode_t status;
  userSeq userList;
  SampleInfoSeq infoSeq;

  DDSEntityManager userManagerS;
  //Create Participant
  userManagerS.createParticipant("SuperChat user");
  //Create TypeSupport
  userTypeSupport_var userTS = new userTypeSupport();
  userManagerS.registerType(userTS.in());
  //Create Topic
  char usertopic_name[] = "SuperChat_user";
  userManagerS.createTopic(usertopic_name);
  //Create Subscriber
  userManagerS.createSubscriber();
  //Create Reader
  userManagerS.createReader();
  //Create Data Reader
  DataReader_var userreader = userManagerS.getReader();
  userDataReader_var userReader = userDataReader::_narrow(userreader.in());
  checkHandle(userReader.in(), "userDataReader::_narrow");

  
  while(RUNNING)
  {
    status = userReader->take(userList, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "userDataReader::take");

    for (DDS::ULong j = 0; j < userList.length(); j++)
    {
      match = 0;
      for(int i = 0; i < numOfUsers && !match; i++)
      {
        if(listOfUsers[i].uuid == userList[j].uuid)
        {
          //cout << "MATCH\n";
          match = 1;
          if(strcmp(listOfUsers[i].nick, userList[j].nick))
          {
            strncpy(listOfUsers[i].nick, userList[j].nick, NICK_SIZE_MAX);
          }
          if(listOfUsers[i].chatroom_idx != userList[j].chatroom_idx)
          {
            listOfUsers[i].chatroom_idx = userList[j].chatroom_idx;
          }
          listOfUsers[i].lastHeard = timeWatchingUsers;
          listOfUsers[i].online = 1;
        }
      }
      if(!match)
      {
        cout << "NEW USER\n";
        User tempUser;
        strncpy(tempUser.nick, userList[j].nick, NICK_SIZE_MAX);
        tempUser.uuid = userList[j].uuid;
        tempUser.chatroom_idx = userList[j].chatroom_idx;
        tempUser.online = 1;
        tempUser.lastHeard = timeWatchingUsers;
        listOfUsers.push_back(tempUser);
        numOfUsers++;
      }
    }

    status = userReader->return_loan(userList, infoSeq);
    checkStatus(status, "userDataReader::return_loan");

    if(check == 50)
    {
      check = 0;
      for(int i = 0; i < numOfUsers; i++)
      {
        if(listOfUsers[i].online && ((timeWatchingUsers - 5) >= listOfUsers[i].lastHeard))
        {
          cout << "USER OFFLINE\n";
          listOfUsers[i].online = 0;
        }
      }
    }

    timeWatchingUsers += 0.2;
    check += 2;
    os_nanoSleep(delay_200ms);

  }

  //Cleanup
  userManagerS.deleteReader();
  userManagerS.deleteSubscriber();
  userManagerS.deleteTopic();
  userManagerS.deleteParticipant();


}

void initializeChatrooms()
{
  //Create a temp chatroom to fill the chatroom vector
  Chatroom temp;
  temp.chatroom_idx = 1;
  char CRname[CHATROOM_NAME_MAX] = {"Public"};
  //Copy the CRname into the temp chatroom name
  strncpy(temp.chatroom_name, CRname, CHATROOM_NAME_MAX);
  listOfChatrooms.push_back(temp);
  //Clear CRname so that all other chatroom names are initialized to empty
  memset(CRname, 0, CHATROOM_NAME_MAX);
  strncpy(temp.chatroom_name, CRname, CHATROOM_NAME_MAX);
  for(int i = 2; i <= CHATROOMS_MAX; i++)
  {
    temp.chatroom_idx = i;
    listOfChatrooms.push_back(temp);
  }
}

void initializeLocalUser()
{
  int uuid = 6;
  int j = 0;
  cin >> uuid;
  cin.get();
  char tempNick[NICK_SIZE_MAX];
  do
  {
    cin.get(tempNick[j]);
    j++;
  }while(j < NICK_SIZE_MAX && (char)tempNick[j-1] != '\n');

  for(int i = 0; i < NICK_SIZE_MAX; i++)
  {
    if(tempNick[i] == '\n')
    {
      tempNick[i] = '\0';
      break;
    }
  }

  strncpy(localUser.nick, tempNick, NICK_SIZE_MAX);
  localUser.uuid = uuid;
  localUser.chatroom_idx = 1;
  listOfUsers.push_back(localUser);
  numOfUsers++;

}

void printChatrooms()
{
  for(int i = 0; i < CHATROOMS_MAX; i++)
  {
    cout << "Chatroom Name: " << listOfChatrooms[i].chatroom_name <<endl;
    cout << "Chatroom_idx: " << listOfChatrooms[i].chatroom_idx <<endl;
  }
}

void printUsers()
{
  for(int i = 0; i < numOfUsers; i++)
  {
    cout << "User Nick: " << listOfUsers[i].nick <<endl;
    cout << "UUid: " << listOfUsers[i].uuid <<endl;
  }
}

int main()
{
  int status = 0;
  int trash, moretrash;	//Garbage variables to send as arguments
  pthread_t subscribe, publish, userinfo, getuserinfo;

  initializeChatrooms();
  initializeLocalUser();

  //Create threads and send trash and more as useless arguments
  pthread_create(&userinfo, NULL, sendUserInfo, (void *) &trash);
  pthread_create(&getuserinfo, NULL, watchUsers, (void *) &trash);
  pthread_create(&subscribe, NULL, sub, (void *) &trash);
  pthread_create(&publish, NULL, pub, (void *) &moretrash);

  
  //Join threads
  pthread_join(subscribe, (void **)status);
  pthread_join(publish, (void **)status);
  pthread_join(getuserinfo, (void **)status);
  pthread_join(userinfo, (void **)status);

//printUsers();

  return 0;
}