//
// Created by Guilherme Coutinho on 02/11/2022.
//
#include "Order.h"

Order::Order() = default;

Order::Order(Student student, int type) {
    this->student = student;
    this->type = type;
}

