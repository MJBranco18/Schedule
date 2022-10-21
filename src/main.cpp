#include <iostream>
#include "ScheduleManager.h"
#include "ScheduleUc.h"
#include "Student.h"
#include "Slot.h"
#include "ClassUc.h"

void showMenu(){
    std::cout << "------------------- Menu -------------------" << std::endl;
    std::cout << "| 1- Ocupacao                              |" << std::endl;
    std::cout << "| 2- Horario                               |" << std::endl;
    std::cout << "| 3- Listar Estudantes                     |" << std::endl;
    std::cout << "| 4- Estudantes com mais n UC's            |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}


void test(ScheduleManager obj){
    std::vector<ScheduleUc> testVectorS = obj.getSchedule();
    for(int i =0;i < 30; i++){
        std::cout << testVectorS[i].get_classUc().get_ucCode() << std::endl;
        //<< testVectorS[i].get_classUc().get_classCode()
    }
}

int main(){
    ScheduleManager obj;
    obj.readFiles("classes_per_uc.csv","classes.csv","students_classes.csv");
    showMenu();
    //test(obj);
    return 0;
}