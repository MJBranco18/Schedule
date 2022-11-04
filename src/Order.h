#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "ClassUc.h"

/**
 * Classe que representa o objeto de um pedido
 */
class Order{
private:
    Student student;
    int type;
    ClassUc classUc, classUcRem;

public:
    Order();
    Order(Student student, ClassUc classUc,int type);
    Order(Student student, ClassUc classUcRem, ClassUc classUc, int type);
    ClassUc getClassUc() const;
    Student& getStudent();
    int getType() const;
    ClassUc getClassUcRem() const;
};

#endif
