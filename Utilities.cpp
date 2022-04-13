#include "Utilities.h"

void Utilities::menu(Company *&company, Employee *&employees)
{
    int option;
    size_t projectsSize = 0, employeesSize = 0;

    while (true)
    {
        cout << "\x1B[36m";
        cout << "\nWybierz numer (1-2):\n";
        cout << "\n\n1 - Company menu \n";
        cout << "2 - Employees menu \n";
        cout << "0 - Quit \n";
        cout << "\033[0m";
        cin >> option;
        switch (option)
        {
        case 0:
            cout << "Goodbay\n";
            return;
        case 1:
            cout << "\x1B[33m";
            cout << "\n------------------------------------\n";
            cout << "Company menu";
            cout << "\n------------------------------------\n";
            cout << "\033[0m";
            company->projectsManager();
            break;
        case 2:
            cout << "\x1B[33m";
            cout << "\n------------------------------------\n";
            cout << " Employees menu";
            cout << "\n------------------------------------\n";
            cout << "\033[0m";
            employeesManager(employees, employeesSize);
            break;
        default:
            cout << "\x1B[31m";
            cout << "\n------------------------------------\n";
            cout << "[WARNING] - Wrong option!";
            cout << "\n------------------------------------\n";
            cout << "\033[0m";
            break;
        }
    }
}
