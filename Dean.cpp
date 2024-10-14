#include "Dean.h"

void Dean::inputData() {
    Teacher::inputData();
    std::cout << "输入绩效: ";
    std::cin >> performancePay;
}

void Dean::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Teacher::outData(teacherStudentMap);
    std::cout << "绩效: " << performancePay << "\n总收入: " << getIncome() << std::endl;
}

double Dean::getIncome() const {
    return salary + performancePay;
}