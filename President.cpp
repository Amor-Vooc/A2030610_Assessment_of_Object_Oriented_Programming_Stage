#include "President.h"

void President::inputData() {
    Teacher::inputData();
    std::cout << "输入年薪: ";
    std::cin >> annualSalary;
}

void President::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Teacher::outData(teacherStudentMap);
    std::cout << "年薪: " << annualSalary << "\n总收入: " << getIncome() << std::endl;
}

double President::getIncome() const {
    return salary + annualSalary / 12;
}