// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.1.1
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:461

#ifndef _TAO_IDL_DDS_BUILTINTOPICSS_YRTSIB_H_
#define _TAO_IDL_DDS_BUILTINTOPICSS_YRTSIB_H_


#include "dds_builtinTopicsC.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/Fixed_Array_SArgument_T.h"
#include "tao/PortableServer/Var_Array_SArgument_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::DDS::octSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::octSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  template<>
  class SArg_Traits< ::DDS::BuiltinTopicKey_t_tag>
    : public
        Fixed_Array_SArg_Traits_T<
            ::DDS::BuiltinTopicKey_t_var,
            ::DDS::BuiltinTopicKey_t_forany,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::DDS::StringSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::StringSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::Duration_t>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::Duration_t,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::UserDataQosPolicy>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::UserDataQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::TopicDataQosPolicy>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::TopicDataQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::GroupDataQosPolicy>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::GroupDataQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::TransportPriorityQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::TransportPriorityQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::LifespanQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::LifespanQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::DDS::DurabilityQosPolicyKind>
    : public
        Basic_SArg_Traits_T<
            ::DDS::DurabilityQosPolicyKind,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::DurabilityQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::DurabilityQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::DDS::PresentationQosPolicyAccessScopeKind>
    : public
        Basic_SArg_Traits_T<
            ::DDS::PresentationQosPolicyAccessScopeKind,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::PresentationQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::PresentationQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::DeadlineQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::DeadlineQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::LatencyBudgetQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::LatencyBudgetQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::DDS::OwnershipQosPolicyKind>
    : public
        Basic_SArg_Traits_T<
            ::DDS::OwnershipQosPolicyKind,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::OwnershipQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::OwnershipQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::OwnershipStrengthQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::OwnershipStrengthQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::DDS::LivelinessQosPolicyKind>
    : public
        Basic_SArg_Traits_T<
            ::DDS::LivelinessQosPolicyKind,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::LivelinessQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::LivelinessQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::TimeBasedFilterQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::TimeBasedFilterQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::PartitionQosPolicy>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::PartitionQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::DDS::ReliabilityQosPolicyKind>
    : public
        Basic_SArg_Traits_T<
            ::DDS::ReliabilityQosPolicyKind,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::ReliabilityQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::ReliabilityQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::DDS::DestinationOrderQosPolicyKind>
    : public
        Basic_SArg_Traits_T<
            ::DDS::DestinationOrderQosPolicyKind,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::DestinationOrderQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::DestinationOrderQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::DDS::HistoryQosPolicyKind>
    : public
        Basic_SArg_Traits_T<
            ::DDS::HistoryQosPolicyKind,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::HistoryQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::HistoryQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::ResourceLimitsQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::ResourceLimitsQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::DurabilityServiceQosPolicy>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DDS::DurabilityServiceQosPolicy,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::ParticipantBuiltinTopicData>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::ParticipantBuiltinTopicData,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::TopicBuiltinTopicData>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::TopicBuiltinTopicData,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::PublicationBuiltinTopicData>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::PublicationBuiltinTopicData,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::DDS::SubscriptionBuiltinTopicData>
    : public
        Var_Size_SArg_Traits_T<
            ::DDS::SubscriptionBuiltinTopicData,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_sh.cpp:38

namespace POA_DDS
{
  

// TAO_IDL - Generated from
// be/be_visitor_module/module_sh.cpp:69

} // module DDS

#endif /* ifndef */

