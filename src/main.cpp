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
    std::vector<ScheduleUc> schedules = obj.getSchedule();
    for(ScheduleUc s : schedules){
        std::cout << "\n" << s.get_classUc().get_ucCode() << " - " << s.get_classUc().get_classCode() <<  ":" << std::endl;

        for(Slot slot : s.get_ucClassSchedule()){
            std::cout << slot.get_day() << " at " << slot.get_startHour() << " during "
                      << slot.get_duration() << " hours and type of class is " << slot.get_type() << std::endl;
        }

        std::cout << std::endl;
    }
}

bool occupationsCresc(std::pair<int,int> p1, std::pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    //if p1.second == p2.second
    if(p1.first < p2.first) return true;
    if(p1.first > p2.first) return false;
    return false;
}

bool occupationsDecresc(std::pair<int,int> p1, std::pair<int,int> p2){
    if(p1.second > p2.second) return true;
    if(p1.second < p2.second) return false;
    //if p1.second == p2.second
    if(p1.first > p2.first) return true;
    if(p1.first < p2.first) return false;
    return false;
}

void occupations(){
    short choice;
    std::string year, ucCode;
    std::vector<Student> students = obj.getStudents();

    std::vector<std::pair<int,int>> occupations(16,{0,0});
    std::cout << "\nInserir ano: "; std::cin >> year;
    std::cout << "Inserir UC: "; std::cin >> ucCode;

    for(int i = 1; i <= 16; i++) occupations[i-1].first = i;

    for(const Student& student : students){
        for(ClassUc currClassUc : student.getClasses()){
            if(ucCode == currClassUc.get_ucCode() && year == currClassUc.get_classCode().substr(0,1)){
                int _class = std::stoi(currClassUc.get_classCode().substr(5));
                occupations[_class-1].second++;
            }
        }
    }

    std::cout << "\n1- Ordenar por UC" << std::endl;
    std::cout << "2- Ordenacao crescente" << std::endl;
    std::cout << "3- Ordenacao decrescente" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1:
            for(auto p : occupations) std::cout << "Turma " << p.first << ": " << p.second << std::endl;
            break;
        case 2:
            std::sort(occupations.begin(),occupations.end(), occupationsCresc);
            for(auto p : occupations) std::cout << "Turma " << p.first << ": " << p.second << std::endl;
            break;
        case 3:
            std::sort(occupations.begin(),occupations.end(), occupationsDecresc);
            for(auto p : occupations) std::cout << "Turma " << p.first << ": " << p.second << std::endl;
            break;
        default:
            //colocar erro
            break;
    }
}


void showSchedule(){
    std::string stuName;
    std::vector<Student> students = obj.getStudents();
    std::vector<ScheduleUc> scheduleUc = obj.getSchedule();
    std::vector<Slot> classesCurrentScheduleUc;
    std::cout << "Student name: "; std::cin >> stuName;

    for(Student student : students){
        if(student.getName() == stuName){
            for(ClassUc classUc : student.getClasses()){
                for(ScheduleUc currentScheduleUc : scheduleUc){
                    if(classUc.get_classCode() == currentScheduleUc.get_classUc().get_classCode()
                    && classUc.get_ucCode() == currentScheduleUc.get_classUc().get_ucCode())
                        classesCurrentScheduleUc = currentScheduleUc.get_ucClassSchedule();

                }
                std::cout << student.getName() << "'s classes: " << std::endl;
                for(Slot slot : classesCurrentScheduleUc){
                    std::cout << classUc.get_ucCode() << " - " << classUc.get_classCode()
                              << " at " << slot.get_day() << " at " << slot.get_startHour() << " during "
                              << slot.get_duration() << " type of class is " << slot.get_type() << std::endl;
                }
            }
        }
    }

    /*
    std::cout << "-------- |Segunda| --------------------------------------------------------------------" << std::endl;
    std::cout << "|  8:00  | " <<
     */
}

int main(){
    short choice;
    obj.readFiles("classes_per_uc.csv","classes.csv","students_classes.csv");
    test();
    /*
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
     */

    return 0;
}