#ifndef SCHEDULE_ORDER_H
#define SCHEDULE_ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "ClassUc.h"

class Order{
private:
    Student student;
    int type;
    ClassUc classUc;

public:
    Order();
    Order(Student student, ClassUc classUc,int type);
    ClassUc getClassUc() const;
    void setClassUc(ClassUc classUc);
    const Student &getStudent() const;
    void setStudent(const Student &student);
    int getType() const;
    void setType(int type);
};

#endif
