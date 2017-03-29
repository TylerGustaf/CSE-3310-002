
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
#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "ccpp_HelloWorldData.h"
#include "os.h"

//#include "example_main.h"

using namespace DDS;
//using namespace HelloWorldData;
using namespace SuperChat;


void *sub(void* trash)
{
  os_time delay_2ms = { 0, 2000000 };
  os_time delay_200ms = { 0, 200000000 };
  messageSeq messageList;
  chatroomSeq chatroomList;
  userSeq userList;
  SampleInfoSeq infoSeq;

  DDSEntityManager messageMgr;
  DDSEntityManager CRmanager; //Test CR manager
  DDSEntityManager userManager; //Test User manager

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

  bool closed = false;
  ReturnCode_t status =  - 1;
  int count = 0;
  while (true) // We dont want the example to run indefinitely
  {
    status = messageReader->take(messageList, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "messageDataReader::take");
    for (DDS::ULong j = 0; j < messageList.length(); j++)
    {
      cout << "=== [Subscriber] message received :" << endl;
      cout << "    UUID  : " << messageList[j].uuid << endl;
      cout << "    CR_idx : " <<messageList[j].chatroom_idx <<endl;
      cout << "    Message : " << messageList[j].message;
      cout << "    cksum : " <<messageList[j].cksum <<endl;
      closed = true;
    }
    status = messageReader->return_loan(messageList, infoSeq);
    checkStatus(status, "messageDataReader::return_loan");

    status = chatroomReader->take(chatroomList, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "chatroomDataReader::take");
    for (DDS::ULong j = 0; j < chatroomList.length(); j++)
    {
      cout << "=== [Subscriber] chatroom received :" << endl;
      cout << "    CR_idx : " <<chatroomList[j].chatroom_idx <<endl;
      cout << "    CR Name : " << chatroomList[j].chatroom_name << endl;
      closed = true;
    }
    status = chatroomReader->return_loan(chatroomList, infoSeq);
    checkStatus(status, "chatroomDataReader::return_loan");

    status = userReader->take(userList, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "userDataReader::take");
    for (DDS::ULong j = 0; j < userList.length(); j++)
    {
      cout << "=== [Subscriber] user received :" << endl;
      cout << "    UUID  : " << userList[j].uuid << endl;
      cout << "    CR_idx : " <<userList[j].chatroom_idx <<endl;
      cout << "    Nick : " << userList[j].nick << endl;
      closed = true;
    }
    status = userReader->return_loan(userList, infoSeq);
    checkStatus(status, "userDataReader::return_loan");

    os_nanoSleep(delay_200ms);
    ++count;
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
  char input[144];

  ReturnCode_t status;
  os_time delay_1s = { 1, 0 };
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

  //create Publisher
  messageMgr.createPublisher();
  CRmanager.createPublisher();
  userManager.createPublisher();

  // create DataWriter :
  // If autodispose_unregistered_instances is set to true (default value),
  // you will have to start the subscriber before the publisher
  bool autodispose_unregistered_instances = false;
  messageMgr.createWriter(autodispose_unregistered_instances);
  CRmanager.createWriter(autodispose_unregistered_instances);
  userManager.createWriter(autodispose_unregistered_instances);

  // Publish Events
  DataWriter_var messagewriter = messageMgr.getWriter();
  DataWriter_var chatroomwriter = CRmanager.getWriter();
  DataWriter_var userwriter = userManager.getWriter();

  messageDataWriter_var messageWriter = messageDataWriter::_narrow(messagewriter.in());
  chatroomDataWriter_var chatroomWriter = chatroomDataWriter::_narrow(chatroomwriter.in());
  userDataWriter_var userWriter = userDataWriter::_narrow(userwriter.in());

  message messageInstance; /* Example on Stack */
  chatroom chatroomInstance;
  user userInstance;

  messageInstance.uuid = 1007;
  messageInstance.cksum = 5;
  messageInstance.chatroom_idx = 9;

  chatroomInstance.chatroom_idx = 3;
  chatroomInstance.chatroom_name[0] = 'Z';

  userInstance.nick[0] = 'A';
  userInstance.uuid = 777;
  userInstance.chatroom_idx = 9;

  status = chatroomWriter->write(chatroomInstance, DDS::HANDLE_NIL);
  checkStatus(status, "chatroomDataWriter::write");

  status = userWriter->write(userInstance, DDS::HANDLE_NIL);
  checkStatus(status, "userDataWriter::write");

  cout << "===[Publisher] Ready ..." <<endl;
  while(true)
  {
    j = 0;
    //Loop to get characters from input
    do
    {
       cin.get(input[j]);
       j++;
    }while(j < 144 && (char)input[j-1] != '\n');

    for(int i = 0; i < 144; i++)
    {
      messageInstance.message[i] = input[i];
    }

    status = messageWriter->write(messageInstance, DDS::HANDLE_NIL);
    checkStatus(status, "messageDataWriter::write");
    //os_nanoSleep(delay_1s);

    for(int i = 0; i < 144; i++)
    {
      input[i] = '\0';
    }
}

  /* Remove the DataWriters */
  messageMgr.deleteWriter();
  CRmanager.deleteWriter();
  userManager.deleteWriter();

  /* Remove the Publisher. */
  messageMgr.deletePublisher();
  CRmanager.deletePublisher();
  userManager.deletePublisher();

  /* Remove the Topics. */
  messageMgr.deleteTopic();
  CRmanager.deleteTopic();
  userManager.deleteTopic();

  /* Remove Participant. */
  messageMgr.deleteParticipant();
  CRmanager.deleteParticipant();
  userManager.deleteParticipant();

  return 0;
}

int main()
{
  int status = 0;
  int trash, moretrash;	//Garbage variables to send as arguments
  pthread_t mBoard, chat;

  //Create threads and send trash and more as useless arguments

  pthread_create(&mBoard, NULL, sub, (void *) &trash);
  //sleep(5);
  pthread_create(&chat, NULL, pub, (void *) &moretrash);
  
  //Join threads
  pthread_join(mBoard, (void **)status);
  pthread_join(chat, (void **)status);

  pthread_exit(NULL);
}
