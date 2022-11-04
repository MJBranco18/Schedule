#include "Order.h"

Order::Order() = default;

Order::Order(Student student, ClassUc classUc, int type) {
    this->student = student;
    this->type = type;
    this->classUc= classUc;
}

Order::Order(Student student, ClassUc classUcRem, ClassUc classUc, int type) {
    this->student = student;
    this->type = type;
    this->classUcRem = classUcRem;
    this->classUc = classUc;
}

Student& Order::getStudent(){
    return this->student;
}

int Order::getType() const {
    return this->type;
}

ClassUc Order::getClassUc() const {
    return this->classUc;
}

ClassUc Order::getClassUcRem() const{
    return classUcRem;
}