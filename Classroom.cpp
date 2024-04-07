#include "Classroom.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::fstream;


void Classroom::initialize() {
    Student s1 = Student("Nguyen Van A", "23520000", "0908070605", 8.1);
    studentList.push_back(s1);
    Student s2 = Student("Le Thi B", "23520001", "0123456789", 6.5);
    studentList.push_back(s2);
    Student s3 = Student("Tran Van C", "23520002", "0234567890", 8.6);
    studentList.push_back(s3);
    Student s4 = Student("Do Thi D", "23520003", "0345678901", 7.8);
    studentList.push_back(s4);
    Student s5 = Student("Ho Van E", "23520004", "0456789012", 9.5);
    studentList.push_back(s5);
}

Classroom::Classroom() {
    initialize();
}

void Classroom::addStudent(Student s) {
    if (isStudentExisted(s.getName())) {
        cout << "Da co hoc sinh trong lop" << endl;
    } else {
        studentList.push_back(s);
        cout << "Da them hoc sinh moi." << endl;
    }
}

void Classroom::removeStudent(string name) {
    for (size_t i = 0; i < studentList.size(); i++) {
        if (name.compare(studentList[i].getName()) == 0) {
            studentList.erase(studentList.begin() + i);
            cout << "Da xoa thanh cong hoc sinh." << name << "." << endl;
            break;
        }

        if (i == studentList.size() - 1) {
            cout << "Khong tim thay hoc sinh " << name << " de xoa." << endl;
        }
    }
}

bool Classroom::isStudentExisted(string name) {
    for (size_t i = 0; i < studentList.size(); i++) {
        if (name.compare(studentList[i].getName()) == 0) {
            return true;
        }
    }

    return false;
}

void Classroom::viewStudent(string name) {
    for (size_t i = 0; i < studentList.size(); i++) {
        if (name.compare(studentList[i].getName()) == 0) {
            studentList[i].getData();
            break;
        }
    }
    if (!isStudentExisted(name)) {
        cout << "Hoc sinh " << name << " chua co trong lop." << endl;
    }
}

void Classroom::getData() {
    for (size_t i = 0; i < studentList.size(); i++) {
        studentList[i].getData();
    }
}

void Classroom::viewStudentsAbove8() {
    for (size_t i = 0; i < studentList.size(); i++) {
        if (studentList[i].getAvgPoint() >= 8.0) {
            studentList[i].getData();
        }
    }
}

void Classroom::writeDataToFile(string fileName) {
    fstream myFile;
    myFile.open(fileName);

    if (myFile.is_open()) {
        myFile << studentList.size() << endl;
        for (size_t i = 0; i < studentList.size(); i++) {
            Student data = studentList[i];
            myFile << data.getName() << endl;
            myFile << data.getId() << endl;
            myFile << data.getPhoneNumber() << endl;
            myFile << data.getAvgPoint() << endl;
        }
        cout << "Viet vao file thanh cong.\n";
    } else {
        cout << "Mo file khong thanh cong.\n";
    }

    myFile.close();
}