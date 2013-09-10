/*
 * test.c
 *
 * Copyright (C) TuoAn
 *
 */

#include "osa.h"
#include "module.h"
#include "cat.h"
#include "xml.h"
#include "log.h"


static osa_err_t   testConfRead(CAT_Conf *cf, void *out_data); 
static osa_err_t   testConfWrite(CAT_Conf *cf, void *data); 
static osa_err_t   testModuleEntry(CAT_Conf *cf, int argc, char **argv);
static void        testModuleExit(CAT_Conf *cf);

 
static CAT_Module  testModule =
{
    .name   = "test",
    .state  = CAT_MODULE_ON,
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



osa_err_t   CAT_TestModuleInit()
{
    CAT_LogDebug("Initialize test module\n");
    
    CAT_ModuleRegister(&testModule);
    
    return OSA_ERR_OK;
}

void    CAT_TestModuleExit()
{
    CAT_LogDebug("Exit test module\n");
    
    CAT_ModuleUnregister(&testModule);
}




osa_err_t   testConfRead(CAT_Conf *cf, void *out_data)
{
    XML_TestModuleRead(cf, out_data);
    return OSA_ERR_OK;
}

osa_err_t   testConfWrite(CAT_Conf *cf, void *data)
{
    
}

osa_err_t   testModuleEntry(CAT_Conf *cf, int argc, char **argv)
{
    CAT_LogDebug("Entry TEST module!\n");
    
    CONF_Test   testConf;
    
    CAT_ConfSetModuleConf(cf, &testModule);
    CAT_ConfRead(cf, &testConf);
    
    // 如果模块为关闭状态，则不处理
    if (testConf.state == CAT_MODULE_OFF)
    {
        return OSA_ERR_OK;
    }
    else
    {
        return OSA_ERR_OK;
    }
}

void    testModuleExit(CAT_Conf *cf)
{
    
}
