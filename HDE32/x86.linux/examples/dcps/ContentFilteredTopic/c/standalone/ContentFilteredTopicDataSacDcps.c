#if defined (__cplusplus)
extern "C" {
#endif

#include "ContentFilteredTopicDataSacDcps.h"
#include "ContentFilteredTopicDataSplDcps.h"

#include <dds_dcps.h>
#include <dds_dcps_private.h>

DDS_sequence_StockMarket_Stock *DDS_sequence_StockMarket_Stock__alloc (void)
{
    return (DDS_sequence_StockMarket_Stock *)DDS__malloc (DDS_sequence_free, 0, sizeof(DDS_sequence_StockMarket_Stock));
}

StockMarket_Stock *DDS_sequence_StockMarket_Stock_allocbuf (DDS_unsigned_long len)
{
    DDS_boolean DDS_sequence_StockMarket_Stock_freebuf (void *buffer);

    return (StockMarket_Stock *)DDS_sequence_allocbuf (DDS_sequence_StockMarket_Stock_freebuf, sizeof (StockMarket_Stock), len);
}

DDS_boolean DDS_sequence_StockMarket_Stock_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    StockMarket_Stock *b = (StockMarket_Stock *)buffer;
    DDS_unsigned_long i;
    void StockMarket_Stock__free (void *object);

    for (i = 0; i < *count; i++) {
        StockMarket_Stock__free (&b[i]);
    }
    return TRUE;
}

extern c_bool __StockMarket_Stock__copyIn(c_base base, void *from, void *to);
extern void __StockMarket_Stock__copyOut(void *from, void *to);
extern const char *StockMarket_Stock_metaDescriptor[];
extern const c_ulong StockMarket_Stock_metaDescriptorArrLength;

StockMarket_StockTypeSupport
StockMarket_StockTypeSupport__alloc (
    void
    )
{
    c_ulong i;
    os_size_t strlength =0;
    char * metaDescriptor;
    StockMarket_StockTypeSupport result;
    for (i = 0; i < StockMarket_Stock_metaDescriptorArrLength; i++) {
        strlength +=strlen(StockMarket_Stock_metaDescriptor[i]);
    }

    metaDescriptor = (char*)malloc(strlength+1);
    metaDescriptor[0] = '\0';
    for (i = 0; i < StockMarket_Stock_metaDescriptorArrLength; i++) {
        strcat(metaDescriptor,StockMarket_Stock_metaDescriptor[i]);
    }
	result = DDS__FooTypeSupport__alloc (
	    __StockMarket_Stock__name(),
            __StockMarket_Stock__keys(),
            metaDescriptor,
            NULL,
            (DDS_copyIn)__StockMarket_Stock__copyIn,
            (DDS_copyOut)__StockMarket_Stock__copyOut,
            (DDS_unsigned_long)(sizeof(StockMarket_Stock)),
            (DDS_typeSupportAllocBuffer)DDS_sequence_StockMarket_Stock_allocbuf
        );
    free(metaDescriptor);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockTypeSupport_register_type (
    StockMarket_StockTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooTypeSupport_register_type (
	    (DDS_TypeSupport)_this,
	    domain,
	    name
	);
    return result;
}

DDS_string
StockMarket_StockTypeSupport_get_type_name (
    StockMarket_StockTypeSupport _this
    )
{
    DDS_string result = (DDS_string)
        DDS__FooTypeSupport_get_type_name (
	    (DDS_TypeSupport)_this
	);
    return result;
}

DDS_InstanceHandle_t
StockMarket_StockDataWriter_register_instance (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data
	);
    return result;
}

DDS_InstanceHandle_t
StockMarket_StockDataWriter_register_instance_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_unregister_instance (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance (
	    (const DDS_DataWriter)_this,
	    (DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_unregister_instance_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_write (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_write_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_dispose (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_dispose_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_writedispose (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_writedispose_w_timestamp (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataWriter_get_key_value (
    StockMarket_StockDataWriter _this,
    StockMarket_Stock *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_get_key_value (
	    (DDS_DataWriter)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
StockMarket_StockDataWriter_lookup_instance (
    StockMarket_StockDataWriter _this,
    const StockMarket_Stock *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_lookup_instance (
        (DDS_DataWriter)_this,
        (DDS_sample)key_holder
    );
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_read (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_take (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_read_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_take_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_read_next_sample (
    StockMarket_StockDataReader _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_take_next_sample (
    StockMarket_StockDataReader _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_read_next_instance_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_take_next_instance_w_condition (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_return_loan (
    StockMarket_StockDataReader _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_return_loan (
            (DDS_DataReader)_this,
            (DDS_sequence)received_data,
            info_seq
    );
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReader_get_key_value (
    StockMarket_StockDataReader _this,
    StockMarket_Stock *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_get_key_value (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
StockMarket_StockDataReader_lookup_instance (
    StockMarket_StockDataReader _this,
    const StockMarket_Stock *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReader_lookup_instance (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReaderView_read (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReaderView_take (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_next_sample (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_next_sample (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
StockMarket_StockDataReaderView_return_loan (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_return_loan (
            (DDS_DataReaderView)_this,
            (DDS_sequence)received_data,
            info_seq
    );

    if ( result == DDS_RETCODE_OK ) {
        DDS__free(received_data->_buffer);
        received_data->_length  = 0;
        received_data->_maximum = 0;
        received_data->_buffer  = NULL;

        DDS__free(info_seq->_buffer);
        info_seq->_length  = 0;
        info_seq->_maximum = 0;
        info_seq->_buffer  = NULL;
    }

    return result;
}


DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
StockMarket_StockDataReaderView_read_next_instance_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
StockMarket_StockDataReaderView_take_next_instance_w_condition (
    StockMarket_StockDataReaderView _this,
    DDS_sequence_StockMarket_Stock *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
StockMarket_StockDataReaderView_get_key_value (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_get_key_value (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}


DDS_InstanceHandle_t
StockMarket_StockDataReaderView_lookup_instance (
    StockMarket_StockDataReaderView _this,
    StockMarket_Stock *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReaderView_lookup_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

#if defined (__cplusplus)
}
#endif
