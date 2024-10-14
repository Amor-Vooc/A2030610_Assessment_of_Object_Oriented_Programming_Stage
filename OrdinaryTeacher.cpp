#include "OrdinaryTeacher.h"

void OrdinaryTeacher::inputData() {
    Teacher::inputData();
    std::cout << "输入课时费: ";
    std::cin >> hourlyWage;
    std::cout << "输入教学时长: ";
    std::cin >> teachingHours;
}

void OrdinaryTeacher::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Teacher::outData(teacherStudentMap);
    std::cout << "课时费: " << hourlyWage << "\n教学时长: " << teachingHours << "\n总收入: " << getIncome() << std::endl;
}

double OrdinaryTeacher::getIncome() const {
    return salary + hourlyWage * teachingHours;
}