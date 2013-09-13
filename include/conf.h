/*
 * conf.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CONF_H_
#define CONF_H_

#include "osa.h"
#include "ats.h"


struct _ATS_CONF
{
    char            file[OSA_NAME_MAX];      // 配置文件名
    ATS_ModuleConf  *mcf;                   // 模块配置 
};


ATS_Conf   *ATS_ConfInit(const char *file);
void        ATS_ConfExit(ATS_Conf *self);

void        ATS_ConfSetModuleConf(ATS_Conf *self, ATS_Module *m);

osa_err_t   ATS_ConfRead(ATS_Conf *self, void *out_data);
osa_err_t   ATS_ConfWrite(ATS_Conf *self, void *data);

#endif /* CONF_H_ */
