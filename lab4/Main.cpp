#include <iostream>
#include <string>
#include <locale>
#include "Menu.h"

using namespace std;

unsigned int Employee::employeesCreated = 0;
unsigned int Project::projectsCreated = 0;

int main()
{
	setlocale(LC_CTYPE, "Polish");
	menu();
}
