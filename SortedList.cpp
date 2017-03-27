#include "SortedList.h"

// 리스트를 비운다.
void SortedList::MakeEmpty()
{
	m_Length = 0;
}

// Get a number of records in current list.
int SortedList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool SortedList::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// add a new data into list.
int SortedList::Add(ItemType inData)
{
	if (!IsFull())	//꽉 차지 않았으면 항목을 추가한다.
	{
		if (m_Length == 0)	//Array에 아무 항목이 없으면 비교할 필요 없이 추가해준다.
		{
			m_Array[m_Length] = inData;
			m_Length++;
			return 1;	//항목을 추가했으므로 1을 리턴해준다.
		}
		else	//Array에 기존 항목이 존재할 때
		{
			for (int i = 0; i<m_Length; i++)
			{
				switch (m_Array[i].CompareByPName(inData))	//Array에 존재하는 기존 항목의 파일명과 사용자가 추가하고자 하는 신규 항목의 파일명을 비교한다.
				{
				case LESS:	//기존의 항목이 더 작을때(신규 항목이 더 클때)
					if (i == m_Length - 1)	//Array의 마지막에 도달했는데도 신규 항목이 더 크면 가장 큰 값이므로 마지막에 추가해준다.
					{
						m_Array[m_Length] = inData;
						m_Length++;
						return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
					}
					break;	//Array의 마지막이 아닌데도 기존의 항목이 더 작으면 Array의 다음 항목과 비교를 위해 switch문을 빠져나온다.
				case GREATER:	//기존의 항목이 더 클때(신규 항목이 더 작을때)
					for (int j = m_Length; j>i; j--)	//기존의 항목들을 1칸씩 뒤로 옮긴다.
					{
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = inData;	//신규 항목을 Array에 추가해준다.
					m_Length++;
					return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
					break;
				case EQUAL:	//기존의 항목과 같을 때
					return -1;	//중복되는 값이므로 추가할 수 없다. -1을 리턴해준다.
					break;
				}
			}
		}
	}
	else	//꽉 찼으므로 추가할 수 없다.
		return 0;	//0을 리턴해준다.
}


// Initialize list iterator.
void SortedList::ResetList()
{
	m_CurPointer = -1;
}



// move list iterator to the next item in list and get that item.
int SortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}


//파일명값만 존재하는 data에 (배열 안에 존재하는 항목들 중) 알맞는 항목을 찾아 복사해준다.
int SortedList::Get(ItemType& data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetPName() == data.GetPName())	//data와 'm_Array 중 하나의 항목'의 파일명값이 같을 때
		{
			data = m_Array[i];
			return 1;	//data에 복사해준 뒤 1을 리턴한다.
		}
	}
	return 0;	//찾지 못하면 0을 리턴한다.
}


//파일명값만 존재하는 data를 이용하여 그 파일명값과 같은 파일명을 가지고 있는 항목을 지워주고 length를 1 빼준다.
int SortedList::Delete(ItemType data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetPName() == data.GetPName())	//data와 'm_Array 중 하나의 항목'의 파일명이 같을 때
		{
			for (int j = i; j<m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	//지울 항목의 자리에 다음 항목을 복사하고 이것을 마지막 항목까지 반복한다. m_Length를 1 줄여준다.
			return 1;	//항목을 삭제하는데 성공했으므로 1을 리턴해준다.
		}
	}
	return 0;	//항목을 삭제하는데 실패했으므로 0을 리턴해준다.
}

int SortedList::Delete2(ItemType data, ItemType data2)
{
	for (int i = 0; i < m_Length; i++)
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i].GetPWhen() == data.GetPWhen() || (data.GetPWhen() < m_Array[i].GetPWhen()) && (m_Array[i].GetPWhen() < data2.GetPWhen()) || m_Array[i].GetPWhen() == data2.GetPWhen())	//data와 'm_Array 중 하나의 항목'의 파일명이 같을 때
			{
				for (int j = i; j < m_Length - 1; j++)
				{
					m_Array[j] = m_Array[j + 1];
				}
				m_Length--;	//지울 항목의 자리에 다음 항목을 복사하고 이것을 마지막 항목까지 반복한다. m_Length를 1 줄여준다.
					//항목을 삭제하는데 성공했으므로 1을 리턴해준다.
			}
		}
		return 1;
	}
	return 0;	//항목을 삭제하는데 실패했으므로 0을 리턴해준다.
}

//data를 이용하여 그 ID값을 가지고 있는 항목을 찾고 그곳에 data의 내용을 복사한다.
int SortedList::Replace(ItemType data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetPName() == data.GetPName())	//data와 'List 중 하나의 항목'의 ID값이 같을 때
		{
			m_Array[i].SetRecord(data.GetPName(), data.GetPWhen(), data.GetPSize(),data.GetPEventName());	//data의 내용을 List의 항목에 복사한다.
			return 1;	//항목을 수정하는데 성공했으므로 1을 리턴해준다.
		}
	}
	return 0;	//항목을 수정하는데 실패했으므로 0을 리턴해준다.
}



//파일명값만 존재하는 data에 (배열 안에 존재하는 항목들 중) 알맞는 항목을 Binary Search를 이용해 찾아 복사해준다.
int SortedList::GetByBinarySearch(ItemType& data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = 0;
	while (first <= last && !found)	//first가 last보다 커지면 더이상 진행하지 않는다. found가 1이 되면 진행하지 않는다.
	{
		int mid = (first + last) / 2;	//mid는 first와 last의 평균값
		switch (data.CompareByPName(m_Array[mid]))	//data와 m_Array[mid]의 파일명값 비교
		{
		case LESS:
			last = mid - 1;
			break;	//data의 파일명값이 더 작을때, last를 mid-1로 옮겨준다.
		case GREATER:
			first = mid + 1;
			break;	//data의 파일명값이 더 클때, first를 mid+1로 옮겨준다.
		case EQUAL:
			data = m_Array[mid];
			found = 1;
			return 1;	//data와 m_Array[mid]의 파일명값이 같으면 data에 객체를 복사해주고 1을 리턴한다. 반복문을 빠져나오기 위해 found=1을 해준다.
			break;
		}
	}
	return 0;	//찾지 못했으므로 0을 리턴해준다.
}