/*
 * module.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef MODULE_H_
#define MODULE_H_

#include "osa.h"
#include "cat.h"

#ifdef __cplusplus
extern "C" {
#endif

enum
{
    CAT_MODULE_OFF = 0,
    CAT_MODULE_ON = 1,
};


struct _CAT_MODULE_CONF
{
    CAT_Conf    *(*open)(const char *file);                            // 打开模块配置文件
    void        (*close)(CAT_Conf *cf);                         // 关闭模块配置文件
    osa_err_t   (*read)(CAT_Conf *cf, void *out_data);          // 读取配置文件
    osa_err_t   (*write)(CAT_Conf *cf, void *data);             // 写配置文件
    osa_err_t   (*ctrl)(CAT_Conf *cf, osa_uint32_t cmd, void *arg);     // 控制
};



struct _CAT_MODULE
{
    char            name[OSA_NAME_MAX];                 // 模块名字
    osa_uint8_t     state;                              // 模块状态，ON或者OFF
    CAT_ModuleConf  cf;                                 // 模块配置文件
    
    osa_err_t       (*entry)(CAT_Conf *conf, int argc, char **argv);     // 模块入口
    void            (*exit)(CAT_Conf *conf);      // 模块出口
};

#define CAT_MODULE_MAX      10

CAT_Module      *CAT_ModuleFind(const char *name);
osa_err_t       CAT_ModuleRegister(CAT_Module *module);
osa_err_t       CAT_ModuleUnregister(CAT_Module *module);

void            CAT_ModuleInitAll(int argc, char **argv);

#ifdef __cplusplus
}
#endif

#endif /* MODULE_H_ */
