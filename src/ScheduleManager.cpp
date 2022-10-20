#include "ScheduleManager.h"

ScheduleManager::ScheduleManager() = default;

ScheduleManager::ScheduleManager(std::vector<Student> students, std::vector<ScheduleUc> schedule){
    this->students = students; //erro de assignment por ser uma variável do tipo set, tentar dar fix
    this->schedule = schedule;
}

void ScheduleManager::readFiles(std::string file1, std::string file2, std::string file3){
    std::fstream in1, in2, in3;
    std::string classCode, ucCode, token = "aba";
    in1.open(file1); in2.open(file2); in3.open(file3);
    if(in1.is_open())
        std::cout << "The file opened!" << std::endl;
    else
        std::cout << "Error Occurred. File did not open." << std::endl;

    std::getline(in1,token, ','); std::getline(in1,token, ','); //step var names ahead
    ScheduleUc current;
    while(std::getline(in1,token, ',')){ //só para testar para ver se o ficheiro é bem lido
        std::cout << token << std::endl;
    }

}