#include <iostream>
#include "ScheduleManager.h"
#include "ScheduleUc.h"
#include "Student.h"
#include "Slot.h"
#include "ClassUc.h"
#include <vector>
#include <algorithm>


ScheduleManager obj;

void showMenu(){
    std::cout << "------------------- Menu -------------------" << std::endl;
    std::cout << "| 1- Ocupacao                              |" << std::endl;
    std::cout << "| 2- Horario                               |" << std::endl;
    std::cout << "| 3- Listar Estudantes                     |" << std::endl;
    std::cout << "| 4- Estudantes com mais n UC's            |" << std::endl;
    std::cout << "| 5- Alterar horario                       |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}


void test_schedules(){
    std::vector<ScheduleUc> schedules = obj.getSchedule();
    for(const ScheduleUc& s : schedules){
        std::cout << "\n" << s.get_classUc().get_ucCode() << " - " << s.get_classUc().get_classCode() <<  ":" << std::endl;

        for(Slot slot : s.get_ucClassSchedule()){
            std::cout << slot.get_day() << " at " << slot.get_startHour() << " during "
                      << slot.get_duration() << " hours and type of class is " << slot.get_type() << std::endl;
        }

        std::cout << std::endl;
    }
}
void test_students(){
    std::vector<Student> students = obj.getStudents();
    for(Student s : students){
        std::cout << s.getName() << "-" << s.getStuCode() <<  ":" << std::endl;
        for(ClassUc c : s.getClasses()) std::cout << c.get_ucCode() << " - " << c.get_classCode() <<  std::endl;
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
    std::cout << "\nInserir ano:"; std::cin >> year;
    std::cout << "Inserir UC: "; std::cin >> ucCode;

    for(int i = 1; i <= 16; i++) occupations[i-1].first = i;

    for(const Student& student : students){
        for(const ClassUc& currClassUc : student.getClasses()){
            if(ucCode == currClassUc.get_ucCode() && year == currClassUc.get_classCode().substr(0,1)){
                int _class = std::stoi(currClassUc.get_classCode().substr(5));
                occupations[_class-1].second++;
            }
        }
    }

    std::cout << "\n--------------------------------" << std::endl;
    std::cout << "| 1- Ordenar por UC            |"<< std::endl;
    std::cout << "| 2- Ordenacao crescente       |" << std::endl;
    std::cout << "| 3- Ordenacao decrescente     |" << std::endl;
    std::cout << "--------------------------------" << std::endl;
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
        case 0: //voltar para trás
            showMenu();

        default:
            //colocar erro
            break;
    }
}


void showSchedule(){
    std::string stuName;
    std::vector<Student> students = obj.getStudents();
    ScheduleUc studentClasses;
    std::vector<ScheduleUc> scheduleUc = obj.getSchedule(), studentSchedule;
    std::vector<Slot> classesCurrentScheduleUc;
    std::vector<std::vector<ScheduleUc>> sm; //matriz para colocar as aulas

    std::cout << "Student name: "; std::cin >> stuName;

    for(const Student& student : students){
        if(student.getName() == stuName){
            for(const ClassUc& classUc : student.getClasses()){
                for(const ScheduleUc& currentScheduleUc : scheduleUc){
                    if(classUc.get_classCode() == currentScheduleUc.get_classUc().get_classCode()
                    && classUc.get_ucCode() == currentScheduleUc.get_classUc().get_ucCode()){
                        classesCurrentScheduleUc = currentScheduleUc.get_ucClassSchedule();
                        studentClasses.set_ucClassSchedule(classesCurrentScheduleUc);
                        studentClasses.set_classUc({classUc.get_ucCode(),classUc.get_classCode()});
                        studentSchedule.push_back(studentClasses);
                    }
                }
            }
        }
    }

    std::cout << "\n" << stuName << "'s schedule: " << std::endl;

    std::cout << "------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "|        |    Segunda    |     Terça     |    Quarta     |    Quinta     |     Sexta     |" << std::endl;
    std::cout << "|----------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|  8:00  |" << std::endl;
    std::cout << "|  8:30  |" << std::endl;
    std::cout << "|  9:00  |" << std::endl;
    std::cout << "|  9:30  |" << std::endl;
    std::cout << "| 10:00  |" << std::endl;
    std::cout << "| 10:30  |" << std::endl;
    std::cout << "| 11:00  |" << std::endl;
    std::cout << "| 11:30  |" << std::endl;
    std::cout << "| 12:00  |" << std::endl;
    std::cout << "| 12:30  |" << std::endl;
    std::cout << "| 13:00  |" << std::endl;
    std::cout << "| 13:30  |" << std::endl;
    std::cout << "| 14:00  |" << std::endl;
    std::cout << "| 14:30  |" << std::endl;
    std::cout << "| 15:00  |" << std::endl;
    std::cout << "| 15:30  |" << std::endl;
    std::cout << "| 16:00  |" << std::endl;
    std::cout << "| 16:30  |" << std::endl;
    std::cout << "| 17:00  |" << std::endl;
    std::cout << "| 17:30  |" << std::endl;
    std::cout << "| 18:00  |" << std::endl;
    std::cout << "| 18:30  |" << std::endl;
    std::cout << "| 19:00  |" << std::endl;
    std::cout << "| 19:30  |" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;

}

bool alphOrder(Student s1, Student s2){
    return s1.getName()<s2.getName();
}

void listStudents() {
    short choice;
    int count = 0;
    std::string _class, year, ucCode;
    std::string last = " ";
    std::vector<Student> students = obj.getStudents();
    std::sort(students.begin(),students.end(), alphOrder);

    std::cout << "--------------------------------" << std::endl;
    std::cout << "| 1- Listar por ano            |" << std::endl;
    std::cout << "| 2- Listar por UC             |" << std::endl;
    std::cout << "| 3- Listar por turma          |" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "\nInserir ano:" ; std::cin >> year;
            std::cout << "\nEstudantes do " << year << "o ano: \n" << std::endl;
            for(Student student : students){
                for(ClassUc classUc: student.getClasses()){
                    if(classUc.get_classCode().substr(0,1) == year && student.getName() != last){
                        count++;
                        std::cout<< count <<" - " << student.getName() << std::endl;
                        last = student.getName();
                    }
                }
            }
            break;

        case 2:
            std::cout << "Inserir UC:"; std::cin >> ucCode;
            std::cout << "\nEstudantes de " << ucCode << ":\n" << std::endl;
            for(Student student : students){
                for(ClassUc classUc: student.getClasses()){
                    if(classUc.get_ucCode() == ucCode && student.getName() != last){
                        count++;
                        std::cout<< count <<" - "<< student.getName() << std::endl;
                        last = student.getName();
                    }
                }
            }
            break;

        case 3:
            std::cout << "Inserir UC:" ;std::cin >> ucCode;
            std::cout << "Inserir turma: "; std::cin >> _class;
            std::cout << "\nEstudantes de " << ucCode <<" da turma " <<_class << ":\n" << std::endl;
            for(Student student : students){
                for(ClassUc classUc: student.getClasses()){
                    if(classUc.get_ucCode() == ucCode && classUc.get_classCode() == _class && student.getName() != last){
                        count++;
                        std::cout<< count <<" - " << student.getName() << std::endl;
                        last = student.getName();
                    }
                }
            }
            break;
        case 0: //voltar para trás
            showMenu();

        default:
            //colocar erro
            break;
    }
}

int main(){
    short choice;
    obj.readFiles("classes_per_uc.csv","classes.csv","students_classes.csv");
    //test_students();
    //test_schedules()

    showMenu(); std::cin >> choice;

    switch (choice) {
        case 1:
            occupations();
            break;

        case 2:
            showSchedule();
            break;

        case 3:
            listStudents();
            break;

        case 4:
            break;

        case 5:
            break;

        default:
            break;
    }


    return 0;
}