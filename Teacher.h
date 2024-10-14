#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
//#include "Student.h"
#include "Person.h"

class Student; // 前向声明
//class Person;

class Teacher : public Person {
protected:
    std::string teacherID;
    std::string title;
    std::string department;
    double salary;

public:
    void inputData() override;

    void outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const override;

    virtual double getSalary() const;

    virtual void setSalary(double salary);

    virtual double getIncome() const = 0; // 纯虚函数

    friend std::ostream& operator<<(std::ostream& os, const Teacher& t);
};
#endif