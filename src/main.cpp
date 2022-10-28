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

/*
void test(ScheduleManager obj){
    std::vector<Student> students = obj.getStudents();
    for(Student s : students){
        std::cout << s.getName() << " - " << s.getStuCode() <<  " - ";
        for(ClassUc c : s.getClasses()) std::cout << c.get_ucCode() << " - " << c.get_classCode() << " - " << c.get_occupation()<<  std::endl;
    }
}


void fillOccupation(const ScheduleManager& obj){
    std::vector<Student> students = obj.getStudents();
    for(const Student& s : students){
        for(ClassUc c : s.getClasses()) c.set_occupation(c.get_occupation() + 1);
    }
}
*/

void occupations(){
    short ocupationChoice;
    std::string classCode, year, ucCode;
    std::cout << "Ocupacao de?" << std::endl;
    std::cout << "1- Turma" << std::endl;
    std::cout << "2- Ano" << std::endl;
    std::cout << "3- UC\n" << std::endl;
    std::cin >> ocupationChoice;
    switch (ocupationChoice) {
        case 1:
            std::cout << "Inserir turma: "; std::cin >> classCode;
            //fazer função de ocupação para a turma recebida
            break;

        case 2:
            std::cout << "Inserir ano: "; std::cin >> year;
            //fazer função de ocupação para o ano recebido
            break;

        case 3:
            std::cout << "Inserir UC: "; std::cin >> ucCode;
            //fazer função de ocupação para a turma recebida
            break;
        default:
            break;
    }
}

void showSchedule(){
    std::string stuName;
    std::cout << "Student name: "; std::cin >> stuName;
    
}

int main(){
    short choice;
    ScheduleManager obj;
    obj.readFiles("classes_per_uc.csv","classes.csv","students_classes.csv");
    //fillOccupation(obj);
    //test(obj);
    showMenu(); std::cin >> choice;

    switch (choice) {
        case 1:
            occupations();
            break;

        case 2:
            showSchedule();
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