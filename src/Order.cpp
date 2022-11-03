//
// Created by Guilherme Coutinho on 02/11/2022.
//
#include "Order.h"

Order::Order() = default;

Order::Order(Student student, ClassUc classUc, int type) {
    this->student = student;
    this->type = type;
    this->classUc = classUc;
}

const Student &Order::getStudent() const {
    return this->student;
}

void Order::setStudent(const Student &student) {
    this->student = student;
}

int Order::getType() const {
    return this->type;
}

void Order::setType(int type) {
    this->type = type;
}

ClassUc Order::getClassUc() const {
    return this->classUc;
}

void Order::setClassUc(ClassUc classUc){
    this->classUc = classUc;
}