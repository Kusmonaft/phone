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
        cout << "Имя: " << Name << '\n'<< "Домашний: " << Home_num << '\n' << "Рабочий: " << Work_num << '\n' << "Мобильный: " << Mobile_num << '\n' << "Информация об абоненте: " << Info << '\n';
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
        cout << "Меню:\n1. Добавить контакт\n2. Удалить контакт\n3. Искать контакт по имени\n4. Показать контакты\n5. Сохранить контакт в файл\n6. Выход\nВведите выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (numContacts < MAX_SIZE)
            {
                char name[MAX_SIZE], home_num[11], work_num[11], mobile_num[11], info[MAX_SIZE];
                cout << "Введите имя: ";
                cin >> name;
                cout << "Введите домашний: ";
                cin >> home_num;
                cout << "Введите рабочий: ";
                cin >> work_num;
                cout << "Введите мобильный: ";
                cin >> mobile_num;
                cout << "Введите дополнительную информацию: ";
                cin >> info;

                contacts[numContacts] = new Phonebook(name, home_num, work_num, mobile_num, info);
                numContacts++;
            }
            else
            {
                cout << "Телефон переполнен!\n";
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
            cout << "вы вышли из программы\n";
            break;
        default:
            cout << "Ошибка ввода\n";
        }

        for (int i = 0; i < numContacts; i++)
        {
            delete contacts[i];
        }
    } while (choice != '7');


    return 0;
}
