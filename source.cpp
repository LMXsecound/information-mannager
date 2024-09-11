#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

constexpr const int MAX = 1000;
enum {EXIT = 0, ADD = 1, SHOW = 2, DEL = 3, SRCH = 4, MODI = 5, CLR = 6};

void pause() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	printf("Press any key to exit...");
	_getch();
}

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1��������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;

}

struct Person
{
	bool m_Sex; // 0->male, 1->female
	int m_Age; // ����
	string m_Name; // ����
	string m_Phone; // �绰
	string m_Addr; // ��ַ
};

struct Addressbooks
{
	Person personArray[MAX]; // ͨѶ¼�б������ϵ������
	int m_Size; // ͨѶ¼����Ա����
};

int main()
{
	int select = 0;
	bool loopSitu = true;
    //创建通讯录
	Addressbooks abs;
	//初始化通讯录中人数
	abs.m_Size = 0;
	while (loopSitu)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case ADD:
			break;

		case SHOW:
			break;

		case DEL:
			break;

		case SRCH:
			break;

		case MODI:
			break;

		case CLR:
			break;

		case EXIT:
			loopSitu = false;
			break;

		default:
			break;
		}
		system("cls");
	}

	pause();

	return 0;
}