#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

constexpr const int MAX = 1000;
enum { EXIT = 0, ADD = 1, SHOW = 2, DEL = 3, SRCH = 4, MODI = 5, CLR = 6 };

void pause() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
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
	bool m_Sex; // 1->male, 2->female
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

void addPerson(Addressbooks& abs)
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
		abs.personArray[abs.m_Size].m_Name = name;

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
				abs.personArray[abs.m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs.personArray[abs.m_Size].m_Age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs.personArray[abs.m_Size].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address = "";
		cin >> address;
		abs.personArray[abs.m_Size].m_Addr = address;

		//更新通讯录人数
		abs.m_Size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks& abs)
{
	if (abs.m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs.m_Size; i++)
		{
			cout << "姓名：" << abs.personArray[i].m_Name << "\t";
			cout << "性别：" << (abs.personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs.personArray[i].m_Age << "\t";
			cout << "电话：" << abs.personArray[i].m_Phone << "\t";
			cout << "住址：" << abs.personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");

}

int isExist(Addressbooks& abs, string name)
{
	for (int i = 0; i < abs.m_Size; i++)
	{
		if (abs.personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks& abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs.m_Size; i++)
		{
			abs.personArray[i] = abs.personArray[i + 1];
		}
		abs.m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
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
			addPerson(abs);
			break;

		case SHOW:
			showPerson(abs);
			break;

		case DEL:
			deletePerson(abs);
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