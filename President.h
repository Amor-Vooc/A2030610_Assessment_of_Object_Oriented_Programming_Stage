#ifndef PRESIDENT_H
#define PRESIDENT_H

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

class President : public Teacher {
private:
    double annualSalary;

public:
    void inputData() override;

    void outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const override;

    double getIncome() const override;
};

#endif