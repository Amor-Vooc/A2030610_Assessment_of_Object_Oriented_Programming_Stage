#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "Person.h"
//#include "Teacher.h"

class Teacher; // 前向声明
//class Person;

class Student : public Person {
private:
    std::string studentID;
    std::string className;
    double chinese;
    double math;
    double english;
    Teacher* mentor; // 指导老师

public:
    void inputData() override;

    void outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const override;

    void setMentor(Teacher* mentor);

    Teacher* getMentor() const;
};
#endif