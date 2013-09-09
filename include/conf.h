/*
 * conf.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CONF_H_
#define CONF_H_

#include "osa.h"

typedef enum
{
    CAT_MODULE_ON,
    CAT_MODULE_OFF,
}CAT_ModuleState;

typedef struct
{
    char            name[OSA_NAME_MAX];         // 模块名字
    CAT_ModuleState	state;                      // 标志：ON / OFF
    osa_err_t       (*get)(CAT_Conf *cf, osa_uint32_t cmd, void *out_data);     // 获取信息函数
    osa_err_t       (*set)(CAT_Conf *cf, osa_uint32_t cmd, void *data);         // 设置信息函数
}
CAT_ModuleConf;

CAT_ModuleConf	*CAT_ModuleConfFind(const char *name);
osa_err_t		CAT_ModuleConfRegister(CAT_ModuleConf *cmf);
void			CAT_ModuleConfUnregister(CAT_ModuleConf *cmf);



#define     CAT_MODULE_MAX   10

typedef struct _CAT_CONF
{
    char            file[OSA_NAME_MAX]      // 配置文件
    CAT_ModuleConf  *mc[CAT_MODULE_MAX];    // 模块配置信息
}
CAT_Conf;


// 配置文件接口
osa_err_t       CAT_ConfOpen(CAT_Conf *self, const char *file);
void            CAT_ConfClose(CAT_Conf *self);
osa_err_t       CAT_ConfParse(CAT_Conf *self);
osa_err_t       CAT_ConfGet(CAT_Conf *self, osa_uint32_t cmd, void *out_data);
osa_err_t       CAT_ConfSet(CAT_Conf *self, osa_uint32_t cmd, void *data);


#endif /* CONF_H_ */
