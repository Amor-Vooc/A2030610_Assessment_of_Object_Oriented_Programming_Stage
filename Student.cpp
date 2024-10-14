#include "Student.h"
#include "Teacher.h"

void Student::inputData() {
    Person::inputData();
    std::cout << "����ѧ��ѧ��: ";
    std::cin >> studentID;
    std::cout << "����ѧ���༶: ";
    std::cin >> className;
    std::cout << "����ѧ�����ĳɼ�: ";
    std::cin >> chinese;
    std::cout << "����ѧ����ѧ�ɼ�: ";
    std::cin >> math;
    std::cout << "����ѧ��Ӣ��ɼ�: ";
    std::cin >> english;
}

void Student::outData(const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) const {
    Person::outData(std::map<Teacher*, std::vector<Student*>>());
    std::cout << "\nѧ��ѧ��: " << studentID << "\nѧ���༶: " << className << "\nѧ����ʦ: ";
    if (Student::mentor == nullptr)
        std::cout << "��\n";
    else
        std::cout << mentor->getName() << std::endl;
    std::cout << "ѧ�����ĳɼ�: " << chinese << "\nѧ����ѧ�ɼ�: " << math << "\nѧ��Ӣ��ɼ�: " << english << std::endl;
}

void Student::setMentor(Teacher* mentor) {
    this->mentor = mentor;
}

Teacher* Student::getMentor() const {
    return mentor;
}
