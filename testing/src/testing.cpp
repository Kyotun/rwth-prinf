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
	int* p = nullptr;
	int a[10] = {};
	int i = 5;
	a[3] = 30;
	a[4] = 40;
	p = &(a[3]);
	cout << p << endl;
	i = *p;
	cout << i << endl;
	p++;
	cout << p << endl; // p zeigt die Adresse von viertem Element von Array a.
	i = *p;
	cout << i << endl;

	return 0;
}
