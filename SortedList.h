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
	*	@brief	primary key를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
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
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int Get(ItemType& data);


	/**
	*	@brief	사용자가 지정한 ItemType를 배열에서 삭제한다.
	*	@pre	data의 사진파일명 변수는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int Delete(ItemType data);


	/**
	*	@brief	사용자가 지정한 ItemType를 배열에서 삭제한다.
	*	@pre	data의 사진이찍힌년월일 변수는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int Delete2(ItemType data, ItemType data2 );




	/**
	*	@brief	사용자가 지정한 ItemType에 해당하는 배열의 자리에 파라미터의 내용을 복사한다.
	*	@pre	data의 모든 변수가 채워져있어야 한다.
	*	@post	사용자가 지정한 항목이 data와 같아진다.
	*	@param	data : 모든 변수가 채워져있는 ItemType.
	*	@return	성공적으로 수정했으면 1, 아니면 0을 리턴한다.
	*/
	int Replace(ItemType data);


	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다. 대상을 찾을때 Binary Search를 이용한다.
	*	@pre	data의 사진파일명 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int GetByBinarySearch(ItemType& data);

private :
	ItemType m_Array[MAXSIZE]; // list array.
	int m_Length; // <number of elements in list.
	int m_CurPointer; // iterator pointer.

};

#endif // _SORTEDLIST_H