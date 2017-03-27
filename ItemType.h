#pragma once
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
두 아이템 사이의 관계.
*/
enum RelationType{ LESS, GREATER , EQUAL};



/*
아이템 정보 클래스
*/
class ItemType
{
public:
		//초기 생성자
	ItemType()
	{
		m_pName = "";
		m_pWhen = "               ";
		m_pSize = -1;
		m_pEventName = "";
	}

		//소멸자
	~ItemType() {}
/*
*	@brief 사진 파일명을 얻음.
*	@pre 사진 파일명을 설정.
*	@post. 
*	@return m_pName.
*/
	string GetPName()
	{
		return m_pName;
	}


/*
*	@brief 사진이 촬영된 년월일시간을 얻음.
*	@pre 사진의 촬영된 년월일시간을 설정.
*	@post.
*	@return 사진이 촬영된 년월일시간.
*/
	string GetPWhen()
	{
		return m_pWhen;
	}


/*
*	@brief 사진의 사이즈를 얻음.
*	@pre 사진의 사이즈를 설정.
*	@post.
*	@return 사진의 사이즈.
*/
	int GetPSize()
	{
		return m_pSize;
	}


	/*
	*	@brief 이벤트 명을 얻음.
	*	@pre 이벤트 명을 설정.
	*	@post.
	*	@return 이벤트 명.
	*/
	string GetPEventName()
	{
		return m_pEventName;
	}







	/**
	*	@brief	사진 이름을 설정.
	*	@pre	.
	*	@post	사진 이름이 설정됨.
	*	@param	inPName	사진 이름.
	*/
	void SetPName(string inPName)
	{
		m_pName = inPName;
	}


	/**
	*	@brief	사진이 찍힌 년월일시간을 설정.
	*	@pre	none.
	*	@post	사진이 찍힌 년월일시간이 설정됨.
	*	@param	inWhen 사진이 찍힌 년월일시간.
	*/
	void SetWhen(string inWhen)
	{
		m_pWhen = inWhen;
	}


	/**
	*	@brief	사진의 사이즈를 설정.
	*	@pre	none.
	*	@post	사진의 사이즈가 설정됨.
	*	@param	inPSize 사진의 사이즈.
	*/
	void SetPSize(int inPSize)
	{
		m_pSize = inPSize;
	}



	/**
	*	@brief	사진의 이벤트명을 설정..
	*	@pre	none.
	*	@post	사진의 이벤트명이 설정됨.
	*	@param	inPEName 사진의 이벤트명.
	*/
	string SetPEventName(string inPEName)
	{
		return inPEName;
	}



	/*
	*	@brief 사진의 레코드를 설정.
	*	@pre .
	*	@post 사진의 레코드가 설정됨.
	*	@param inPName	사진 이름.
	*	@param inWhen 사진이 찍힌 년월일시간.
	*	@param inPSize 사진의 사이즈.
	*	@param inPEName 사진의 이벤트명.
	*/
	void SetRecord(string inPName, string inWhen, int inPSize, string inPEName)
	{
		SetPName(inPName);
		SetWhen(inWhen);
		SetPSize(inPSize);
		SetPEventName(inPEName);
	}


/*
*	@brief 사진파일명을 스크린에 디스플레이한다.
*	@pre 사진 파일명 설정.
*	@post 사진 파일명이 스크린에 디스플레이된다.
*/
	void DisplayPNameOnScreen()
	{
		cout << "\tPName   : " << m_pName << endl;
	};


	/*
	*	@brief 사진이 찍힌 년월일을 스크린에 디스플레이한다.
	*	@pre 사진 찍힌 년월일을 설정.
	*	@post 사진 찍힌 년월일이 스크린에 디스플레이된다.
	*/
	void DisplayPWhenOnScreen()
	{
		cout << "\tPWhen   : " << m_pWhen << endl;
	};

	/*
	*	@brief 사진의 파일 크기를 스크린에 디스플레이한다.
	*	@pre 사진의 파일 크기를 설정.
	*	@post 사진의 파일 크기가 스크린에 디스플레이된다.
	*/
	void DisplayPSizeOnScreen()
	{
		cout << "\tPSize   : " << m_pSize << endl;
	};

	
	/*
	*	@brief 사진의 이벤트 이름을 스크린에 디스플레이한다.
	*	@pre 사진의 이벤트 이름을 설정.
	*	@post 사진의 이벤트 이름이 스크린에 디스플레이된다.
	*/
	void DisplayPEventNameOnScreen()
	{
		cout << "\tPEventName :  " << m_pEventName << endl;
	};



	/*
	*	@brief 사진의 레코드정보를 스크린에 디스플레이한다.
	*	@pre 사진의 레코드를 설정.
	*	@post 사진의 레코드 정보가 디스플레이된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayPNameOnScreen();
		DisplayPWhenOnScreen();
		DisplayPSizeOnScreen();
		DisplayPEventNameOnScreen();
	};



	/*	
	*	@brief 사진의 파일명을 키보드로 설정
	*	@pre
	*	@post 사진의 파일명이 설정됨.
	*/
	void SetPNameFromKB();



	/*
	*	@brief 사진의 찍힌 년월일 시간을 키보드로 설정
	*	@pre
	*	@post 사진의 찍힌 년월일 시간이 설정됨.
	*/
	void SetPWhenFromKB();


	/*
	*	@brief 사진의 파일크기를 키보드로 설정
	*	@pre
	*	@post 사진의 파일 크기가 설정됨.
	*/
	void SetPSizeFromKB();



	/*
	*	@brief 사진의 이벤트명을 키보드로 설정
	*	@pre
	*	@post 사진의 이벤트명이 설정됨.
	*/
	void SetPEventNameFromKB();



	/*
	*	@brief 사진의 레코드를 키보드로 설정
	*	@pre
	*	@post 사진의 레코드가 설정됨.
	*/
	void SetRecordFromKB();


	/*
	*	@brief 파일로부터 사진 레코드를 읽어온다.
	*	@pre 타겟파일이 열린다.
	*	@post 파일레코드가 설정된다.
	*	@param fin file descriptor.
	*	@return 함수가 잘 동작하면 1을 리턴하고 그렇지 않다면0을 리턴한다.
	*/
	int ReadDataFromFile(ifstream& fin);



	/*
	*	@brief 레코드를 파일안에 적는다.
	*	@pre 타겟파일이 열린다. 리스트가 초기화 되어져있어야한다.
	*	@post 타겟파일이 새로운 사진레코드를 포함시킨다.
	*	@param fout file descriptor.
	*	@return 함수가 잘 동작하면 1을 리턴하고 그렇지 않다면0을 리턴한다.
	*/
	int WriteDataToFile(ofstream& fout);


	/*
	*	두 아이템을 비교한다.
	*	@brief 사진파일 명으로 두 아이템타입을 비교한다.
	*	@pre 두 아이템 타입이 초기화되어져 있어야한다.
	*	@  post 타겟 파일이 새로운 아이템레코드를 포함시킨다.
	*	@param data		비교를위한 타겟아이템
	*	@return return LESS if this.id < data.id, 
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByPName(const ItemType &data);  

protected:
	string m_pName;
	string m_pWhen;
	int m_pSize;
	string m_pEventName;
};
#endif // !_ITEMTYPE_H
