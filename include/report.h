/*
 * cat_report.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CAT_REPORT_H_
#define CAT_REPORT_H_

#include "osa.h"

typedef struct _CAT_REPORT_INTERFACE
{
    void        (*open)(const char *file);
    void        (*close)();
    void        (*write)();
    void        (*read)();
}CAT_Report;


osa_err_t   CAT_ReportModuleInit();
void        CAT_ReportModuleExit();


extern CAT_Report   g_reportFile;

#endif /* CAT_REPORT_H_ */
