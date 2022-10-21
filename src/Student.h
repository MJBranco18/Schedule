#ifndef TRABALHO_STUDENT_H
#define TRABALHO_STUDENT_H

#include "ClassUc.h"
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    long int stuCode;
    std::vector<ClassUc> classes;
public:
    Student();
    Student(std::string name, long int stuCode, std::vector<ClassUc> classes);
    std::string getName() const;
    long int getStuCode() const;
    std::vector<ClassUc> getClasses() const;
    void setName(std::string name);
    void setStuCode(long int stuCode);
    void setClasses(std::vector<ClassUc> classes);

};


#endif