#include "Student.h"

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

Student::Student() {

}

Student::Student(string name, string id, string phoneNumber, float avgPoint) {
    this->name = name;
    this->id = id;
    this->phoneNumber = phoneNumber;
    this->avgPoint = avgPoint;
}


void Student::checkAndHandleError() {
    if (!isValidName(name)) {
        cout << "Ten khong hop le.\n";
        inputData();
        return;
    }
    if (!isValidId(id)) {
        cout << "MSSV khong hop le.\n";
        inputData();
        return;
    }
    if (!isValidPhoneNumber(phoneNumber)) {
        cout << "SDT khong hop le.\n";
        return;
    }
    if (!isValidAvgPoint(avgPoint)) {
        cout << "Diem trung binh khong hop le.\n";
        return;
    }
}

void Student::getData() {
    cout << name << endl;
    cout << id << endl;
    cout << phoneNumber << endl;
    cout << avgPoint << endl;
}

void Student::inputData() {
    cout << "Nhap thong tin cho hoc sinh moi: " << endl;
    cout << "Ho ten: ";
    getline(cin, name);
    cout << "MSSV: ";
    getline(cin, id);
    cout << "SDT: ";
    getline(cin, phoneNumber);
    cout << "Diem trung binh: ";
    cin >> avgPoint;

    cin.ignore();

    checkAndHandleError();
}

string Student::getName() {
    return name;
}

string Student::getId() {
    return id;
}

string Student::getPhoneNumber() {
    return phoneNumber;
}

float Student::getAvgPoint() {
    return avgPoint;
}

bool Student::isValidName(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (!isalpha(s[i]) && s[i] != ' ') {
            return false;
        }
    }

    return true;
}

bool Student::isValidId(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }

    return true;
}

bool Student::isValidPhoneNumber(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

bool Student::isValidAvgPoint(float p) {
    if (p >= 0.0 && p <= 10.0) {
        return true;
    }

    return false;
}