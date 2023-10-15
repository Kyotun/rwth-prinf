//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int fakulteatBerechner(int x)
{
	int fak = 1;
	for(int i = x; i > 0; i--){
		fak *= i;
	}
	return fak;


}


int main() {
	int zahl;
	cout << "Bitte geben sie die Zahl,deren Fakultät berechnet werden soll, aus: ";
	cin >> zahl;

	cout << fakulteatBerechner(zahl);

	return 0;
}
