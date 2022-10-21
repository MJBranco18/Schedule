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
    std::vector<Student> students = obj.getStudents();
    for(Student s : students){
        std::cout << s.getName() << " - " << s.getStuCode() <<  " - ";
        for(ClassUc c : s.getClasses()) std::cout << c.get_ucCode() << " - " << c.get_classCode() << std::endl;
    }
}


int main(){
    int choice;
    ScheduleManager obj;
    obj.readFiles("classes_per_uc.csv","classes.csv","students_classes.csv");
    test(obj);
    showMenu(); std::cin >> choice;

    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
    //test(obj);
    return 0;
}