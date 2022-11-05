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
    Student student_;
    int type_;
    ClassUc classUc_, classUcRem_;

public:
    Order();
    Order(const Student& student, const ClassUc& classUc, int type);
    Order(const Student& student, const ClassUc& classUcRem, const ClassUc& classUc, int type);
    ClassUc getClassUc() const;
    Student& getStudent();
    int getType() const;
    ClassUc getClassUcRem() const;
};

#endif
