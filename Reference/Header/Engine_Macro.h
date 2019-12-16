#ifndef Engine_Macro_h__
#define Engine_Macro_h__

#define NO_EVENT 0
#define DEAD_OBJ 1

#define  WINCX 1280
#define  WINCY 720

#define FNULL 0.f
#define FHLF  0.5f
#define FONE  1.f

//

#define V3_NORMAL(_pOut , _pIn) D3DXVec3Normalize(_pOut, _pIn);
#define V3_NORMAL_S(_pSelf)		D3DXVec3Normalize(_pSelf, _pSelf);

//
#define COMP_TO_BUFFFER(_pComponent) static_cast<ENGINE::CVIBuffer*>(_pComponent)
#define COMP_TO_TEXTURE(_pComponent) static_cast<ENGINE::CTexture*>(_pComponent)
#define COMP_TO_TRANS(_pComponent)   static_cast<ENGINE::CTransform*>(_pComponent)

#define TARGET_TO_TRANS(_Target) static_cast<CTransform*>((_Target)->Get_Component(L"Transform"))

//

#define BEGIN(NAME)		\
namespace NAME			\
{

#define END				\
}

#ifdef ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)
#else
#define ENGINE_DLL _declspec(dllimport)
#endif

#define USING(NAME)	\
using namespace NAME;

//

#ifndef MSG_BOX
#define	MSG_BOX(_message)			MessageBox(NULL, TEXT(_message), L"System Message", MB_OK)
#endif

#define NULL_CHECK( _ptr)	\
{if( _ptr == 0){__asm { int 3 };return;}}

#define NULL_CHECK_RETURN( _ptr, _return)	\
{if( _ptr == 0){__asm { int 3 };return _return;}}

#define NULL_CHECK_MSG( _ptr, _message )		\
{if( _ptr == 0){MessageBox(NULL, _message, L"System Message",MB_OK);__asm { int 3 };}}

#define NULL_CHECK_RETURN_MSG( _ptr, _return, _message )	\
{if( _ptr == 0){MessageBox(NULL, _message, L"System Message",MB_OK);__asm { int 3 };return _return;}}


#define FAILED_CHECK(_hr)	if( ((HRESULT)(_hr)) < 0 )	\
{ MessageBoxW(NULL, L"Failed", L"System Error",MB_OK); __asm { int 3 }; return E_FAIL;}

#define FAILED_CHECK_RETURN(_hr, _return)	if( ((HRESULT)(_hr)) < 0 )		\
{ MessageBoxW(NULL, L"Failed", L"System Error",MB_OK); __asm { int 3 }; return _return;}

#define FAILED_CHECK_MSG( _hr, _message)	if( ((HRESULT)(_hr)) < 0 )	\
{ MessageBoxW(NULL, _message, L"System Message",MB_OK); __asm { int 3 };return E_FAIL;}

#define FAILED_CHECK_RETURN_MSG( _hr, _return, _message)	if( ((HRESULT)(_hr)) < 0 )	\
{ MessageBoxW(NULL, _message, L"System Message",MB_OK); __asm { int 3 };return _return;}



#define NO_COPY(CLASSNAME)							\
private:											\
	CLASSNAME(const CLASSNAME&);					\
	CLASSNAME& operator = (const CLASSNAME&);		

#define DECLARE_SINGLETON(CLASSNAME)				\
	NO_COPY(CLASSNAME)								\
private:											\
	static CLASSNAME*	m_pInstance;				\
public:												\
	static CLASSNAME*	GetInstance( void );		\
	static void DestroyInstance( void );			

#define IMPLEMENT_SINGLETON(CLASSNAME)				\
	CLASSNAME*	CLASSNAME::m_pInstance = NULL;		\
	CLASSNAME*	CLASSNAME::GetInstance( void )	{	\
		if(NULL == m_pInstance) {					\
			m_pInstance = new CLASSNAME;			\
		}											\
		return m_pInstance;							\
	}												\
	void CLASSNAME::DestroyInstance( void ) {		\
		if(NULL != m_pInstance)	{					\
			delete m_pInstance;						\
			m_pInstance = NULL;						\
		}											\
	}


#endif // Engine_Macro_h__
