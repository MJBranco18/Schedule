#ifndef TRABALHO_CLASSUC_H
#define TRABALHO_CLASSUC_H

#include <iostream>
#include <string>

class ClassUc {
private:
    std::string ucCode, classCode;
    int occupation;
public:

    ClassUc();
    ClassUc(std::string ucCode, std::string classCode, int occupation);

    std::string get_ucCode() const;
    std::string get_classCode() const;
    void set_ucCode(std::string ucCode);
    void set_classCode(std::string classCode);
    int get_occupation() const;
    void set_occupation(int occupation);
};


#endif