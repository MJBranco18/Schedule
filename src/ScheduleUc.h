#ifndef TRABALHO_SCHEDULEUC_H
#define TRABALHO_SCHEDULEUC_H

#include "Slot.h"
#include "ClassUc.h"
#include <vector>

class ScheduleUc {
private:
    ClassUc classUc;
    std::vector<Slot> schedule;
public:
    ScheduleUc();
    ScheduleUc(ClassUc classUc, std::vector<Slot> schedule);
    void set_classUc(ClassUc classUc);
    void set_schedule(std::vector<Slot> schedule);
    ClassUc get_classUc() const;
    std::vector<Slot> get_schedule() const;
};


#endif
