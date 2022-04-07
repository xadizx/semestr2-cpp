#include "Employee.h"

void Employee::print() {
    cout << "\n==============================\n";
    cout << "Displaying data for employee: " << this->id << "\n\n";
    cout << "First name: " << this->firstName << "\n";
    cout << "Last name: " << this->lastName << "\n";
    cout << "Year of birth: " << this->birthYear << "\n";
    cout << "Pesel: " << this->pesel;
    cout << "\n==============================\n";
}

void createEmployee(Employee*& employee) {
    employee = new Employee();
}
void removeEmployee(Employee*& employee) {
    delete employee;
    employee = nullptr;
}

void createEmployee(Employee*& employees, const size_t size) {
    employees = new Employee[size];
}
void printEmployee(Employee*& employees, const size_t size) {
    cout << "<======= Employees =======>\n";
    for (size_t i = 0; i < size; i++)
        employees[i].print();
}
void removeEmployee(Employee*& employees, const size_t size) {
    delete[] employees;
    employees = nullptr;
}

void removeEmployee(Employee*& employees, size_t& size, size_t index) {
    if (index < size) {
        Employee* temp = new Employee[size - 1];
        short int j = -1;
        for (size_t i = 0; i < size; ++i) {
            if (i != index) {
                ++j;
                // temp[j] = employees[i];
                temp[i].setFirstName(employees[i].getFirstName());
                temp[i].setLastName(employees[i].getLastName());
                temp[i].setPesel(employees[i].getPesel());
                temp[i].setBirthYear(employees[i].getBirthYear());
            }
        }
        delete[] employees;
        employees = temp;
        size--;
    }
    else
        cout << "ERROR: Index jest nieprawidłowy ! \n";
}
void addEmployee(Employee*& employees, size_t& size) {
    Employee* temp = new Employee[size + 1];

    for (size_t i = 0; i < size; i++){
        temp[i].setFirstName(employees[i].getFirstName());
        temp[i].setLastName(employees[i].getLastName());
        temp[i].setPesel(employees[i].getPesel());
        temp[i].setBirthYear(employees[i].getBirthYear());
        // temp[i] = employees[i];
    }

    delete[] employees;
    employees = temp;
    size++;
}
void printEmployeeFromYear(Employee*& employees, const size_t& size, unsigned int year) {
    cout << "<======= Employees born in " << year << " =======>\n";
    for (size_t i = 0; i < size; i++)
        if (employees[i].getBirthYear() == year) {
            employees[i].print();
        }
}

void editEmployee(Employee*& employees, size_t& size, size_t index) {
    string name,last,pesel;
    unsigned int newYear;
    cout << "Podaj nowe imie \n";
    cin >> name;
    employees[index].setFirstName(name);

    cout << "Podaj nowe nazwisko: \n";
    cin >> last;
    employees[index].setLastName(last);

    cout << "Podaj nowy pesel: \n";
    cin >> pesel;
    employees[index].setPesel(pesel);

    cout << "Podaj nowy rok urodzenia: \n";
    cin >> newYear;
    employees[index].setBirthYear(newYear);
}

