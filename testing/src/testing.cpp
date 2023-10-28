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

class Animal{
private:
	string species;
	int age;
	double weight;
public:
	string getSpecies(){return species;}
	int getAge(){return age;}
	double getWeight(){return weight;}
	Animal() = default;
	Animal(string species, int age, double weight);
};

Animal::Animal(string species, int age, double weight){
	this->species = species;
	this->age = age;
	this->weight = weight;
}

int main()
{
	vector<shared_ptr<Animal>> animalVector;
	shared_ptr<Animal> cat = make_shared<Animal>("Cat", 7, 3.9);
	shared_ptr<Animal> dog = make_shared<Animal>("Dog", 11, 36.4);
	shared_ptr<Animal> turtle = make_shared<Animal>("Turtle", 52, 1.5);
	animalVector.push_back(cat);
	animalVector.push_back(dog);
	animalVector.push_back(turtle);

	if(cat){
		std::cout << "Der Pointer `cat` existiert noch mit Inhalt: " << cat->getSpecies() << ", age: " << cat->getAge() << ", weight: " << cat->getWeight() << std::endl;
	} else {
		std::cout << "Der ursprüngliche Pointer `cat` ist jetzt nullpointer." << std::endl;
	}

	if(dog){
		std::cout << "Der Pointer `dog` existiert noch mit Inhalt: "  << dog->getSpecies() << ", age: " << dog->getAge() << ", weight: " << dog->getWeight() << std::endl;
	} else {
		std::cout << "Der ursprüngliche Pointer `dog` ist jetzt nullpointer." << std::endl;
	}
	if(turtle){
		std::cout << "Der Pointer `turtle` existiert noch mit Inhalt: " << turtle->getSpecies() << ", age: " << turtle->getAge() << ", weight: " << turtle->getWeight() << std::endl;
	} else {
		std::cout << "Der ursprüngliche Pointer `turtle` ist jetzt nullpointer." << std::endl;
	}


	for(auto& i : animalVector){
		std::cout << "Species: " << i->getSpecies() << ", Age: " << i->getAge() << " years,  Weight: " << i->getWeight() << " kg" << std::endl;
	}

	return 0;

}
