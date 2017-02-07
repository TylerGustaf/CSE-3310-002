#include "ContentFilteredTopicDataSplDcps.h"
#include "ContentFilteredTopicData_DCPS.hpp"

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
#include <org/opensplice/core/EntityRegistry.hpp>

c_bool
__StockMarket_Stock__copyIn(
    c_base base,
    class ::StockMarket::Stock *from,
    struct _StockMarket_Stock *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
        to->ticker = c_stringNew(base, from->ticker_.c_str());
#else
            to->ticker = c_stringNew(base, from->ticker_.c_str());
#endif
    to->price = (c_float)from->price_;
    return result;
}

INSTANTIATE_TYPED_REGISTRIES(::StockMarket::Stock)

void
__StockMarket_Stock__copyOut(
    void *_from,
    void *_to)
{
    struct _StockMarket_Stock *from = (struct _StockMarket_Stock *)_from;
    class ::StockMarket::Stock *to = (class ::StockMarket::Stock *)_to;
    to->ticker_ = (from->ticker ? from->ticker : "");
    to->price_ = (::DDS::Float)from->price;
}

