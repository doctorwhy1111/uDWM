#pragma once
#include "framework.h"
#include "baseobject.h"

class CVisual : public CBaseObject
{
public:
    HRESULT Create(const struct MIL_CHANNEL__*, class CVisual**);
    HRESULT AddInstruction(class CRenderDataInstruction*);
    HRESULT ClearInstructions();
    bool HasInstructions();
    static void SetDirtyFlags(ULONG);
    void ClearDirtyFlags(ULONG);
    bool CheckDirtyFlags(ULONG);
    void PropagateDirtyChildren();
    HRESULT UpdateRenderData();





protected:
    void* operator new(unsigned int, void*);
    void* operator new(unsigned int);
    void* operator new[](unsigned int);
    void operator delete(void*);
    void operator delete[](void*);
    CVisual();
    virtual ~CVisual();
    HRESULT Initialize(const struct MIL_CHANNEL__*);
    public 
    public 
    public 
    public 
    public HRESULT ValidateVisual();
    public HRESULT ValidateVisualPostSubgraph();
    public HRESULT RenderRecursive();
    public unsigned int GetCompositionNodeHandle();
    public class CResource* GetCompositionNode();
    public struct MIL_CHANNEL__* GetChannel();
    public class VisualCollection* GetChildren();
    public HRESULT SetParent(class CVisual*);
    public class CVisual* GetParent();
    public HRESULT AddChild(class CVisual*, bool);
    public HRESULT InsertChildAfter(class CVisual*, class CVisual*);
    public HRESULT InsertChildBefore(class CVisual*, class CVisual*);
    public HRESULT RemoveChild(class CVisual*);
    public HRESULT RemoveAllChildren();
    public HRESULT MoveToFront();
    public HRESULT SetRenderForCapture(bool);
    public HRESULT ApplyContextualizedOpacityParameter(float);
    public HRESULT SetHasContextualizedOpacity(bool);
    public HRESULT ParameterAbstraction(enum MilVisualRenderParameterType::Enum, unsigned int);
    public HRESULT SetColorTransform(struct MilColorTransform&);
    public HRESULT SetColorTransformRoot();
    public HRESULT UpdateLayout();
    public bool DoCanvasLayout(struct tagSIZE&, struct _MARGINS&, struct tagSIZE&, struct tagPOINT*, struct tagSIZE*);
    public struct tagSIZE& GetSize();
    public HRESULT SetSize(struct tagSIZE*);
    public HRESULT SetSize(int, int);
    public HRESULT SetWidth(int);
    public HRESULT SetHeight(int);
    public struct tagPOINT& GetOffset();
    public void SetOffset(struct tagPOINT&);
    public void SetOffset(struct tagPOINT*);
    public void SetInsetFromParentLeft(int);
    public void SetInsetFromParentRight(int);
    public void SetInsetFromParentTop(int);
    public void SetInsetFromParentBottom(int);
    public void SetInsetFromParent(struct _MARGINS&);
    public struct _MARGINS& GetInsetFromParent();
    public void SetRotation(float);
    public float GetRotation();
    public void SetScale(struct MilPoint2F);
    public void SetScale(float, float);
    public struct MilPoint2D& GetScale();
    public void SetRTLMirror(bool);
    public bool GetRTLMirror();
    public void SetOpacity(float);
    public float GetOpacity();
    public bool TransformFromParent(struct tagPOINT&, struct tagPOINT*);
    public void OnMouseEnter();
    public void OnMouseLeave();
    public void OnMouseLeftButton(bool);
    public void MouseEnter();
    public void MouseLeave();
    public HRESULT SetIsVisible(bool);
    public bool IsVisible();
    public bool DoHitTest(struct tagPOINT&, class CVisual**, unsigned int*);
    public void SetHitTestResult(unsigned int);
    public unsigned int GetHitTestResult();
    public void GetLocalToWorldTransform(struct D2DMatrix*);
    public HRESULT OnGlobalTimeUpdated();
    public void DisablePrefiltering();
    public void DisableTrilinearFiltering();
    public void DisableAnisotropicFiltering();
    public void DisableZBuffer();
    public void SetInterpolationMode(enum MilBitmapInterpolationMode::Enum);
    public void ClearInterpolationMode();
    public void SetCompositingMode(enum MilCompositingMode::Enum);
    public void Hide();
    public void Unhide();
    public void ExcludeFromCloning(bool);
    public bool IsExcludedFromCloning();
    public HRESULT CloneVisualTree(class CVisual**);
    public HRESULT UpdateOpacity();
    protected void GetMirrorTransform(struct D2DMatrix*);
    protected HRESULT UpdateOffset();
    private HRESULT UpdateTransform();
    private bool GetCurrentTransform(struct D2DMatrix*);
    private HRESULT UpdateRenderOptions();
    protected class CResource* m_prCompNode;
    protected class CVisual* m_pParent;
    protected class VisualCollection m_vcChildren;
    protected const unsigned long DF_HAVEDIRTYCHILDREN;
    protected const unsigned long DF_LAYOUT;
    protected const unsigned long DF_RENDERDATA;
    protected const unsigned long DF_OFFSET;
    protected const unsigned long DF_TRANSFORM;
    protected const unsigned long DF_OPACITY;
    protected const unsigned long DF_RENDEROPTIONS;
    protected const unsigned long DF_OWNEDSECONDARYWINDOWREPRESENTATION;
    protected const unsigned long DF_VISUAL_UNUSED_0;
    protected const unsigned long DF_VISUAL_UNUSED_1;
    protected const unsigned long DF_VISUAL_UNUSED_2;
    protected const unsigned long DF_VISUAL_UNUSED_3;
    protected const unsigned long DF_VISUAL_UNUSED_4;
    protected const unsigned long DF_VISUAL_UNUSED_5;
    protected const unsigned long DF_VISUAL_UNUSED_6;
    protected const unsigned long DF_VISUAL_UNUSED_7;
    protected const unsigned long DF_VISUAL_UNUSED_8;
    protected const unsigned long DF_VISUAL_UNUSED_9;
    protected const unsigned long DF_VISUAL_UNUSED_10;
    protected const unsigned long DF_VISUAL_UNUSED_11;
    protected const unsigned long DF_VISUAL_UNUSED_12;
    protected const unsigned long DF_VISUAL_UNUSED_13;
    protected const unsigned long DF_VISUAL_UNUSED_14;
    protected unsigned long m_dwDirtyFlags;
    private bool m_fMirrorX : 1;
    private bool m_fHasTransform : 1;
    private bool m_fIsVisible : 1;
    private bool m_fIsExcludedFromCloning : 1;
    private class CResource* m_prRenderData;
    private class CResource* m_prMatrixTransform;
    private struct tagPOINT m_offset;
    private struct tagSIZE m_size;
    private struct _MARGINS m_insetFromParent;
    private float m_angle;
    private struct MilPoint2D m_scale;
    private float m_opacity;
    private unsigned int m_hitTestResult;
    private struct MilRenderOptions m_renderOptions;
    private 
    protected void* __vecDelDtor(unsigned int);
private:
    CVisual(class CVisual&);
    int operator=(class CVisual&);
    class DynArray<CRenderDataInstruction*, 0> m_rgpRenderDataInstructions;
};