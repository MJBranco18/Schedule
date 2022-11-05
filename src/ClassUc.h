#ifndef CLASSUC_H
#define CLASSUC_H

#include <iostream>
#include <string>

/**
 * Classe que representa o objeto de uma turma associada a uma UC
 */
class ClassUc {
private:
    std::string ucCode_, classCode_;
public:

    ClassUc();
    ClassUc(const std::string& ucCode, const std::string& classCode);

    std::string get_ucCode() const;
    std::string get_classCode() const;
    void set_ucCode(const std::string& ucCode);
    void set_classCode(const std::string& classCode);
};

#endif