#pragma once
#include "framework.h"
#include "baseobject.h"
#include "pch.h"

class MilStretch
{

};
class CBitmapSource : public CBaseObject
{
    struct _MARGINS
    {
        int cxLeftWidth;
        int cxRightWidth;
        int cyTopHeight;
        int cyBottomHeight;
    };
    enum MilStretch::Enum
    {
        None = 0,
        Fill = 1,
        Uniform = 2,
        UniformToFill = 3,
        FORCE_DWORD = -1
    };
public:
    HRESULT Create(const struct MIL_CHANNEL__*, wchar_t*, class CBitmapSource**);
    HRESULT Create(UINT, UINT, UINT, UINT, void*, const struct MIL_CHANNEL__*, class CBitmapSource**);
    HRESULT Create(class CBitmapSource*, struct tagRECT&, struct _MARGINS*, class CBitmapSource**);
    HRESULT Create(void*, unsigned long, const struct MIL_CHANNEL__*, class CBitmapSource**);
    HRESULT Create(struct IWICBitmap*, struct _MARGINS*, const struct MIL_CHANNEL__*, class CBitmapSource**);
    HRESULT Create(struct HICON__*, const struct MIL_CHANNEL__*, class CBitmapSource**);
    HRESULT Create(struct HINSTANCE__*, void*, const int, const struct MIL_CHANNEL__*, class CBitmapSource**);
    HRESULT Create(const struct MIL_CHANNEL__*, class CBitmapSource**);
    UINT GetWidth();
    UINT GetHeight();
    struct tagSIZE& GetSize();
    struct tagRECT& GetSourceClip();
    bool HasSourceClip();
    void SetOverdrawMargins(struct _MARGINS&);
    struct _MARGINS& GetOverdrawMargins();
    void SetSizingMargins(struct _MARGINS&);
    struct _MARGINS& GetSizingMargins();
    void SetContentMargins(struct _MARGINS&);
    struct _MARGINS& GetContentMargins();
    class CResource* GetResource();
    HRESULT GetDrawNineGridInstruction(class CDrawNineGridInstruction**);
    HRESULT CreateOrUpdateImageBrush(class CResource**, class CResource**, class CResource**, enum MilStretch::Enum);
    struct IWICBitmap* GetWICBitmap();

protected:
    void* operator new(unsigned int, void*);
    void* operator new(unsigned int);
    void* operator new[](unsigned int);
    void operator delete(void*);
    void operator delete[](void*);
private:
    CBitmapSource(class CBitmapSource&);
    CBitmapSource();
    virtual ~CBitmapSource();
    int operator=(class CBitmapSource&);
    HRESULT Initialize(const struct MIL_CHANNEL__*);
    HRESULT Update(unsigned int, unsigned int, void*);
    HRESULT Update(struct IWICBitmap*);
    HRESULT Update(struct HICON__*);
    HRESULT EnsureNineGridInstruction();
    class CResource* m_prBitmapSource;
    struct tagSIZE m_naturalSize;
    struct _MARGINS m_smSizingMargins;
    struct _MARGINS m_smOverdraw;
    struct _MARGINS m_contentMargins;
    struct tagRECT m_rcSourceClip;
    struct IWICBitmap* m_pIWICBitmap;
protected:
    void* __vecDelDtor(unsigned int);
};