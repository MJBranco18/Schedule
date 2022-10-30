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