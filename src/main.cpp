#include <iostream>
#include "ScheduleUc.h"
#include "Student.h"
#include "Slot.h"
#include "ClassUc.h"
#include "mainFunctions.cpp"
#include <string>
#include <vector>


void test_schedules(){
    std::vector<ScheduleUc> schedules = obj.getSchedule();
    for(const ScheduleUc& s : schedules){
        std::cout << "\n" << s.get_classUc().get_ucCode() << " - " << s.get_classUc().get_classCode() <<  ":" << std::endl;

        for(const Slot& slot : s.get_ucClassSchedule()){
            std::cout << slot.get_day() << " at " << slot.get_startHour() << " during "
                      << slot.get_duration() << " hours and type of class is " << slot.get_type() << std::endl;
        }

        std::cout << std::endl;
    }
}

void test_students(){
    std::vector<Student> students = obj.getStudents();
    for(const Student& s : students){
        std::cout << s.getName() << "-" << s.getStuCode() <<  ":" << std::endl;
        for(const ClassUc& c : s.getClasses()) std::cout << c.get_ucCode() << " - " << c.get_classCode() <<  std::endl;
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
            moreThanNUc();
            break;

        case 5:
            break;

        default:
            break;
    }


    return 0;
}