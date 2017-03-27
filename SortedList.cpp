#include "SortedList.h"

// ����Ʈ�� ����.
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
	if (!IsFull())	//�� ���� �ʾ����� �׸��� �߰��Ѵ�.
	{
		if (m_Length == 0)	//Array�� �ƹ� �׸��� ������ ���� �ʿ� ���� �߰����ش�.
		{
			m_Array[m_Length] = inData;
			m_Length++;
			return 1;	//�׸��� �߰������Ƿ� 1�� �������ش�.
		}
		else	//Array�� ���� �׸��� ������ ��
		{
			for (int i = 0; i<m_Length; i++)
			{
				switch (m_Array[i].CompareByPName(inData))	//Array�� �����ϴ� ���� �׸��� ���ϸ�� ����ڰ� �߰��ϰ��� �ϴ� �ű� �׸��� ���ϸ��� ���Ѵ�.
				{
				case LESS:	//������ �׸��� �� ������(�ű� �׸��� �� Ŭ��)
					if (i == m_Length - 1)	//Array�� �������� �����ߴµ��� �ű� �׸��� �� ũ�� ���� ū ���̹Ƿ� �������� �߰����ش�.
					{
						m_Array[m_Length] = inData;
						m_Length++;
						return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
					}
					break;	//Array�� �������� �ƴѵ��� ������ �׸��� �� ������ Array�� ���� �׸�� �񱳸� ���� switch���� �������´�.
				case GREATER:	//������ �׸��� �� Ŭ��(�ű� �׸��� �� ������)
					for (int j = m_Length; j>i; j--)	//������ �׸���� 1ĭ�� �ڷ� �ű��.
					{
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = inData;	//�ű� �׸��� Array�� �߰����ش�.
					m_Length++;
					return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
					break;
				case EQUAL:	//������ �׸�� ���� ��
					return -1;	//�ߺ��Ǵ� ���̹Ƿ� �߰��� �� ����. -1�� �������ش�.
					break;
				}
			}
		}
	}
	else	//�� á���Ƿ� �߰��� �� ����.
		return 0;	//0�� �������ش�.
}


// Initialize list iterator.
void SortedList::ResetList()
{
	m_CurPointer = -1;
}



// move list iterator to the next item in list and get that item.
int SortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}


//���ϸ��� �����ϴ� data�� (�迭 �ȿ� �����ϴ� �׸�� ��) �˸´� �׸��� ã�� �������ش�.
int SortedList::Get(ItemType& data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetPName() == data.GetPName())	//data�� 'm_Array �� �ϳ��� �׸�'�� ���ϸ��� ���� ��
		{
			data = m_Array[i];
			return 1;	//data�� �������� �� 1�� �����Ѵ�.
		}
	}
	return 0;	//ã�� ���ϸ� 0�� �����Ѵ�.
}


//���ϸ��� �����ϴ� data�� �̿��Ͽ� �� ���ϸ��� ���� ���ϸ��� ������ �ִ� �׸��� �����ְ� length�� 1 ���ش�.
int SortedList::Delete(ItemType data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetPName() == data.GetPName())	//data�� 'm_Array �� �ϳ��� �׸�'�� ���ϸ��� ���� ��
		{
			for (int j = i; j<m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	//���� �׸��� �ڸ��� ���� �׸��� �����ϰ� �̰��� ������ �׸���� �ݺ��Ѵ�. m_Length�� 1 �ٿ��ش�.
			return 1;	//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
		}
	}
	return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
}

int SortedList::Delete2(ItemType data, ItemType data2)
{
	for (int i = 0; i < m_Length; i++)
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i].GetPWhen() == data.GetPWhen() || (data.GetPWhen() < m_Array[i].GetPWhen()) && (m_Array[i].GetPWhen() < data2.GetPWhen()) || m_Array[i].GetPWhen() == data2.GetPWhen())	//data�� 'm_Array �� �ϳ��� �׸�'�� ���ϸ��� ���� ��
			{
				for (int j = i; j < m_Length - 1; j++)
				{
					m_Array[j] = m_Array[j + 1];
				}
				m_Length--;	//���� �׸��� �ڸ��� ���� �׸��� �����ϰ� �̰��� ������ �׸���� �ݺ��Ѵ�. m_Length�� 1 �ٿ��ش�.
					//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
			}
		}
		return 1;
	}
	return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
}

//data�� �̿��Ͽ� �� ID���� ������ �ִ� �׸��� ã�� �װ��� data�� ������ �����Ѵ�.
int SortedList::Replace(ItemType data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetPName() == data.GetPName())	//data�� 'List �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			m_Array[i].SetRecord(data.GetPName(), data.GetPWhen(), data.GetPSize(),data.GetPEventName());	//data�� ������ List�� �׸� �����Ѵ�.
			return 1;	//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
		}
	}
	return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
}



//���ϸ��� �����ϴ� data�� (�迭 �ȿ� �����ϴ� �׸�� ��) �˸´� �׸��� Binary Search�� �̿��� ã�� �������ش�.
int SortedList::GetByBinarySearch(ItemType& data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = 0;
	while (first <= last && !found)	//first�� last���� Ŀ���� ���̻� �������� �ʴ´�. found�� 1�� �Ǹ� �������� �ʴ´�.
	{
		int mid = (first + last) / 2;	//mid�� first�� last�� ��հ�
		switch (data.CompareByPName(m_Array[mid]))	//data�� m_Array[mid]�� ���ϸ� ��
		{
		case LESS:
			last = mid - 1;
			break;	//data�� ���ϸ��� �� ������, last�� mid-1�� �Ű��ش�.
		case GREATER:
			first = mid + 1;
			break;	//data�� ���ϸ��� �� Ŭ��, first�� mid+1�� �Ű��ش�.
		case EQUAL:
			data = m_Array[mid];
			found = 1;
			return 1;	//data�� m_Array[mid]�� ���ϸ��� ������ data�� ��ü�� �������ְ� 1�� �����Ѵ�. �ݺ����� ���������� ���� found=1�� ���ش�.
			break;
		}
	}
	return 0;	//ã�� �������Ƿ� 0�� �������ش�.
}