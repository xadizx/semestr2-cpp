#include <iostream>
#include <string>
#include <locale>
#include "Utilities.h"

using namespace std;

unsigned int Employee::employeesCreated = 0;
unsigned int Company::Project::projectsCreated = 0;

int main()
{
	Company *company = new Company();
	Employee *employees = nullptr;

	// cout << (*company)[0].getName() << endl;

	setlocale(LC_CTYPE, "Polish");
	Utilities::menu(company, employees);
}
