#ifndef TRABALHO_SCHEDULEUC_H
#define TRABALHO_SCHEDULEUC_H

#include "Slot.h"
#include <vector>

class ScheduleUc {
private:
    int ucCode, classCode;
    std::vector<Slot> schedule;
public:
    ScheduleUc();
    ScheduleUc(int ucCode, int classCode, std::vector<Slot> schedule);

};


#endif
