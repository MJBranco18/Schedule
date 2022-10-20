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

    std::string getUcCode() const;
    std::string getClassCode() const;
    void setUcCode(std::string ucCode);
    void setClassCode(std::string classCode);
};


#endif
