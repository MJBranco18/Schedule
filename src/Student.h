#ifndef STUDENT_H
#define STUDENT_H

#include "ClassUc.h"
#include <string>
#include <vector>

/**
 * Classe que representa o objeto de um estudante
 */
class Student {
private:
    std::string name_;
    long int stuCode_;
    std::vector<ClassUc> classes_;
public:
    Student();
    Student(const std::string& name, long int stuCode, const std::vector<ClassUc>& classes);
    bool operator < (const Student& s) const;
    //Student operator = (const Student& s) const;
    std::string getName() const;
    long int getStuCode() const;
    std::vector<ClassUc> getClasses() const;
    void setName(const std::string& name);
    void setStuCode(long int stuCode);
    void setClasses(const std::vector<ClassUc>& classes);
    void addClass(const ClassUc& _class);
    void removeClass(int pos);

};


#endif