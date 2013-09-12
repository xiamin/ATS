/*
 * cat_test.h
 *
 * Copyright (C) TuoAn
 *
 */
 
#include "test_xml.h"
#include "test_data.h"
#include "log.h"
#include "test.h"

#include "tinyxml.h"

#ifdef __cplusplus
extern "C" {
#endif



// 解析云台配置
static osa_err_t   _ParsePtz(TiXmlDocument *xmlDoc);

// 解析网络配置
static osa_err_t   _ParseNetwork(TEST_Network *out_network);




void    *XML_LoadFile(const char *file)
{
    TiXmlDocument   *doc = new TiXmlDocument(file);
    
    bool ret = doc->LoadFile();
    if (ret != true)
    {
        CAT_LogError("Failed to load XML file: %s\n", file);
        
        return NULL;
    }
    
    _ParsePtz(doc);
    
    
    return (void *)doc;
}


osa_err_t   XML_ParseAll(void *xmlDoc)
{
    osa_err_t   err;
    
    TiXmlDocument   *doc = (TiXmlDocument *)xmlDoc;
    
    if (!doc)
    {
        return OSA_ERR_ERR;
    }
    

}


void    *XML_GetTestPointRoot(void *xmlRoot, char *name)
{
    TiXmlElement    *tmp = ((TiXmlElement *)xmlRoot)->FirstChildElement("test_point");
    TiXmlAttribute  *attr = NULL;
    while (tmp)
    {
        attr = tmp->FirstAttribute();
        if (!strcmp(attr->Value(), name))
        {
            return tmp;
        }
        tmp = tmp->NextSiblingElement("module");
    }

    return NULL;
}

static osa_err_t   _ParsePtz(TiXmlDocument *xmlDoc)
{
    TEST_Ptz    *ptz = malloc(sizeof(TEST_Ptz));
    if (!ptz)
    {
        goto noMem;
    }
    
    TiXmlElement    *root = xmlDoc->RootElement();
    if (!root)
    {
        goto xmlErr;
    }
    
    TiXmlElement    *ptzRoot = XML_GetTestPointRoot(root, PTZ_NODE_NAME);
    
    
    if (err == OSA_ERR_OK)
    {
        CAT_TestPoint   *newTest = CAT_TestPointNew(PTZ_NODE_NAME);
        
        if (!newTest)
        {
            goto noMem;
        }
        
        newTest->param  = ptz;
        newTest->result = CAT_TEST_FAILED;
        newTest->start  = _PtzTestEntry;
    }
    
    
xmlErr:
    
    return OSA_ERR_ERR;
noMem:
    CAT_LogError("No memory!\n");
    return OSA_ERR_ERR;;

err:
    CAT_LogError("Error!\n");
    return OSA_ERR_ERR;
}


#ifdef __cplusplus
}
#endif