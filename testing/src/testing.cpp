//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a = 5;
	int& b = a;
	int* c = &a;
	cout << "Das ist b, auch der Wert von a: " << b << endl;
	cout << "Das ist c, auch die Adresse von a: " << c << endl;

	b = 10;
	cout << "Das ist der neue Wert von a: " << a << endl;
	cout << "Wie sieht dann b aus?: " << b << endl;

	int &d = *c;
	cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << endl;

	d = 15;
	cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << endl;
	*c = 5;
	cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << endl;

	return 0;
}
