#include "ClassUc.h"

ClassUc::ClassUc() {}

ClassUc::ClassUc(const std::string& ucCode, const std::string& classCode){
    this->ucCode_ = ucCode;
    this->classCode_ = classCode;
}

std::string ClassUc::get_ucCode() const {
    return this->ucCode_;
}

std::string ClassUc::get_classCode() const {
    return this->classCode_;
}

void ClassUc::set_ucCode(const std::string& ucCode) {
    this->ucCode_ = ucCode;
}

void ClassUc::set_classCode(const std::string& classCode) {
    this->classCode_ = classCode;
}



