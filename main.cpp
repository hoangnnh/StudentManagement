#include <iostream>
#include <string>

#include "Classroom.h"
#include "Student.h"

using namespace std;

void separate() {
    cout << "-------------------------------" << endl;
}


int main() {
    Classroom myClass = Classroom();

    bool running = true;
    while (running) {
        cout << "1. Them hoc sinh vao lop." << endl;
        cout << "2. Xem thong tin cua mot hoc sinh trong lop." << endl;
        cout << "3: Kiem tra hoc sinh da co trong lop hay chua." << endl;
        cout << "4. Xem thong tin tat ca hoc sinh trong lop." << endl;
        cout << "5. Xoa mot hoc sinh khoi danh sanh lop." << endl;
        cout << "6. Xem thong tin tat co hoc sinh co diem trung > 8." << endl;
        cout << "0. Thoat chuong trinh va viet vao file." << endl;
        cout << "Nhap thao tac muon thuc hien (0-6): ";

        int operation;
        cin >> operation;

        cin.ignore();

        separate();

        Student s;
        string name;
        bool existed;

        switch (operation) {
            case 0:
                running = false;
                break;

            case 1:
                s.inputData();
                myClass.addStudent(s);
                separate();
                break;

            case 2:
                cout << "Nhap ten hoc sinh: ";
                getline(cin, name);

                myClass.viewStudent(name);
                separate();

                break;

            case 3:
                cout << "Nhap ten hoc sinh: ";
                getline(cin, name);

                existed = myClass.isStudentExisted(name);
                if (existed) {
                    cout << "Hoc sinh " << name << " da co trong lop." << endl;
                } else {
                    cout << "Hoc sinh " << name << " chua co trong lop." << endl;
                }

                separate();

                break;

            case 4:
                myClass.getData();
                break;

            case 5:
                cout << "Nhap ten hoc sinh: ";
                getline(cin, name);

                myClass.removeStudent(name);
                break;

            case 6:
                myClass.viewStudentsAbove8();
                break;

            default:
                running = false;
                break;

        }
    }

    myClass.writeDataToFile("./LopHoc.txt");

    return 0;
}