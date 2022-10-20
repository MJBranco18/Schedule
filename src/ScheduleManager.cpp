#include "ScheduleManager.h"

ScheduleManager::ScheduleManager() = default;

ScheduleManager::ScheduleManager(std::vector<Student> students, std::vector<ScheduleUc> schedule){
    this->students = students; //erro de assignment por ser uma variável do tipo set, tentar dar fix
    this->schedule = schedule;
}

void ScheduleManager::readFiles(std::string file1, std::string file2, std::string file3){
    std::ifstream in1, in2, in3;
    std::string classCode, ucCode, token;
    in1.open(file1); in2.open(file2); in3.open(file3);
    std::getline(in1, token, ',');
    std::cout << token << std::endl;
    ScheduleUc current;
    while(std::getline(in1,token, ',')){
        std::cout << token << std::endl;
    }

}