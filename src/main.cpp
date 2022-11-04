#include <iostream>
#include "mainFunctions.cpp"
#include <vector>

void test(){
    std::set<Student> students = obj.getStudents();
    std::string studentName;
    Student s;

    std::cout << "Nome Estudante: ";
    std::cin >> studentName;

    s.setName(studentName);
    auto it = students.find(s);

    if( it != students.end()){
        std::cout << "Found " << it->getName() << " - " << it->getStuCode() << std::endl;
    }
}

/**
 * Função principal que corre a aplicação
 */
int main(){
    short choice = 0;
    std::string stuName;
    obj.readFiles("classes_per_uc.csv","classes.csv","students_classes.csv");
    test();
    /*
    //while para poder fazer várias mudanças e operações sem ter que correr o programa outra vez
    while(choice != -1) {
        showMenu(); std::cin >> choice;

        switch (choice) {
            case 1:
                occupations();
                break;

            case 2:
                std::cout << "Nome estudante: ";
                std::cin >> stuName;
                showSchedule(stuName);
                break;

            case 3:
                listStudents();
                break;

            case 4:
                moreThanNUc();
                break;

            case 5:
                addOrder();
                break;

            case 6:
                changeSchedule();
                break;

            case 0:
                choice = -1;
                break;

            default:
                std::cout << "\nEscolha uma opcao valida." << std::endl;
                break;
        }
    }
*/
    return 0;
}