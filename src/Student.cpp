#include "Student.h"

Student::Student() = default;

Student::Student(std::string name, long int stuCode, std::vector<ClassUc> classes) {
    this->name = name;
    this->stuCode = stuCode;
    this->classes = classes;
}

std::string Student::getName() const {
    return this->name;
}

long int Student::getStuCode() const{
    return this->stuCode;
}

std::vector<ClassUc> Student::getClasses() const{
    return this->classes;
}

void Student::setName(std::string name){
    this->name = name;
}

void Student::setStuCode(long int stuCode){
    this->stuCode = stuCode;
}

void Student::setClasses(std::vector<ClassUc> classes){
    this->classes = classes;
}

void Student::addClass(ClassUc _class) {
    this->classes.push_back(_class);
}

void Student::removeClass(int pos) {
    this->classes.erase(classes.begin() + pos);
}