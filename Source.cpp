#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_SIZE = 100;

class Phonebook 
{
private:
    char* Name;
    char Home_num[11];
    char Work_num[11];
    char Mobile_num[11];
    char Info[MAX_SIZE];
public:
    Phonebook(const char* name, const char* home_num, const char* work_num, const char* mobile_num, const char* info)
    {
        Name = new char[strlen(name) + 1];
        strcpy_s(Name, strlen(name) + 1, name);
        strcpy_s(Home_num, strlen(home_num) + 1, home_num);
        strcpy_s(Work_num, strlen(work_num) + 1, work_num);
        strcpy_s(Mobile_num, strlen(mobile_num) + 1, mobile_num);
        strcpy_s(Info, strlen(info) + 1, info);
    }
    ~Phonebook()
    {
        delete[] Name;
    }

    void display()
    {
        cout << "���: " << Name << '\n'<< "��������: " << Home_num << '\n' << "�������: " << Work_num << '\n' << "���������: " << Mobile_num << '\n' << "���������� �� ��������: " << Info << '\n';
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");

    Phonebook* contacts[MAX_SIZE];

    enum { CIN = 1, DELET = 2 };
    int numContacts = 0;
    char choice;
    do
    {
        cout << "����:\n1. �������� �������\n2. ������� �������\n3. ������ ������� �� �����\n4. �������� ��������\n5. ��������� ������� � ����\n6. �����\n������� �����: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (numContacts < MAX_SIZE)
            {
                char name[MAX_SIZE], home_num[11], work_num[11], mobile_num[11], info[MAX_SIZE];
                cout << "������� ���: ";
                cin >> name;
                cout << "������� ��������: ";
                cin >> home_num;
                cout << "������� �������: ";
                cin >> work_num;
                cout << "������� ���������: ";
                cin >> mobile_num;
                cout << "������� �������������� ����������: ";
                cin >> info;

                contacts[numContacts] = new Phonebook(name, home_num, work_num, mobile_num, info);
                numContacts++;
            }
            else
            {
                cout << "������� ����������!\n";
            }
            break;
        case 2:
            Phonebook::~Phonebook()
            {

                if (name != nullptr)
                {
                    delete name;
                }

                if (work_num != nullptr)
                {
                    delete work_num;
                }
                if (home_num != nullptr)
                {
                    delete home_num;
                }
                if (mobile_num != nullptr)
                {
                    delete mobile_num;
                }
                if (info != nullptr)
                {
                    delete info;
                }

            }
            break;
        case 3:

            break;
        case 4:
            for (int i = 0; i < numContacts; i++)
            {
                contacts[i]->display();
            }
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            cout << "�� ����� �� ���������\n";
            break;
        default:
            cout << "������ �����\n";
        }

        for (int i = 0; i < numContacts; i++)
        {
            delete contacts[i];
        }
    } while (choice != '7');


    return 0;
}
