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

static CAT_Conf    s_conf = {0};


CAT_Conf   *CAT_ConfInit(const char *file)
{
    OSA_ASSERT(file != NULL);
    
    strncpy(s_conf.file, file, OSA_NAME_MAX-1);
    s_conf.mcf = NULL;
    
    return &s_conf;
}

void    CAT_ConfExit(CAT_Conf *self)
{
    s_conf.mcf = NULL;
}

void    CAT_ConfSetModuleConf(CAT_Conf *self, CAT_Module *m)
{
    self->mcf = &m->cf;
}


osa_err_t   CAT_ConfRead(CAT_Conf *self, void *out_data)
{
    if (self->mcf->read)
    {
        return self->mcf->read(self, out_data);
    }
}


osa_err_t   CAT_ConfWrite(CAT_Conf *self, void *data)
{
    if (self->mcf->write)
    {
        return self->mcf->write(self, data);
    }
}
