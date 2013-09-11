/*
 * log.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef LOG_H_
#define LOG_H_

#include "osa.h"

#undef NDEBUG

#ifdef __cplusplus
extern "C" {
#endif

enum
{
    CAT_LOG_OFF     = 0,
    CAT_LOG_FATAL   = 1,
    CAT_LOG_ERROR   = 2,
    CAT_LOG_WARN    = 3,
    CAT_LOG_INFO    = 4,
    CAT_LOG_DEBUG   = 5,

    CAT_LOG_MAX     = 6,
};

#ifndef NDEBUG

#define CAT_LogFatal(fmt, args...)  CAT_Log(CAT_LOG_FATAL, __FILE__, __LINE__, fmt, ##args)
#define CAT_LogError(fmt, args...)  CAT_Log(CAT_LOG_ERROR, __FILE__, __LINE__, fmt, ##args)
#define CAT_LogWarn(fmt, args...)  CAT_Log(CAT_LOG_WARN, __FILE__, __LINE__, fmt, ##args)
#define CAT_LogInfo(fmt, args...)  CAT_Log(CAT_LOG_INFO, __FILE__, __LINE__, fmt, ##args)
#define CAT_LogDebug(fmt, args...)  CAT_Log(CAT_LOG_DEBUG, __FILE__, __LINE__, fmt, ##args)

#else

#define CAT_LogFatal(fmt, args...)
#define CAT_LogError(fmt, args...)
#define CAT_LogWarn(fmt, args...)
#define CAT_LogInfo(fmt, args...)
#define CAT_LogDebug(fmt, args...)

#endif


void        CAT_Log(osa_uint8_t logType, char *file, osa_uint32_t line, char *fmt, ...);
void        CAT_LogSetLevel(osa_uint8_t level);
osa_uint8_t CAT_LogGetLevel();

osa_err_t   CAT_LogModuleInit();
void        CAT_LogModuleExit();


#ifdef __cplusplus
}
#endif

#endif /* LOG_H_ */
