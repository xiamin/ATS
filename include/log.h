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
    ATS_LOG_OFF     = 0,
    ATS_LOG_FATAL   = 1,
    ATS_LOG_ERROR   = 2,
    ATS_LOG_WARN    = 3,
    ATS_LOG_INFO    = 4,
    ATS_LOG_DEBUG   = 5,

    ATS_LOG_MAX     = 6,
};

#ifndef NDEBUG

#define ATS_LogFatal(fmt, args...)  ATS_Log(ATS_LOG_FATAL, __FILE__, __LINE__, fmt, ##args)
#define ATS_LogError(fmt, args...)  ATS_Log(ATS_LOG_ERROR, __FILE__, __LINE__, fmt, ##args)
#define ATS_LogWarn(fmt, args...)  ATS_Log(ATS_LOG_WARN, __FILE__, __LINE__, fmt, ##args)
#define ATS_LogInfo(fmt, args...)  ATS_Log(ATS_LOG_INFO, __FILE__, __LINE__, fmt, ##args)
#define ATS_LogDebug(fmt, args...)  ATS_Log(ATS_LOG_DEBUG, __FILE__, __LINE__, fmt, ##args)

#else

#define ATS_LogFatal(fmt, args...)
#define ATS_LogError(fmt, args...)
#define ATS_LogWarn(fmt, args...)
#define ATS_LogInfo(fmt, args...)
#define ATS_LogDebug(fmt, args...)

#endif


void        ATS_Log(osa_uint8_t logType, char *file, osa_uint32_t line, char *fmt, ...);
void        ATS_LogSetLevel(osa_uint8_t level);
osa_uint8_t ATS_LogGetLevel();

osa_err_t   ATS_LogModuleInit();
void        ATS_LogModuleExit();


#ifdef __cplusplus
}
#endif

#endif /* LOG_H_ */
