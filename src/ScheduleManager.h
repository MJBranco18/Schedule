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
    std::vector<Student> students; //se possivel, mudar para set
    std::vector<ScheduleUc> schedule;
public:
    ScheduleManager();
    ScheduleManager(std::vector<Student> students, std::vector<ScheduleUc> schedule);
    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);

    std::vector<Student>& getStudents();
    std::vector<ScheduleUc>& getSchedule();
    void setStudents(std::vector<Student> students);
    void setSchedule(std::vector<ScheduleUc> schedule);


};


#endif