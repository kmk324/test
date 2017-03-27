#include "ItemType.h"

//���� ���ϸ��� Ű����� �����Ѵ�.
void ItemType::SetPNameFromKB()
{
	cout << "\tPName : ";
	cin >> m_pName;
}


//������ �Կ��� ����Ͻð��� Ű����� �����Ѵ�.
void ItemType::SetPWhenFromKB()
{
	cout << "\tPWhen : ";
	cin >> m_pWhen;
}


// �������� ũ�⸦ Ű����� �����Ѵ�.
void ItemType::SetPSizeFromKB()
{
	cout << "\tPSize : ";
	cin >> m_pSize;
}

//���������� �̺�Ʈ���� Ű����� �����Ѵ�.
void ItemType::SetPEventNameFromKB()
{
	cout << "\tPEventName : ";
	cin >> m_pEventName;
}


//���� ���� ���ڵ带 Ű����� �����Ѵ�.
void ItemType::SetRecordFromKB()
{
	SetPNameFromKB();
	SetPWhenFromKB();
	SetPSizeFromKB();
	SetPEventNameFromKB();
}

//���Ϸκ��� ���ڵ带 �д´�.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_pName;
	fin >> m_pWhen;
	fin >> m_pSize;
	fin >> m_pEventName;
	return 1;
};


//���Ͽ� ���ڵ带 ����.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_pName << " ";
	fout << m_pWhen << " ";
	fout << m_pSize << " ";
	fout << m_pEventName << " ";
	return 1;
}

// �� ������Ÿ���� ���Ѵ�.
RelationType ItemType :: CompareByPName(const ItemType &data)
{
	if (this->m_pName > data.m_pName)
		return GREATER;
	else if (this->m_pName < data.m_pName)
		return LESS;
	else
		return EQUAL;
}
