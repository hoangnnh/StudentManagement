#ifndef STUDENTMANAGEMENT_STUDENT_H
#define STUDENTMANAGEMENT_STUDENT_H

#include <string>

using std::string;

class Student {
public:
    Student();
    Student(string, string, string, float);

    string getName();
    string getId();
    string getPhoneNumber();
    float getAvgPoint();

    void getData();
    void inputData();

    bool isValidName(string);
    bool isValidId(string);
    bool isValidPhoneNumber(string);
    bool isValidAvgPoint(float);
    void checkAndHandleError();
private:
    string name;
    string id;
    string phoneNumber;
    float avgPoint;
};


#endif
