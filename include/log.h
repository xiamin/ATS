/*
 * log.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef LOG_H_
#define LOG_H_

#include "osa.h"

enum
{
    CAT_LOG_FATAL,
    CAT_LOG_ERROR,
    CAT_LOG_WARN,
    CAT_LOG_INFO,
    CAT_LOG_DEBUG,

    CAT_LOG_MAX,
};

#ifndef NDEBUG

#define CAT_LogFatal(fmt, args...)  CAT_Log(CAT_LOG_FATAL, __FILE__, __func__, __LINE__, fmt, ##args)
#define CAT_LogError(fmt, args...)  CAT_Log(CAT_LOG_ERROR, __FILE__, __func__, __LINE__, fmt, ##args)
#define CAT_LogWarn(fmt, args...)  CAT_Log(CAT_LOG_ERROR, __FILE__, __func__, __LINE__, fmt, ##args)
#define CAT_LogInfo(fmt, args...)  CAT_Log(CAT_LOG_ERROR, __FILE__, __func__, __LINE__, fmt, ##args)
#define CAT_LogDebug(fmt, args...)  CAT_Log(CAT_LOG_ERROR, __FILE__, __func__, __LINE__, fmt, ##args)

#else

#define CAT_LogFatal(fmt, args...)
#define CAT_LogError(fmt, args...)
#define CAT_LogWarn(fmt, args...)
#define CAT_LogInfo(fmt, args...)
#define CAT_LogDebug(fmt, args...)

#endif


void CAT_Log(osa_uint8_t logType, char *file, char *func, osa_uint32_t line, char *fmt, ...);

#endif /* LOG_H_ */
