#include "ScheduleManager.h"


ScheduleManager::ScheduleManager() = default;

void ScheduleManager::readFiles(const std::string& file1, const std::string& file2, const std::string& file3){
    std::fstream in1, in2, in3;
    std::string token;
    ScheduleUc current_scheduleUc;
    ClassUc current_classUc;
    Student current_student;
    Slot current_slot;

    in1.open(file1); in2.open(file2); in3.open(file3); //open files

    std::getline(in1,token, '\n'); //step var names ahead
    std::getline(in2,token,'\n');  //step var names ahead
    std::getline(in3,token,'\n');  //step var names ahead

    //reads file 2 - classes.csv
    while(std::getline(in2,token,'\n')){
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;

        while((std::getline(iss, tempstr, ','))){
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);
        }

        current_classUc.set_classCode(temp[0]);
        current_classUc.set_ucCode(temp[1]);
        current_slot.set_day(temp[2]);
        current_slot.set_startHour(std::stod(temp[3]));
        current_slot.set_duration(std::stod(temp[4]));
        current_slot.set_type(temp[5]);


        std::vector<Slot> ucClSch;
        ucClSch.push_back(current_slot);
        current_scheduleUc.set_ucClassSchedule(ucClSch);
        current_scheduleUc.set_classUc(current_classUc);

        this->schedule.push_back(current_scheduleUc);
    }

    //file 2 - clean data
    for(int i = 0; i < this->schedule.size(); i++){
        for(int j = i + 1; j < this->schedule.size(); j++){
            if(this->schedule[j].get_classUc().get_classCode() == this->schedule[i].get_classUc().get_classCode()
               && this->schedule[j].get_classUc().get_ucCode() == this->schedule[i].get_classUc().get_ucCode() ){
                current_slot = this->schedule[j].get_ucClassSchedule()[0];
                this->schedule.erase(this->schedule.begin() + j);
                j--;
                this->schedule[i].addSlot(current_slot);
            }
        }
    }

    //reads file 3 - students_classes.csv
    while(std::getline(in3,token,'\n')){
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::vector<ClassUc> tempClasses;
        std::string tempstr;
        std::vector<ClassUc> classes;
        auto it = this->students.begin();

        while((std::getline(iss, tempstr, ','))){
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);
        }

        current_student.setStuCode(std::stol(temp[0]));
        current_student.setName(temp[1]);
        current_classUc.set_ucCode(temp[2]);
        current_classUc.set_classCode(temp[3]);
        it = this->students.find(current_student);

        if(it != this->students.end()){
            classes = it->getClasses();
            this->students.erase(it);
        }

        classes.push_back(current_classUc);
        current_student.setClasses(classes);

        this->students.insert(current_student);
        current_scheduleUc.set_classUc(current_classUc);
    }
}

std::set<Student>& ScheduleManager::getStudents(){
    return this->students;
}

std::vector<ScheduleUc>& ScheduleManager::getSchedule(){
    return this->schedule;
}

