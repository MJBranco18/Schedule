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
    std::vector<Student> students; //se possivel, mudar para set
    std::vector<ScheduleUc> schedule;
public:
    ScheduleManager();
    ScheduleManager(std::vector<Student> students, std::vector<ScheduleUc> schedule);
    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);

    std::vector<Student> getStudents() const;
    std::vector<ScheduleUc> getSchedule() const;
    void setStudents(std::vector<Student> students);
    void setSchedule(std::vector<ScheduleUc> schedule);


};


#endif