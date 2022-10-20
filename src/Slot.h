#ifndef TRABALHO_SLOT_H
#define TRABALHO_SLOT_H

#include <string>

class Slot {
private:
    float startHour, duration;
    std::string type, day;
public:
    Slot(std::string day, float startHour, float duration, std::string type);
};


#endif
