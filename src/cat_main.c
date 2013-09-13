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

ATS_Conf  *g_conf;

int main(int argc, char **argv)
{   
    g_conf = ATS_ConfInit(ATS_CONFIG_FILE);
    
    //  初始化日志模块
    ATS_LogModuleInit();
    
    //  初始化内存池模块
    //ATS_MemPoolModuleInit();
    
    // 初始化测试模块
    ATS_TestModuleInit();
    
    // 初始化报告模块
    ATS_ReportModuleInit();
    
    // 初始化GUI模块
    ATS_GuiModuleInit();
    
    // 初始化ERP模块
    //ATS_ErpModuleInit();
    
    
    ATS_ModuleInitAll(argc, argv);

    ATS_TestStartAll();
    
    ATS_ConfExit(g_conf);
}
