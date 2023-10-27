//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

void Function(int a){
	a = 5;
}

void Function_zwei(int &a){
	int* b = nullptr;
	b = &a;
	a = 5;
	cout << "Das ist *b: " << *b << endl;
	cout << "Das ist b: " << b << endl;

}
int main()
{
	int a = 0;
	Function(a);
	cout << "Von der normalen Funktion: " << a << endl;
	Function_zwei(a);
	cout << "Von der call by reference Funktion: " << a << endl;
	return 0;

}
