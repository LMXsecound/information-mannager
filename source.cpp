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
	int m_Age; //年龄
	string m_Name; //姓名
	string m_Phone; //电话
	string m_Addr;  //住址
};

struct Addressbooks
{
	Person personArray[MAX]; //通讯录中保存的联系人数组
	int m_Size; //通讯录中人员个数
};

void addPerson(Addressbooks abs)
{
	//判断电话本是否满了
	if (abs.m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		//abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				/*abs->personArray[abs->m_Size].m_Sex = sex;*/
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		/*abs->personArray[abs->m_Size].m_Age = age;*/

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		/*abs->personArray[abs->m_Size].m_Phone = phone;*/

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		/*abs->personArray[abs->m_Size].m_Addr = address;*/

		//更新通讯录人数
		/*abs->m_Size++;*/

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

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