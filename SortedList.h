#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/

class SortedList
{
public:
	/**
	*	default constructor.
	*/
	SortedList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~SortedList() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();
	
	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	primary key�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��Ѵ�.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(ItemType data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(ItemType& data);

	/**
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int Get(ItemType& data);


	/**
	*	@brief	����ڰ� ������ ItemType�� �迭���� �����Ѵ�.
	*	@pre	data�� �������ϸ� ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Delete(ItemType data);


	/**
	*	@brief	����ڰ� ������ ItemType�� �迭���� �����Ѵ�.
	*	@pre	data�� ��������������� ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Delete2(ItemType data, ItemType data2 );




	/**
	*	@brief	����ڰ� ������ ItemType�� �ش��ϴ� �迭�� �ڸ��� �Ķ������ ������ �����Ѵ�.
	*	@pre	data�� ��� ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� ������ �׸��� data�� ��������.
	*	@param	data : ��� ������ ä�����ִ� ItemType.
	*	@return	���������� ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Replace(ItemType data);


	/**
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�. ����� ã���� Binary Search�� �̿��Ѵ�.
	*	@pre	data�� �������ϸ� ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int GetByBinarySearch(ItemType& data);

private :
	ItemType m_Array[MAXSIZE]; // list array.
	int m_Length; // <number of elements in list.
	int m_CurPointer; // iterator pointer.

};

#endif // _SORTEDLIST_H