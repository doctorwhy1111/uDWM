#include "baseobject.h"


CBaseObject::CBaseObject(CBaseObject&)
{
}

CBaseObject::CBaseObject()
{
}

CBaseObject::~CBaseObject()
{
	// hi
}

ULONG CBaseObject::AddRef()
{
	int result;
	result = this->m_cRef + 1;
	this->m_cRef = result;
	return result;
}

ULONG CBaseObject::Release()
{
	bool v1;
	v1 = this->m_cRef-- == 1;
	m_cRef = this->m_cRef;
	return m_cRef;
}
