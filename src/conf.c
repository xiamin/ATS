/*
 * conf.c
 *
 * Copyright (C) TuoAn
 *
 */


#include "osa.h"
#include "conf.h"
#include "conf_data.h"
#include "module.h"

static ATS_Conf    s_conf = {0};


ATS_Conf   *ATS_ConfInit(const char *file)
{
    OSA_ASSERT(file != NULL);
    
    strncpy(s_conf.file, file, OSA_NAME_MAX-1);
    s_conf.mcf = NULL;
    
    return &s_conf;
}

void    ATS_ConfExit(ATS_Conf *self)
{
    s_conf.mcf = NULL;
}

void    ATS_ConfSetModuleConf(ATS_Conf *self, ATS_Module *m)
{
    self->mcf = &m->cf;
}


osa_err_t   ATS_ConfRead(ATS_Conf *self, void *out_data)
{
    if (self->mcf->read)
    {
        return self->mcf->read(self, out_data);
    }
}


osa_err_t   ATS_ConfWrite(ATS_Conf *self, void *data)
{
    if (self->mcf->write)
    {
        return self->mcf->write(self, data);
    }
}
