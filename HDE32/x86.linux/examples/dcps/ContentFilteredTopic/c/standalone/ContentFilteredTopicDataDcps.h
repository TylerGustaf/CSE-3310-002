#ifndef CONTENTFILTEREDTOPICDATADCPS_H
#define CONTENTFILTEREDTOPICDATADCPS_H

#include <dds_dcps.h>


#ifndef _StockMarket_Stock_defined
#define _StockMarket_Stock_defined
#ifdef __cplusplus
struct StockMarket_Stock;
#else /* __cplusplus */
typedef struct StockMarket_Stock StockMarket_Stock;
#endif /* __cplusplus */
#endif /* _StockMarket_Stock_defined */
 StockMarket_Stock *StockMarket_Stock__alloc (void);

struct StockMarket_Stock {
    DDS_string ticker;
    DDS_float price;
};

#endif
