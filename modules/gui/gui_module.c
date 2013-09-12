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
#include "gui.h"


static osa_err_t   guiConfRead(CAT_Conf *cf, void *out_data); 
static osa_err_t   guiConfWrite(CAT_Conf *cf, void *data); 
static osa_err_t   guiModuleEntry(CAT_Conf *cf, int argc, char **argv);
static void        guiModuleExit(CAT_Conf *cf);
static void        guiStart();
 
static CAT_Module  guiModule =
{
    .name   = "gui",
    .state  = CAT_MODULE_ON,
    .cf     =
    {
        .open   = NULL,
        .close  = NULL,
        .read   = guiConfRead,
        .write  = guiConfWrite,
        .ctrl   = NULL,
    },
    .entry  = guiModuleEntry,
    .exit   = guiModuleExit,
};



osa_err_t   CAT_GuiModuleInit()
{
    CAT_LogDebug("Initialize test module\n");
    
    CAT_ModuleRegister(&guiModule);
    
    return OSA_ERR_OK;
}

void    CAT_GuiModuleExit()
{
    CAT_LogDebug("Exit test module\n");
    
    CAT_ModuleUnregister(&guiModule);
}




static osa_err_t   guiConfRead(CAT_Conf *cf, void *out_data)
{
    XML_GuiModuleRead(cf, out_data);
    return OSA_ERR_OK;
}

static osa_err_t   guiConfWrite(CAT_Conf *cf, void *data)
{
    
}

static osa_err_t   guiModuleEntry(CAT_Conf *cf, int argc, char **argv)
{
    CAT_LogDebug("Enter GUI module!\n");
    
    CONF_Gui   guiConf;
    
    CAT_ConfSetModuleConf(cf, &guiModule);
    CAT_ConfRead(cf, &guiConf);
    
    
    // 如果模块为关闭状态，则不处理
    if (guiConf.state == CAT_MODULE_OFF)
    {
        return OSA_ERR_OK;
    }
    else
    {
        CAT_GuiStart(argc, argv);
        return OSA_ERR_OK;
    }
}

static void    guiModuleExit(CAT_Conf *cf)
{
    
}
