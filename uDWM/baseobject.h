#pragma once
#include "framework.h"

class CBaseObject
{
public:
    CBaseObject(class CBaseObject&);
    CBaseObject();
    virtual ~CBaseObject();
    unsigned long AddRef();
    unsigned long Release();
    class CBaseObject& operator=(class CBaseObject&);
    void* __vecDelDtor(unsigned int);
protected:
    long m_cRef;
};