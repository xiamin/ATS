/*
 * conf.c
 *
 * Copyright (C) TuoAn
 *
 */


#include "osa.h"
#include "conf.h"

osa_err_t       CAT_ConfInit(CAT_Conf *self, const char *file)
{
    OSA_ASSERT(file != OSA_NULL);

    osa_file_t  f;
    osa_err_t   err;

    err = osa_file_open(&f, file, OSA_FMODE_RDWR);
	if (err != OSA_ERR_OK)
	{
	    CAT_LogError("Failed to open file: %s", file);
		return OSA_ERR_ERR;
	}

	self->fd =
}

void            CAT_ConfExit(CAT_Conf *self);

// 设置模块的解析函数
void            CAT_ConfSetModuleParseFunc(CAT_ModuleConf *self, parseFunc parse);

// 解析配置文件
osa_err_t       CAT_ConfParse(CAT_Conf *self);
