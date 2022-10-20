#include "ClassUc.h"


ClassUc::ClassUc() {}

ClassUc::ClassUc(std::string ucCode, std::string classCode){
    this->ucCode = ucCode;
    this->classCode = classCode;
}

std::string ClassUc::getUcCode() const {
    return this->ucCode;
}

std::string ClassUc::getClassCode() const {
    return this->classCode;
}

void ClassUc::setUcCode(std::string ucCode) {
    this->ucCode = ucCode;
}

void ClassUc::setClassCode(std::string classCode) {
    this->classCode = classCode;
}
