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

static osa_err_t   logConfRead(CAT_Conf *cf, void *out_data); 
static osa_err_t   logConfWrite(CAT_Conf *cf, void *data); 
static osa_err_t   logModuleEntry(CAT_Conf *cf, int argc, char **argv);
static void        logModuleExit(CAT_Conf *cf);


 
static CAT_Module  logModule =
{
    .name   = "log",
    .state  = CAT_MODULE_ON,
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



osa_err_t   CAT_LogModuleInit()
{
    CAT_LogSetLevel(CAT_LOG_OFF);

    CAT_LogDebug("Initialize log module\n");
    
    CAT_ModuleRegister(&logModule);
    
    return OSA_ERR_OK;
}

void    CAT_LogModuleExit()
{
    CAT_LogDebug("Exit log module\n");
    
    CAT_ModuleUnregister(&logModule);
}


osa_err_t   logConfRead(CAT_Conf *cf, void *out_data)
{
    XML_LogModuleRead(cf, out_data);
    return OSA_ERR_OK;
}

osa_err_t   logConfWrite(CAT_Conf *cf, void *data)
{
    
}

osa_err_t   logModuleEntry(CAT_Conf *cf, int argc, char **argv)
{
    CAT_LogDebug("Entry TEST module!\n");
    
    osa_err_t   err;
    CONF_Log   logConf;
    
    CAT_ConfSetModuleConf(cf, &logModule);
    CAT_ConfRead(cf, &logConf);
    

    if (logConf.state == CAT_MODULE_OFF)
    {
        CAT_LogSetLevel(CAT_LOG_OFF);
        return OSA_ERR_OK;
    }
    else
    {
        CAT_LogSetLevel(logConf.level);
        
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

void    logModuleExit(CAT_Conf *cf)
{
    
}


void    CAT_LogSetLevel(osa_uint8_t level)
{
    log.logLevel = level;
}


osa_uint8_t CAT_LogGetLevel()
{
    return log.logLevel;
}


void CAT_Log(osa_uint8_t logType, char *file, osa_uint32_t line, char *fmt, ...)
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
        case CAT_LOG_FATAL:
        {
            sz += sprintf(buf, "[FATAL] ");
            break;
        }
        case CAT_LOG_ERROR:
        {
            sz += sprintf(buf, "[ERROR] ");
            break;
        }
        case CAT_LOG_WARN:
        {
            sz += sprintf(buf, "[WARN] ");
            break;
        }
        case CAT_LOG_INFO:
        {
            sz += sprintf(buf, "[INFO] ");
            break;
        }
        case CAT_LOG_DEBUG:
        {
            sz += sprintf(buf, "[DEBUG]<%s, %s> ", file, line);
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
