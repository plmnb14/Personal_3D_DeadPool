// RendererMgr
HRESULT	Reserve_Size_Render(const _ushort& wSize)
{
	return CRendererMgr::GetInstance()->Reserve_ContainerSize(wSize);
 }

HRESULT	Ready_Buffers(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& wContainerIdx,
	const _tchar* pBufferTag,
	BUFFERID eID,
	const _ulong& dwCntX,
	const _ulong& dwCntZ,
	const _ulong& dwVtxItv)
{
	return CRendererMgr::GetInstance()->Ready_Buffers(pGraphicDev, wContainerIdx, pBufferTag, eID, dwCntX, dwCntZ, dwVtxItv);
}

HRESULT		Ready_Texture(LPDIRECT3DDEVICE9 pGraphicDev,
	const _ushort& wContainerIdx,
	const _tchar* pTextureTag,
	TEXTURETYPE eType,
	const _tchar* pPath,
	const _uint& iCnt)
{
	return CRendererMgr::GetInstance()->Ready_Texture(pGraphicDev, wContainerIdx, pTextureTag, eType, pPath, iCnt);
}

void		Render_Texture(const _ushort& wContainerIdx, const _tchar* pTextureTag, const _uint& iIndex)
{
	CRendererMgr::GetInstance()->Render_Texture(wContainerIdx, pTextureTag, iIndex);
 }

void		Render_Buffer(const _ushort& wContainerIdx, const _tchar* pBufferTag)
{
	CRendererMgr::GetInstance()->Render_Buffer(wContainerIdx, pBufferTag);
 }

CRenderer*		Clone(const _ushort& wContainerIdx, const _tchar* pResourceTag)
{
	return CRendererMgr::GetInstance()->Clone(wContainerIdx, pResourceTag);
}

// Release Renderer
void Release_Resources()
{
	CRendererMgr::GetInstance()->DestroyInstance();
}