//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class myClass{

	private:
		int income;
		string name;
		string gender;

	public:
		myClass(){
			cout << "Constructor\n";
		}
		~myClass(){
			cout << "Destructor\n";
		}

		void setIncome(int number);
		int getIncome();
};

void myClass::setIncome(int number){
	income = number;
}

int myClass::getIncome(){
	return income;
}

int main() {
	myClass character;
	character.setIncome(5);
	cout << character.getIncome() << endl;

	return 0;
}
