#include "Person.h"

void Person::inputData() {
    std::cout << "\n����������: ";
    std::cin >> name;
    std::cout << "����������: ";
    std::cin >> age;
    std::cout << "�������Ա�: ";
    std::cin >> gender;
}

void Person::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    std::cout << "\n==============��ϸ��Ϣ==============" << "\n����: " << name << "\n����: " << age << "\n�Ա�: " << gender;
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