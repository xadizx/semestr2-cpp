#pragma once
#include <iostream>
#include <string>
#include "Client.h"

class ForeignClient : public Client
{
  string country;
  string currency;
  string phonePrefix;

public:
  ForeignClient(
      string name = "FancyForeignCompany",
      size_t contactNumber = 123456789,
      size_t employeeCount = 5,
      string country = "US",
      string currency = "USD",
      string phonePrefix = "+1")
      : Client(name, contactNumber, employeeCount)
  {
    this->country = country;
    this->currency = currency;
    this->phonePrefix = phonePrefix;
  }

  void phoneToClient()
  {
    cout << this->phonePrefix << " " << this->getContactNumber() << endl;
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

    cout << "Total cost: " << hoursSum * 20 << " " << this->currency << endl;
    cout << "Taxes law: " << this->country << endl;
  }
};
