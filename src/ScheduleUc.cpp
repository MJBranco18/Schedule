#include "ScheduleUc.h"

ScheduleUc::ScheduleUc(int ucCode, int classCode, std::vector<Slot> schedule){
    this->ucCode = ucCode;
    this->classCode = classCode;
    this->schedule = schedule;
}