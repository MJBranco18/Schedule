#ifndef SCHEDULEMANAGER_H
#define SCHEDULEMANAGER_H

#include "Student.h"
#include "ScheduleUc.h"
#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <istream>
#include <fstream>

/**
 * Classe que representa o objeto principal da aplicação
 * que neste caso é o gestor de horários
 */
class ScheduleManager {
private:
    std::set<Student> students;
    std::vector<ScheduleUc> schedule;
public:
    ScheduleManager();
    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);

    std::set<Student>& getStudents();
    std::vector<ScheduleUc>& getSchedule();


};


#endif