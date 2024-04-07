#ifndef STUDENTMANAGEMENT_CLASSROOM_H
#define STUDENTMANAGEMENT_CLASSROOM_H

#include <vector>

#include "Student.h"

using std::vector;

class Classroom {
public:
    Classroom();
    void initialize();
    void addStudent(Student);
    void removeStudent(string);
    void getData();
    void viewStudent(string);
    bool isStudentExisted(string);
    void viewStudentsAbove8();
    void writeDataToFile(string);
private:
    vector<Student> studentList;
};

#endif
