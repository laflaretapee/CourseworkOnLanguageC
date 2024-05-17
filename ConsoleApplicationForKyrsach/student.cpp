#include "student.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

// ������� ��� ���������� ������ �������� � ����� �������
void AddStudent(Student x[], int& n) {
    if (n < MAX_STUDENTS) {
        cout << "������� ��� �����������: ";
        cin >> x[n].fullname.familia >> x[n].fullname.name >> x[n].fullname.otchestvo;
        cout << "������� ����� ��� ���.����� �����������: ";
        cin.ignore();
        getline(cin, x[n].address.city);
        cout << "������� ����� ���������� �����������: ";
        getline(cin, x[n].address.street);
        cout << "������� ��� ���������� �����������: ";
        getline(cin, x[n].address.home);
        cout << "������� ������ �� ����������: ";
        cin >> x[n].marks.math;
        cin.ignore(); // ������� ������� �����
        cout << "������� ������ �� ������: ";
        cin >> x[n].marks.physics;
        cin.ignore(); // ������� ������� �����
        cout << "������� ������ �� �������� �����: ";
        cin >> x[n].marks.russian;
        cin.ignore(); // ������� ������� �����

        n++;
    }
    else {
        cout << "���������� ������������ ���������� ��������� (" << MAX_STUDENTS << ")." << endl;
    }
}

// ������� ��� ������ ���������� � ���������
void OutputStudent(Student x[], int n) {
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| �   |          �.�.�.                  |           �����              | ������ �� ���������� | ������ �� ������ | ������ �� ���.��. | ��.���� |\n";
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

// ������� ��� �������� ������
void DeleteStudent(Student x[], int& n, int index) {
    if (index < 0 || index >= n) {
        cout << "������: ������������ ����� ������." << endl;
        return;
    }

    cout << "�� �������, ��� ������ ������� ��� ������? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        for (int i = index; i < n - 1; ++i) {
            x[i] = x[i + 1];
        }

        n--;
    }
    else {
        cout << "�������� ��������." << endl;
    }
}

void SaveToFile(Student x[], int n) {
    string filename;
    cout << "������� ��� ����� ��� ���������� ������: ";
    cin >> filename;

    ofstream file(filename);
    if (file.is_open()) {
        file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
        file << "| �   |          �.�.�.                  |           �����              | ������ �� ���������� | ������ �� ������ | ������ �� ���.��. | ��.���� |\n";
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

        cout << "������ ������� ��������� � ���� " << filename << endl;
    }
    else {
        cout << "������ ��� �������� ����� " << filename << " ��� ������." << endl;
    }

    file.close();
}

void LoadFromFile(Student x[], int& n, string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        n = 0; // �������������� ���������� ���������

        while (n < MAX_STUDENTS && file >> x[n].fullname.familia >> x[n].fullname.name >> x[n].fullname.otchestvo
            >> x[n].address.city >> x[n].address.street >> x[n].address.home
            >> x[n].marks.math >> x[n].marks.physics >> x[n].marks.russian) {
            n++; // ����������� ���������� ���������
        }

        cout << "������ ������� ��������� �� ����� " << filename << endl;
    }
    else {
        cout << "������ ��� �������� ����� " << filename << " ��� ������." << endl;
    }

    file.close();
}


// ������� ��� ���������� ��������� �� ���
void SortStudentsByName(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.fullname.familia + " " + a.fullname.name + " " + a.fullname.otchestvo) <
            (b.fullname.familia + " " + b.fullname.name + " " + b.fullname.otchestvo);
        });
}

// ������� ��� ���������� ��������� �� �������� �����
void SortStudentsByAverageMarks(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.marks.math + a.marks.physics + a.marks.russian) / 3.0 >
            (b.marks.math + b.marks.physics + b.marks.russian) / 3.0;
        });
}

// ������� ��� ���������� ��������� �� ������� �� ���������
void SortStudentsBySubjectMarks(Student x[], int n, string subject) {
    if (subject == "����������") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.math > b.marks.math;
            });
    }
    else if (subject == "������") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.physics > b.marks.physics;
            });
    }
    else if (subject == "���.��") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.russian > b.marks.russian;
            });
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";
    cout << "| �   |          �.�.�.                  |           �����              | ������ �� " << setw(11) << left << subject << "|\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";

    for (int i = 0; i < n; i++) {
        if (subject == "����������") {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        else {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        cout << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
            << "| " << setw(21) << left;
        if (subject == "����������") {
            cout << x[i].marks.math;
        }
        else if (subject == "������") {
            cout << x[i].marks.physics;
        }
        else if (subject == "���.��") {
            cout << x[i].marks.russian;
        }
        cout << "|\n";
    }
    cout << "+------+----------------------------------+------------------------------+---------------------+\n";
}

void SaveSortedStudentsToFile(Student x[], int n, string subject) {
    // �������� ���� ������� ��� ����������
    SortStudentsBySubjectMarks(x, n, subject);

    // ��������� ���� ��� ������
    ofstream outputFile("output.txt");

    // ��������� �������
    outputFile << "+-----+----------------------------------+------------------------------+----------------------+\n";
    outputFile << "| �   |          �.�.�.                  |           �����              | ������ �� " << setw(11) << left << subject << "|\n";
    outputFile << "+-----+----------------------------------+------------------------------+----------------------+\n";

    // ������� ������ ��������� � ����
    for (int i = 0; i < n; i++) {
        outputFile << "| " << setw(4) << left << i + 1 << "| ";
        outputFile << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
            << "| " << setw(21) << left;
        if (subject == "����������") {
            outputFile << x[i].marks.math;
        }
        else if (subject == "������") {
            outputFile << x[i].marks.physics;
        }
        else if (subject == "���.��") {
            outputFile << x[i].marks.russian;
        }
        outputFile << "|\n";
    }
    outputFile << "+------+----------------------------------+------------------------------+---------------------+\n";

    // ��������� ����
    outputFile.close();
}



// ������� ��� ���������� ��������� �� ��� � �������� �������
void SortStudentsByNameR(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.fullname.familia + " " + a.fullname.name + " " + a.fullname.otchestvo) >
            (b.fullname.familia + " " + b.fullname.name + " " + b.fullname.otchestvo);
        });
}

