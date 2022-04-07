#include "Menu.h"

void menu() {
    int option;
    Project** projects = nullptr;
    size_t  projectsSize = 0, employeesSize = 0;

    Employee* employees = nullptr;

    while (true)
    {
        cout << "\nChoose number (1-2):\n";
        cout << "\n\n1 - Projects menu \n";
        cout << "2 - Employees menu \n";
        cin >> option;
        switch (option) {
        case 1:
            cout << "\n------------------------------------\n";
            cout << "Projects manager menu";
            cout << "\n------------------------------------\n";
            projectsManager(projects, projectsSize);
            break;
        case 2:
            cout << "\n------------------------------------\n";
            cout << " Employees manager menu";
            cout << "\n------------------------------------\n";
            employeesManager(employees, employeesSize);
            break;
        default:
            cout << "\n------------------------------------\n";
            cout << "[WARNING] - Wrong option!";
            cout << "\n------------------------------------\n";
            break;
        }
    }
}
