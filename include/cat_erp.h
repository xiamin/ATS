/*
 * cat_erp.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CAT_ERP_H_
#define CAT_ERP_H_

#include "osa.h"

typedef struct _CAT_ERP_INTERFACE
{
    osa_uint8_t     (*init)();              // 初始化ERP
    void            (*exit)();              // 退出ERP
    osa_uint8_t     (*connect)();           // 连接ERP系统
    osa_uint8_t     (*disconnect)();        // 断开ERP系统
}CAT_Erp;



#endif /* CAT_ERP_H_ */
