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
    Student current_student;
    Slot current_slot;

    in1.open(file1); in2.open(file2); in3.open(file3); //open files

    std::getline(in1,token, '\n'); //step var names ahead
    std::getline(in2,token,'\n');  //step var names ahead
    std::getline(in3,token,'\n');  //step var names ahead


    //reads classes_per_uc.csv, mas não é preciso porque o classes.csv lê os mesmos ficheiros
/*
    while(std::getline(in1,token, '\n')){
        std::stringstream iss(token);

        unsigned long pos = token.find(',');
        ucCode = token.substr(0,pos);
        classCode = token.substr(pos+1);

        current_classUc.set_ucCode(ucCode);
        current_classUc.set_classCode(classCode);

        current_scheduleUc.set_classUc(current_classUc);

        schedule.push_back(current_scheduleUc);
    }
*/
    //reads classes.csv
    while(std::getline(in2,token,'\n')){
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;

        while((std::getline(iss, tempstr, ','))) temp.push_back(tempstr);

        current_classUc.set_classCode(temp[0]);
        current_classUc.set_ucCode(temp[1]);
        current_slot.set_day(temp[2]);
        current_slot.set_startHour(std::stod(temp[3]));
        current_slot.set_duration(std::stod(temp[4]));
        current_slot.set_type(temp[5]);

        std::vector<Slot> ucClSch = current_scheduleUc.get_ucClassSchedule();
        ucClSch.push_back(current_slot);
        current_scheduleUc.set_ucClassSchedule(ucClSch);
        current_scheduleUc.set_classUc(current_classUc);

        schedule.push_back(current_scheduleUc);
    }

    //read students_class.csv
    while(std::getline(in3,token,'\n')){
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;

        while((std::getline(iss, tempstr, ','))) temp.push_back(tempstr);

        current_student.setStuCode(std::stol(temp[0]));
        current_student.setName(temp[1]);
        current_classUc.set_ucCode(temp[2]);
        current_classUc.set_classCode(temp[3]);
        current_scheduleUc.set_classUc(current_classUc);

        std::vector<ClassUc> classStudents;
        classStudents.push_back(current_classUc);
        current_student.setClasses(classStudents);
        students.push_back(current_student);
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
