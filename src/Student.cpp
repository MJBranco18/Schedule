#include "Student.h"

Student::Student(std::string name, int stuCode, std::string statute,std::vector<ClassUc> classes) {
    this->name = name;
    this->stuCode = stuCode;
    this->statute = statute;
    this->classes = classes;
}

