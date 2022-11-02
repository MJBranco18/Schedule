#ifndef TRABALHO_CLASSUC_H
#define TRABALHO_CLASSUC_H

#include <iostream>
#include <string>

class ClassUc {
private:
    std::string ucCode, classCode;
public:

    ClassUc();
    ClassUc(std::string ucCode, std::string classCode);

    std::string get_ucCode() const;
    std::string get_classCode() const;
    void set_ucCode(std::string ucCode);
    void set_classCode(std::string classCode);
};

#endif