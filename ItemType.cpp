#include "ItemType.h"

//사진 파일명을 키보드로 설정한다.
void ItemType::SetPNameFromKB()
{
	cout << "\tPName : ";
	cin >> m_pName;
}


//사진이 촬영된 년월일시간을 키보드로 설정한다.
void ItemType::SetPWhenFromKB()
{
	cout << "\tPWhen : ";
	cin >> m_pWhen;
}


// 사진파일 크기를 키보드로 설정한다.
void ItemType::SetPSizeFromKB()
{
	cout << "\tPSize : ";
	cin >> m_pSize;
}

//사진파일의 이벤트명을 키보드로 설정한다.
void ItemType::SetPEventNameFromKB()
{
	cout << "\tPEventName : ";
	cin >> m_pEventName;
}


//사진 파일 레코드를 키보드로 설정한다.
void ItemType::SetRecordFromKB()
{
	SetPNameFromKB();
	SetPWhenFromKB();
	SetPSizeFromKB();
	SetPEventNameFromKB();
}

//파일로부터 레코드를 읽는다.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_pName;
	fin >> m_pWhen;
	fin >> m_pSize;
	fin >> m_pEventName;
	return 1;
};


//파일에 레코드를 쓴다.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_pName << " ";
	fout << m_pWhen << " ";
	fout << m_pSize << " ";
	fout << m_pEventName << " ";
	return 1;
}

// 두 아이템타입을 비교한다.
RelationType ItemType :: CompareByPName(const ItemType &data)
{
	if (this->m_pName > data.m_pName)
		return GREATER;
	else if (this->m_pName < data.m_pName)
		return LESS;
	else
		return EQUAL;
}
