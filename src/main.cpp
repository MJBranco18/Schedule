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

int main(){
    ScheduleManager obj;
    obj.readFiles("csv_files/classes_per_uc.csv","csv_files/classes.csv","csv_files/students_classes.csv");
    showMenu();
    return 0;
}