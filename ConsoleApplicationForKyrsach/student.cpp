#include "student.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

// Функция для добавления нового студента в конец массива
void AddStudent(Student x[], int& n) {
    if (n < MAX_STUDENTS) {
        cout << "Введите ФИО абитуриента: ";
        cin >> x[n].fullname.familia >> x[n].fullname.name >> x[n].fullname.otchestvo;
        cout << "Введите город или нас.пункт абитуриента: ";
        cin.ignore();
        getline(cin, x[n].address.city);
        cout << "Введите улицу проживания абитуриента: ";
        getline(cin, x[n].address.street);
        cout << "Введите дом проживания абитуриента: ";
        getline(cin, x[n].address.home);
        cout << "Введите оценку по математике: ";
        cin >> x[n].marks.math;
        cin.ignore(); // Очищаем входной буфер
        cout << "Введите оценку по физике: ";
        cin >> x[n].marks.physics;
        cin.ignore(); // Очищаем входной буфер
        cout << "Введите оценку по русскому языку: ";
        cin >> x[n].marks.russian;
        cin.ignore(); // Очищаем входной буфер

        n++;
    }
    else {
        cout << "Достигнуто максимальное количество студентов (" << MAX_STUDENTS << ")." << endl;
    }
}

// Функция для вывода информации о студентах
void OutputStudent(Student x[], int n) {
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << "| " << setw(4) << i + 1 << "| "
                << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                << "| " << setw(21) << left << x[i].marks.math
                << "| " << setw(17) << left << x[i].marks.physics
                << "| " << setw(18) << left << x[i].marks.russian
                << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                << "|\n";
        }
        else {
            cout << "| " << i + 1 << setw(5) << "   | "
                << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                << "| " << setw(21) << left << x[i].marks.math
                << "| " << setw(17) << left << x[i].marks.physics
                << "| " << setw(18) << left << x[i].marks.russian
                << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                << "|\n";
        }
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
}

// Функция для удаления записи
void DeleteStudent(Student x[], int& n, int index) {
    if (index < 0 || index >= n) {
        cout << "Ошибка: Некорректный номер записи." << endl;
        return;
    }

    cout << "Вы уверены, что хотите удалить эту запись? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        for (int i = index; i < n - 1; ++i) {
            x[i] = x[i + 1];
        }

        n--;
    }
    else {
        cout << "Удаление отменено." << endl;
    }
}

void SaveToFile(Student x[], int n) {
    string filename;
    cout << "Введите имя файла для сохранения данных: ";
    cin >> filename;

    ofstream file(filename);
    if (file.is_open()) {
        file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
        file << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
        file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

        for (int i = 0; i < n; i++) {
            if (i < 9) {
                file << "| " << i + 1 << setw(5) << "   | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
            if (i >= 9 && i < 99) {
                file << "| " << i + 1 << setw(4) << "  | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
            if (i > 99) {
                file << "| " << i + 1 << setw(3) << " | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
        }

        file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

        cout << "Данные успешно сохранены в файл " << filename << endl;
    }
    else {
        cout << "Ошибка при открытии файла " << filename << " для записи." << endl;
    }

    file.close();
}

void LoadFromFile(Student x[], int& n, string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        n = 0; // Инициализируем количество студентов

        while (n < MAX_STUDENTS && file >> x[n].fullname.familia >> x[n].fullname.name >> x[n].fullname.otchestvo
            >> x[n].address.city >> x[n].address.street >> x[n].address.home
            >> x[n].marks.math >> x[n].marks.physics >> x[n].marks.russian) {
            n++; // Увеличиваем количество студентов
        }

        cout << "Данные успешно загружены из файла " << filename << endl;
    }
    else {
        cout << "Ошибка при открытии файла " << filename << " для чтения." << endl;
    }

    file.close();
}


// Функция для сортировки студентов по ФИО
void SortStudentsByName(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.fullname.familia + " " + a.fullname.name + " " + a.fullname.otchestvo) <
            (b.fullname.familia + " " + b.fullname.name + " " + b.fullname.otchestvo);
        });
}

// Функция для сортировки студентов по среднему баллу
void SortStudentsByAverageMarks(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.marks.math + a.marks.physics + a.marks.russian) / 3.0 >
            (b.marks.math + b.marks.physics + b.marks.russian) / 3.0;
        });
}

