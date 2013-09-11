/*
 * module.c
 *
 * Copyright (C) TuoAn
 *
 */

 
#include "osa.h"
#include "module.h"
#include "log.h"

// 模块容器
CAT_Module  *mBox[CAT_MODULE_MAX] = {NULL};


CAT_Module *CAT_ModuleFind(const char *name)
{
    OSA_ASSERT(name != NULL);
    
    CAT_Module  *m = NULL;
    osa_uint32_t    i;
    
    for (i=0; i<CAT_MODULE_MAX; i++)
    {
        if (mBox[i] && !strcmp(mBox[i]->name, name))
        {
            m = mBox[i];
            break;
        }
    }
    
    if (i == CAT_MODULE_MAX)
    {
        CAT_LogWarn("No module found : %s\n", name);
    }
    
    return m;
}


osa_err_t CAT_ModuleRegister(CAT_Module *module)
{
    CAT_Module  *p = NULL;
    osa_err_t   err;
    
    CAT_LogInfo("Register module: %s\n", module->name);
    
    if ((p = CAT_ModuleFind(module->name)) != NULL)
    {
        CAT_LogInfo("Replace module: %s\n", module->name);
        
        p = module;
        
        err = OSA_ERR_OK;
    }
    else
    {
        osa_uint32_t    i;
        
        for (i=0; i<CAT_MODULE_MAX; i++)
        {
            if (!mBox[i])
            {
                mBox[i] = module;
                err = OSA_ERR_OK;
                break;
            }
        }
        
        if (i == CAT_MODULE_MAX)
        {
            CAT_LogError("No space !\n");
            err = OSA_ERR_ERR;
        }
    }
    
    return err;
}


osa_err_t CAT_ModuleUnregister(CAT_Module *module)
{
    CAT_Module  *p = NULL;
    
    CAT_LogInfo("Unregister module : %s\n", module->name);
    
    if ((p = CAT_ModuleFind(module->name)) != NULL)
    {
        p = NULL;
    }
    
    return OSA_ERR_OK;
}


void    CAT_ModuleInitAll(int argc, char **argv)
{
    osa_uint32_t i;
    osa_err_t   err;
    
    for (i=0; i<CAT_MODULE_MAX; i++)
    {
        if (mBox[i] && mBox[i]->entry)
        {
            CAT_LogInfo("Initialize module: %s\n", mBox[i]->name);
  
            err = mBox[i]->entry(g_conf, argc, argv);
            if (err != OSA_ERR_OK)
            {
                CAT_LogError("Failed to initialize module : %s\n", mBox[i]->name);
            }
        }
    }
}