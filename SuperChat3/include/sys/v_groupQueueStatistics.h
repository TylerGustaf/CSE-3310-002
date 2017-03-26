/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2013 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef V_GROUPQUEUESTATISTICS_H
#define V_GROUPQUEUESTATISTICS_H

#include "v_kernel.h"
#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * \brief The <code>v_groupQueueStatistics</code> cast method.
 *
 * This method casts an object to a <code>v_groupQueueStatistics</code> object.
 * Before the cast is performed, if compiled with the NDEBUG flag not set,
 * the type of the object is checked to be <code>v_groupQueueStatistics</code> or
 * one of its subclasses.
 */
#define v_groupQueueStatistics(s) (C_CAST(s,v_groupQueueStatistics))

OS_API v_groupQueueStatistics
v_groupQueueStatisticsNew(
    v_kernel k);

OS_API void
v_groupQueueStatisticsInit(
    v_groupQueueStatistics _this);

OS_API void
v_groupQueueStatisticsDeinit(
    v_groupQueueStatistics _this);

OS_API void
v_groupQueueStatisticsFree(
    v_groupQueueStatistics _this);

OS_API c_bool
v_groupQueueStatisticsReset(
    v_groupQueueStatistics _this,
    const c_char *fieldName);

#undef OS_API

#endif
