//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: HelloWorldData.h
//  Source: ../../idl/HelloWorldData.idl
//  Generated: Mon Feb  6 23:21:43 2017
//  OpenSplice V6.4.140407OSS
//  
//******************************************************************
#ifndef _HELLOWORLDDATA_H_
#define _HELLOWORLDDATA_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"


namespace HelloWorldData
{
   struct Msg;

   struct Msg
   {
         DDS::Long userID;
         DDS::String_mgr message;
   };

   typedef DDS_DCPSStruct_var < Msg> Msg_var;
   typedef DDS_DCPSStruct_out < Msg> Msg_out;
}




#endif 
