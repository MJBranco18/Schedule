#include "ScheduleManager.h"

ScheduleManager::ScheduleManager() = default;

ScheduleManager::ScheduleManager(std::set<Student> students, std::vector<ScheduleUc> schedule){
    this->students = students; //erro de assignment por ser uma varável do tipo set, tentar dar fix
    this->schedule = schedule;
}

void ScheduleManager::readFiles(){

}