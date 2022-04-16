#include "Company.h"

int Company::randomNumber(int begin, int end)
{
  random_device seed;
  mt19937 engine(seed());
  uniform_int_distribution<int> uniformDist(begin, end);
  return uniformDist(engine);
}

void Company::Project::print()
{
  cout << "ID: " << this->id << "\n";
  cout << "Project name: " << this->name << "\n";
  cout << "Client name: " << this->clientName << "\n";
  cout << "Project status: " << this->status << "\n";
}

Company::Company(string name, size_t projectsSize)
{
  this->name = name;
  this->projectsSize = projectsSize;
  this->createProjects();
}

Company::~Company()
{
  for (size_t i = 0; i < this->projectsSize; i++)
  {
    delete this->projects[i];
  }
  delete[] this->projects;
}

Company::Company(const Company &obj)
{
  name = obj.name;
  projectsSize = obj.projectsSize;
  projects = new Project *[projectsSize];

  for (size_t i = 0; i < projectsSize; i++)
  {
    projects[i] = new Project(*obj.projects[i]);
  }
}

void Company::print()
{
  cout << "Name: " << this->name << " \n";
  cout << "Projects count: " << this->projectsSize << "\n\n";
}

void Company::createProjects()
{
  this->projects = new Project *[projectsSize];
  for (size_t i = 0; i < projectsSize; i++)
  {
    this->projects[i] = new Project();
  }
}
void Company::printProjects()
{
  cout << "\x1B[33m";
  cout << "<======= Projects =======>\n";
  cout << "\033[0m";

  for (int i = 0; i < this->projectsSize; i++)
  {
    this->projects[i]->print();
    cout << "\n";
  }
}
void Company::removeProjects()
{
  for (size_t ind = 0; ind < this->projectsSize; ind++)
    delete this->projects[ind];
  delete[] this->projects;
  projects = nullptr;
  this->projectsSize = 0;
}
void Company::removeProject(size_t index)
{
  if (index < this->projectsSize)
  {
    Project **temp = new Project *[this->projectsSize - 1];
    short int j = -1;
    for (size_t i = 0; i < this->projectsSize; ++i)
    {
      if (i != index)
      {
        ++j;
        temp[j] = projects[i];
      }
    }
    delete[] this->projects;
    this->projects = temp;
    this->projectsSize--;
  }
  else
    cout << "ERROR: Index jest nieprawidłowy ! \n";
}
void Company::addProject()
{
  Project **temp = new Project *[(projectsSize + 1)];
  if (this->projectsSize == 0)
  {
    this->createProjects();
  }
  else
  {
    temp[(this->projectsSize + 1)] = new Project();

    for (size_t i = 0; i < (projectsSize); i++)
    {
      temp[i] = this->projects[i];
    }

    temp[projectsSize] = new Project();

    delete[] this->projects;
  }

  this->projects = temp;
  this->projectsSize++;
}
void Company::printActiveProjects()
{
  cout << "\x1B[33m";
  cout << "<======= Active projects =======>\n";
  cout << "\033[0m";
  for (int i = 0; i < this->projectsSize; i++)
  {
    if (this->projects[i]->getStatus())
    {
      this->projects[i]->print();
      cout << "\n";
    }
  }
}
void Company::editProject(size_t index)
{
  string newName, newClientName;
  cout << "Podaj nową nazwę projektu: \n";
  cin.ignore();
  getline(cin, newName);

  this->projects[index]->name = newName;

  cout << "Podaj nową nazwę klienta: \n";
  cin.ignore();
  getline(cin, newClientName);
  this->projects[index]->clientName = newClientName;
}

void Company::projectsManager()
{
  int option, index;
  while (true)
  {
    cout << "\x1B[36m";
    cout << "1 - Dodaj nowy rekrod \n";
    cout << "2 - Usuń rekord \n";
    cout << "3 - Edytuj rekord \n";
    cout << "4 - Wyswietl tablice \n";
    cout << "5 - Wyswietl aktywne projekty \n";
    cout << "6 - Wyswietl ilosc projektów \n";
    cout << "0 - Wyjście \n";
    cout << "\n\nWybierz opcje (0-6):\n";
    cout << "\033[0m";
    cin >> option;
    switch (option)
    {
    case 0:
      return;
      break;
    case 1:
      this->addProject();
      break;
    case 2:
      cout << "Podaj index rekordu do usunięcia: \n";
      cin >> index;
      this->removeProject(index);
      break;
    case 3:
      cout << "Podaj index rekordu do zmiany: \n";
      cin >> index;
      this->editProject(index);
      break;
    case 4:
      this->printProjects();
      break;
    case 5:
      this->printActiveProjects();
      break;
    case 6:
      cout << "\nRozmiar tablicy z projektami: " << this->projectsSize << "\n\n";
      break;
    default:
      cout << "\nBrak opcji o danym numerze\n\n";
      break;
    }
  }
}

Company &Company::operator=(const Company &oldObj)
{
  if (&oldObj != this)
  {
    this->removeProjects();

    name = oldObj.name;
    projectsSize = oldObj.projectsSize;
    projects = new Project *[projectsSize];

    for (size_t i = 0; i < projectsSize; i++)
    {
      projects[i] = new Project(*oldObj.projects[i]);
    }
  }
  return *this;
}

Company::Project *Company::operator[](const size_t i)
{
  return projects[i];
}
