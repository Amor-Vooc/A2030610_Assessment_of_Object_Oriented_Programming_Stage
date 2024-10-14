#include "Teacher.h"
#include "Student.h"

void Teacher::inputData() {
    Person::inputData();
    std::cout << "输入教师编号: ";
    std::cin >> teacherID;
    std::cout << "输入教师职称: ";
    std::cin >> title;
    std::cout << "输入教师系别: ";
    std::cin >> department;
    std::cout << "输入教师基本工资: ";
    std::cin >> salary;
}

void Teacher::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Person::outData(teacherStudentMap);
    std::cout << "\n教师编号: " << teacherID << "\n职称: " << title << "\n系别: " << department << "\n基本工资: " << salary << "\n指导的学生: \n";
    auto it = teacherStudentMap.find(const_cast<Teacher*>(this));
    if (it != teacherStudentMap.end()) {
        for (const auto& student : it->second) {
            std::cout << "\t" << student->getName() << "\n";
        }
    }
    else
        std::cout << "\t" << "无" << "\n";
    //std::cout << std::endl;
}

double Teacher::getSalary() const {
    return salary;
}

void Teacher::setSalary(double salary) {
    this->salary = salary;
}

std::ostream& operator<<(std::ostream& os, const Teacher& t) {
    t.outData(std::map<Teacher*, std::vector<Student*>>());
    return os;
}