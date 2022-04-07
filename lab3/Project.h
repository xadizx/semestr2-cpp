#pragma once
#include <string>
#include <iostream>
#include <random>

using namespace std;

int randomNumber(int begin, int end);

class Project
{
    static unsigned int projectsCreated;
    const unsigned int id;
    string name;
    string clientName;
    bool status;

    public:
        Project(string name = "Sample project", string clientName = "Company", bool status = randomNumber(0,1)) : id(projectsCreated) {
            this->name = name;
            this->clientName = clientName;
            this->status = status;
            projectsCreated++;
        }
        void print();
        void setName(string newName) { this->name = newName; }
        void setClient(string newName) { this->clientName = newName; }
        bool getStatus() const { return status; }
        static string printStatus(bool);
};

void createProject(Project*&);
void removeProject(Project*&);

void createProject(Project*&, const size_t);
void printProject(Project*&, const size_t);
void removeProject(Project*&, const size_t);

void createProject(Project**&, const size_t&);
void printProject(Project**, const size_t&);
void removeProject(Project**&, size_t&);
void removeProject(Project**&, size_t&, size_t);
void addProject(Project**&, size_t&);
void printActiveProject(Project**, const size_t&);
void editProject(Project**&, size_t&, size_t);

void projectsManager(Project**&, size_t&);