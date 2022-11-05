#ifndef SCHEDULEUC_H
#define SCHEDULEUC_H

#include "Slot.h"
#include "ClassUc.h"
#include <vector>

/**
 * Classe que representa o objeto das aulas de uma turma
 */
class ScheduleUc {
private:
    ClassUc classUc_;
    std::vector<Slot> ucClassSchedule_;
public:
    ScheduleUc();
    ScheduleUc(const ClassUc& classUc, const std::vector<Slot>& ucClassSchedule);
    void set_classUc(const ClassUc& classUc);
    void set_ucClassSchedule(const std::vector<Slot>& ucClassSchedule);
    ClassUc get_classUc() const;
    std::vector<Slot> get_ucClassSchedule() const;
    void addSlot(const Slot& slot);
};


#endif