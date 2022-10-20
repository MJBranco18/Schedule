#include "ScheduleManager.h"

ScheduleManager::ScheduleManager() = default;

ScheduleManager::ScheduleManager(std::vector<Student> students, std::vector<ScheduleUc> schedule){
    this->students = students;
    this->schedule = schedule;
}

void ScheduleManager::readFiles(const std::string& file1, const std::string& file2, const std::string& file3){
    std::fstream in1, in2, in3;
    std::string classCode, ucCode, token;
    ScheduleUc current_scheduleUc;
    ClassUc current_classUc;

    in1.open(file1); in2.open(file2); in3.open(file3); //open files

    std::getline(in1,token, '\n'); //step var names ahead

    while(std::getline(in1,token, '\n')){
        std::stringstream iss(token);

        unsigned long pos = token.find(',');
        ucCode = token.substr(0,pos);
        classCode = token.substr(pos+1);

        current_classUc.setUcCode(ucCode);
        current_classUc.setClassCode(classCode);

        current_scheduleUc.set_classUc(current_classUc);

        schedule.push_back(current_scheduleUc);
    }

}

void ScheduleManager::setStudents(std::vector<Student> students) {
    this->students = students;
}

void ScheduleManager::setSchedule(std::vector<ScheduleUc> schedule) {
    this->schedule = schedule;
}

std::vector<Student> ScheduleManager::getStudents() const {
    return this->students;
}

std::vector<ScheduleUc> ScheduleManager::getSchedule() const {
    return this->schedule;
}
