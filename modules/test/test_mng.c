/*
 * cat_test.h
 *
 * Copyright (C) TuoAn
 *
 */
 
#include "osa.h"
#include "test.h"
#include "test_xml.h"
#include "log.h"
#include "ats.h"

#include "report.h"


#ifdef __cplusplus
extern "C" {
#endif


// 测试点链表
static osa_list_t   testPointList = {&testPointList, &testPointList};


ATS_TestPoint   *ATS_TestPointFind(const char *name)
{
    OSA_ASSERT(name != NULL);
    
    ATS_TestPoint   *node = NULL;
    
    osa_list_t  *l = NULL;
    
    for (l=testPointList.next; l != &testPointList; l=l->next)
    {
        node = osa_list_entry(l, ATS_TestPoint, list);
        
        // 找到
        if (!strcmp(node->name, name))
        {
            return node;
        }
    }
    
    return NULL;
}


osa_err_t   ATS_TestPointRegister(ATS_TestPoint *self)
{
    if (!self)
    {
        return OSA_ERR_ERR;
    }

    self->report = &g_reportFile;
    
    ATS_TestPoint   *p = NULL;
    
    if ((p = ATS_TestPointFind(self->name)) != NULL)
    {
        ATS_LogWarn("Replace test point : %s\n", self->name);
        
        p = self;
    }
    else
    {
        ATS_LogInfo("Add new test point : %s\n", self->name);
        
        osa_list_insert_after(testPointList.next, &self->list);    
    }

    
    return OSA_ERR_OK;
}


osa_err_t   ATS_TestPointUnregister(ATS_TestPoint *self)
{
    if (!self)
    {
        return OSA_ERR_ERR;
    }
    
    ATS_TestPoint   *p = NULL;
    
    if ((p = ATS_TestPointFind(self->name)) != NULL)
    {
        ATS_LogInfo("Remove test !\n");
        
        osa_list_remove(&p->list);
    }

    return OSA_ERR_OK;
}

osa_err_t   ATS_TestStartAll()
{   
    ATS_TestPoint   *node = NULL;
    
    osa_list_t  *l = NULL;
    
    for (l=testPointList.next; l != &testPointList; l=l->next)
    {
        node = osa_list_entry(l, ATS_TestPoint, list);
        
        if (node->startTest)
        {
            node->result = node->startTest(&node->testCase);

            if (node->result == ATS_TEST_SUCCESS)
            {
                if (node->successFunc)
                {
                    node->successFunc(node);
                }
            }
            else if (node->result == ATS_TEST_FAILED)
            {
                if (node->failedFunc)
                {
                    node->failedFunc(node);
                }
            }
        }
    }
    
    return OSA_ERR_OK;
}


osa_err_t   ATS_TestParseTemplete(const char *file)
{
    if (!file)
    {
        return OSA_ERR_ERR;
    }
    
    ATS_LogInfo("Start parse test templete file !\n");

    XML_ParseAll(file);
    
    return OSA_ERR_OK;
}


ATS_TestPoint   *ATS_TestPointNew(const char *name)
{
    ATS_TestPoint   *p = (ATS_TestPoint *)malloc(sizeof(ATS_TestPoint));
    
    if (!p)
    {
        ATS_LogError("No memory !\n");
        
        return NULL;
    }
    
    memset(p, 0, sizeof(ATS_TestPoint));
    
    strncpy(p->name, name, OSA_NAME_MAX-1);
    
    return p;
}


void    ATS_TestPointDelete(ATS_TestPoint *self)
{
    if (!self)
    {
        return;
    }
    
    free(self);
}

void    ATS_TestReleaseResource()
{
    
}

void    ATS_TestCaseBoxAssociate(ATS_TestCaseBox *self, osa_uint32_t num, osa_uint32_t size, void *priv)
{
    self->caseNum   = num;
    self->caseSize  = size;
    self->privData  = priv;
}



#ifdef __cplusplus
}
#endif
