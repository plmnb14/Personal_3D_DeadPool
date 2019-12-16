#ifndef RendererMgr_h__
#define RendererMgr_h__

#include "Engine_Defines.h"
#include "Base.h"

#include "Renderer.h"
#include "TriCol.h"
#include "RcCol.h"
#include "RcTex.h"
#include "TerrainTex.h"

#include "Texture.h"


BEGIN(ENGINE)

class ENGINE_DLL CRendererMgr : public CBase
{
	DECLARE_SINGLETON(CRendererMgr)

private:
	explicit CRendererMgr(void);
	virtual ~CRendererMgr(void);

public:
	void Get_VertexInfo(
		const _ushort& wContainerIdx,
		const _tchar* pBufferTag,
		void* pVertex);

public:
	void Set_VertexInfo(
		const _ushort& wContainerIdx,
		const _tchar* pBufferTag,
		void* pVertex);

public:
	HRESULT	Reserve_ContainerSize(const _ushort& wSize);

	HRESULT	Ready_Buffers(LPDIRECT3DDEVICE9 pGraphicDev,
		const _ushort& wContainerIdx,
		const _tchar* pBufferTag,
		BUFFERID eID,
		const _ulong& dwCntX = 1,
		const _ulong& dwCntZ = 1,
		const _ulong& dwVtxItv = 1);

	HRESULT		Ready_Texture(LPDIRECT3DDEVICE9 pGraphicDev,
		const _ushort& wContainerIdx,
		const _tchar* pTextureTag,
		TEXTURETYPE eType,
		const _tchar* pPath,
		const _uint& iCnt = 1);

	void Render_Texture(const _ushort& wContainerIdx, const _tchar* pTextureTag, const _uint& iIndex = 0);

	void Render_Buffer(const _ushort& wContainerIdx, const _tchar* pBufferTag);

	CRenderer*	Clone(const _ushort& wContainerIdx,const _tchar* pResourceTag);
private:
	CRenderer*	Find_Renderer(const _ushort& wContainerIdx, const _tchar* pRendererTag);

private:
	map<const _tchar*, CRenderer*>*		m_pmapRenderer;
	_ushort									m_wContainerSize;

public:
	virtual void Free(void);

};

END
#endif // RendererMgr_h__
