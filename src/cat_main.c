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
    
    CAT_TestModuleInit();
    CAT_GuiModuleInit();
    CAT_ReportModuleInit();
    CAT_LogModuleInit();
    //CAT_ErpModuleInit();
    //CAT_GuiModuleInit();
    
    CAT_ModuleInitAll(argc, argv);
    
    CAT_ConfExit(g_conf);
}