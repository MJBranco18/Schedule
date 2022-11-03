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
    ClassUc classUc, classUcAdd, classUcRem;
    std::vector<ClassUc> classesAdd, classesRem;

public:
    Order();
    Order(Student student, ClassUc classUc,int type);
    Order(Student student, ClassUc classUcRem, ClassUc classUcAdd, int type);
    Order(Student student, std::vector<ClassUc> classesRem, std::vector<ClassUc> classesAdd, int type);
    ClassUc getClassUc() const;
    void setClassUc(ClassUc classUc);
    const Student &getStudent() const;
    void setStudent(const Student &student);
    int getType() const;
    void setType(int type);
};

#endif
