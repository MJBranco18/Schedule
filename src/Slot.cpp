#include "Slot.h"

Slot::Slot() = default;

Slot::Slot(const std::string& day, float startHour, float duration, const std::string& type){
    this->day_ = day;
    this->startHour_ = startHour;
    this->duration_ = duration;
    this->type_ = type;
}

std::string Slot::get_day() const {
    return day_;
}
void Slot::set_day(const std::string& day) {
    this -> day_ = day;
}

double Slot::get_startHour() const {
    return startHour_;
}
void Slot::set_startHour(double startHour) {
    this -> startHour_ = startHour;
}

double Slot::get_duration() const {
    return duration_;
}
void Slot::set_duration(double duration) {
    this->duration_ = duration;
}

std::string Slot::get_type() const{
    return type_;
}
void Slot::set_type(const std::string& type) {
    this->type_ = type;
}


