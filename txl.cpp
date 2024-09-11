#include <bits/stdc++.h>

using namespace std;

struct Person {
    bool m_sex;
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
       << "Sex  : " << B.m_sex << endl \
       << "Age  : " << B.m_age << endl \
       << "Phone: " << B.m_phone << endl;
    return os;
}

class AddressBooks {
private:
    int m_size;
    priority_queue< Person*, vector<Person*> > pq;
    Person *head;
    Person *cur;

    void search(string name);
public:
    AddressBooks();
    void addPerson(Person& p);
    void srchPerson(string name);
    void remPerson(string name);// panduan 0;
    void clrPerson();
    void displayPerson();
    void modPerson();
};

AddressBooks::AddressBooks() {
    head = new Person(-1, -1, "0", "-1", "-1");
    cur = head;
    m_size = 0;
}

void AddressBooks::addPerson(Person& p) {
    m_size ++;
    pq.push(&p);
    cur->next = &p;
    cur = &p;
}

int main() {
    AddressBooks book;
    Person *p = new Person(14, 15, "lxl", "123", "sm");
    book.addPerson(*p);
    return 0;
}