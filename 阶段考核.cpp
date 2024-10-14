#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "OrdinaryTeacher.h"
#include"Dean.h"
#include "President.h"

//class Teacher; // 前向声明

//class Student;


void displayMenu() { // 显示操作菜单
    std::cout << "\n=========通过数字选择操作:=========" << std::endl;
    std::cout << "1. 添加人员 (学生/教师)" << std::endl;
    std::cout << "2. 显示所有成员" << std::endl;
    std::cout << "3. 通过姓名查询人员" << std::endl;
    std::cout << "4. 通过姓名删除人员" << std::endl;
    std::cout << "5. 管理学生的导师" << std::endl;
    std::cout << "6. 管理导师的学生" << std::endl;
    std::cout << "7. 同类对象按年龄排序" << std::endl;
    std::cout << "8. 退出" << std::endl;
    std::cout << "===================================\n" << std::endl;
}

void addPerson(std::vector<Person*>& persons, std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) { // 1 号操作菜单
    int choice;
    std::cout << "\n选择添加人员的种类:" << std::endl;
    std::cout << "1. 普通教师" << std::endl;
    std::cout << "2. 系主任" << std::endl;
    std::cout << "3. 院长" << std::endl;
    std::cout << "4. 学生\n" << std::endl;
    std::cin >> choice;

    Person* person = nullptr;
    Teacher* teacher = nullptr;

    switch (choice) {
    case 1:
        teacher = new OrdinaryTeacher();
        teacher->inputData();
        person = teacher;
        break;
    case 2:
        teacher = new Dean();
        teacher->inputData();
        person = teacher;
        break;
    case 3:
        teacher = new President();
        teacher->inputData();
        person = teacher;
        break;
    case 4:
        person = new Student();
        person->inputData();
        break;
    default:
        std::cout << "\n非法选项！" << std::endl;
        return;
    }

    if (person) {
        persons.push_back(person);
        if (auto* student = dynamic_cast<Student*>(person)) {
            Teacher* mentor = nullptr;
            std::string mentorName;
            std::cout << "输入学生导师姓名: ";
            std::cin >> mentorName;
            for (auto* p : persons) {
                auto* t = dynamic_cast<Teacher*>(p);
                if ( t && t->getName() == mentorName) {
                    mentor = t;
                    break;
                }
            }
            if (mentor) {
                student->setMentor(mentor);
                teacherStudentMap[mentor].push_back(student);
            }
            else {
                std::cout << "\n没有找到该导师!" << std::endl;
            }
        }
    }
}

void displayAllPersons(const std::vector<Person*>& persons, const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) {
    for (const auto& person : persons) {
        //std::cout << *person << std::endl;
        person->outData(teacherStudentMap);
    }
}

void queryPersonByName(const std::vector<Person*>& persons, const std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) {
    std::string name;
    std::cout << "\n输入需要查询的人员姓名: ";
    std::cin >> name;

    for (const auto& person : persons) {
        if (person->getName() == name) {
            //std::cout << *person << std::endl;
            person->outData(teacherStudentMap);
            return;
        }
    }

    std::cout << "\n没有找到该人员!" << std::endl;
}

void deletePersonByName(std::vector<Person*>& persons, std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) {
    std::string name;
    std::cout << "\n输入需要删除的人员姓名: ";
    std::cin >> name;

    for (auto it = persons.begin(); it != persons.end(); ++it) {
        if ((*it)->getName() == name) {
            if (auto* teacher = dynamic_cast<Teacher*>(*it)) {
                auto& students = teacherStudentMap[teacher];
                for (auto* student : students) {
                    student->setMentor(nullptr);
                }
                teacherStudentMap.erase(teacher);
            }
            else if (auto* student = dynamic_cast<Student*>(*it)) {
                Teacher* mentor = student->getMentor();
                if (mentor) {
                    auto& students = teacherStudentMap[mentor];
                    students.erase(std::remove(students.begin(), students.end(), student), students.end());
                }
            }
            delete* it;
            persons.erase(it);
            std::cout << "\n人员已删除." << std::endl;
            return;
        }
    }

    std::cout << "\n没有找到该人员!" << std::endl;
}

