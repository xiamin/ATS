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
    
    CONF_Log   logConf;
    
    CAT_ConfSetModuleConf(cf, &logModule);
    CAT_ConfRead(cf, &logConf);
    
    // 如果模块为关闭状态，则不处理
    if (logConf.state == CAT_MODULE_OFF)
    {
        return OSA_ERR_OK;
    }
    else
    {
        return OSA_ERR_OK;
    }
}

void    logModuleExit(CAT_Conf *cf)
{
    
}

void CAT_Log(osa_uint8_t logType, char *file, osa_uint32_t line, char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    
    char buf[1024] = {0};
    osa_size_t  sz = 0;
    
    switch (logType)
    {
        case CAT_LOG_FATAL:
        {
            sz += sprintf(buf, "[FATAL]");
            break;
        }
        case CAT_LOG_ERROR:
        {
            sz += sprintf(buf, "[ERROR]");
            break;
        }
        case CAT_LOG_WARN:
        {
            sz += sprintf(buf, "[WARN]");
            break;
        }
        case CAT_LOG_INFO:
        {
            sz += sprintf(buf, "[INFO]");
            break;
        }
        case CAT_LOG_DEBUG:
        {
            sz += sprintf(buf, "[DEBUG]");
            break;
        }
        default:
        {
        }
    }
    
    sz += sprintf(buf+sz, "<%s,%d>", file, line);
    
    sz += vsprintf(buf+sz, fmt, ap);
    
    printf("%s", buf);
    
    va_end(ap);
}
