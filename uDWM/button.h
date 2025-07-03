#pragma once
#include "framework.h"

class CBitmapSourceArray
{

};
class CCanvas
{

};
class CMesh2DVisual : public CCanvas
{
    public HRESULT Create(const struct MIL_CHANNEL__*, class CMesh2DVisual**);
    protected void* operator new(unsigned int, void*);
    protected void* operator new(unsigned int);
    protected void* operator new[](unsigned int);
    protected void operator delete(void*);
    protected void operator delete[](void*);
    private void CMesh2DVisual(class CMesh2DVisual&);
    protected void CMesh2DVisual();
    protected void ~CMesh2DVisual();
    protected HRESULT Initialize(const struct MIL_CHANNEL__*);
    private int operator=(class CMesh2DVisual&);
    public HRESULT InsertAfterMeshImage(class CMeshImage*, class CMeshImage*);
    public HRESULT AddMeshImage(class CMeshImage*);
    public void RemoveMeshImage(class CMeshImage*);
    public void RemoveAllMeshImages();
    public HRESULT ValidateVisualPostSubgraph();
    public HRESULT UpdateLayout();
    public void UpdateMeshLayout();
    public HRESULT UpdateMesh();
    public HRESULT AddDrawMesh2DInstruction(class CResource*, class CResource*);
    public HRESULT SetClipMargins(struct _MARGINS*);
    public HRESULT CloneVisualTree(class CVisual**);
    public HRESULT InsertMeshImageAtIndex(class CMeshImage*, unsigned int);
    public const unsigned long DF_MESHLAYOUT;
    public const unsigned long DF_MESH;
    private class DynArray<CMeshImage*, 0> m_rgpMeshImages;
    private struct _MARGINS* m_pmarClip;
    public void __local_vftable_ctor_closure();
    protected void* __vecDelDtor(unsigned int);
};
class CButton : public CMesh2DVisual
{
    enum ButtonStates
    {
        Normal = 0,
        Hover = 1,
        Pressed = 2,
        Disabled = 3,
        ButtonStateLast = 4
    };
public:
    HRESULT Create(const struct MIL_CHANNEL__*, class CButton**);
    HRESULT ValidateVisual();
    HRESULT UpdateLayout();
    HRESULT SetVisualStates(class CBitmapSourceArray&, class CBitmapSourceArray&, class CBitmapSource*);
    void SetEnabled(bool);
    void OnMouseEnter();
    void OnMouseLeave();
    void OnMouseLeftButton(bool);
    void SetMouseCapture(bool);
    HRESULT OnGlobalTimeUpdated();
    void SetGhost();
    void SetReverseRTLMirror(bool);
    bool IsPressed();
protected:
    void* operator new(unsigned int, void*);
    void* operator new(unsigned int);
    void* operator new[](unsigned int);
    void operator delete(void*);
    void operator delete[](void*);
    ~CButton();
    CButton();
    HRESULT Initialize(const struct MIL_CHANNEL__*);
    HRESULT UpdateOffset();
    void* __vecDelDtor(unsigned int);
private:
    CButton(class CButton&);
    int operator=(class CButton&);
    bool IsMouseOver();
    bool IsMouseCaptured();
    bool IsMouseButtonDown();
    HRESULT RedrawVisual();
    HRESULT DrawStateW(class CMeshButton*, enum CButton::ButtonStates);
    void UpdateCrossfade();
    void ComputeFadeValues(float*, float*);
    HRESULT ActivateTimeline(class CTimeline<float>**, float, float, float, enum InterpolationMode);
    void DeactivateTimeline(class CTimeline<float>**);
    void UpdateMeshPositionAndSize();
    bool m_fIsEnabled : 1;
    bool m_fIsMouseOver : 1;
    bool m_fIsMouseButtonDown : 1;
    bool m_fIsMouseCaptured : 1;
    bool m_fIsGhost : 1;
    bool m_fReverseRTLMirror : 1;
    class CMeshButton* m_pMeshButton;
    class CMeshButton* m_pMeshButtonLast;
    class CBitmapSourceArray m_rgpBitmapSourceStates;
    class CBitmapSourceArray m_rgpbsGlyphStates;
    class CBitmapSource* m_pGlowImage;
    enum CButton::ButtonStates m_buttonState;
    float m_FadeInInitial;
    float m_FadeOutInitial;
    class CTimeline<float>* m_ptlFade;
    const unsigned long DF_VISUALSTATE;
    const unsigned long DF_CROSSFADE;
};