#include "Application.h"



void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// Ű���忡�� ���������� �Է¹޾� ����Ʈ�� �߰�				
			AddImage();
			break;
		case 2:	// Ű���忡�� �����̸��� �Է¹޾� ����Ʈ���� ã�� ����
			DeleteImage();
			break;
		case 3:// �������� ����					
			m_List.MakeEmpty();
				
			break;
		case 4:		// Ű���忡�� �Է��� �����̸����� ����Ʈ���� ã�� ���
			
					FindNDisplayImage();
			break;
		case 5:		// Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ������ �������� ����
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
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

						// ���� list ���
	DisplayAllItem();

	return 1;
}


int Application::AddImage()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if (m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// ���� list ���
	DisplayAllItem();

	return 1;
}

// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


//ã�� ���ϸ��� ����ڿ��� �Է¹ް� SortedList�� Get�Լ��� ȣ���Ѵ�.
bool Application:: FindNDisplayImage()
{
	cout << "\tã��";
	ItemType data;	//Get�Լ��� ItemType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetPNameFromKB();	//����ڿ��Լ� ���ϸ��� �Է¹޴´�.
	if (m_List.GetByBinarySearch(data))	//���ϸ��� ���� data�� Get���� ���� ������ ������ ä���.
	{
		cout << "\tã�ҽ��ϴ�." << endl;
		data.DisplayRecordOnScreen();
		return 1;	//ã���� �� �׸��� ������ְ� 1�� �����Ѵ�.
	}
	else
		cout << "\tã�� ���߽��ϴ�." << endl;
	return 0;	//ã�� ���ϸ� ã�� ���ߴٴ� �޽����� ����ϰ� 0�� �����Ѵ�.
}





//ã�� ���ϸ��� ����ڿ��� �Է¹ް� SortedList�� Delete�Լ��� ȣ���Ѵ�.
void Application::DeleteImage()
{
	cout << "\t����";
	ItemType data;	//Delete�Լ��� ItemType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetPNameFromKB();	//����ڿ��Լ� ���ϸ��� �Է¹޴´�.
	if (m_List.Delete(data))	//Delete�Լ��� data�� �Ѱ��ش�.
	{
		cout << "\t������ �Ϸ��߽��ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
	}
	else
		cout << "\t�������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
}




// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}




// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
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
	cout << "\t���� �Ⱓ�� ����";
	ItemType data;	//Delete�Լ��� ItemType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetPWhenFromKB();	//����ڿ��Լ� ������ ��������Ͻð����� �Է¹޴´�.
	cout << "\t���� �Ⱓ�� ��";
	ItemType data2;

	data2.SetPWhenFromKB();

	if (m_List.Delete2(data,data2))	//Delete�Լ��� data�� �Ѱ��ش�.
	{
		cout << "\t������ �Ϸ��߽��ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
	}
	else
		cout << "\t�������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
}

