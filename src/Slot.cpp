#include "Slot.h"

Slot::Slot(std::string day, float startHour, float duration, std::string type){
    this->day = day;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}