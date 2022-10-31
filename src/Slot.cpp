#include "Slot.h"

Slot::Slot() {}

Slot::Slot(std::string day, double startHour, double duration, std::string type){
    this->day = day;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}

std::string Slot::get_day() const {
    return day;
}
void Slot::set_day(std::string day) {
    this -> day = day;
}

double Slot::get_startHour() const {
    return startHour;
}
void Slot::set_startHour(double startHour) {
    this -> startHour = startHour;
}

double Slot::get_duration() const {
    return duration;
}
void Slot::set_duration(double duration) {
    this->duration = duration;
}

std::string Slot::get_type() const{
    return type;
}
void Slot::set_type(std::string type) {
    this->type = type;
}