// Функция для сортировки студентов по оценкам по предметам
void SortStudentsBySubjectMarks(Student x[], int n, string subject) {
    if (subject == "математика") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.math > b.marks.math;
            });
    }
    else if (subject == "физика") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.physics > b.marks.physics;
            });
    }
    else if (subject == "рус.яз") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.russian > b.marks.russian;
            });
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по " << setw(11) << left << subject << "|\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";

    for (int i = 0; i < n; i++) {
        if (subject == "математика") {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        else {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        cout << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
            << "| " << setw(21) << left;
        if (subject == "математика") {
            cout << x[i].marks.math;
        }
        else if (subject == "физика") {
            cout << x[i].marks.physics;
        }
        else if (subject == "рус.яз") {
            cout << x[i].marks.russian;
        }
        cout << "|\n";
    }
    cout << "+------+----------------------------------+------------------------------+---------------------+\n";
}

void SaveSortedStudentsToFile(Student x[], int n, string subject) {
    // Вызываем вашу функцию для сортировки
    SortStudentsBySubjectMarks(x, n, subject);

    // Открываем файл для записи
    ofstream outputFile("output.txt");

    // Заголовок таблицы
    outputFile << "+-----+----------------------------------+------------------------------+----------------------+\n";
    outputFile << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по " << setw(11) << left << subject << "|\n";
    outputFile << "+-----+----------------------------------+------------------------------+----------------------+\n";

    // Выводим данные студентов в файл
    for (int i = 0; i < n; i++) {
        outputFile << "| " << setw(4) << left << i + 1 << "| ";
        outputFile << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
            << "| " << setw(21) << left;
        if (subject == "математика") {
            outputFile << x[i].marks.math;
        }
        else if (subject == "физика") {
            outputFile << x[i].marks.physics;
        }
        else if (subject == "рус.яз") {
            outputFile << x[i].marks.russian;
        }
        outputFile << "|\n";
    }
    outputFile << "+------+----------------------------------+------------------------------+---------------------+\n";

    // Закрываем файл
    outputFile.close();
}



// Функция для сортировки студентов по ФИО в обратном порядке
void SortStudentsByNameR(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.fullname.familia + " " + a.fullname.name + " " + a.fullname.otchestvo) >
            (b.fullname.familia + " " + b.fullname.name + " " + b.fullname.otchestvo);
        });
}

// Функция для сортировки студентов по среднему баллу в обратном порядке
void SortStudentsByAverageMarksR(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.marks.math + a.marks.physics + a.marks.russian) / 3.0 <
            (b.marks.math + b.marks.physics + b.marks.russian) / 3.0;
        });
}

