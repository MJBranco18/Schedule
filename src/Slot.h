#ifndef SLOT_H
#define SLOT_H

#include <string>

/**
 * Classe que representa o objeto do horário de uma aula,
 * com dia, hora de início, duração e o tipo da aula
 */
class Slot {
private:
    float startHour_, duration_;
    std::string type_, day_;
public:
    Slot();
    Slot(const std::string& day, float startHour, float duration, const std::string& type);
    std::string get_day() const;
    double get_startHour() const;
    double get_duration() const;
    std::string get_type() const;
    void set_day(const std::string& day);
    void set_startHour(double startHour);
    void set_duration(double duration);
    void set_type(const std::string& type);
};


#endif