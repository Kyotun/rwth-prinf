//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

enum CentCoin
{
	C01 = 1,
	C02,
	C05 = 5,
	C10 = 10,
	C20 = 20,
	C50 = 50,

};

int main() {

	int i = 10;
	while(i > 0){
		i--;
		continue;
		cout << i << " ";
		if(i == 5){
			continue;
		}
		cout << i << endl;
	}
	cout << "End of while";

	return 0;
}
