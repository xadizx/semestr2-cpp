#pragma once
#include <string>
#include <iostream>
#include <random>

using namespace std;

class Company
{
  string name;
  size_t projectsSize;

  friend class Utilities;

  class Project
  {
    static unsigned int projectsCreated;
    const unsigned int id;
    string name;
    string clientName;
    bool status;

    friend class Company;

  public:
    Project(string name = "Sample project", string clientName = "Company", bool status = Company::randomNumber(0, 1)) : id(projectsCreated)

    {
      this->name = name;
      this->clientName = clientName;
      this->status = status;
      projectsCreated++;
    }
    void print();
    void setName(string newName) { this->name = newName; }
    void setClient(string newName) { this->clientName = newName; }
    bool getStatus() const { return status; }
    string getName() const { return name; }
    static string printStatus(bool);
  };

  Project **projects;

public:
  static int randomNumber(int begin, int end);

  Company(string name = "Sample company", size_t projectsSize = 5);
  ~Company();
  Company(const Company &obj);

  void print();

  size_t getProjectSize() const { return projectsSize; }
  Project getProjects() const { return **projects; }

  void createProjects();
  void printProjects();
  void removeProjects();
  void addProject();
  void printActiveProjects();
  void removeProject(size_t);
  void editProject(size_t);
  void projectsManager();

  Company &operator=(const Company &);
  Company::Project &operator[](const size_t);
  friend ostream &operator<<(ostream &out, const Company &company)
  {
    for (int i = 0; i < company.projectsSize; i++)
      out << company.projects[i]->getName() << "\t";
    return out;
  }
};
