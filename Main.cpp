#include <iostream>
#include <string>
#include <locale>
#include "Menu.h"

using namespace std;

unsigned int Employee::employeesCreated = 0;
unsigned int Company::Project::projectsCreated = 0;

int main()
{
	Company *company = new Company();
	Employee *employees = nullptr;

	setlocale(LC_CTYPE, "Polish");
	Menu::menu(company, employees);
}
