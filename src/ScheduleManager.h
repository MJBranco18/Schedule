#ifndef TRABALHO_SCHEDULEMANAGER_H
#define TRABALHO_SCHEDULEMANAGER_H

#include "Student.h"
#include "ScheduleUc.h"
#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <istream>
#include <fstream>


class ScheduleManager {
private:
    std::vector<Student> students; //se possível, mudar para set
    std::vector<ScheduleUc> schedule;
public:
    ScheduleManager();
    ScheduleManager(std::vector<Student> students, std::vector<ScheduleUc> schedule);
    void readFiles(std::string file1, std::string file2, std::string file3);
};


#endif
