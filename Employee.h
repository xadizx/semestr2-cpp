#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee
{
    static unsigned int employeesCreated;
    const unsigned int id;
    string firstName;
    string lastName;
    string pesel;
    unsigned int birthYear;

    public:
        Employee(string firstName = "First", string lastName = "Last", string pesel = "000", unsigned int birthYear = 2000) : id(employeesCreated) {
            this->firstName = firstName;
            this->lastName = lastName;
            this->pesel = pesel;
            this->birthYear = birthYear;
            employeesCreated++; 
        }
        void print();
        void setFirstName(string newName) { this->firstName = newName; }
        void setLastName(string newName) { this->lastName = newName; }
        void setPesel(string newPesel) { this->pesel = newPesel; }
        void setBirthYear(unsigned int newBirthYear) { this->birthYear = newBirthYear; }
        unsigned int getBirthYear() const { return birthYear; }
        string getFirstName() const { return firstName; }
        string getLastName() const { return lastName; }
        string getPesel() const { return pesel; }
};


void createEmployee(Employee*&);
void removeEmployee(Employee*&);

void createEmployee(Employee*&, const size_t);
void printEmployee(Employee*&, const size_t);
void removeEmployee(Employee*&, const size_t);
void removeEmployee(Employee*&, size_t&, size_t);
void addEmployee(Employee*&, size_t&);
void printEmployeeFromYear(Employee*&, const size_t&, unsigned int);
void editEmployee(Employee*&, size_t&, size_t);

void createEmployee(Employee**&, const size_t&);
void printEmployee(Employee**, const size_t&);
void removeEmployee(Employee**&, size_t&);
void removeEmployee(Employee**&, size_t&, size_t);
void addEmployee(Employee**&, size_t&);
void printEmployeeFromYear(Employee**&, const size_t&, unsigned int);
void editEmployee(Employee**&, size_t&, size_t);

void employeesManager(Employee*&, size_t&);
