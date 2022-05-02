#pragma once
#include "Employee.h"
#include "Company.h"
#include "Client.h"
#include "LocalClient.h"
#include "ForeignClient.h"

class Menu
{
public:
  void static menu(Company *&, Employee *&);

  void static createProject(Company::Project *&);
  void static removeProject(Company::Project *&);

  void static createProject(Company::Project *&, const size_t);
  void static printProject(Company::Project *&, const size_t);
  void static removeProject(Company::Project *&, const size_t);
};
