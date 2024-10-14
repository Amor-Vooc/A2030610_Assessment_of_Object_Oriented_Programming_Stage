#include "Person.h"

void Person::inputData() {
    std::cout << "\n请输入姓名: ";
    std::cin >> name;
    std::cout << "请输入年龄: ";
    std::cin >> age;
    std::cout << "请输入性别: ";
    std::cin >> gender;
}

void Person::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    std::cout << "\n==============详细信息==============" << "\n姓名: " << name << "\n年龄: " << age << "\n性别: " << gender;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    p.outData(std::map<Teacher*, std::vector<Student*>>());
    return os;
}

const std::string& Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}