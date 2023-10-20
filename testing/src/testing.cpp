//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

namespace name1
{
	void foo(){
		cout << "name1" << endl;
	}
}

namespace name2
{
	void foo(){
		cout << "name2" << endl;
	}
}


int main() {

	name1::foo();


	name2::foo();

	return 0;
}
