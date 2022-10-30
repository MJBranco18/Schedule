#include "ScheduleUc.h"

ScheduleUc::ScheduleUc() {}

ScheduleUc::ScheduleUc(ClassUc classUc, std::vector<Slot> ucClassSchedule){
    this->classUc = classUc;
    this->ucClassSchedule = ucClassSchedule;
}

void ScheduleUc::set_classUc(ClassUc classUc) {
    this->classUc = classUc;
}

void ScheduleUc::set_ucClassSchedule(std::vector<Slot> ucClassSchedule) {
    this->ucClassSchedule = ucClassSchedule;
}

ClassUc ScheduleUc::get_classUc() const {
    return this->classUc;
}

std::vector<Slot> ScheduleUc::get_ucClassSchedule() const {
    return this->ucClassSchedule;
}

void ScheduleUc::addSlot(Slot slot) {
    this->ucClassSchedule.push_back(slot);
}
