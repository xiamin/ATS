/*
 * conf.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CONF_H_
#define CONF_H_

#include "osa.h"
#include "cat.h"


struct _CAT_CONF
{
    char            file[OSA_NAME_MAX];      // 配置文件名
    CAT_ModuleConf  *mcf;                   // 模块配置 
};


CAT_Conf   *CAT_ConfInit(const char *file);
void        CAT_ConfExit(CAT_Conf *self);

void        CAT_ConfSetModuleConf(CAT_Conf *self, CAT_Module *m);

osa_err_t   CAT_ConfRead(CAT_Conf *self, void *out_data);
osa_err_t   CAT_ConfWrite(CAT_Conf *self, void *data);

#endif /* CONF_H_ */
