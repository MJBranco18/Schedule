#include "ScheduleUc.h"

ScheduleUc::ScheduleUc() {}

ScheduleUc::ScheduleUc(ClassUc classUc, std::vector<Slot> schedule){
    this->classUc = classUc;
    this->schedule = schedule;
}

void ScheduleUc::set_classUc(ClassUc classUc) {
    this->classUc = classUc;
}

void ScheduleUc::set_schedule(std::vector<Slot> schedule) {
    this->schedule = schedule;
}

ClassUc ScheduleUc::get_classUc() const {
    return this->classUc;
}

std::vector<Slot> ScheduleUc::get_schedule() const {
    return this->schedule;
}
