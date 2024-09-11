#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

enum {EXIT = 0, ADD = 1, SHOW = 2, DEL = 3, \
SRCH = 4, MODI = 5, CLR = 6};

struct Person {
    bool m_sex;// 0->F, 1->M
    int m_age;
    string m_name;
    string m_phone;
    string m_addr;
    Person *next;

    Person(bool sex, int age, string name, string phone, string addr):
        m_sex(sex), m_age(age), m_name(name), m_phone(phone), \
        m_addr(addr) {}

    bool operator< (const Person& B) {
        return this->m_name < B.m_name;
    }
};


ostream& operator<< (ostream& os, const Person& B) {
    os << "Name : " << B.m_name << endl \
       << "Sex  : " << (B.m_sex ? "M" : "F") << endl \
       << "Age  : " << B.m_age << endl \
       << "Phone: " << B.m_phone << endl;
    return os;
}

class AddressBooks {
private:
    int m_size;
    //priority_queue< Person*, vector<Person*>, greater<Person*> > pq;
    map<string, Person*> list;
    Person *head;
    Person *cur;

    Person* search(string name) {
        if (!list.count(name)) return nullptr;
        else return list[name];
    }

public:
    AddressBooks();
    void addPerson(Person& p);
    Person* srchPerson(const string& name);
    void remPerson(const string& name);// panduan 0;
    void clrPerson();
    void displayPerson();
    void modPerson(const string& name, Person*);
};

AddressBooks::AddressBooks() {
    head = new Person(-1, -1, "0", "-1", "-1");
    cur = head;
    m_size = 0;
    cur->next = nullptr;
}

void AddressBooks::displayPerson() {
    map<string, Person*>::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter) {
        cout << *(iter->second);
        /*cout << "Press any key to continue..." << endl;
        _getch();*/
        system("pause");
        system("cls");
    }
}

void AddressBooks::modPerson(const string& name, Person* p) {
    remPerson(name);
    addPerson(*p);
}

void AddressBooks::clrPerson() {
    list.clear();
    for (Person* i = head->next; i != nullptr; i = i->next) {
        delete i;
    }
    head->next = nullptr;
    cur = head;
}

void AddressBooks::remPerson(const string& name) {
    Person* p = search(name);
    if (p == nullptr) return ;
    list.erase(name);
    delete p;
}

void AddressBooks::addPerson(Person& p) {
    m_size ++;
    list[p.m_name] = &p;
    cur->next = &p;
    cur = &p;
    cur->next = nullptr;
}

Person* AddressBooks::srchPerson(const string& name) {
    return search(name);
}

void showMenu() {
    cout << "0.EXIT" << endl;
    cout << "1.ADD " << endl;
    cout << "2.DISP" << endl;
    cout << "3.DEL " << endl;
    cout << "4.SRCH" << endl;
    cout << "5.MODI" << endl;
    cout << "6.CLR " << endl;
    cout << "CHOICE: " ;
}

int main() {
    int choice;
    bool loopSitu = true;
    AddressBooks book;

    bool sex;
    int age;
    string _sex = "";
    string name;
    string phone;
    string addr;
    string temp;
    Person* current;

    while (loopSitu) {
        showMenu();
        cin >> choice;
        getchar();

        switch (choice) {
        case ADD:
            system("cls");
            cout << "name : ";
            getline(cin, name);
            cout << "phone: ";
            getline(cin, phone);
            cout << "addr :";
            getline(cin, addr);
            cout << "sex [M/F] :";
            getline(cin, _sex);
            if (_sex[0] == 'F') sex = false;
            else if (_sex[0] == 'M') sex = true;
            else {
                cout << "AutoSetting: Male" << endl;
                sex = true;
            }
            cout << "age   :";
            cin >> age;
            current = new Person(sex, age, name, phone, addr);
            book.addPerson(*current);
            system("cls");
            break;
        
        case EXIT:
            system("cls");
            cout << "Good Bye! " << endl;
            book.clrPerson();
            loopSitu = false;
            system("pause");
            system("cls");
            break;
        
        case SHOW:
            system("cls");
            book.displayPerson();
            break;
        
        case MODI:
            system("cls");
            cout << "Input the name: ";
            getline(cin, name);
            temp = name;
            current = book.srchPerson(name);
            if (current == nullptr) {
                cout << "Not exist!" << endl;
                system("pause");
                system("cls");
                break;
            }
            cout << *current;
            cout << "name : ";
            getline(cin, name);
            cout << "phone: ";
            getline(cin, phone);
            cout << "addr : ";
            getline(cin, addr);
            cout << "sex [M/F] : ";
            getline(cin, _sex);
            if (_sex[0] == 'F') sex = false;
            else if (_sex[0] == 'M') sex = true;
            else {
                cout << "AutoSetting: Male" << endl;
                sex = true;
            }
            cout << "age   :";
            cin >> age;
            current = new Person(sex, age, name, phone, addr);
            book.modPerson(temp, current);
            cout << "Mod success!" << endl;
            system("pause");
            system("cls");
            break;

        case DEL:
            system("cls");
            cout << "name: ";
            getline(cin, name);
            current = book.srchPerson(name);
            if (current == nullptr) cout << "Not exist." << endl;
            else book.remPerson(name);
            system("pause");
            system("cls");
            break;

        case SRCH:
            system("cls");
            cout << "name :";
            getline(cin, name);
            current = book.srchPerson(name);
            if (current == nullptr) cout << "Not exist." << endl;
            else cout << *current << endl;
            system("pause");
            system("cls");
            break;



        case CLR:
            system("cls");
            cout << "Are you sure?[y/n]" << endl;
            cin >> name;
            if (name == "y") book.clrPerson();
            system("cls");
            break;

        default:
            system("cls");
            cout << "Operation not include" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    /*
    MODI: first display person, than rewrite the info, then modiperson
    every time modify remember to save at files. at book function
    */
    /*
    Person *p = new Person(14, 15, "lxl", "123", "sm");
    book.addPerson(*p);
    cout << *book.srchPerson("lxl") << endl;*/
    return 0;
}