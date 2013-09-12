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
#include "cat.h"

#include "report.h"


#ifdef __cplusplus
extern "C" {
#endif


// 测试点链表
static osa_list_t   testPointList = {&testPointList, &testPointList};


CAT_TestPoint   *CAT_TestPointFind(const char *name)
{
    OSA_ASSERT(name != NULL);
    
    CAT_TestPoint   *node = NULL;
    
    osa_list_t  *l = NULL;
    
    for (l=testPointList.next; l != &testPointList; l=l->next)
    {
        node = osa_list_entry(l, CAT_TestPoint, list);
        
        // 找到
        if (!strcmp(node->name, name))
        {
            return node;
        }
    }
    
    return NULL;
}


osa_err_t   CAT_TestPointRegister(CAT_TestPoint *self)
{
    if (!self)
    {
        return OSA_ERR_ERR;
    }

    self->report = &g_reportFile;
    
    CAT_TestPoint   *p = NULL;
    
    if ((p = CAT_TestPointFind(self->name)) != NULL)
    {
        CAT_LogWarn("Replace test point : %s\n", self->name);
        
        p = self;
    }
    else
    {
        CAT_LogInfo("Add new test point : %s\n", self->name);
        
        osa_list_insert_after(testPointList.next, &self->list);    
    }

    
    return OSA_ERR_OK;
}


osa_err_t   CAT_TestPointUnregister(CAT_TestPoint *self)
{
    if (!self)
    {
        return OSA_ERR_ERR;
    }
    
    CAT_TestPoint   *p = NULL;
    
    if ((p = CAT_TestPointFind(self->name)) != NULL)
    {
        CAT_LogInfo("Remove test !\n");
        
        osa_list_remove(&p->list);
    }

    return OSA_ERR_OK;
}

osa_err_t   CAT_TestStartAll()
{   
    CAT_TestPoint   *node = NULL;
    
    osa_list_t  *l = NULL;
    
    for (l=testPointList.next; l != &testPointList; l=l->next)
    {
        node = osa_list_entry(l, CAT_TestPoint, list);
        
        if (node->startTest)
        {
            node->result = node->startTest(&node->testCase);

            if (node->result == CAT_TEST_SUCCESS)
            {
                if (node->successFunc)
                {
                    node->successFunc(node);
                }
            }
            else if (node->result == CAT_TEST_FAILED)
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


osa_err_t   CAT_TestParseTemplete(const char *file)
{
    if (!file)
    {
        return OSA_ERR_ERR;
    }
    
    CAT_LogInfo("Start parse test templete file !\n");

    XML_ParseAll(file);
    
    return OSA_ERR_OK;
}


CAT_TestPoint   *CAT_TestPointNew(const char *name)
{
    CAT_TestPoint   *p = (CAT_TestPoint *)malloc(sizeof(CAT_TestPoint));
    
    if (!p)
    {
        CAT_LogError("No memory !\n");
        
        return NULL;
    }
    
    memset(p, 0, sizeof(CAT_TestPoint));
    
    strncpy(p->name, name, OSA_NAME_MAX-1);
    
    return p;
}


void    CAT_TestPointDelete(CAT_TestPoint *self)
{
    if (!self)
    {
        return;
    }
    
    free(self);
}

void    CAT_TestReleaseResource()
{
    
}

void    CAT_TestCaseSet(CAT_TestCase *self, osa_uint32_t num, osa_uint32_t size, void *priv)
{
    self->caseNum   = num;
    self->caseSize  = size;
    self->privData  = priv;
}



#ifdef __cplusplus
}
#endif
