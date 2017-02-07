#include "ContentFilteredTopicDataSplDcps.h"
#include "ccpp_ContentFilteredTopicData.h"
#include "dds_type_aliases.h"

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

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__StockMarket_Stock__copyIn(
    c_base base,
    struct ::StockMarket::Stock *from,
    struct _StockMarket_Stock *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->ticker){
        to->ticker = c_stringNew(base, from->ticker);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'StockMarket::Stock.ticker' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->ticker = c_stringNew(base, from->ticker);
#endif
    to->price = (c_float)from->price;
    return result;
}

void
__StockMarket_Stock__copyOut(
    void *_from,
    void *_to)
{
    struct _StockMarket_Stock *from = (struct _StockMarket_Stock *)_from;
    struct ::StockMarket::Stock *to = (struct ::StockMarket::Stock *)_to;
    to->ticker = DDS::string_dup(from->ticker ? from->ticker : "");
    to->price = (::DDS::Float)from->price;
}

