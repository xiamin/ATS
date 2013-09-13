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


static osa_err_t   guiConfRead(ATS_Conf *cf, void *out_data); 
static osa_err_t   guiConfWrite(ATS_Conf *cf, void *data); 
static osa_err_t   guiModuleEntry(ATS_Conf *cf, int argc, char **argv);
static void        guiModuleExit(ATS_Conf *cf);
static void        guiStart();
 
static ATS_Module  guiModule =
{
    .name   = "gui",
    .state  = ATS_MODULE_ON,
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



osa_err_t   ATS_GuiModuleInit()
{
    ATS_LogDebug("Initialize test module\n");
    
    ATS_ModuleRegister(&guiModule);
    
    return OSA_ERR_OK;
}

void    ATS_GuiModuleExit()
{
    ATS_LogDebug("Exit test module\n");
    
    ATS_ModuleUnregister(&guiModule);
}




static osa_err_t   guiConfRead(ATS_Conf *cf, void *out_data)
{
    XML_GuiModuleRead(cf, out_data);
    return OSA_ERR_OK;
}

static osa_err_t   guiConfWrite(ATS_Conf *cf, void *data)
{
    
}

static osa_err_t   guiModuleEntry(ATS_Conf *cf, int argc, char **argv)
{
    ATS_LogDebug("Enter GUI module!\n");
    
    CONF_Gui   guiConf;
    
    ATS_ConfSetModuleConf(cf, &guiModule);
    ATS_ConfRead(cf, &guiConf);
    
    
    // 如果模块为关闭状态，则不处理
    if (guiConf.state == ATS_MODULE_OFF)
    {
        return OSA_ERR_OK;
    }
    else
    {
        ATS_GuiStart(argc, argv);
        return OSA_ERR_OK;
    }
}

static void    guiModuleExit(ATS_Conf *cf)
{
    
}
