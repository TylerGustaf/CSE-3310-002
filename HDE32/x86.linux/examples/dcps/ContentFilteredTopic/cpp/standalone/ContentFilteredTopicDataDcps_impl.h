#ifndef CONTENTFILTEREDTOPICDATADCPS_IMPL_H_
#define CONTENTFILTEREDTOPICDATADCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_ContentFilteredTopicData.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


namespace StockMarket {

    class  StockTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        StockTypeSupportFactory() {}
        virtual ~StockTypeSupportFactory() {}
    private:
        ::DDS::DataWriter_ptr
        create_datawriter (gapi_dataWriter handle);
    
        ::DDS::DataReader_ptr
        create_datareader (gapi_dataReader handle);
    
        ::DDS::DataReaderView_ptr
        create_view (gapi_dataReaderView handle);
    };
    
    class  StockTypeSupport : public virtual StockTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type(
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name() THROW_ORB_EXCEPTIONS;
    
        StockTypeSupport (void);
        virtual ~StockTypeSupport (void);
    
    private:
        StockTypeSupport (const StockTypeSupport &);
        void operator= (const StockTypeSupport &);
    
        static const char *metaDescriptor[];
        static const ::DDS::ULong metaDescriptorArrLength;
    };
    
    typedef StockTypeSupportInterface_var StockTypeSupport_var;
    typedef StockTypeSupportInterface_ptr StockTypeSupport_ptr;
    
    class  StockDataWriter_impl : public virtual StockDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance(
            const Stock & instance_data) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
            const Stock & instance_data,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
            const Stock & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Stock & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Stock & instance_data) THROW_ORB_EXCEPTIONS;
    
    
        StockDataWriter_impl (
            gapi_dataWriter handle
        );
    
        virtual ~StockDataWriter_impl (void);
    
    private:
        StockDataWriter_impl(const StockDataWriter_impl &);
        void operator= (const StockDataWriter &);
    };
    
    class  StockDataReader_impl : public virtual StockDataReader,
                                        public ::DDS::DataReader_impl
    {
        friend class StockDataReaderView_impl;
    public:
        virtual ::DDS::ReturnCode_t read(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Stock & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Stock & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Stock & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Stock & instance) THROW_ORB_EXCEPTIONS;
    
        StockDataReader_impl (
            gapi_dataReader handle
        );
    
        virtual ~StockDataReader_impl(void);
    
    private:
        StockDataReader_impl(const StockDataReader &);
        void operator= (const StockDataReader &);
    
        static ::DDS::ReturnCode_t check_preconditions(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples
        );
    };
    
    class  StockDataReaderView_impl : public virtual StockDataReaderView,
                                        public ::DDS::DataReaderView_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Stock & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Stock & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            StockSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Stock & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Stock & instance) THROW_ORB_EXCEPTIONS;
    
        StockDataReaderView_impl (
            gapi_dataReader handle
        );
    
        virtual ~StockDataReaderView_impl(void);
    
    private:
        StockDataReaderView_impl(const StockDataReaderView &);
        void operator= (const StockDataReaderView &);
    };
    
}

#endif
