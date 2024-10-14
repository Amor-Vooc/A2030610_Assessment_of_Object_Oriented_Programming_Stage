#include "Teacher.h"
#include "Student.h"

void Teacher::inputData() {
    Person::inputData();
    std::cout << "�����ʦ���: ";
    std::cin >> teacherID;
    std::cout << "�����ʦְ��: ";
    std::cin >> title;
    std::cout << "�����ʦϵ��: ";
    std::cin >> department;
    std::cout << "�����ʦ��������: ";
    std::cin >> salary;
}

void Teacher::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Person::outData(teacherStudentMap);
    std::cout << "\n��ʦ���: " << teacherID << "\nְ��: " << title << "\nϵ��: " << department << "\n��������: " << salary << "\nָ����ѧ��: \n";
    auto it = teacherStudentMap.find(const_cast<Teacher*>(this));
    if (it != teacherStudentMap.end()) {
        for (const auto& student : it->second) {
            std::cout << "\t" << student->getName() << "\n";
        }
    }
    else
        std::cout << "\t" << "��" << "\n";
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