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
	// ���� �����Ͽ���
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
	// ���� ���� �Ͽ��� �ϳ��� �� �������� ������ �߻����� ����.
}