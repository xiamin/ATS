/*
 * memPool_module.c
 *
 * Copyright (C) TuoAn
 *
 */

#include <stdarg.h>

#include "osa.h"
#include "module.h"
#include "ats.h"
#include "conf_xml.h"
#include "memPool.h"


#ifdef __cplusplus
extern "C" {
#endif


static osa_err_t   memPoolModuleEntry(ATS_Conf *cf, int argc, char **argv);
static void        memPoolModuleExit(ATS_Conf *cf);


 
static ATS_Module  memPoolModule =
{
    .name   = "memPool",
    .state  = ATS_MODULE_ON,
    .cf     =
    {
        .open   = NULL,
        .close  = NULL,
        .read   = NULL,
        .write  = NULL,
        .ctrl   = NULL,
    },
    .entry  = memPoolModuleEntry,
    .exit   = memPoolModuleExit,
};



osa_err_t   ATS_MemPoolModuleInit()
{
    ATS_LogDebug("Initialize memPool module\n");
    
    ATS_ModuleRegister(&memPoolModule);
    
    return OSA_ERR_OK;
}

void    ATS_MemPoolModuleExit()
{
    ATS_LogDebug("Exit memPool module\n");
    
    ATS_ModuleUnregister(&memPoolModule);
}


osa_err_t   memPoolModuleEntry(ATS_Conf *cf, int argc, char **argv)
{
    ATS_LogDebug("Entry TEST module!\n");
}

void    memPoolModuleExit(ATS_Conf *cf)
{ 
}




#ifdef __cplusplus
}
#endif
