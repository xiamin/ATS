/*
 * conf.c
 *
 * Copyright (C) TuoAn
 *
 */


#include "osa.h"
#include "conf.h"
#include "conf_cmd.h"

CAT_Conf    conf;


CAT_ModuleConf *CAT_ModuleConfFind(const char *name)
{
    OSA_ASSERT(name != OSA_NULL);
    
    CAT_ModuleConf    *p = NULL;
    osa_uint32_t     i;
    
    for (i=0; i<CAT_MODULE_MAX; i++)
    {
        // 找到了
        if (!strcmp(conf.mc[i]->name, name))
        {
            p = conf.mc[i];
            break;
        }
    }

    return p;
}

osa_err_t   CAT_ModuleConfRegister(CAT_ModuleConf *cmf)
{
    CAT_ModuleConf  *p = NULL;
    
    // 如果找到模块，则替换，否则新建
    if ((p = CAT_ModuleConfFind(cmf->name)) != NULL)
    {
        CAT_LogInfo("Replace module: %s\n", cmf->name);
        p = cmf;
        
        return OSA_ERR_OK;
    }
    else
    {
        CAT_LogInfo("New module :%s\n", cmf->name);
        
        osa_uint32_t    i;
        
        for (i=0; i<CAT_MODULE_MAX; i++)
        {
            // 找到空位
            if (!conf.mc[i])
            {
                conf.mc[i] = cmf;
                break;
            }
        }
        
        if (i == CAT_MODULE_MAX)
        {
            CAT_LogInfo("No module space :%s\n", cmf->name);
            
            return OSA_ERR_ERR;
        }
        
        return OSA_ERR_OK;
    }
}


void    CAT_ModuleConfUnregister(CAT_ModuleConf *cmf)
{
    CAT_ModuleConf  *p = NULL;
    
    if ((p = CAT_ModuleConfFind(cmf->name) != NULL)
    {
        *p = NULL;
    }
}


osa_err_t   CAT_ConfOpen(CAT_Conf *self, const char *file)
{
    OSA_ASSERT(file != OSA_NULL);

    osa_err_t   err;

    err = osa_file_open(&self->file, file, OSA_FMODE_RDWR);
    if (err != OSA_ERR_OK)
    {
        CAT_LogError("Failed to open configuration file : %s\n", file);
        return OSA_ERR_ERR;
    }

    return OSA_ERR_OK;
}


void    CAT_ConfClose(CAT_Conf *self)
{
    osa_file_close(&self->file);
}


osa_err_t   CAT_ConfGet(CAT_Conf *self, osa_uint32_t cmd, void *out_data)
{
    CAT_ModuleConf  *p = NULL;
    
    if (cmd >= CMD_TEST_MIN && cmd <CMD_TEST_MAX)
    {
        p = CAT_ModuleConfFind(TEST_MODULE_NAME);
    }
    else if (cmd >= CMD_REPORT_MIN && cmd < CMD_REPORT_MAX)
    {
        p = CAT_ModuleConfFind(REPORT_MODULE_NAME);
    }
    else if (cmd >= CMD_ERP_MIN && cmd < CMD_ERP_MAX)
    {
        p = CAT_ModuleConfFind(ERP_MODULE_NAME);
    }
    else if (cmd >= CMD_GUI_MIN && cmd < CMD_GUI_MAX)
    {
        p = CAT_ModuleConfFind(GUI_MODULE_NAME);
    }
    else
    {
        CAT_LogError("Unknown command : %d\n", cmd);
        
        return OSA_ERR_ERR;
    }
    
    return p->get(self, cmd, out_data);
}


osa_err_t   CAT_ConfSet(CAT_Conf *self, osa_uint32_t cmd, void *data)
{
    CAT_ModuleConf  *p = NULL;
    
    if (cmd >= CMD_TEST_MIN && cmd <CMD_TEST_MAX)
    {
        p = CAT_ModuleConfFind(TEST_MODULE_NAME);
    }
    else if (cmd >= CMD_REPORT_MIN && cmd < CMD_REPORT_MAX)
    {
        p = CAT_ModuleConfFind(REPORT_MODULE_NAME);
    }
    else if (cmd >= CMD_ERP_MIN && cmd < CMD_ERP_MAX)
    {
        p = CAT_ModuleConfFind(ERP_MODULE_NAME);
    }
    else if (cmd >= CMD_GUI_MIN && cmd < CMD_GUI_MAX)
    {
        p = CAT_ModuleConfFind(GUI_MODULE_NAME);
    }
    else
    {
        CAT_LogError("Unknown command : %d\n", cmd);
        
        return OSA_ERR_ERR;
    }
    
    return p->set(self, cmd, data);
}
