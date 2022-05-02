#pragma once
#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;

class Client
{
  string name;
  size_t contactNumber;
  size_t *employeeMothlyHours;
  size_t employeeCount;

public:
  Client(string name = "Sample client", size_t contactNumber = 123456789, size_t employeeCount = 5)
  {
    this->name = name;
    this->contactNumber = contactNumber;
    this->employeeCount = employeeCount;
    this->employeeMothlyHours = new size_t[employeeCount];
    for (int i = 0; i < employeeCount; i++)
    {
      this->employeeMothlyHours[i] = Utilities::randomNumber(40, 160);
    }
  }
  string getName() const { return name; }
  size_t getContactNumber() const { return contactNumber; }
  size_t getEmployeeCount() const { return employeeCount; }
  size_t *getEmployeeMothlyHours() const { return employeeMothlyHours; }

  virtual ~Client()
  {
    cout << "\x1B[31m";
    cout << "Client destructor" << endl;
    cout << "\033[0m";
    delete this->employeeMothlyHours;
  }

  virtual void phoneToClient() = 0;
  virtual void generateInvoice() = 0;
};

void clientsManager();
