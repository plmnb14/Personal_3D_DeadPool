CBase::CBase()
	: m_dwRefCnt(0)
{

}

CBase::~CBase()
{

}


unsigned long CBase::Addref()
{
	return m_dwRefCnt++;
	// 후위 연산하여야
}
unsigned long CBase::Release()
{
	if (0 == m_dwRefCnt)
	{
		Free();

		delete	this;

		return 0;
	}

	return m_dwRefCnt--;
	// 후위 연산 하여야 하나가 덜 지워지는 현상이 발생하지 않음.
}