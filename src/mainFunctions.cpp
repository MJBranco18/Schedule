#include <iostream>
#include "ScheduleManager.h"
#include "ScheduleUc.h"
#include "Student.h"
#include "Slot.h"
#include "ClassUc.h"
#include "Order.h"
#include "orderFunctions.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

ScheduleManager obj;
std::queue<Order> orders;

/**
 *  Main menu da aplicação
 */
void showMenu(){
    std::cout << "\n\n------------------- Menu -------------------" << std::endl;
    std::cout << "| 1- Ocupacao                              |" << std::endl;
    std::cout << "| 2- Horario                               |" << std::endl;
    std::cout << "| 3- Listar Estudantes                     |" << std::endl;
    std::cout << "| 4- Estudantes com mais de n UC's         |" << std::endl;
    std::cout << "| 5- Adicionar pedido de troca de turma    |" << std::endl;
    std::cout << "| 6- Tratar pedidos                        |" << std::endl;
    std::cout << "| 0- Sair                                  |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}
/**
 * Função para as ocupações
 */
void occupations(){
    short choice;
    unsigned long nTurmas;
    bool totalParcial;
    std::string ucCode;
    std::set<Student> students = obj.getStudents();
    auto it = students.begin();
    std::vector<std::pair<int,int>> occupations(16,{0,0});
    std::cout << "Inserir UC: "; std::cin >> ucCode;

    for(int i = 1; i <= 16; i++) occupations[i-1].first = i;

    for(; it != students.end();it++){
        for(const ClassUc& currClassUc : it->getClasses()){
            if(ucCode == currClassUc.get_ucCode()){
                int _class = std::stoi(currClassUc.get_classCode().substr(5));
                occupations[_class-1].second++;
            }
        }
    }


    //Menu para escolher a ordenação das ocupações
    std::cout << "\n--------------------------------" << std::endl;
    std::cout << "| 1- Ordenar por turma         |"<< std::endl;
    std::cout << "| 2- Ordenacao crescente       |" << std::endl;
    std::cout << "| 3- Ordenacao decrescente     |" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cin >> choice;


    std::cout << "Listagem total ou parcial? (1 = total, 0 = parcial): "; std::cin >> totalParcial;


    //Caso o utilizador escolha a listagem parcial, introduz quantas turmas quiser listar
    if(totalParcial) nTurmas = occupations.size();
    else {
        std::cout << "\nQuantas turmas? "; std::cin >> nTurmas;
    }


    //Dar handle à escolha do utilizador
    switch (choice) {
        case 1:
            for(int i = 0 ; i < nTurmas ; i++) {
                if (!occupations[i].second) continue;
                std::cout << "Turma " << occupations[i].first << ": " << occupations[i].second << std::endl;
            }
            break;

        case 2:
            std::sort(occupations.begin(),occupations.end(), occupationsCresc);
            for(int i = 0 ; i < nTurmas ; i++) {
                if (!occupations[i].second) continue;
                std::cout << "Turma " << occupations[i].first << ": " << occupations[i].second << std::endl;
            }
            break;

        case 3:
            std::sort(occupations.begin(),occupations.end(), occupationsDecresc);
            for(int i = 0 ; i < nTurmas ; i++) {
                if (!occupations[i].second) continue;
                std::cout << "Turma " << occupations[i].first << ": " << occupations[i].second << std::endl;
            }
            break;

        default:
            std::cout << "\nEscolha uma opção valida." << std::endl;
            break;
    }
}

/**
 * Função para preencher a matriz do horário
 */
void durations(const ScheduleUc& currentClass, const Slot& currentSlot, std::vector<std::vector<std::string>>& sm, int day){
    /*
     * Handle das várias situações:
     *  - Duração da aula;
     *  - Começo da aula;
     */
    if(currentSlot.get_duration() == 1){
        std::string temp = std::to_string(currentSlot.get_startHour());
        temp = temp.substr(0,temp.find('.') + 2);
        if (temp.length() == 3){
            if(temp[2] == '0') {
                int place = temp[0] - '0' - 8;
                sm[2*(place + 1*place)][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type() +
                        (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place) + 1][day] = "               ";
                sm[2*(place + 1*place + 1)][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
            }
            else if(temp[2] == '5') {
                int place = temp[0] - '0' - 8;
                sm[2*(place + 1*place + 1)][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place + 1) + 1][day] = "               ";
                sm[2*(place + 1*place + 2)][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
            }
        }
        else if (temp.length() == 4){
            if(temp[3] == '0') {
                int place = std::stoi(temp.substr(0,2)) - 8;
                sm[2*(place + 1*place)][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type() +
                        (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place) + 1 ][day] = "               ";
                sm[2*(place + 1 *place + 1)][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
            }
            else if(temp[3] == '5') {
                int place = std::stoi(temp.substr(0,2)) - 8;
                sm[2*(place + 1*place + 1)][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place + 1) + 1][day] = "               ";
                sm[2*(place + 1*place + 2)][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
            }
        }
    }

    else if(currentSlot.get_duration() == 1.5){
        std::string temp = std::to_string(currentSlot.get_startHour());
        temp = temp.substr(0,temp.find('.') + 2);
        if (temp.length() == 3){
            if(temp[2] == '0') {
                int place = temp[0] - '0' - 8;
                sm[2*(place + 1*place)][day] = "               ";
                sm[2*(place + 1*place) + 1][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place) + 2][day] = "               ";
                sm[2*(place + 1*place) + 3][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2*(place + 1*place) + 4][day] = "               ";
            }
            else if(temp[2] == '5') {
                int place = temp[0] - '0' - 8;
                sm[2*(place + 1*place + 1)][day] = "               ";
                sm[2*(place + 1*place + 1) + 1][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place + 1) + 2][day] = "               ";
                sm[2*(place + 1*place + 1) + 3][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2*(place + 1*place + 1) + 4][day] = "               ";
            }
        }
        else if (temp.length() == 4){
            if(temp[3] == '0') {
                int place = std::stoi(temp.substr(0,2)) - 8;
                sm[2*(place + 1*place)][day] = "               ";
                sm[2*(place + 1*place) + 1][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place) + 2][day] = "               ";
                sm[2*(place + 1*place) + 3][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2*(place + 1*place) + 4][day] = "               ";
            }
            else if(temp[3] == '5') {
                int place = std::stoi(temp.substr(0,2)) - 8;
                sm[2*(place + 1*place + 1)][day] = "               ";
                sm[2*(place + 1*place + 1) + 1][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place + 1) + 2][day] = "               ";
                sm[2*(place + 1*place + 1) + 3][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2*(place + 1*place + 1) + 4][day] = "               ";
            }
        }
    }

    else if(currentSlot.get_duration() == 2){
        std::string temp = std::to_string(currentSlot.get_startHour());
        temp = temp.substr(0,temp.find('.') + 2);
        if (temp.length() == 3){
            if(temp[2] == '0') {
                int place = temp[0] - '0' - 8;
                sm[2* (place + 1*place)][day] = "               ";
                sm[2* (place + 1*place) + 1][day] = "               ";
                sm[2* (place + 1*place) + 2][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2* (place + 1*place) + 3][day] = "               ";
                sm[2* (place + 1*place) + 4][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2* (place + 1*place) + 5][day] = "               ";
                sm[2* (place + 1*place) + 6][day] = "               ";
            }
            else if(temp[2] == '5') {
                int place = temp[0] - '0' - 8;
                sm[2*(place + 1*place + 1)][day] = "               ";
                sm[2*(place + 1*place + 1) + 1][day] = "               ";
                sm[2*(place + 1*place + 1) + 2][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2*(place + 1*place + 1) + 3][day] = "               ";
                sm[2*(place + 1*place + 1) + 4][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2*(place + 1*place + 1) + 5][day] = "               ";
                sm[2*(place + 1*place + 1) + 6][day] = "               ";
            }
        }
        else if (temp.length() == 4){
            if(temp[3] == '0') {
                int place = std::stoi(temp.substr(0,2)) - 8;
                sm[2* (place + 1*place)][day] = "               ";
                sm[2* (place + 1*place) + 1][day] = "               ";
                sm[2* (place + 1*place) + 2][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2* (place + 1*place) + 3][day] = "               ";
                sm[2* (place + 1*place) + 4][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2* (place + 1*place) + 5][day] = "               ";
                sm[2* (place + 1*place) + 6][day] = "               ";
            }
            else if(temp[3] == '5') {
                int place = std::stoi(temp.substr(0,2)) - 8;
                sm[2* (place + 1*place)][day] = "               ";
                sm[2* (place + 1*place) + 1][day] = "               ";
                sm[2* (place + 1*place) + 2][day] = "  " + currentClass.get_classUc().get_ucCode() + "  " + currentSlot.get_type()
                        + (currentSlot.get_type().length() == 1 ? "  " : " ");
                sm[2* (place + 1*place) + 3][day] = "               ";
                sm[2* (place + 1*place) + 4][day] = "    " + currentClass.get_classUc().get_classCode() + "    ";
                sm[2* (place + 1*place) + 5][day] = "               ";
                sm[2* (place + 1*place) + 6][day] = "               ";
            }
        }
    }
}

