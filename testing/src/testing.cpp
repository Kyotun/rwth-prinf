//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct BirthDate
{
	string name;
	int year, month, day;
};

int main() {

	BirthDate special;
	special.name = "Emir Pisirici";
	special.day = 27;
	special.month = 1;
	special.year = 2002;
	cout << "First name: " << special.name << endl;

	BirthDate* p_special = &special;
	p_special->name = "Pisirici, Emir";
	cout << "Second name: " << special.name << endl;

	(*p_special).name = "Emir Pisirici";
	cout << "Third name: " << special.name << endl;

	return 0;
}
