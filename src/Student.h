#ifndef TRABALHO_STUDENT_H
#define TRABALHO_STUDENT_H

#include "ClassUc.h"
#include <string>
#include <vector>

class Student {
private:
    std::string name, statute;
    int stuCode;
    std::vector<ClassUc> classes;
public:
    Student(std::string name, int stuCode, std::string statute,std::vector<ClassUc> classes);

    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif
