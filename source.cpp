#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

constexpr const int MAX = 1000;
enum {EXIT = 0, ADD = 1, SHOW = 2, DEL = 3, SRCH = 4, MODI = 5, CLR = 6};

void pause() {
	cout << "欢迎下次使用！" << endl;
	printf("Press any key to exit...");
	_getch();
}

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}

struct Person
{
	bool m_Sex; // 0->male, 1->female
	int m_Age; // 年龄
	string m_Name; // 名字
	string m_Phone; // 电话
	string m_Addr; // 地址
};

struct Addressbooks
{
	Person personArray[MAX]; // 通讯录中保存的联系人数组
	int m_Size; // 通讯录中人员个数
};

int main()
{
	int select = 0;
	bool loopSitu = true;

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