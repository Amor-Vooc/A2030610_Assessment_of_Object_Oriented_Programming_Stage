#include "President.h"

void President::inputData() {
    Teacher::inputData();
    std::cout << "������н: ";
    std::cin >> annualSalary;
}

void President::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Teacher::outData(teacherStudentMap);
    std::cout << "��н: " << annualSalary << "\n������: " << getIncome() << std::endl;
}

double President::getIncome() const {
    return salary + annualSalary / 12;
}