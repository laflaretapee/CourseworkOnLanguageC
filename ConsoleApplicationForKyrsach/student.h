#ifndef STUDENT_H
#define STUDENT_H

#include <string>

const int MAX_STUDENTS = 200;

struct Name {
    std::string name,
        familia,
        otchestvo;
};

struct Marker {
    double math,
        physics,
        russian;
};

struct Address {
    std::string city,
        street,
        home;
};

struct Student {
    Name fullname;
    Marker marks;
    Address address;
};



void AddStudent(Student x[], int& n);
void OutputStudent(Student x[], int n);
void DeleteStudent(Student x[], int& n, int index);
void SaveToFile(Student x[], int n);
void LoadFromFile(Student x[], int& n, std::string filename);
void SortStudentsByName(Student x[], int n);
void SortStudentsByNameR(Student x[], int n);
void SortStudentsByAverageMarks(Student x[], int n);
void SortStudentsByAverageMarksR(Student x[], int n);
void SortStudentsBySubjectMarks(Student x[], int n, std::string subject);
void SortStudentsBySubjectMarksR(Student x[], int n, std::string subject);
void FindStudentsByCity(Student x[], int n, std::string city);
void FindStudentsByStreet(Student x[], int n, std::string street);
void OutputSubjectMarks(Student x[], int n);
void SaveSortedStudentsToFile(Student x[], int n, std::string subject);


#endif