void manageStudentMentor(std::vector<Person*>& persons, std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) {
    std::string studentName;
    std::cout << "\n输入学生姓名: ";
    std::cin >> studentName;

    Student* student = nullptr;
    for (auto* person : persons) {
        auto* s = dynamic_cast<Student*>(person);
        if ( s && s->getName() == studentName) {
            student = s;
            break;
        }
    }

    if (!student) {
        std::cout << "\n没有找到该学生!" << std::endl;
        return;
    }

    std::cout << "\n1. 添加导师" << std::endl;
    std::cout << "2. 变更导师" << std::endl;
    std::cout << "3. 移除导师\n" << std::endl;
    int choice;
    std::cin >> choice;

    std::string mentorName;
    Teacher* mentor = nullptr;

    switch (choice) {
    case 1:
        if (student->getMentor()) {
            std::cout << "\n学生已有导师，不允许继续添加！请使用变更导师选项." << std::endl; // 按题目要求一个学生只能有一个指导老师
            break;
        }
    case 2:
        std::cout << "\n输入导师姓名: ";
        std::cin >> mentorName;
        for (auto* person : persons) {
            auto* t = dynamic_cast<Teacher*>(person);
            if ( t && t->getName() == mentorName) {
                mentor = t;
                break;
            }
        }
        if (!mentor) {
            std::cout << "\n没有找到该导师!" << std::endl;
            return;
        }
        if (choice == 2 && student->getMentor()) {
            auto& oldStudents = teacherStudentMap[student->getMentor()];
            oldStudents.erase(std::remove(oldStudents.begin(), oldStudents.end(), student), oldStudents.end());
        }
        student->setMentor(mentor);
        teacherStudentMap[mentor].push_back(student);
        std::cout << "\n导师 " << (choice == 1 ? "已添加." : "已修改.") << std::endl;
        break;
    case 3:
        if (auto* currentMentor = student->getMentor()) {
            auto& students = teacherStudentMap[currentMentor];
            students.erase(std::remove(students.begin(), students.end(), student), students.end());
            student->setMentor(nullptr);
            std::cout << "\n导师已移除." << std::endl;
        }
        else {
            std::cout << "\n该学生没有导师." << std::endl;
        }
        break;
    default:
        std::cout << "\n非法选项!" << std::endl;
        break;
    }
}

void manageTeachersStudents(std::vector<Person*>& persons, std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) {
    std::string teacherName;
    std::cout << "\n输入导师姓名: ";
    std::cin >> teacherName;

    Teacher* teacher = nullptr;
    for (auto* person : persons) {
        auto* t = dynamic_cast<Teacher*>(person);
        if ( t && t->getName() == teacherName) {
            teacher = t;
            break;
        }
    }

    if (!teacher) {
        std::cout << "\n没有找到该导师!" << std::endl;
        return;
    }

    std::cout << "\n1. 添加学生" << std::endl;
    std::cout << "2. 移除学生\n" << std::endl;
    int choice;
    std::cin >> choice;

    std::string studentName;
    Student* student = nullptr;

    switch (choice) {
    case 1:
        std::cout << "\n输入学生姓名: ";
        std::cin >> studentName;
        for (auto* person : persons) {
            auto* s = dynamic_cast<Student*>(person);
            if ( s && s->getName() == studentName) {
                student = s;
                break;
            }
        }
        if (!student) {
            std::cout << "\n没有找到该学生!" << std::endl;
            return;
        }
        if (student->getMentor()) { // 题目要求一个学生只能一个导师，如果学生已有导师，就更新导师信息 
            auto& oldStudents = teacherStudentMap[student->getMentor()];
            std::cout << "\n学生已有导师，已将该学生导师信息更新." << std::endl;
            oldStudents.erase(std::remove(oldStudents.begin(), oldStudents.end(), student), oldStudents.end());
        }
        student->setMentor(teacher);
        teacherStudentMap[teacher].push_back(student);
        std::cout << "\n学生已添加." << std::endl;
        break;
    case 2:
        std::cout << "\n输入学生姓名: ";
        std::cin >> studentName;
        for (auto* person : persons) {
            auto* s = dynamic_cast<Student*>(person);
            if ( s && s->getName() == studentName) {
                student = s;
                break;
            }
        }
        if (!student) {
            std::cout << "\n没有找到该学生!" << std::endl;
            return;
        }
        if (student->getMentor() == teacher) {
            auto& students = teacherStudentMap[teacher];
            students.erase(std::remove(students.begin(), students.end(), student), students.end());
            student->setMentor(nullptr);
            std::cout << "\n学生已移除." << std::endl;
        }
        else {
            std::cout << "\n这位老师不是该学生的导师." << std::endl;
        }
        break;
    default:
        std::cout << "\n非法选项!" << std::endl;
        break;
    }
}

