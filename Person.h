#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
//#include "Teacher.h"
//#include "Student.h"

class Student; // Ç°ÏòÉùÃ÷
class Teacher;

class Person {
protected:
    std::string name;
    int age;
    std::string gender;

public:
    virtual void inputData();

    virtual void outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const;

    virtual ~Person() = default;

    friend std::ostream& operator<<(std::ostream& os, const Person& p);

    const std::string& getName() const;

    int getAge() const;
};

#endif // PERSON_H