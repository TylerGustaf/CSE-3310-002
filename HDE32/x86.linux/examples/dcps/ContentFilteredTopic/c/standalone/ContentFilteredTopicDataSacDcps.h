#ifndef CONTENTFILTEREDTOPICDATASACDCPS_H
#define CONTENTFILTEREDTOPICDATASACDCPS_H

#include "ContentFilteredTopicDataDcps.h"

#ifndef DDS_API
#define DDS_API
#endif


#define StockMarket_StockTypeSupport DDS_TypeSupport

 StockMarket_StockTypeSupport
StockMarket_StockTypeSupport__alloc (
    void
    );

 DDS_ReturnCode_t
StockMarket_StockTypeSupport_register_type (
    StockMarket_StockTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

 DDS_string
StockMarket_StockTypeSupport_get_type_name (
    StockMarket_StockTypeSupport _this
    );

#ifndef _DDS_sequence_StockMarket_Stock_defined
#define _DDS_sequence_StockMarket_Stock_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    StockMarket_Stock *_buffer;
    DDS_boolean _release;
} DDS_sequence_StockMarket_Stock;

 DDS_sequence_StockMarket_Stock *DDS_sequence_StockMarket_Stock__alloc (void);
 StockMarket_Stock *DDS_sequence_StockMarket_Stock_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_StockMarket_Stock_defined */

#define StockMarket_StockDataWriter DDS_DataWriter

#define StockMarket_StockDataWriter_enable DDS_Entity_enable

#define StockMarket_StockDataWriter_get_status_changes DDS_Entity_get_status_changes

#define StockMarket_StockDataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define StockMarket_StockDataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define StockMarket_StockDataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define StockMarket_StockDataWriter_get_listener DDS_DataWriter_get_listener

#define StockMarket_StockDataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define StockMarket_StockDataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define StockMarket_StockDataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define StockMarket_StockDataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define StockMarket_StockDataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define StockMarket_StockDataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define StockMarket_StockDataWriter_get_publisher DDS_DataWriter_get_publisher

#define StockMarket_StockDataWriter_get_qos DDS_DataWriter_get_qos

#define StockMarket_StockDataWriter_get_topic DDS_DataWriter_get_topic

#define StockMarket_StockDataWriter_set_listener DDS_DataWriter_set_listener

#define StockMarket_StockDataWriter_set_qos DDS_DataWriter_set_qos

 DDS_InstanceHandle_t
StockMarket_StockDataWriter_register_instance (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data
    );

 DDS_InstanceHandle_t
StockMarket_StockDataWriter_register_instance_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_unregister_instance (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_unregister_instance_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_write (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_write_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_dispose (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_dispose_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_writedispose (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_writedispose_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
StockMarket_StockDataWriter_get_key_value (
    StockMarket_StockDataWriter _this,
    StockMarket_Stock *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
StockMarket_StockDataWriter_lookup_instance (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *key_holder
    );

#define StockMarket_StockDataReader DDS_DataReader

#define StockMarket_StockDataReader_enable DDS_Entity_enable

#define StockMarket_StockDataReader_get_status_changes DDS_Entity_get_status_changes

#define StockMarket_StockDataReader_get_statuscondition DDS_Entity_get_statuscondition

#define StockMarket_StockDataReader_get_instance_handle DDS_Entity_get_instance_handle

#define StockMarket_StockDataReader_create_querycondition DDS_DataReader_create_querycondition

#define StockMarket_StockDataReader_create_readcondition DDS_DataReader_create_readcondition

#define StockMarket_StockDataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define StockMarket_StockDataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define StockMarket_StockDataReader_get_listener DDS_DataReader_get_listener

#define StockMarket_StockDataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define StockMarket_StockDataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define StockMarket_StockDataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define StockMarket_StockDataReader_get_qos DDS_DataReader_get_qos

#define StockMarket_StockDataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define StockMarket_StockDataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define StockMarket_StockDataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define StockMarket_StockDataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define StockMarket_StockDataReader_get_subscriber DDS_DataReader_get_subscriber

#define StockMarket_StockDataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define StockMarket_StockDataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define StockMarket_StockDataReader_set_listener DDS_DataReader_set_listener

#define StockMarket_StockDataReader_set_qos DDS_DataReader_set_qos

#define StockMarket_StockDataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

 DDS_ReturnCode_t
StockMarket_StockDataReader_read (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_take (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_read_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_take_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_read_next_sample (
    StockMarket_StockDataReader _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_take_next_sample (
    StockMarket_StockDataReader _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_read_instance (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_take_instance (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_read_next_instance (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_take_next_instance (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_read_next_instance_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_take_next_instance_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_return_loan (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
StockMarket_StockDataReader_get_key_value (
    StockMarket_StockDataReader _this,
    StockMarket_Stock *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
StockMarket_StockDataReader_lookup_instance (
    StockMarket_StockDataReader _this,
    const StockMarket_Stock *key_holder
    );

#define StockMarket_StockDataReaderView DDS_DataReaderView

#define StockMarket_StockDataReaderView_enable DDS_Entity_enable

#define StockMarket_StockDataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define StockMarket_StockDataReaderView_get_qos DDS_DataReaderView_get_qos

#define StockMarket_StockDataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define StockMarket_StockDataReaderView_set_qos DDS_DataReaderView_set_qos

#define StockMarket_StockDataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define StockMarket_StockDataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define StockMarket_StockDataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define StockMarket_StockDataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_read (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_take (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_next_sample (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_next_sample (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_instance (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_instance (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_next_instance (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_next_instance (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_return_loan (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_next_instance_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_next_instance_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
StockMarket_StockDataReaderView_get_key_value (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
StockMarket_StockDataReaderView_lookup_instance (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *key_holder
    );

#endif