void createEmployee(Employee**& employees, const size_t& size) {
    employees = new Employee * [size];
    for (size_t i = 0; i < size; i++)
        createEmployee(employees[i]);
}
void printEmployee(Employee** employees, const size_t& size) {
    cout << "<======= Employees =======>\n";
    for (size_t i = 0; i < size; i++)
        employees[i]->print();
}
void removeEmployee(Employee**& employees, size_t& size) {
    for (size_t ind = 0; ind < size; ind++)
        delete employees[ind];
    delete[] employees;
    employees = nullptr;
    size = 0;
}
void removeEmployee(Employee**& employees, size_t& size, size_t index) {
    if (index < size) {
        Employee** temp = new Employee * [size - 1];
        short int j = -1;
        for (size_t i = 0; i < size; ++i) {
            if (i != index) {
                ++j;
                temp[j] = employees[i];
            }
        }
        delete[] employees;
        employees = temp;
        size--;
    }
    else
        cout << "ERROR: Index jest nieprawidłowy ! \n";
}
void addEmployee(Employee**& employees, size_t& size) {
    Employee** temp = new Employee * [size + 1];
    if (size == 0) {
        createEmployee(temp[size]);
    }
    else {
        for (size_t i = 0; i < size; i++)
            temp[i] = employees[i];
        createEmployee(temp[size]);
        delete[] employees;
    }
    employees = temp;
    size++;
}
void printEmployeeFromYear(Employee**& employees, const size_t& size, unsigned int year) {
    cout << "<======= Employees born in " << year << " =======>\n";
    for (size_t i = 0; i < size; i++)
        if (employees[i]->getBirthYear() == year) {
            employees[i]->print();
        }
}
void editEmployee(Employee**& employees, size_t& size, size_t index) {
    string newValue;
    unsigned int newYear;
    cout << "Podaj nowe imie \n";
    cin >> newValue;
    employees[index]->setFirstName(newValue);
    cout << "Podaj nowe nazwisko: \n";
    cin >> newValue;
    employees[index]->setLastName(newValue);
    cout << "Podaj nowy pesel: \n";
    cin >> newValue;
    employees[index]->setPesel(newValue);
    cout << "Podaj nowy rok urodzenia: \n";
    cin >> newYear;
    employees[index]->setBirthYear(newYear);
}

void employeesManager(Employee*& employees, size_t& employeesSize) {
    int option, index;
    unsigned int year;
    cout << "1 - Stwórz nową tablicę \n";
    cout << "2 - Dodaj nowy rekrod \n";
    cout << "3 - Usuń rekord (NIEGOTOWE) \n";
    cout << "4 - Edytuj rekord \n";
    cout << "5 - Wyswietl tablice \n";
    cout << "6 - Wyswietl pracownikow na podstawie roku\n";
    cout << "7 - Wyswietl ilosc projektów \n";
    cout << "\n\nWybierz opcje (1-7):\n";
    cin >> option;
    switch (option) {
    case 1:
        if (employeesSize == 0) {
            cout << "Podaj rozmiar tablicy: \n";
            cin >> employeesSize;
            createEmployee(employees, employeesSize);
        }
        else {
            cout << "[ERROR] Tablica jest już stworzona!\n\n";
        }
        break;
    case 2:
        if (employeesSize > 0) {
            addEmployee(employees, employeesSize);
        }
        else {
            cout << "Brak tablicy - stwórz najpierw tablicę";
        }
        break;
    case 3:
        if (employeesSize > 0) {
            cout << "Podaj index rekordu do usunięcia: \n";
            cin >> index;
            removeEmployee(employees, employeesSize, index);
        }
        else {
            cout << "Brak tablicy - stwórz najpierw tablicę";
        }
        break;
    case 4:
        if (employeesSize > 0) {
            cout << "Podaj index rekordu do zmiany: \n";
            cin >> index;
            editEmployee(employees, employeesSize, index);
        }
        else {
            cout << "Brak tablicy - stwórz najpierw tablicę";
        }
        break;
    case 5:
        if (employeesSize > 0) {
            printEmployee(employees, employeesSize);
        }
        else {
            cout << "Brak tablicy - stwórz najpierw tablicę";
        }
        break;
    case 6:
        if (employeesSize > 0) {
            cout << "Podaj rok z którego chesz wyświetlić pracowników: \n";
            cin >> year;
            printEmployeeFromYear(employees, employeesSize, year);
        }
        else {
            cout << "Brak tablicy - stwórz najpierw tablicę";
        }
        break;
    case 7:
        cout << "\nRozmiar tablicy z pracownikami: " << employeesSize << "\n\n";
        break;
    default:
        cout << "\nBrak opcji o danym numerze\n\n";
        break;
    }
}
