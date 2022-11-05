#include "Student.h"

Student::Student() = default;

Student::Student(const std::string& name, long int stuCode, const std::vector<ClassUc>& classes) {
    this->name_ = name;
    this->stuCode_ = stuCode;
    this->classes_ = classes;
}

std::string Student::getName() const {
    return this->name_;
}

long int Student::getStuCode() const{
    return this->stuCode_;
}

std::vector<ClassUc> Student::getClasses() const{
    return this->classes_;
}

void Student::setName(const std::string& name){
    this->name_ = name;
}

void Student::setStuCode(long int stuCode){
    this->stuCode_ = stuCode;
}

void Student::setClasses(const std::vector<ClassUc>& classes){
    this->classes_ = classes;
}

void Student::addClass(const ClassUc& _class) {
    this->classes_.push_back(_class);
}

void Student::removeClass(int pos){
    this->classes_.erase(classes_.begin() + pos);
}

bool Student::operator < (const Student& s) const{
    return this->name_ < s.getName();
}