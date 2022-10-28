#include "ClassUc.h"


ClassUc::ClassUc() {}

ClassUc::ClassUc(std::string ucCode, std::string classCode){
    this->ucCode = ucCode;
    this->classCode = classCode;
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



