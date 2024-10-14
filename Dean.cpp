#include "Dean.h"

void Dean::inputData() {
    Teacher::inputData();
    std::cout << "���뼨Ч: ";
    std::cin >> performancePay;
}

void Dean::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Teacher::outData(teacherStudentMap);
    std::cout << "��Ч: " << performancePay << "\n������: " << getIncome() << std::endl;
}

double Dean::getIncome() const {
    return salary + performancePay;
}