void classifyAndSortPersonsByAge(const std::vector<Person*>& persons, std::map<Teacher*, std::vector<Student*>>& teacherStudentMap) {
    std::vector<Student*> students;
    std::vector<OrdinaryTeacher*> ordinaryTeachers;
    std::vector<Dean*> deans;
    std::vector<President*> presidents;

    for (auto person : persons) {
        if (auto* student = dynamic_cast<Student*>(person)) {
            students.push_back(student);
        }
        else if (auto* ordinaryTeacher = dynamic_cast<OrdinaryTeacher*>(person)) {
            ordinaryTeachers.push_back(ordinaryTeacher);
        }
        else if (auto* dean = dynamic_cast<Dean*>(person)) {
            deans.push_back(dean);
        }
        else if (auto* president = dynamic_cast<President*>(person)) {
            presidents.push_back(president);
        }
    }

    // 将不同类按年龄排序
    auto sortByAge = [](auto& container) {
        std::sort(container.begin(), container.end(), [](auto* a, auto* b) {
            return a->getAge() < b->getAge();
        });
    };

    sortByAge(students);
    sortByAge(ordinaryTeachers);
    sortByAge(deans);
    sortByAge(presidents);

    // 输出排序结果
    std::cout << "\n学生按年龄排序:" << std::endl;
    for (const auto& student : students) {
        student->outData(teacherStudentMap);
    }

    std::cout << "\n普通教师按年龄排序:" << std::endl;
    for (const auto& ordinaryTeacher : ordinaryTeachers) {
        ordinaryTeacher->outData(teacherStudentMap);
    }

    std::cout << "\n系主任按年龄排序:" << std::endl;
    for (const auto& dean : deans) {
        dean->outData(teacherStudentMap);
    }

    std::cout << "\n院长按年龄排序:" << std::endl;
    for (const auto& president : presidents) {
        president->outData(teacherStudentMap);
    }
}

int main() {
    std::vector<Person*> persons;
    std::map<Teacher*, std::vector<Student*>> teacherStudentMap;

    bool exitProgram = false;

    while (!exitProgram) {
        displayMenu(); // 显示操作菜单

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            addPerson(persons, teacherStudentMap);
            break;
        case 2:
            displayAllPersons(persons, teacherStudentMap);
            break;
        case 3:
            queryPersonByName(persons, teacherStudentMap);
            break;
        case 4:
            deletePersonByName(persons, teacherStudentMap);
            break;
        case 5:
            manageStudentMentor(persons, teacherStudentMap);
            break;
        case 6:
            manageTeachersStudents(persons, teacherStudentMap);
            break;
        case 7:
            classifyAndSortPersonsByAge(persons, teacherStudentMap);
            break;
        case 8:
            exitProgram = true;
            break;
        default:
            std::cout << "\n非法选项!" << std::endl;
            break;
        }
    }

    // 清理内存
    for (const auto& person : persons) {
        delete person;
    }

    return 0;
}

//int main() {
//    std::vector<Person*> persons;
//    std::map<Teacher*, std::vector<Student*>> teacherStudentMap;
//    Teacher* teachers[8];
//    Student* students[5];
//
//    // 创建5个普通教师
//    std::cout << "录入教师信息：\n";
//    for (int i = 0; i < 5; ++i) {
//        teachers[i] = new OrdinaryTeacher();
//        teachers[i]->inputData();
//        teachers[i]->setSalary(3000); // 假设基本工资为3000
//        persons.push_back(teachers[i]);
//    }
//
//    // 创建2个系主任
//    std::cout << "\n录入系主任信息：\n";
//    for (int i = 5; i < 7; ++i) {
//        teachers[i] = new Dean();
//        teachers[i]->inputData();
//        teachers[i]->setSalary(5000); // 假设基本工资为5000
//        persons.push_back(teachers[i]);
//    }
//
//    // 创建1个院长
//    std::cout << "\n录入院长信息：\n";
//    teachers[7] = new President();
//    teachers[7]->inputData();
//    teachers[7]->setSalary(7000); // 假设基本工资为7000
//    persons.push_back(teachers[7]);
//
//    // 创建5个学生
//    std::cout << "\n录入学生信息：\n";
//    for (int i = 0; i < 5; ++i) {
//        students[i] = new Student();
//        students[i]->inputData();
//        students[i]->setMentor(teachers[i % 5]); // 假设每个学生的导师是普通教师
//        teacherStudentMap[teachers[i % 5]].push_back(students[i]);
//        persons.push_back(students[i]);
//    }
//
//    // 输出所有人的信息
//    for (const auto& person : persons) {
//        std::cout << *person << std::endl;
//    }
//
//    // 输出每个教师指导的学生信息
//    for (const auto& entry : teacherStudentMap) {
//        std::cout << "教师: " << *entry.first << " 指导的学生:" << std::endl;
//        for (const auto& student : entry.second) {
//            std::cout << "  " << *student << std::endl;
//        }
//    }
//
//    // 清理内存
//    for (const auto& person : persons) {
//        delete person;
//    }
//
//    return 0;
//}