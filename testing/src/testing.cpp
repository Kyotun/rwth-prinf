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

	CentCoin aCoin;
	aCoin = C50;
	int coin = C20 | C50;
	cout << coin << endl;
	cout << aCoin;

	return 0;
}
