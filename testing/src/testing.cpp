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
	char* p = new char [10];
	fill(p, p+10,'0');
	p[3] = 'c';
	for(int i = 0; i < sizeof(p); i++){
		cout << p[i] << endl;
	}
	cout << endl;
	p = nullptr;
	delete [] p;
	for(int i = 0; i < sizeof(p); i++){
		cout << p[i] << endl;
	}
	cout << 'n';
	p = nullptr;
	cout << 'n';
	for(int i = 0; i < sizeof(p); i++){
		cout << p[i] << endl;
	}



	return 0;
}
