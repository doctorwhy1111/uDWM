#include "button.h"
#include "visual.h"

HRESULT CButton::Create(const MIL_CHANNEL__*, CButton**)
{
	return E_NOTIMPL;
}

void CButton::SetEnabled(bool)
{
}

void CButton::OnMouseEnter()
{
	CVisual::SetDirtyFlags(32768, m_dwDirtyFlags);
}

