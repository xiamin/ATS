/*
 * cat_report.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef ATS_REPORT_H_
#define ATS_REPORT_H_

#include "osa.h"

typedef struct _ATS_REPORT_INTERFACE
{
    void        (*open)(const char *file);
    void        (*close)();
    void        (*write)();
    void        (*read)();
}ATS_Report;


osa_err_t   ATS_ReportModuleInit();
void        ATS_ReportModuleExit();


extern ATS_Report   g_reportFile;

#endif /* ATS_REPORT_H_ */
