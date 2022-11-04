#ifndef SCHEDULEUC_H
#define SCHEDULEUC_H

#include "Slot.h"
#include "ClassUc.h"
#include <vector>

class ScheduleUc {
private:
    ClassUc classUc;
    std::vector<Slot> ucClassSchedule;
public:
    ScheduleUc();
    ScheduleUc(ClassUc classUc, std::vector<Slot> ucClassSchedule);
    void set_classUc(ClassUc classUc);
    void set_ucClassSchedule(std::vector<Slot> ucClassSchedule);
    ClassUc get_classUc() const;
    std::vector<Slot> get_ucClassSchedule() const;
    void addSlot(const Slot& slot);
};


#endif