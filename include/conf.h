/*
 * conf.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CONF_H_
#define CONF_H_

#include "osa.h"

//模块关闭
#define CAT_MODULE_OFF      0x00
// 模块打开
#define CAT_MODULE_ON       0x01

typedef osa_err_t   (*parseFunc)();
typedef struct _CAT_MODULE_CONF
{
    char            name[OSA_NAME_MAX];         // 模块名字
    osa_uint8_t     flags;                      // 标志：ON / OFF
    parseFunc       parse;                      // 解析函数
}
CAT_ModuleConf;

typedef struct _CAT_CONF
{
    osa_fd_t        fd;                 // 打开的配置文件描述符
    CAT_ModuleConf  test_module;        // 测试模块配置
    CAT_ModuleConf  report_module;      // 报告模块配置
    CAT_ModuleConf  erp_module;         // erp模块配置
    CAT_ModuleConf  gui_module;         // gui模块配置
}
CAT_Conf;


osa_err_t       CAT_ConfInit(CAT_Conf *self, const char *file);
void            CAT_ConfExit(CAT_Conf *self);

// 设置模块的解析函数
void            CAT_ConfSetModuleParseFunc(CAT_ModuleConf *self, parseFunc parse);

// 解析配置文件
osa_err_t       CAT_ConfParse(CAT_Conf *self);

#endif /* CONF_H_ */
