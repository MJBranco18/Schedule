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


void test(ScheduleManager obj){
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

/*
void fillOccupation(const ScheduleManager& obj){
    std::vector<Student> students = obj.getStudents();
    for(const Student& s : students){
        for(ClassUc c : s.getClasses()) c.set_occupation(c.get_occupation() + 1);
    }
}
*/

bool orderUc(Student s1, Student s2){
    std::vector<ClassUc> classesS1 = s1.getClasses();

    return false;
}

void occupationsPerUc(){
    std::vector<Student> students = obj.getStudents();

    for(Student s : students){

    }
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
            occupationsPerUc();
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
    //fillOccupation(obj);
    test(obj);
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
    //test(obj);
    return 0;
}