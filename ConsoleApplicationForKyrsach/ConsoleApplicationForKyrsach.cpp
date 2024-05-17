#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student studentList[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    char addMore;
    string loadFilename; // Переменная объявлена здесь
    string city, street, home, subject;
    int searchChoice;
    string saveFilename;

    do {
        cout << "Меню:" << endl;
        cout << "(1)Ввести данные абитуриента" << endl;
        cout << "(2)Вывести данные абитуриентов в виде таблицы" << endl;
        cout << "(3)Удалить запись" << endl;
        cout << "(4)Сохранить данные в файл" << endl;
        cout << "(5)Загрузить данные из файла" << endl;
        cout << "(6)Сортировка по ФИО" << endl;
        cout << "(7)Сортировка по среднему баллу" << endl;
        cout << "(8)Сортировка по оценкам по предметам" << endl;
        cout << "(9)Поиск по адресу" << endl;
        cout << "(10)Перечень предметов с указанием среднего балла" << endl;
        cout << "(0)Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            do {
                AddStudent(studentList, studentCount);
                cout << "Добавить еще абитуриента? (y/n): ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            OutputStudent(studentList, studentCount);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            int index;
            OutputStudent(studentList, studentCount);
            cout << "Введите номер записи для удаления(общее количество записей " << studentCount << "):";
            cin >> index;
            DeleteStudent(studentList, studentCount, index - 1);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            SaveToFile(studentList, studentCount);
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Введите имя файла для загрузки данных: ";
            cin >> loadFilename;
            LoadFromFile(studentList, studentCount, loadFilename);
            break;
        case 6:
            system("cls");
            cout << "Выберите порядок сортировки:" << endl;
            cout << "1. Прямой порядок" << endl;
            cout << "2. Обратный порядок" << endl;
            cout << "Введите ваш выбор: ";
            cin >> choice;
            switch (choice) {
            case 1:
                SortStudentsByName(studentList, studentCount);
                cout << "Студенты отсортированы по ФИО в прямом порядке." << endl;
                break;
            case 2:
                SortStudentsByNameR(studentList, studentCount);
                cout << "Студенты отсортированы по ФИО в обратном порядке." << endl;
                break;
            default:
                cout << "Некорректный ввод. Повторите попытку." << endl;
                break;
            }
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            cout << "Выберите порядок сортировки:" << endl;
            cout << "1. Прямой порядок" << endl;
            cout << "2. Обратный порядок" << endl;
            cout << "Введите ваш выбор: ";
            cin >> choice;
            switch (choice) {
            case 1:
                SortStudentsByAverageMarks(studentList, studentCount);
                cout << "Студенты отсортированы по среднему баллу в прямом порядке." << endl;
                break;
            case 2:
                SortStudentsByAverageMarksR(studentList, studentCount);
                cout << "Студенты отсортированы по среднему баллу в обратном порядке." << endl;
                break;
            default:
                cout << "Некорректный ввод. Повторите попытку." << endl;
                break;
            }
            system("pause");
            system("cls");
            break;
        case 8:
        {
            system("cls");
            cout << "Выберите порядок сортировки:" << endl;
            cout << "1. Прямой порядок" << endl;
            cout << "2. Обратный порядок" << endl;
            cout << "Введите ваш выбор: ";
            cin >> choice;
            switch (choice) {
            case 1:
            {
                string subject;
                cout << "Выберите предмет для сортировки (математика, физика и рус.яз): ";
                cin >> subject;
                SortStudentsBySubjectMarks(studentList, studentCount, subject);
                cout << "Студенты отсортированы по оценкам по предмету " << subject << " в прямом порядке." << endl;
                break;
            }
            case 2:
            {
                string subject;
                cout << "Введите предмет для сортировки (математика, физика, рус.яз): ";
                cin >> subject;
                SortStudentsBySubjectMarksR(studentList, studentCount, subject);
                cout << "Студенты отсортированы по оценкам по предмету " << subject << " в обратном порядке." << endl;
                break;
            }
            default:
                cout << "Некорректный ввод. Повторите попытку." << endl;
                break;
            }
            // Save sorted data to file
            cout << "Сохранить отсортированные данные в файл? (y/n): ";
            char saveToFile;
            cin >> saveToFile;
            if (saveToFile == 'y' || saveToFile == 'Y') {
                SaveToFile(studentList, studentCount); // Pass the filename here
            }
            system("pause");
            system("cls");
            break;
        }


        case 9:
            do {
                system("cls");
                
                cout << "Поиск:" << endl;
                cout << "(1)По городу" << endl;
                cout << "(2)По улице" << endl;
                cout << "Выберите метод поиска: ";
                cin >> searchChoice;

                // Проверяем, успешно ли произошло считывание числа
                if (cin.fail()) {
                    cout << "Некорректный ввод. Повторите попытку." << endl;
                    cin.clear();
                    continue;
                }

                // Очищаем буфер ввода
                cin.ignore();

                switch (searchChoice) {
                case 1:
                    cout << "Введите город: ";
                    getline(cin, city);
                    FindStudentsByCity(studentList, studentCount, city);
                    break;
                case 2:
                    cout << "Введите улицу: ";
                    getline(cin, street);
                    FindStudentsByStreet(studentList, studentCount, street);
                    
                    break;
                default:
                    cout << "Некорректный ввод. Повторите попытку." << endl;
                }
            } while (searchChoice != 1 && searchChoice != 2);
            system("pause");
            system("cls");
            break;
        case 10:
            system("cls");
            OutputSubjectMarks(studentList, studentCount);
            system("pause");
            system("cls");
            break;

        case 11:
            system("cls");
            SaveSortedStudentsToFile(studentList, studentCount, subject);
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный ввод. Повторите попытку." << endl;
        }
    } while (choice != 0);

    return 0;
}