/**
 * Função que chama a função anterior para cada aula do aluno e
 * escreve na consola o horário atravez de uma matriz para o utilizador
 */
void showSchedule(const std::string& stuName){
    std::set<Student> students = obj.getStudents();
    Student s; s.setName(stuName);
    auto it = students.find(s);
    ScheduleUc studentClasses;
    std::vector<ScheduleUc> scheduleUc = obj.getSchedule(), studentSchedule;
    std::vector<Slot> classesCurrentScheduleUc;
    std::vector<std::vector<std::string>> sm(
            43,std::vector<std::string>(5,"---------------")); //matriz para colocar as aulas


    if(it != students.end()) {
        for (const ClassUc &classUc: it->getClasses()) {
            for (const ScheduleUc &currentScheduleUc: scheduleUc) {
                if (classUc.get_classCode() == currentScheduleUc.get_classUc().get_classCode()
                    && classUc.get_ucCode() == currentScheduleUc.get_classUc().get_ucCode()) {
                    classesCurrentScheduleUc = currentScheduleUc.get_ucClassSchedule();
                    studentClasses.set_ucClassSchedule(classesCurrentScheduleUc);
                    studentClasses.set_classUc({classUc.get_ucCode(), classUc.get_classCode()});
                    studentSchedule.push_back(studentClasses);
                }
            }
        }


        for (const ScheduleUc &currentClass: studentSchedule) {
            for (const Slot &currentSlot: currentClass.get_ucClassSchedule()) {
                if (currentSlot.get_day() == "Monday") {
                    durations(currentClass, currentSlot, sm, 0);
                } else if (currentSlot.get_day() == "Tuesday") {
                    durations(currentClass, currentSlot, sm, 1);
                } else if (currentSlot.get_day() == "Wednesday") {
                    durations(currentClass, currentSlot, sm, 2);
                } else if (currentSlot.get_day() == "Thursday") {
                    durations(currentClass, currentSlot, sm, 3);
                } else if (currentSlot.get_day() == "Friday") {
                    durations(currentClass, currentSlot, sm, 4);
                }
            }
        }
    }

    std::cout << "\n" << stuName << "'s schedule: " << std::endl;

    std::cout << "------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Inicio |    Segunda    |     Terca     |    Quarta     |    Quinta     |     Sexta     |" << std::endl;
    std::cout << "|--------|---------------|---------------|---------------|---------------|---------------|" << std::endl;
    std::cout << "|  8:00  |" << sm[0][0] << '|' << sm[0][1] << '|' << sm[0][2] << '|' << sm[0][3] << '|' << sm[0][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[1][0] << '|' << sm[1][1] << '|' << sm[1][2] << '|' << sm[1][3] << '|' << sm[1][4] << '|' << std::endl;
    std::cout << "|  8:30  |" << sm[2][0] << '|' << sm[2][1] << '|' << sm[2][2] << '|' << sm[2][3] << '|' << sm[2][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[3][0] << '|' << sm[3][1] << '|' << sm[3][2] << '|' << sm[3][3] << '|' << sm[3][4] << '|' << std::endl;
    std::cout << "|  9:00  |" << sm[4][0] << '|' << sm[4][1] << '|' << sm[4][2] << '|' << sm[4][3] << '|' << sm[4][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[5][0] << '|' << sm[5][1] << '|' << sm[5][2] << '|' << sm[5][3] << '|' << sm[5][4] << '|' << std::endl;
    std::cout << "|  9:30  |" << sm[6][0] << '|' << sm[6][1] << '|' << sm[6][2] << '|' << sm[6][3] << '|' << sm[6][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[7][0] << '|' << sm[7][1] << '|' << sm[7][2] << '|' << sm[7][3] << '|' << sm[7][4] << '|' << std::endl;
    std::cout << "| 10:00  |" << sm[8][0] << '|' << sm[8][1] << '|' << sm[8][2] << '|' << sm[8][3] << '|' << sm[8][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[9][0] << '|' << sm[9][1] << '|' << sm[9][2] << '|' << sm[9][3] << '|' << sm[9][4] << '|' << std::endl;
    std::cout << "| 10:30  |" << sm[10][0] << '|' << sm[10][1] << '|' << sm[10][2] << '|' << sm[10][3] << '|' << sm[10][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[11][0] << '|' << sm[11][1] << '|' << sm[11][2] << '|' << sm[11][3] << '|' << sm[11][4] << '|' << std::endl;
    std::cout << "| 11:00  |" << sm[12][0] << '|' << sm[12][1] << '|' << sm[12][2] << '|' << sm[12][3] << '|' << sm[12][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[13][0] << '|' << sm[13][1] << '|' << sm[13][2] << '|' << sm[13][3] << '|' << sm[13][4] << '|' << std::endl;
    std::cout << "| 11:30  |" << sm[14][0] << '|' << sm[14][1] << '|' << sm[14][2] << '|' << sm[14][3] << '|' << sm[14][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[15][0] << '|' << sm[15][1] << '|' << sm[15][2] << '|' << sm[15][3] << '|' << sm[15][4] << '|' << std::endl;
    std::cout << "| 12:00  |" << sm[16][0] << '|' << sm[16][1] << '|' << sm[16][2] << '|' << sm[16][3] << '|' << sm[16][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[17][0] << '|' << sm[17][1] << '|' << sm[17][2] << '|' << sm[17][3] << '|' << sm[17][4] << '|' << std::endl;
    std::cout << "| 12:30  |" << sm[18][0] << '|' << sm[18][1] << '|' << sm[18][2] << '|' << sm[18][3] << '|' << sm[18][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[19][0] << '|' << sm[19][1] << '|' << sm[19][2] << '|' << sm[19][3] << '|' << sm[19][4] << '|' << std::endl;
    std::cout << "| 13:00  |" << sm[20][0] << '|' << sm[20][1] << '|' << sm[20][2] << '|' << sm[20][3] << '|' << sm[20][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[21][0] << '|' << sm[21][1] << '|' << sm[21][2] << '|' << sm[21][3] << '|' << sm[21][4] << '|' << std::endl;
    std::cout << "| 13:30  |" << sm[22][0] << '|' << sm[22][1] << '|' << sm[22][2] << '|' << sm[22][3] << '|' << sm[22][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[23][0] << '|' << sm[23][1] << '|' << sm[23][2] << '|' << sm[23][3] << '|' << sm[23][4] << '|' << std::endl;
    std::cout << "| 14:00  |" << sm[24][0] << '|' << sm[24][1] << '|' << sm[24][2] << '|' << sm[24][3] << '|' << sm[24][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[25][0] << '|' << sm[25][1] << '|' << sm[25][2] << '|' << sm[25][3] << '|' << sm[25][4] << '|' << std::endl;
    std::cout << "| 14:30  |" << sm[26][0] << '|' << sm[26][1] << '|' << sm[26][2] << '|' << sm[26][3] << '|' << sm[26][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[27][0] << '|' << sm[27][1] << '|' << sm[27][2] << '|' << sm[27][3] << '|' << sm[27][4] << '|' << std::endl;
    std::cout << "| 15:00  |" << sm[28][0] << '|' << sm[28][1] << '|' << sm[28][2] << '|' << sm[28][3] << '|' << sm[28][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[29][0] << '|' << sm[29][1] << '|' << sm[29][2] << '|' << sm[29][3] << '|' << sm[29][4] << '|' << std::endl;
    std::cout << "| 15:30  |" << sm[30][0] << '|' << sm[30][1] << '|' << sm[30][2] << '|' << sm[30][3] << '|' << sm[30][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[31][0] << '|' << sm[31][1] << '|' << sm[31][2] << '|' << sm[31][3] << '|' << sm[31][4] << '|' << std::endl;
    std::cout << "| 16:00  |" << sm[32][0] << '|' << sm[32][1] << '|' << sm[32][2] << '|' << sm[32][3] << '|' << sm[32][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[33][0] << '|' << sm[33][1] << '|' << sm[33][2] << '|' << sm[33][3] << '|' << sm[33][4] << '|' << std::endl;
    std::cout << "| 16:30  |" << sm[34][0] << '|' << sm[34][1] << '|' << sm[34][2] << '|' << sm[34][3] << '|' << sm[34][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[35][0] << '|' << sm[35][1] << '|' << sm[35][2] << '|' << sm[35][3] << '|' << sm[35][4] << '|' << std::endl;
    std::cout << "| 17:00  |" << sm[36][0] << '|' << sm[36][1] << '|' << sm[36][2] << '|' << sm[36][3] << '|' << sm[36][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[37][0] << '|' << sm[37][1] << '|' << sm[37][2] << '|' << sm[37][3] << '|' << sm[37][4] << '|' << std::endl;
    std::cout << "| 17:30  |" << sm[38][0] << '|' << sm[38][1] << '|' << sm[38][2] << '|' << sm[38][3] << '|' << sm[38][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[39][0] << '|' << sm[39][1] << '|' << sm[39][2] << '|' << sm[39][3] << '|' << sm[39][4] << '|' << std::endl;
    std::cout << "| 18:00  |" << sm[40][0] << '|' << sm[40][1] << '|' << sm[40][2] << '|' << sm[40][3] << '|' << sm[40][4] << '|' << std::endl;
    std::cout << "|--------|" << sm[41][0] << '|' << sm[41][1] << '|' << sm[41][2] << '|' << sm[41][3] << '|' << sm[41][4] << '|' << std::endl;
    std::cout << "| 18:30  |" << sm[42][0] << '|' << sm[42][1] << '|' << sm[42][2] << '|' << sm[42][3] << '|' << sm[42][4] << '|' << std::endl;
    std::cout << "------------------------------------------------------------------------------------------" << std::endl;

}

/**
 * Função que lista os estudantes de cada ano/UC/turma
 */
void listStudents() {
    short choice;
    int count = 0;
    unsigned long nStudents;
    bool totalParcial;
    std::string _class, year, ucCode;
    std::string last = " ";
    std::set<Student> students = obj.getStudents();

    std::cout << "--------------------------------" << std::endl;
    std::cout << "| 1- Listar por ano            |" << std::endl;
    std::cout << "| 2- Listar por UC             |" << std::endl;
    std::cout << "| 3- Listar por turma          |" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cin >> choice;


    std::cout << "Listagem total ou parcial? (1 = total, 0 = parcial): "; std::cin >> totalParcial;


    //Caso o utilizador escolha a listagem parcial, introduz quantas turmas quiser listar
    if(!totalParcial) {
        std::cout << "\nQuantos estudantes? "; std::cin >> nStudents;
    }
    else nStudents = INT32_MAX;


    //Dar handle à escolha do utilizador
    switch (choice) {
        case 1:
            std::cout << "\nInserir ano: ";
            std::cin >> year;
            std::cout << "\nEstudantes do " << year << "o ano: \n" << std::endl;
            for (const Student &student: students) {
                for (const ClassUc &classUc: student.getClasses()) {
                    if (classUc.get_classCode().substr(0, 1) == year && student.getName() != last && count < nStudents) {
                        count++;
                        std::cout << student.getName() << " - " << student.getStuCode() << std::endl;
                        last = student.getName();
                    }
                }
            }
            if(totalParcial) {
                std::cout << "\nEstao inscritos " << count << " estudantes no " << year << "o ano." << std::endl;
            }
            break;

        case 2:
            std::cout << "Inserir UC: "; std::cin >> ucCode;
            std::cout << "\nEstudantes de " << ucCode << ":\n" << std::endl;
            for(const Student& student : students){
                for(const ClassUc& classUc: student.getClasses()){
                    if(classUc.get_ucCode() == ucCode && student.getName() != last && count < nStudents){
                        count++;
                        std::cout << student.getName() << " - " << student.getStuCode() << std::endl;
                        last = student.getName();
                    }
                }
            }
            if(totalParcial) {
                std::cout << "\nEstao inscritos " << count << " estudantes em " << ucCode << "." << std::endl;
            }
            break;

        case 3:
            std::cout << "Inserir UC: " ; std::cin >> ucCode;
            std::cout << "Inserir turma (apenas o numero): "; std::cin >> _class;
            std::cout << "\nEstudantes de " << ucCode << " da turma " << _class << ":\n" << std::endl;
            for(const Student& student : students){
                for(const ClassUc& classUc: student.getClasses()){
                    if(classUc.get_ucCode() == ucCode && std::to_string(std::stoi(classUc.get_classCode()
                    .substr(classUc.get_classCode().size()-2))) == _class && student.getName() != last && count < nStudents){
                        count++;
                        std::cout << count << " - " << student.getName() << " - " << student.getStuCode() << std::endl;
                        last = student.getName();
                    }
                }
            }
            break;

        default:
            std::cout << "\nEscolha uma opcao valida." << std::endl;
            break;
    }
}

/**
 * Função que mostra quais os estudantes que têm mais que um determinado número de UC's
 */
void moreThanNUc(){
    short n;
    int count = 0;
    bool totalParcial;
    unsigned long nStudents;
    std::set<Student> students = obj.getStudents();

    std::cout << "Estudantes inscritos em mais de quantas UC's? "; std::cin >> n;

    std::cout << "Listagem total ou parcial? (1 = total, 0 = parcial): "; std::cin >> totalParcial;


    //Caso o utilizador escolha a listagem parcial, introduz quantas turmas quiser listar
    if(!totalParcial) {
        std::cout << "\nQuantos estudantes? "; std::cin >> nStudents;
    }
    else nStudents = INT32_MAX;

    std::cout << "Estudantes inscritos em mais de " << n << " UC's: \n" << std::endl;

    for(const Student& student : students){
        if(student.getClasses().size() > n && count < nStudents){
            count++;
            std::cout << student.getName() << " - "  << student.getStuCode() <<std::endl;
        }
    }
    if(totalParcial) {
        std::cout << "\n" << count << " estudantes tem mais de " << n << " UC's.";
    }
}

/**
 * Função que recebe o input do utilizador de um pedido de alteração de horário
 */
void addOrder(){
    short choice = 0;
    std::string studentName, classCode, ucCode, classCodeRem, classCodeAdd, ucCodeRem, ucCodeAdd;
    std::set<Student> students = obj.getStudents();
    Student s;
    auto it = students.begin();
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "| 1- Remover estudante de turma               |" << std::endl;
    std::cout << "| 2- Adicionar estudante a turma              |" << std::endl;
    std::cout << "| 3- Alterar turma                            |" << std::endl;
    std::cout << "| 4- Alterar conjunto de turmas               |" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    std::cin >> choice;


    //Handle da escolha do utilizador
    switch (choice) {
        case 1:
        case 2:
            std::cout << "Nome Estudante: ";
            std::cin >> studentName;
            std::cout << "Turma: ";
            std::cin >> classCode;
            std::cout << "UC: ";
            std::cin >> ucCode;
            s.setName(studentName);
            it = students.find(s);

            if(it != students.end()){
                if (choice != 1) {
                    for (const ClassUc &curr: it->getClasses()) {
                        if (curr.get_ucCode() == ucCode) {
                            std::cout << "Este estudante ja tem essa UC." << std::endl;
                        }
                    }
                }
                Order _new = Order(*it, {ucCode, classCode}, choice);
                orders.push(_new);
            }
            break;
        case 3:
            std::cout << "Nome Estudante: ";
            std::cin >> studentName;
            std::cout << "Turma a remover: ";
            std::cin >> classCodeRem;
            std::cout << "UC a remover: ";
            std::cin >> ucCodeRem;
            std::cout << "Turma a adicionar: ";
            std::cin >> classCodeAdd;
            std::cout << "UC a adicionar: ";
            std::cin >> ucCodeAdd;

            s.setName(studentName);
            it = students.find(s);

            if(it != students.end()) {
                if (choice != 1) {
                    for (const ClassUc &curr: it->getClasses()) {
                        if (curr.get_ucCode() == ucCodeAdd && ucCodeRem != ucCodeAdd) {
                            std::cout << "Este estudante ja tem essa UC." << std::endl;
                        }
                    }
                }
                Order _new = Order(*it, {ucCodeRem, classCodeRem},
                                   {ucCodeAdd, classCodeAdd}, choice);
                orders.push(_new);
            }
            break;

        case 4:
            short n;
            std::cout << "Nome Estudante: ";
            std::cin >> studentName;
            std::cout << "Quantas turmas quer adicionar/remover? "; std::cin >> n;

            s.setName(studentName);
            it = students.find(s);

            if(it != students.end()) {
                if (choice != 1) {
                    for (const ClassUc &curr: it->getClasses()) {
                        if (curr.get_ucCode() == ucCode && ucCodeRem != ucCodeAdd) {
                            std::cout << "Este estudante ja tem essa UC." << std::endl;
                        }
                    }
                }

                for(int i = 1; i <= n ; i++) {
                    std::cout << "Turma a remover: ";
                    std::cin >> classCodeRem;
                    std::cout << "UC a remover: ";
                    std::cin >> ucCodeRem;
                    std::cout << "Turma a adicionar: ";
                    std::cin >> classCodeAdd;
                    std::cout << "UC a adicionar: ";
                    std::cin >> ucCodeAdd;
                    Order _new = Order(*it, {ucCodeRem, classCodeRem},
                                       {ucCodeAdd, classCodeAdd}, 3);
                    orders.push(_new);
                }
            }

            break;

        default:
            std::cout << "\nEscolha uma opcao valida." << std::endl;
            break;
    }
}

/**
 * Função que verifica se uma turma pode ser adicionada a uma estudante
 */

bool canAdd(Order& current){
    int minOccupation = 10000;
    std::set<Student> students = obj.getStudents();
    std::vector<ScheduleUc> schedule = obj.getSchedule();
    std::vector<Slot> studentsHours, newClassesHours;
    int occupation = 0, cap = 28;


    //definir ocupacao da turma
    for(const Student& student : students){
        for(const ClassUc& currClassUc : student.getClasses()){
            if(current.getClassUc().get_ucCode() == currClassUc.get_ucCode()
            && current.getClassUc().get_classCode() == currClassUc.get_classCode()){
                occupation++;
            }
        }
    }

    if(occupation >= cap) {
        std::cout << "Nao foi possivel adicionar o/a " << current.getStudent().getName() << " a turma " <<
                  current.getClassUc().get_classCode() << " da UC " <<
                  current.getClassUc().get_ucCode() << " devido a turma estar cheia." << std::endl;
        return false;
    }


    //horas da turma do pedido
    for(const ScheduleUc& currSchedule : schedule){
        if(currSchedule.get_classUc().get_ucCode() == current.getClassUc().get_ucCode() &&
           currSchedule.get_classUc().get_classCode() == current.getClassUc().get_classCode()){
            newClassesHours = currSchedule.get_ucClassSchedule();
        }
    }


    for(const ClassUc& _class : current.getStudent().getClasses()) {
        //horas para cada turma do estudante
        for (const ScheduleUc &currSchedule: schedule) {
            if (currSchedule.get_classUc().get_ucCode() == _class.get_ucCode() &&
                currSchedule.get_classUc().get_classCode() == _class.get_classCode()) {
                studentsHours = currSchedule.get_ucClassSchedule();
            }
        }

        for(const Slot& slot1 : studentsHours){
            for(const Slot& slot2 : newClassesHours){
                if((slot1.get_day() == slot2.get_day() &&
                    (slot2.get_startHour() + slot2.get_duration() <= slot1.get_startHour() ||
                     slot2.get_startHour() >= slot1.get_startHour() + slot1.get_duration())) || slot1.get_day() != slot2.get_day())
                    continue;
                else {
                    std::cout << "Nao foi possivel adicionar o/a " << current.getStudent().getName() << " a turma " <<
                              current.getClassUc().get_classCode() << " da UC " <<
                              current.getClassUc().get_ucCode() << " devido a sobreposicao de horarios."
                              << std::endl;
                    return false;
                }
            }
        }
    }


    //ocupacao de todas as turmas para verificar desiquilibrio
    std::vector<std::pair<int,int>> occupations(16,{0,0});

    for(int i = 1; i <= 16; i++) occupations[i-1].first = i;

    for(const Student& student : students){
        for(const ClassUc& currClassUc : student.getClasses()){
            if(current.getClassUc().get_ucCode() == currClassUc.get_ucCode()){
                int _class = std::stoi(currClassUc.get_classCode().substr(5));
                occupations[_class-1].second++;
            }
        }
    }

    for(auto p : occupations){
        if (p.second == 0) continue;

        if (p.second < minOccupation) minOccupation = p.second;
    }

    if(occupations[std::stoi(current.getClassUc().get_classCode().substr(5)) - 1].second + 1
    >= minOccupation + 4) {
        std::cout << "Nao foi possivel adicionar o/a " << current.getStudent().getName() << " a turma " <<
                  current.getClassUc().get_classCode() << " da UC " <<
                  current.getClassUc().get_ucCode() << " devido a uma provocacao de desiquilibrio "
                                                       "entre turmas." << std::endl;
        return false;
    }

    return true;
}

/**
 * Função que trata dos pedidos adicionados à fila de espera
 */

void changeSchedule() {
    ClassUc temp;
    while(!orders.empty()) {
        Order current = orders.front();
        orders.pop();
        auto it = obj.getStudents().find(current.getStudent());

        switch (current.getType()) {
            case 1: //remover turma a estudante
                if(it != obj.getStudents().end()){
                    for (int i = 0; i < it->getClasses().size(); i++) {
                        if (it->getClasses()[i].get_classCode() == current.getClassUc().get_classCode()
                            && it->getClasses()[i].get_ucCode() == current.getClassUc().get_ucCode()) {
                            Student s = *it;
                            s.removeClass(i);
                            *it = s;
                            current.getStudent().removeClass(i);
                        }
                    }
                }

                std::cout << "Turma " << current.getClassUc().get_classCode() << " removida do horario do/a " << current.getStudent().getName() << std::endl;
                break;

            case 2: //adicionar turma a estudante
                if (canAdd(current)) {
                    if(it != obj.getStudents().end()){
                        Student s = *it;
                        s.addClass(current.getClassUc());
                        *it = s;
                    }
                    std::cout << "Turma " << current.getClassUc().get_classCode() << " adicionada ao horario do/a " <<
                    current.getStudent().getName() << std::endl;
                }
                break;

            case 3: //alterar uma turma por outra
                //remove a turma incialmente
                if(it != obj.getStudents().end()){
                    for (int i = 0; i < it->getClasses().size(); i++) {
                        if (it->getClasses()[i].get_classCode() == current.getClassUcRem().get_classCode()
                            && it->getClasses()[i].get_ucCode() == current.getClassUcRem().get_ucCode()) {
                            temp = current.getClassUc();
                            Student s = *it;
                            s.removeClass(i);
                            *it = s;
                            current.getStudent().removeClass(i);
                        }
                    }
                }


                if (canAdd(current)) { //se puder adicionar, adiciona
                    if(it != obj.getStudents().end()){
                        current.getStudent().addClass(temp);
                        Student s = *it;
                        s.addClass(current.getClassUc());
                        *it = s;
                    }
                    std::cout << "Turma " << current.getClassUc().get_classCode() << " adicionada ao horario do/a " <<
                    current.getStudent().getName() << std::endl;
                }
                else { //se não puder adicionar, adiciona a turma previamente removida
                    if(it != obj.getStudents().end()) {
                        Student s = *it;
                        s.addClass(current.getClassUcRem());
                        *it = s;
                    }
                }
                break;

            default:
                break;
        }
    }
}
