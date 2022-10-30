#include <iostream>
#include "ScheduleManager.h"
#include "ScheduleUc.h"
#include "Student.h"
#include "Slot.h"
#include "ClassUc.h"
#include <vector>

ScheduleManager obj;

void showMenu(){
    std::cout << "------------------- Menu -------------------" << std::endl;
    std::cout << "| 1- Ocupacao                              |" << std::endl;
    std::cout << "| 2- Horario                               |" << std::endl;
    std::cout << "| 3- Listar Estudantes                     |" << std::endl;
    std::cout << "| 4- Estudantes com mais n UC's            |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}


void test(){
    std::vector<Student> students = obj.getStudents();
    for(Student s : students){
        std::cout << s.getName() << " - " << s.getStuCode() <<  ":" << std::endl;
        int count = 0;
        for(ClassUc c : s.getClasses()){
            std::cout << count << "- " << c.get_ucCode() << " - " << c.get_classCode() <<  std::endl;
            count++;
        }
        std::cout << std::endl;
    }
}

void occupationsPerUc(std::string year, std::string ucCode){
    std::vector<Student> students = obj.getStudents();
    int occupations[16] = {0};
    for(const Student& student : students){
        for(ClassUc currClassUc : student.getClasses()){
            if(ucCode == currClassUc.get_ucCode() && year == currClassUc.get_classCode().substr(0,1)){
                int _class = std::stoi(currClassUc.get_classCode().substr(5));
                occupations[_class-1]++;
            }
        }
    }

    for(int i = 1; i <= 16; i++) std::cout << "Turma " << i << ": " << occupations[i-1] << std::endl;
}

void occupations(){
    short choice;
    std::string year, ucCode;
    std::cout << "Inserir ano: "; std::cin >> year;
    std::cout << "Inserir UC: "; std::cin >> ucCode;

    std::cout << "\n1- Ordenar por UC" << std::endl;
    std::cout << "2- Ordenacao crescente" << std::endl;
    std::cout << "3- Ordenacao decrescente" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1:
            occupationsPerUc(year, ucCode);
            break;

        case 2:
            break;

        case 3:
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
    obj.readFiles("classes_per_uc.csv","classes.csv","students_classes.csv");


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
     

    return 0;
}