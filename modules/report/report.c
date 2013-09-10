/*
 * report.c
 *
 * Copyright (C) TuoAn
 *
 */

#include "osa.h"
#include "module.h"
#include "cat.h"
#include "conf_xml.h"
#include "log.h"
#include "report.h"

static osa_err_t   reportConfRead(CAT_Conf *cf, void *out_data); 
static osa_err_t   reportConfWrite(CAT_Conf *cf, void *data); 
static osa_err_t   reportModuleEntry(CAT_Conf *cf, int argc, char **argv);
static void        reportModuleExit(CAT_Conf *cf);

 
static CAT_Module  reportModule =
{
    .name   = "report",
    .state  = CAT_MODULE_ON,
    .cf     =
    {
        .open   = NULL,
        .close  = NULL,
        .read   = reportConfRead,
        .write  = reportConfWrite,
        .ctrl   = NULL,
    },
    .entry  = reportModuleEntry,
    .exit   = reportModuleExit,
};



osa_err_t   CAT_ReportModuleInit()
{
    CAT_LogDebug("Initialize report module\n");
    
    CAT_ModuleRegister(&reportModule);
    
    return OSA_ERR_OK;
}

void        CAT_ReportModuleExit()
{
    CAT_LogDebug("Exit report module\n");
    
    CAT_ModuleUnregister(&reportModule);
}




osa_err_t   reportConfRead(CAT_Conf *cf, void *out_data)
{
    XML_ReportModuleRead(cf, out_data);
    return OSA_ERR_OK;
}

osa_err_t   reportConfWrite(CAT_Conf *cf, void *data)
{
    
}

osa_err_t   reportModuleEntry(CAT_Conf *cf, int argc, char **argv)
{
    CAT_LogDebug("Entry TEST module!\n");
    
    CONF_Test   reportConf;
    
    CAT_ConfSetModuleConf(cf, &reportModule);
    CAT_ConfRead(cf, &reportConf);
    
    // 如果模块为关闭状态，则不处理
    if (reportConf.state == CAT_MODULE_OFF)
    {
        return OSA_ERR_OK;
    }
    else
    {
        return OSA_ERR_OK;
    }
}

void    reportModuleExit(CAT_Conf *cf)
{
    
}
