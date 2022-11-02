#ifndef SCHEDULE_ORDER_H
#define SCHEDULE_ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class Order{
private:
    Student student;
    int type;

public:
    Order();
    Order(Student student, int type);
};

#endif
