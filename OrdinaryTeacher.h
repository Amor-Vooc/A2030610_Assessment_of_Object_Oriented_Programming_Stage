#ifndef ORDINARYTEACHER_H
#define ORDINARYTEACHER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
//#include "Student.h"
#include "Teacher.h"
//#include "Person.h"

//class Teacher;
class Person; // Ç°ÏòÉùÃ÷
class student;

class OrdinaryTeacher : public Teacher {
private:
    double hourlyWage;
    int teachingHours;

public:
    void inputData() override;

    void outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const override;

    double getIncome() const override;
};
#endif