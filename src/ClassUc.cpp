#include "ClassUc.h"


ClassUc::ClassUc() {}

ClassUc::ClassUc(std::string ucCode, std::string classCode, int occupation ){
    this->ucCode = ucCode;
    this->classCode = classCode;
    this->occupation = 0;
}

std::string ClassUc::get_ucCode() const {
    return this->ucCode;
}

std::string ClassUc::get_classCode() const {
    return this->classCode;
}

void ClassUc::set_ucCode(std::string ucCode) {
    this->ucCode = ucCode;
}

void ClassUc::set_classCode(std::string classCode) {
    this->classCode = classCode;
}

int ClassUc::get_occupation() const {
    return occupation;
}

void ClassUc::set_occupation(int occupation) {
    ClassUc::occupation = occupation;
}



