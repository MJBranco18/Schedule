#ifndef TRABALHO_SCHEDULEMANAGER_H
#define TRABALHO_SCHEDULEMANAGER_H

#include "Student.h"
#include "ScheduleUc.h"
#include <set>
#include <vector>

class ScheduleManager {
private:
    std::set<Student> students;
    std::vector<ScheduleUc> schedule;
public:
    ScheduleManager();
    ScheduleManager(std::set<Student> students, std::vector<ScheduleUc> schedule);
    void readFiles();
};


#endif
