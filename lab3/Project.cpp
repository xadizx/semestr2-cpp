#include "Project.h"

int randomNumber(int begin, int end) {
    random_device seed;
    mt19937 engine(seed());
    uniform_int_distribution<int> uniformDist(begin, end);
    return uniformDist(engine);
}

string Project::printStatus(bool status) {
    if (status == true)
        return "Active";
    else
        return "Archived";
}

void Project::print() {
    cout << "\n==============================\n";
    cout << "Displaying data for project: " << this->id << "\n\n";
    cout << "Name: " << this->name << "\n";
    cout << "Client: " << this->clientName << "\n";
    cout << "Status: " << Project::printStatus(this->status);
    cout << "\n==============================\n";
}

void createProject(Project*& project) {
    project = new Project();
}
void removeProject(Project*& project) {
    delete project;
    project = nullptr;
}

void createProject(Project*& projects, const size_t size) {
    projects = new Project[size];
}
void printProject(Project*& projects, const size_t size) {
    cout << "<======= Projects =======>\n" ;
    for (size_t i = 0; i < size; i++)
        projects[i].print();
}
void removeProject(Project*& projects, const size_t size) {
    delete[] projects;
    projects = nullptr;
}

void createProject(Project**& projects, const size_t& size) {
    projects = new Project * [size];
    for (size_t i = 0; i < size; i++)
        createProject(projects[i]);
}
void printProject(Project** projects, const size_t& size) {
    cout << "<======= Projects =======>\n";
    for (size_t i = 0; i < size; i++)
        projects[i]->print();
}
void removeProject(Project**& projects, size_t& size) {
    for (size_t ind = 0; ind < size; ind++)
        delete projects[ind];
    delete[] projects;
    projects = nullptr;
    size = 0;
}
void removeProject(Project**& projects, size_t& size, size_t index) {
    if (index < size) {
        Project** temp = new Project * [size - 1];
        short int j =  -1;
        for (size_t i = 0; i < size; ++i) {
            if (i != index) {
                ++j;
                temp[j] = projects[i];
            }
        }
        delete[] projects;
        projects = temp;
        size--;
    }
    else
        cout << "ERROR: Index jest nieprawidłowy ! \n";
}
void addProject(Project**& projects, size_t& size) {
    Project** temp = new Project * [size + 1];
    if (size == 0) {
        createProject(temp[size]);
    }
    else {
        for (size_t i = 0; i < size; i++)
            temp[i] = projects[i];
        createProject(temp[size]);
        delete[] projects;
    }
    projects = temp;
    size++;
}
void printActiveProject(Project** projects, const size_t& size) {
    cout << "<======= Active projects =======>\n";
    for (size_t i = 0; i < size; i++) {
        if (projects[i]->getStatus() == true) {
            projects[i]->print();
        }
    }
}
void editProject(Project**& projects, size_t& size, size_t index) {
    string newName;
    cout << "Podaj nową nazwę projektu: \n";
    cin >> newName;
    projects[index]->setName(newName);
    cout << "Podaj nową nazwę klienta: \n";
    cin >> newName;
    projects[index]->setClient(newName);
}

void projectsManager(Project**& projects, size_t& projectsSize) {
    int option, index;
    cout << "1 - Stwórz nową tablicę\n";
    cout << "2 - Dodaj nowy rekrod \n";
    cout << "3 - Usuń rekord \n";
    cout << "4 - Edytuj rekord \n";
    cout << "5 - Wyswietl tablice \n";
    cout << "6 - Wyswietl aktywne projekty \n";
    cout << "7 - Wyswietl ilosc projektów \n";
    cout << "\n\nWybierz opcje (1-7):\n";
    cin >> option;
    switch (option) {
    case 1:
        if (projectsSize == 0) {
            cout << "Podaj rozmiar tablicy: \n";
            cin >> projectsSize;
            createProject(projects, projectsSize);
        }
        else {
            cout << "[ERROR] Tablica jest ju stworzona!\n\n";
        }
        break;
    case 2:
        if (projectsSize > 0) {
            addProject(projects, projectsSize);
        }
        else {
            cout << "Brak tablicy - Stwórz najpierw tablicę";
        }
        break;
    case 3:
        if (projectsSize > 0) {
            cout << "Podaj index rekordu do usunięcia: \n";
            cin >> index;
            removeProject(projects, projectsSize, index);
        }
        else {
            cout << "Brak tablicy - Stwórz najpierw tablicę";
        }
        break;
    case 4:
        if (projectsSize > 0) {
            cout << "Podaj index rekordu do zmiany: \n";
            cin >> index;
            editProject(projects, projectsSize, index);
        }
        else {
            cout << "Brak tablicy - Stwórz najpierw tablicę";
        }
        break;
    case 5:
        if (projectsSize > 0) {
            printProject(projects, projectsSize);
        }
        else {
            cout << "Brak tablicy - Stwórz najpierw tablicę";
        }
        break;
    case 6:
        if (projectsSize > 0) {
            printActiveProject(projects, projectsSize);
        }
        else {
            cout << "Brak tablicy - Stwórz najpierw tablicę";
        }
        break;
    case 7:
        cout << "\nRozmiar tablicy z projektami: " << projectsSize << "\n\n";
        break;
    default:
        cout << "\nBrak opcji o danym numerze\n\n";
        break;
    }
}