// ������� ��� ���������� ��������� �� �������� ����� � �������� �������
void SortStudentsByAverageMarksR(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.marks.math + a.marks.physics + a.marks.russian) / 3.0 <
            (b.marks.math + b.marks.physics + b.marks.russian) / 3.0;
        });
}

// ������� ��� ���������� ��������� �� ������� �� ��������� � �������� �������
void SortStudentsBySubjectMarksR(Student x[], int n, string subject) {
    if (subject == "����������") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.math < b.marks.math;
            });
    }
    else if (subject == "������") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.physics < b.marks.physics;
            });
    }
    else if (subject == "���.��") {
        sort(x, x + n, [](const Student& a, const Student& b) {
            return a.marks.russian < b.marks.russian;
            });
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";
    cout << "| �   |          �.�.�.                  |           �����              | ������ �� " << setw(11) << left << subject << "|\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+\n";

    for (int i = 0; i < n; i++) {
        if (subject == "����������") {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        else {
            cout << "| " << setw(4) << left << i + 1 << "| ";
        }
        cout << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
            << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
            << "| " << setw(21) << left;
        if (subject == "����������") {
            cout << x[i].marks.math;
        }
        else if (subject == "������") {
            cout << x[i].marks.physics;
        }
        else if (subject == "���.��") {
            cout << x[i].marks.russian;
        }
        cout << "|\n";
    }
    cout << "+------+----------------------------------+------------------------------+---------------------+\n";
}



void FindStudentsByCity(Student x[], int n, string city) {
    bool found = false;
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| �   |          �.�.�.                  |           �����              | ������ �� ���������� | ������ �� ������ | ������ �� ���.��. | ��.���� |\n";
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
        cout << "�������� �� ���������� ������ �� �������." << endl;
    }
    char saveToFile;
    cout << "��������� ���������� � ����? (y/n): ";
    cin >> saveToFile;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        string filename;
        cout << "������� ��� ����� ��� ���������� ������: ";
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
            file << "| �   |          �.�.�.                  |           �����              | ������ �� ���������� | ������ �� ������ | ������ �� ���.��. | ��.���� |\n";
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
                file << "�������� �� ���������� ������ �� �������." << endl;
            }

            file.close();
            cout << "������ ������� ��������� � ���� " << filename << endl;
        }
        else {
            cout << "������ ��� �������� ����� " << filename << " ��� ������." << endl;
        }
    }
}

// ������� ��� ������ ��������� �� �����
void FindStudentsByStreet(Student x[], int n, string street) {
    bool found = false;

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| �   |          �.�.�.                  |           �����              | ������ �� ���������� | ������ �� ������ | ������ �� ���.��. | ��.���� |\n";
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
        cout << "�������� �� ��������� ����� �� �������." << endl;
    }

    // ���������� � ����
    char saveToFile;
    cout << "��������� ���������� � ����? (y/n): ";
    cin >> saveToFile;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        string filename;
        cout << "������� ��� ����� ��� ���������� ������: ";
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
            file << "| �   |          �.�.�.                  |           �����              | ������ �� ���������� | ������ �� ������ | ������ �� ���.��. | ��.���� |\n";
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
                file << "�������� �� ��������� ����� �� �������." << endl;
            }

            file.close();
            cout << "������ ������� ��������� � ���� " << filename << endl;
        }
        else {
            cout << "������ ��� �������� ����� " << filename << " ��� ������." << endl;
        }
    }
}

void OutputSubjectMarks(Student x[], int n) {
    cout << "+-------------------------------------+-----------+\n";
    cout << "|            �������                  | �������   |\n";
    cout << "|                                     |  ����     |\n";
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

    cout << "| ����������                          | " << setw(10) << left << mathAverage << "|\n";
    cout << "+-------------------------------------+-----------+\n";
    cout << "| ������                              | " << setw(10) << left << physicsAverage << "|\n";
    cout << "+-------------------------------------+-----------+\n";
    cout << "| ������� ����                        | " << setw(10) << left << russianAverage << "|\n";

    cout << "+-------------------------------------+-----------+\n";
    
    char saveToFile;
    cout << "��������� ���������� � ����? (y/n): ";
    cin >> saveToFile;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        string filename;
        cout << "������� ��� ����� ��� ���������� ������: ";
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            file << "+-------------------------------------+-----------+\n";
            file << "|            �������                  | �������   |\n";
            file << "|                                     |  ����     |\n";
            file << "+-------------------------------------+-----------+\n";

            file << "| ����������                          | " << setw(10) << left << mathAverage << "|\n";
            file << "+-------------------------------------+-----------+\n";
            file << "| ������                              | " << setw(10) << left << physicsAverage << "|\n";
            file << "+-------------------------------------+-----------+\n";
            file << "| ������� ����                        | " << setw(10) << left << russianAverage << "|\n";
            file << "+-------------------------------------+-----------+\n";

            file.close();
            cout << "������ ������� ��������� � ���� " << filename << endl;
        }
        else {
            cout << "������ ��� �������� ����� " << filename << " ��� ������." << endl;
        }
    }
}


