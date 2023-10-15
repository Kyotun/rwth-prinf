//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void referenceTester(int &x)
{
	 x = 2*(x);
}

int main() {
	int zahl;
	cout << "Bitte geben sie die Zahl,deren Multiplikation von 2 berecehnet werden soll, aus: ";
	cin >> zahl;

	referenceTester(zahl);

	cout << zahl;

	return 0;
}
