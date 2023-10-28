//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int squareIt(std::shared_ptr<int>& s) {
    return (*s)*(*s);
}

int main()
{
	std::shared_ptr<int> i_number = std::make_shared<int>(15);

	if(i_number){
		std::cout << "Der Pointer `i_number` existiert noch und hat den Inhalt: " << *i_number << std::endl;
	} else {
		std::cout << "Der Pointer `i_number` existiert nicht mehr." << std::endl;
	}

	int numberSquared = squareIt(i_number);
	std::cout << "Der Wert des Pointers wurde zur Berechnung übergeben: " << numberSquared << std::endl;

	if(i_number){
		std::cout << "Der Pointer `i_number` existiert noch und hat den Inhalt: " << *i_number << std::endl;
	} else {
		std::cout << "Der Pointer `i_number` existiert nicht mehr." << std::endl;
	}

	return 0;

}
