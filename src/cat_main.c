/*
 * cat_main.c
 *
 * Copyright (C) TuoAn
 *
 */


#include "osa.h"
#include "conf.h"
#include "conf_data.h"
#include "module.h"
#include "cat.h"

#include "test.h"
#include "report.h"
#include "erp.h"
#include "gui.h"
#include "log.h"

CAT_Conf  *g_conf;

int main(int argc, char **argv)
{   
    g_conf = CAT_ConfInit(CAT_CONFIG_FILE);
    
    //  初始化日志模块
    CAT_LogModuleInit();
    
    //  初始化内存池模块
    CAT_MemPoolModuleInit();
    
    // 初始化测试模块
    CAT_TestModuleInit();
    
    // 初始化报告模块
    CAT_ReportModuleInit();
    
    // 初始化GUI模块
    CAT_GuiModuleInit();
    
    // 初始化ERP模块
    //CAT_ErpModuleInit();
    
    
    CAT_ModuleInitAll(argc, argv);
    
    CAT_ConfExit(g_conf);
}
