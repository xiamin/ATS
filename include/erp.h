/*
 * cat_erp.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef ATS_ERP_H_
#define ATS_ERP_H_

#include "osa.h"

struct _ATS_ERP_INTERFACE
{
    osa_uint8_t     (*init)();              // 初始化ERP
    void            (*exit)();              // 退出ERP
    osa_uint8_t     (*connect)();           // 连接ERP系统
    osa_uint8_t     (*disconnect)();        // 断开ERP系统
};


osa_err_t   ATS_ErpModuleInit();

#endif /* ATS_ERP_H_ */
