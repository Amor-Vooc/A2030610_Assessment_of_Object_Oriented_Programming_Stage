#include "OrdinaryTeacher.h"

void OrdinaryTeacher::inputData() {
    Teacher::inputData();
    std::cout << "�����ʱ��: ";
    std::cin >> hourlyWage;
    std::cout << "�����ѧʱ��: ";
    std::cin >> teachingHours;
}

void OrdinaryTeacher::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Teacher::outData(teacherStudentMap);
    std::cout << "��ʱ��: " << hourlyWage << "\n��ѧʱ��: " << teachingHours << "\n������: " << getIncome() << std::endl;
}

double OrdinaryTeacher::getIncome() const {
    return salary + hourlyWage * teachingHours;
}