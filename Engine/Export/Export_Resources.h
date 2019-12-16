#ifndef Export_Resources_h__
#define Export_Resources_h__

#include "RendererMgr.h"

BEGIN(ENGINE)

// RendererMgr
inline HRESULT	Reserve_Size_Render(const _ushort& wSize);

inline HRESULT	Ready_Buffers(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& wContainerIdx,
	const _tchar* pBufferTag,
	BUFFERID eID,
	const _ulong& dwCntX = 1,
	const _ulong& dwCntZ = 1,
	const _ulong& dwVtxItv = 1);

inline HRESULT		Ready_Texture(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& wContainerIdx,
	const _tchar* pTextureTag,
	TEXTURETYPE eType,
	const _tchar* pPath,
	const _uint& iCnt = 1);

inline void		Render_Texture(const _ushort& wContainerIdx,
	const _tchar* pTextureTag,
	const _uint& iIndex = 0);

inline void		Render_Buffer(const _ushort& wContainerIdx,
	const _tchar* pBufferTag);

inline CRenderer*		Clone(const _ushort& wContainerIdx,
	const _tchar* pResourceTag);


// Release CRenderer
inline void Release_Resources();

#include "Export_Resources.inl"

END

#endif // Export_Resources_h__
