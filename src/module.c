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
ATS_Module  *mBox[ATS_MODULE_MAX] = {NULL};


ATS_Module *ATS_ModuleFind(const char *name)
{
    OSA_ASSERT(name != NULL);
    
    ATS_Module  *m = NULL;
    osa_uint32_t    i;
    
    for (i=0; i<ATS_MODULE_MAX; i++)
    {
        if (mBox[i] && !strcmp(mBox[i]->name, name))
        {
            m = mBox[i];
            break;
        }
    }
    
    if (i == ATS_MODULE_MAX)
    {
        ATS_LogWarn("No module found : %s\n", name);
    }
    
    return m;
}


osa_err_t ATS_ModuleRegister(ATS_Module *module)
{
    ATS_Module  *p = NULL;
    osa_err_t   err;
    
    ATS_LogInfo("Register module: %s\n", module->name);
    
    if ((p = ATS_ModuleFind(module->name)) != NULL)
    {
        ATS_LogInfo("Replace module: %s\n", module->name);
        
        p = module;
        
        err = OSA_ERR_OK;
    }
    else
    {
        osa_uint32_t    i;
        
        for (i=0; i<ATS_MODULE_MAX; i++)
        {
            if (!mBox[i])
            {
                mBox[i] = module;
                err = OSA_ERR_OK;
                break;
            }
        }
        
        if (i == ATS_MODULE_MAX)
        {
            ATS_LogError("No space !\n");
            err = OSA_ERR_ERR;
        }
    }
    
    return err;
}


osa_err_t ATS_ModuleUnregister(ATS_Module *module)
{
    ATS_Module  *p = NULL;
    
    ATS_LogInfo("Unregister module : %s\n", module->name);
    
    if ((p = ATS_ModuleFind(module->name)) != NULL)
    {
        p = NULL;
    }
    
    return OSA_ERR_OK;
}


void    ATS_ModuleInitAll(int argc, char **argv)
{
    osa_uint32_t i;
    osa_err_t   err;
    
    for (i=0; i<ATS_MODULE_MAX; i++)
    {
        if (mBox[i] && mBox[i]->entry)
        {
            ATS_LogInfo("Initialize module: %s\n", mBox[i]->name);
  
            err = mBox[i]->entry(g_conf, argc, argv);
            if (err != OSA_ERR_OK)
            {
                ATS_LogError("Failed to initialize module : %s\n", mBox[i]->name);
            }
        }
    }
}