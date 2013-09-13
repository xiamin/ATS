/*
 * log.c
 *
 * Copyright (C) TuoAn
 *
 */

#include <stdarg.h>

#include "osa.h"
#include "module.h"
#include "cat.h"
#include "conf_xml.h"
#include "log.h"
#include "log.h"

#ifdef __cplusplus
extern "C" {
#endif



struct _Log
{
    osa_uint8_t     logLevel;
    osa_file_t      logFile;
};


static struct _Log  log;

static osa_err_t   logConfRead(ATS_Conf *cf, void *out_data); 
static osa_err_t   logConfWrite(ATS_Conf *cf, void *data); 
static osa_err_t   logModuleEntry(ATS_Conf *cf, int argc, char **argv);
static void        logModuleExit(ATS_Conf *cf);


 
static ATS_Module  logModule =
{
    .name   = "log",
    .state  = ATS_MODULE_ON,
    .cf     =
    {
        .open   = NULL,
        .close  = NULL,
        .read   = logConfRead,
        .write  = logConfWrite,
        .ctrl   = NULL,
    },
    .entry  = logModuleEntry,
    .exit   = logModuleExit,
};



osa_err_t   ATS_LogModuleInit()
{
    // 日志文件没有打开，先关闭日志
    ATS_LogSetLevel(ATS_LOG_OFF);

    ATS_LogDebug("Initialize log module\n");
    
    ATS_ModuleRegister(&logModule);
    
    return OSA_ERR_OK;
}

void    ATS_LogModuleExit()
{
    ATS_LogDebug("Exit log module\n");
    
    ATS_ModuleUnregister(&logModule);
}


osa_err_t   logConfRead(ATS_Conf *cf, void *out_data)
{
    XML_LogModuleRead(cf, out_data);
    return OSA_ERR_OK;
}

osa_err_t   logConfWrite(ATS_Conf *cf, void *data)
{
    
}

osa_err_t   logModuleEntry(ATS_Conf *cf, int argc, char **argv)
{
    ATS_LogDebug("Entry TEST module!\n");
    
    osa_err_t   err;
    CONF_Log   logConf;
    
    ATS_ConfSetModuleConf(cf, &logModule);
    ATS_ConfRead(cf, &logConf);
    

    if (logConf.state == ATS_MODULE_OFF)
    {
        ATS_LogSetLevel(ATS_LOG_OFF);
        return OSA_ERR_OK;
    }
    else
    {
        ATS_LogSetLevel(logConf.level);
        
#if 0
        err = osa_file_open(&log.logFile, logConf.logFile, OSA_FMODE_APPEND);
        if (err != OSA_ERR_OK)
        {
            osa_log_error("Can not open log file!\n");
        }
#endif
        return OSA_ERR_OK;
    }
}

void    logModuleExit(ATS_Conf *cf)
{
    
}


void    ATS_LogSetLevel(osa_uint8_t level)
{
    log.logLevel = level;
}


osa_uint8_t ATS_LogGetLevel()
{
    return log.logLevel;
}


void ATS_Log(osa_uint8_t logType, char *file, osa_uint32_t line, char *fmt, ...)
{
    if (logType > log.logLevel)
    {
        return;
    }
    
    va_list ap;
    va_start(ap, fmt);

    char buf[1024] = {0};
    osa_size_t  sz = 0;
    
    switch (logType)
    {
        case ATS_LOG_FATAL:
        {
            sz += sprintf(buf, "[FATAL] ");
            break;
        }
        case ATS_LOG_ERROR:
        {
            sz += sprintf(buf, "[ERROR] ");
            break;
        }
        case ATS_LOG_WARN:
        {
            sz += sprintf(buf, "[WARN] ");
            break;
        }
        case ATS_LOG_INFO:
        {
            sz += sprintf(buf, "[INFO] ");
            break;
        }
        case ATS_LOG_DEBUG:
        {
            sz += sprintf(buf, "[DEBUG]<%s, %d> ", file, line);
            break;
        }
        default:
        {
        }
    }
    
    sz += vsprintf(buf+sz, fmt, ap);

    buf[1023] = '\0';
    
    printf("%s", buf);

#if 0
    osa_file_write(&log.logFile, buf, sizeof(buf));
#endif
    
    va_end(ap);
}


#ifdef __cplusplus
}
#endif
