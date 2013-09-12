/*
 * memPool_module.c
 *
 * Copyright (C) TuoAn
 *
 */

#include <stdarg.h>

#include "osa.h"
#include "module.h"
#include "cat.h"
#include "conf_xml.h"
#include "memPool.h"


#ifdef __cplusplus
extern "C" {
#endif


static osa_err_t   memPoolModuleEntry(CAT_Conf *cf, int argc, char **argv);
static void        memPoolModuleExit(CAT_Conf *cf);


 
static CAT_Module  memPoolModule =
{
    .name   = "memPool",
    .state  = CAT_MODULE_ON,
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



osa_err_t   CAT_MemPoolModuleInit()
{
    CAT_LogDebug("Initialize memPool module\n");
    
    CAT_ModuleRegister(&memPoolModule);
    
    return OSA_ERR_OK;
}

void    CAT_MemPoolModuleExit()
{
    CAT_LogDebug("Exit memPool module\n");
    
    CAT_ModuleUnregister(&memPoolModule);
}


osa_err_t   memPoolModuleEntry(CAT_Conf *cf, int argc, char **argv)
{
    CAT_LogDebug("Entry TEST module!\n");
}

void    memPoolModuleExit(CAT_Conf *cf)
{ 
}




#ifdef __cplusplus
}
#endif