// Функция для сортировки студентов по оценкам по предметам в обратном порядке
void SortStudentsBySubjectMarksR(Student x[], int n, string subject) {
    if (subject == "математика") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.math < b.marks.math;
            });
    }
    else if (subject == "физика") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.physics < b.marks.physics;
            });
    }
    else if (subject == "рус.яз") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.russian < b.marks.russian;
            });
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по " << setw(11) << left << subject << "|\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";

    for (int i = 0; i < n; i++) {
        if (subject == "математика") {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        else {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        cout << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
            << "| " << setw(21) << left;
        if (subject == "математика") {
            cout << x[i].marks.math;
        }
        else if (subject == "физика") {
            cout << x[i].marks.physics;
        }
        else if (subject == "рус.яз") {
            cout << x[i].marks.russian;
        }
        cout << "|\n";
    }
    cout << "+------+----------------------------------+------------------------------+---------------------+\n";
}



void FindStudentsByCity(Student x[], int n, string city) {
    bool found = false;
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    for (int i = 0; i < n; i++) {
        if (x[i].address.city == city) {
            found = true;
            if (i > 0) {
                cout << "| " << setw(4) << i + 1 << "| "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
            else {
                cout << "| " << i + 1 << setw(5) << "   | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
        }
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    if (!found) {
        cout << "Студенты из указанного города не найдены." << endl;
    }
    char saveToFile;
    cout << "Сохранить результаты в файл? (y/n): ";
    cin >> saveToFile;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        string filename;
        cout << "Введите имя файла для сохранения данных: ";
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
            file << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

            for (int i = 0; i < n; i++) {
                if (x[i].address.city == city) {
                    if (i > 0) {
                        file << "| " << setw(4) << i + 1 << "| "
                            << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                            << "| " << setw(21) << left << x[i].marks.math
                            << "| " << setw(17) << left << x[i].marks.physics
                            << "| " << setw(18) << left << x[i].marks.russian
                            << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                            << "|\n";
                    }
                    else {
                        file << "| " << i + 1 << setw(5) << "   | "
                            << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                            << "| " << setw(21) << left << x[i].marks.math
                            << "| " << setw(17) << left << x[i].marks.physics
                            << "| " << setw(18) << left << x[i].marks.russian
                            << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                            << "|\n";
                    }
                }
            }

            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

            if (!found) {
                file << "Студенты из указанного города не найдены." << endl;
            }

            file.close();
            cout << "Данные успешно сохранены в файл " << filename << endl;
        }
        else {
            cout << "Ошибка при открытии файла " << filename << " для записи." << endl;
        }
    }
}

// Функция для поиска студентов по улице
void FindStudentsByStreet(Student x[], int n, string street) {
    bool found = false;

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    for (int i = 0; i < n; i++) {
        if (x[i].address.street == street) {
            found = true;
            if (i > 0) {
                cout << "| " << setw(4) << i + 1 << "| "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
            else {
                cout << "| " << i + 1 << setw(5) << "   | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
        }
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    if (!found) {
        cout << "Студенты из указанной улицы не найдены." << endl;
    }

    // Сохранение в файл
    char saveToFile;
    cout << "Сохранить результаты в файл? (y/n): ";
    cin >> saveToFile;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        string filename;
        cout << "Введите имя файла для сохранения данных: ";
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
            file << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

            for (int i = 0; i < n; i++) {
                if (x[i].address.street == street) {
                    if (i > 0) {
                        file << "| " << setw(4) << i + 1 << "| "
                            << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                            << "| " << setw(21) << left << x[i].marks.math
                            << "| " << setw(17) << left << x[i].marks.physics
                            << "| " << setw(18) << left << x[i].marks.russian
                            << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                            << "|\n";
                    }
                    else {
                        file << "| " << i + 1 << setw(5) << "   | "
                            << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                            << "| " << setw(21) << left << x[i].marks.math
                            << "| " << setw(17) << left << x[i].marks.physics
                            << "| " << setw(18) << left << x[i].marks.russian
                            << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                            << "|\n";
                    }
                }
            }

            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

            if (!found) {
                file << "Студенты из указанной улицы не найдены." << endl;
            }

            file.close();
            cout << "Данные успешно сохранены в файл " << filename << endl;
        }
        else {
            cout << "Ошибка при открытии файла " << filename << " для записи." << endl;
        }
    }
}

void OutputSubjectMarks(Student x[], int n) {
    cout << "+-------------------------------------+-----------+\n";
    cout << "|            Предмет                  | Средний   |\n";
    cout << "|                                     |  балл     |\n";
    cout << "+-------------------------------------+-----------+\n";

    double mathSum = 0, physicsSum = 0, russianSum = 0;

    for (int i = 0; i < n; i++) {
        mathSum += x[i].marks.math;
        physicsSum += x[i].marks.physics;
        russianSum += x[i].marks.russian;
    }

    double mathAverage = mathSum / n;
    double physicsAverage = physicsSum / n;
    double russianAverage = russianSum / n;

    cout << "| Математика                          | " << setw(10) << left << mathAverage << "|\n";
    cout << "+-------------------------------------+-----------+\n";
    cout << "| Физика                              | " << setw(10) << left << physicsAverage << "|\n";
    cout << "+-------------------------------------+-----------+\n";
    cout << "| Русский язык                        | " << setw(10) << left << russianAverage << "|\n";

    cout << "+-------------------------------------+-----------+\n";
    
    char saveToFile;
    cout << "Сохранить результаты в файл? (y/n): ";
    cin >> saveToFile;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        string filename;
        cout << "Введите имя файла для сохранения данных: ";
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            file << "+-------------------------------------+-----------+\n";
            file << "|            Предмет                  | Средний   |\n";
            file << "|                                     |  балл     |\n";
            file << "+-------------------------------------+-----------+\n";

            file << "| Математика                          | " << setw(10) << left << mathAverage << "|\n";
            file << "+-------------------------------------+-----------+\n";
            file << "| Физика                              | " << setw(10) << left << physicsAverage << "|\n";
            file << "+-------------------------------------+-----------+\n";
            file << "| Русский язык                        | " << setw(10) << left << russianAverage << "|\n";
            file << "+-------------------------------------+-----------+\n";

            file.close();
            cout << "Данные успешно сохранены в файл " << filename << endl;
        }
        else {
            cout << "Ошибка при открытии файла " << filename << " для записи." << endl;
        }
    }
}


