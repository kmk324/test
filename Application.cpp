#include "Application.h"



void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 키보드에서 사진정보를 입력받아 리스트에 추가				
			AddImage();
			break;
		case 2:	// 키보드에서 사진이름을 입력받아 리스트에서 찾아 삭제
			DeleteImage();
			break;
		case 3:// 사진폴더 비우기					
			m_List.MakeEmpty();
				
			break;
		case 4:		// 키보드에서 입력한 사진이름으로 리스트에서 찾아 출력
			
					FindNDisplayImage();
			break;
		case 5:		// 키보드에서 기간을 입력받아서 구간내 사진들을 삭제
			DeleteImageInTimeInterval();
			break;
		case 6:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 7:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add image" << endl;
	cout << "\t   2 : Delete image" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by FileName" << endl;
	cout << "\t   5 : DeleteImageInTimeInterval" << endl;
	cout << "\t   6 : ReadDataFromFile" << endl;
	cout << "\t   7 : WriteDataToFile" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}



// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

						// 현재 list 출력
	DisplayAllItem();

	return 1;
}


int Application::AddImage()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}

// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


//찾을 파일명을 사용자에게 입력받고 SortedList의 Get함수를 호출한다.
bool Application:: FindNDisplayImage()
{
	cout << "\t찾을";
	ItemType data;	//Get함수는 ItemType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetPNameFromKB();	//사용자에게서 파일명값을 입력받는다.
	if (m_List.GetByBinarySearch(data))	//파일명값만 가진 data를 Get으로 보내 나머지 정보를 채운다.
	{
		cout << "\t찾았습니다." << endl;
		data.DisplayRecordOnScreen();
		return 1;	//찾으면 그 항목을 출력해주고 1을 리턴한다.
	}
	else
		cout << "\t찾지 못했습니다." << endl;
	return 0;	//찾지 못하면 찾지 못했다는 메시지를 출력하고 0을 리턴한다.
}





//찾을 파일명을 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
void Application::DeleteImage()
{
	cout << "\t지울";
	ItemType data;	//Delete함수는 ItemType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetPNameFromKB();	//사용자에게서 파일명값을 입력받는다.
	if (m_List.Delete(data))	//Delete함수에 data를 넘겨준다.
	{
		cout << "\t삭제를 완료했습니다." << endl;	//삭제에 성공했으면 메시지를 출력한다.
	}
	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.
}




// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}




// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}




void Application::DeleteImageInTimeInterval()
{
	cout << "\t지울 기간의 시작";
	ItemType data;	//Delete함수는 ItemType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetPWhenFromKB();	//사용자에게서 사진이 찍힌년월일시간값을 입력받는다.
	cout << "\t지울 기간의 끝";
	ItemType data2;

	data2.SetPWhenFromKB();

	if (m_List.Delete2(data,data2))	//Delete함수에 data를 넘겨준다.
	{
		cout << "\t삭제를 완료했습니다." << endl;	//삭제에 성공했으면 메시지를 출력한다.
	}
	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.
}

