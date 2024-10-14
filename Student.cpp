#include "Student.h"
#include "Teacher.h"

void Student::inputData() {
    Person::inputData();
    std::cout << "输入学生学号: ";
    std::cin >> studentID;
    std::cout << "输入学生班级: ";
    std::cin >> className;
    std::cout << "输入学生语文成绩: ";
    std::cin >> chinese;
    std::cout << "输入学生数学成绩: ";
    std::cin >> math;
    std::cout << "输入学生英语成绩: ";
    std::cin >> english;
}

void Student::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Person::outData(std::map<Teacher*, std::vector<Student*>>());
    std::cout << "\n学生学号: " << studentID << "\n学生班级: " << className << "\n学生导师: ";
    if (Student::mentor == nullptr)
        std::cout << "无\n";
    else
        std::cout << mentor->getName() << std::endl;
    std::cout << "学生语文成绩: " << chinese << "\n学生数学成绩: " << math << "\n学生英语成绩: " << english << std::endl;
}

void Student::setMentor(Teacher* mentor) {
    this->mentor = mentor;
}

Teacher* Student::getMentor() const {
    return mentor;
}
