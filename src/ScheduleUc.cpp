#include "ScheduleUc.h"

ScheduleUc::ScheduleUc() = default;

ScheduleUc::ScheduleUc(const ClassUc& classUc, const std::vector<Slot>& ucClassSchedule){
    this->classUc_ = classUc;
    this->ucClassSchedule_ = ucClassSchedule;
}

void ScheduleUc::set_classUc(const ClassUc& classUc) {
    this->classUc_ = classUc;
}

void ScheduleUc::set_ucClassSchedule(const std::vector<Slot>& ucClassSchedule) {
    this->ucClassSchedule_ = ucClassSchedule;
}

ClassUc ScheduleUc::get_classUc() const {
    return this->classUc_;
}

std::vector<Slot> ScheduleUc::get_ucClassSchedule() const {
    return this->ucClassSchedule_;
}

void ScheduleUc::addSlot(const Slot& slot) {
    this->ucClassSchedule_.push_back(slot);
}
