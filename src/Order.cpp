#include "Order.h"

Order::Order() = default;

Order::Order(const Student& student, const ClassUc& classUc, int type) {
    this->student_ = student;
    this->type_ = type;
    this->classUc_ = classUc;
}

Order::Order(const Student& student, const ClassUc& classUcRem, const ClassUc& classUc, int type) {
    this->student_ = student;
    this->type_ = type;
    this->classUcRem_ = classUcRem;
    this->classUc_ = classUc;
}

Student& Order::getStudent(){
    return this->student_;
}

int Order::getType() const {
    return this->type_;
}

ClassUc Order::getClassUc() const {
    return this->classUc_;
}

ClassUc Order::getClassUcRem() const{
    return classUcRem_;
}