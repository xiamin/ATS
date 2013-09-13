/*
 * test.c
 *
 * Copyright (C) TuoAn
 *
 */

#include "osa.h"
#include "module.h"
#include "cat.h"
#include "conf_xml.h"
#include "log.h"


static osa_err_t   testConfRead(ATS_Conf *cf, void *out_data); 
static osa_err_t   testConfWrite(ATS_Conf *cf, void *data); 
static osa_err_t   testModuleEntry(ATS_Conf *cf, int argc, char **argv);
static void        testModuleExit(ATS_Conf *cf);

 
static ATS_Module  testModule =
{
    .name   = "test",
    .state  = ATS_MODULE_ON,
    .cf     =
    {
        .open   = NULL,
        .close  = NULL,
        .read   = testConfRead,
        .write  = testConfWrite,
        .ctrl   = NULL,
    },
    .entry  = testModuleEntry,
    .exit   = testModuleExit,
};



osa_err_t   ATS_TestModuleInit()
{
    ATS_LogDebug("Initialize test module\n");
    
    ATS_ModuleRegister(&testModule);
    
    return OSA_ERR_OK;
}

void    ATS_TestModuleExit()
{
    ATS_LogDebug("Exit test module\n");
    
    ATS_ModuleUnregister(&testModule);
}




osa_err_t   testConfRead(ATS_Conf *cf, void *out_data)
{
    XML_TestModuleRead(cf, out_data);
    return OSA_ERR_OK;
}

osa_err_t   testConfWrite(ATS_Conf *cf, void *data)
{
    
}

osa_err_t   testModuleEntry(ATS_Conf *cf, int argc, char **argv)
{
    ATS_LogDebug("Entry TEST module!\n");
    
    CONF_Test   testConf;
    
    ATS_ConfSetModuleConf(cf, &testModule);
    ATS_ConfRead(cf, &testConf);
    
    // 如果模块为关闭状态，则不处理
    if (testConf.state == ATS_MODULE_OFF)
    {
        return OSA_ERR_OK;
    }
    else
    {
        return OSA_ERR_OK;
    }
}

void    testModuleExit(ATS_Conf *cf)
{
    
}
