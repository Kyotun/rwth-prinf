//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

int squareIt(std::unique_ptr<int> s) {
    int squared = *s;
    return squared*squared;
}



int main()
{
	std::unique_ptr<int> number = std::make_unique<int>(15);
	
	if(number){
		std::cout << "Der Pointer `number` existiert noch und hat den Inhalt: " << *number << std::endl;
	} else {
		std::cout << "Der Pointer `number` existiert nicht mehr." << std::endl;
	}
	
	int numberSquared = squareIt(move(number));
	std::cout << "Der Wert des Pointers wurde zur Berechnung übergeben: " << numberSquared << std::endl;
	
	if(number){
		std::cout << "Der Pointer `number` existiert noch und hat den Inhalt: " << *number << std::endl;
	} else {
		std::cout << "Der Pointer `number` existiert nicht mehr." << std::endl;
	}


	return 0;

}
