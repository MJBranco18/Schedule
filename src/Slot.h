#ifndef TRABALHO_SLOT_H
#define TRABALHO_SLOT_H

#include <string>

class Slot {
private:
    float startHour, duration;
    std::string type, day;
public:
    Slot();
    Slot(std::string day, double startHour, double duration, std::string type);
    std::string get_day() const;
    double get_startHour() const;
    double get_duration() const;
    std::string get_type() const;
    void set_day(std::string day);
    void set_startHour(double startHour);
    void set_duration(double duration);
    void set_type(std::string type);
};


#endif