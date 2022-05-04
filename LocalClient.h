#pragma once
#include <iostream>
#include <string>
#include "Client.h"

class LocalClient : public Client
{
  size_t regon;
  size_t nip;

public:
  LocalClient(string name = "SamplePolishClient", size_t contactNumber = 123456789, size_t employeeCount = 5)
      : Client(name, contactNumber, employeeCount)
  {
    this->regon = 1234;
    this->regon = 4321;
  }
  void displayPolishCompanyData()
  {
    cout << "REGON: " << this->regon << endl;
    cout << "NIP: " << this->nip << endl;
  }
  void phoneToClient()
  {
    cout << "+48 " << this->getContactNumber() << endl;
  }
  void generateInvoice()
  {
    size_t count = this->getEmployeeCount();
    size_t *hours = this->getEmployeeMothlyHours();
    size_t hoursSum = 0;

    for (int i = 0; i < count; i++)
    {
      hoursSum += hours[i];
    }

    cout << "Koszt calkowity: " << hoursSum * 60 << " PLN" << endl;
  }
};
