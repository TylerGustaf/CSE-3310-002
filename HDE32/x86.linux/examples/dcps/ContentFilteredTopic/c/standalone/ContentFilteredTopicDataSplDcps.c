#if defined (__cplusplus)
extern "C" {
#endif

#include "ContentFilteredTopicDataSplDcps.h"
#include "ContentFilteredTopicDataDcps.h"

const char *
__StockMarket_Stock__name(void)
{
    return (const char*)"StockMarket::Stock";
}

const char *
__StockMarket_Stock__keys(void)
{
    return (const char*)"ticker";
}

/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 138 */
#include <v_kernel.h>
#include <v_topic.h>
#include <string.h>
#include <os_report.h>

/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 212 */
c_bool
__StockMarket_Stock__copyIn(c_base base, void *_from, void *_to)
{
    c_bool result = TRUE;

    StockMarket_Stock *from = (StockMarket_Stock *)_from;
    struct _StockMarket_Stock *to = (struct _StockMarket_Stock *)_to;
/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 491 */
/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 298 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->ticker) {
/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 325 */
        to->ticker = c_stringNew(base, from->ticker);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'StockMarket::Stock.ticker' of type 'c_string' is NULL.");
        result = FALSE;
    }
#else
    to->ticker = c_stringNew(base, from->ticker);
#endif
/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 491 */
/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 292 */
    to->price = (c_float)from->price;
/* Code generated in file: /home/dds/OvernightTests/tmp.Z9PhthuYz4/build/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 244 */
    (void) base;
    return result;
}

#include <dds_dcps_private.h>

void
__StockMarket_Stock__copyOut(void *_from, void *_to)
{
    struct _StockMarket_Stock *from = (struct _StockMarket_Stock *)_from;
    StockMarket_Stock *to = (StockMarket_Stock *)_to;
    DDS_string_replace (from->ticker ? from->ticker : "", &to->ticker);
    to->price = (DDS_float)from->price;
}

#include <dds_dcps_private.h>

StockMarket_Stock *StockMarket_Stock__alloc (void)
{
    DDS_boolean StockMarket_Stock__free (void *object);

    return (StockMarket_Stock *)DDS__malloc (StockMarket_Stock__free, 0, sizeof(StockMarket_Stock));
}

DDS_boolean StockMarket_Stock__free (void *object)
{
    StockMarket_Stock *o = (StockMarket_Stock *)object;

    DDS_string_clean (&o->ticker);
    return TRUE;
}

const char * StockMarket_Stock_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"StockMarket\"><Struct name=\"Stock\"><Member name=\"ticker\">",
"<String/></Member><Member name=\"price\"><Float/></Member></Struct></Module></MetaData>"};
const c_ulong  StockMarket_Stock_metaDescriptorArrLength = 2;
#if defined (__cplusplus)
}
#endif
