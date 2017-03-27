#pragma once
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
�� ������ ������ ����.
*/
enum RelationType{ LESS, GREATER , EQUAL};



/*
������ ���� Ŭ����
*/
class ItemType
{
public:
		//�ʱ� ������
	ItemType()
	{
		m_pName = "";
		m_pWhen = "               ";
		m_pSize = -1;
		m_pEventName = "";
	}

		//�Ҹ���
	~ItemType() {}
/*
*	@brief ���� ���ϸ��� ����.
*	@pre ���� ���ϸ��� ����.
*	@post. 
*	@return m_pName.
*/
	string GetPName()
	{
		return m_pName;
	}


/*
*	@brief ������ �Կ��� ����Ͻð��� ����.
*	@pre ������ �Կ��� ����Ͻð��� ����.
*	@post.
*	@return ������ �Կ��� ����Ͻð�.
*/
	string GetPWhen()
	{
		return m_pWhen;
	}


/*
*	@brief ������ ����� ����.
*	@pre ������ ����� ����.
*	@post.
*	@return ������ ������.
*/
	int GetPSize()
	{
		return m_pSize;
	}


	/*
	*	@brief �̺�Ʈ ���� ����.
	*	@pre �̺�Ʈ ���� ����.
	*	@post.
	*	@return �̺�Ʈ ��.
	*/
	string GetPEventName()
	{
		return m_pEventName;
	}







	/**
	*	@brief	���� �̸��� ����.
	*	@pre	.
	*	@post	���� �̸��� ������.
	*	@param	inPName	���� �̸�.
	*/
	void SetPName(string inPName)
	{
		m_pName = inPName;
	}


	/**
	*	@brief	������ ���� ����Ͻð��� ����.
	*	@pre	none.
	*	@post	������ ���� ����Ͻð��� ������.
	*	@param	inWhen ������ ���� ����Ͻð�.
	*/
	void SetWhen(string inWhen)
	{
		m_pWhen = inWhen;
	}


	/**
	*	@brief	������ ����� ����.
	*	@pre	none.
	*	@post	������ ����� ������.
	*	@param	inPSize ������ ������.
	*/
	void SetPSize(int inPSize)
	{
		m_pSize = inPSize;
	}



	/**
	*	@brief	������ �̺�Ʈ���� ����..
	*	@pre	none.
	*	@post	������ �̺�Ʈ���� ������.
	*	@param	inPEName ������ �̺�Ʈ��.
	*/
	string SetPEventName(string inPEName)
	{
		return inPEName;
	}



	/*
	*	@brief ������ ���ڵ带 ����.
	*	@pre .
	*	@post ������ ���ڵ尡 ������.
	*	@param inPName	���� �̸�.
	*	@param inWhen ������ ���� ����Ͻð�.
	*	@param inPSize ������ ������.
	*	@param inPEName ������ �̺�Ʈ��.
	*/
	void SetRecord(string inPName, string inWhen, int inPSize, string inPEName)
	{
		SetPName(inPName);
		SetWhen(inWhen);
		SetPSize(inPSize);
		SetPEventName(inPEName);
	}


/*
*	@brief �������ϸ��� ��ũ���� ���÷����Ѵ�.
*	@pre ���� ���ϸ� ����.
*	@post ���� ���ϸ��� ��ũ���� ���÷��̵ȴ�.
*/
	void DisplayPNameOnScreen()
	{
		cout << "\tPName   : " << m_pName << endl;
	};


	/*
	*	@brief ������ ���� ������� ��ũ���� ���÷����Ѵ�.
	*	@pre ���� ���� ������� ����.
	*	@post ���� ���� ������� ��ũ���� ���÷��̵ȴ�.
	*/
	void DisplayPWhenOnScreen()
	{
		cout << "\tPWhen   : " << m_pWhen << endl;
	};

	/*
	*	@brief ������ ���� ũ�⸦ ��ũ���� ���÷����Ѵ�.
	*	@pre ������ ���� ũ�⸦ ����.
	*	@post ������ ���� ũ�Ⱑ ��ũ���� ���÷��̵ȴ�.
	*/
	void DisplayPSizeOnScreen()
	{
		cout << "\tPSize   : " << m_pSize << endl;
	};

	
	/*
	*	@brief ������ �̺�Ʈ �̸��� ��ũ���� ���÷����Ѵ�.
	*	@pre ������ �̺�Ʈ �̸��� ����.
	*	@post ������ �̺�Ʈ �̸��� ��ũ���� ���÷��̵ȴ�.
	*/
	void DisplayPEventNameOnScreen()
	{
		cout << "\tPEventName :  " << m_pEventName << endl;
	};



	/*
	*	@brief ������ ���ڵ������� ��ũ���� ���÷����Ѵ�.
	*	@pre ������ ���ڵ带 ����.
	*	@post ������ ���ڵ� ������ ���÷��̵ȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayPNameOnScreen();
		DisplayPWhenOnScreen();
		DisplayPSizeOnScreen();
		DisplayPEventNameOnScreen();
	};



	/*	
	*	@brief ������ ���ϸ��� Ű����� ����
	*	@pre
	*	@post ������ ���ϸ��� ������.
	*/
	void SetPNameFromKB();



	/*
	*	@brief ������ ���� ����� �ð��� Ű����� ����
	*	@pre
	*	@post ������ ���� ����� �ð��� ������.
	*/
	void SetPWhenFromKB();


	/*
	*	@brief ������ ����ũ�⸦ Ű����� ����
	*	@pre
	*	@post ������ ���� ũ�Ⱑ ������.
	*/
	void SetPSizeFromKB();



	/*
	*	@brief ������ �̺�Ʈ���� Ű����� ����
	*	@pre
	*	@post ������ �̺�Ʈ���� ������.
	*/
	void SetPEventNameFromKB();



	/*
	*	@brief ������ ���ڵ带 Ű����� ����
	*	@pre
	*	@post ������ ���ڵ尡 ������.
	*/
	void SetRecordFromKB();


	/*
	*	@brief ���Ϸκ��� ���� ���ڵ带 �о�´�.
	*	@pre Ÿ�������� ������.
	*	@post ���Ϸ��ڵ尡 �����ȴ�.
	*	@param fin file descriptor.
	*	@return �Լ��� �� �����ϸ� 1�� �����ϰ� �׷��� �ʴٸ�0�� �����Ѵ�.
	*/
	int ReadDataFromFile(ifstream& fin);



	/*
	*	@brief ���ڵ带 ���Ͼȿ� ���´�.
	*	@pre Ÿ�������� ������. ����Ʈ�� �ʱ�ȭ �Ǿ����־���Ѵ�.
	*	@post Ÿ�������� ���ο� �������ڵ带 ���Խ�Ų��.
	*	@param fout file descriptor.
	*	@return �Լ��� �� �����ϸ� 1�� �����ϰ� �׷��� �ʴٸ�0�� �����Ѵ�.
	*/
	int WriteDataToFile(ofstream& fout);


	/*
	*	�� �������� ���Ѵ�.
	*	@brief �������� ������ �� ������Ÿ���� ���Ѵ�.
	*	@pre �� ������ Ÿ���� �ʱ�ȭ�Ǿ��� �־���Ѵ�.
	*	@  post Ÿ�� ������ ���ο� �����۷��ڵ带 ���Խ�Ų��.
	*	@param data		�񱳸����� Ÿ�پ�����
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
