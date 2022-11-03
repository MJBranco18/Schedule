//
// Created by Guilherme Coutinho on 02/11/2022.
//
#include "Order.h"

Order::Order() = default;

Order::Order(Student student, ClassUc classUc, int type) {
    this->student = student;
    this->type = type;
    this->classUc= classUc;
}

Order::Order(Student student, ClassUc classUcRem, ClassUc classUcAdd, int type) {
    this->student = student;
    this->type = type;
    this->classUcRem = classUcRem;
    this->classUcAdd = classUcAdd;
}

Order::Order(Student student, std::vector<ClassUc> classesRem, std::vector<ClassUc> classesAdd, int type) {
    this->student = student;
    this->type = type;
    this->classesRem = classesRem;
    this->classesAdd = classesAdd;
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

