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
    void set_day(std::string day);

    double get_startHour() const;
    void set_startHour(double startHour);

    double get_duration() const;
    void set_duration(double duration);

    std::string get_type();
    void set_type(std::string type);
};


#endif
