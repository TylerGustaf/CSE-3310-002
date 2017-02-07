#ifndef CONTENTFILTEREDTOPICDATASPLTYPES_H
#define CONTENTFILTEREDTOPICDATASPLTYPES_H

#include "ccpp_ContentFilteredTopicData.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ContentFilteredTopicData_StockMarket__load (c_base base);

extern c_metaObject __StockMarket_Stock__load (c_base base);
extern const char * __StockMarket_Stock__keys (void);
extern const char * __StockMarket_Stock__name (void);
struct _StockMarket_Stock ;
extern  c_bool __StockMarket_Stock__copyIn(c_base base, struct StockMarket::Stock *from, struct _StockMarket_Stock *to);
extern  void __StockMarket_Stock__copyOut(void *_from, void *_to);
struct _StockMarket_Stock {
    c_string ticker;
    c_float price;
};

#endif
