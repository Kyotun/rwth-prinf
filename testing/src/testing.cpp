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
        std::string species;
        int age;
        double weight;
    public:
        std::string getSpecies(){return species;}
        int getAge(){return age;}
        double getWeight() {return weight;}
        Animal() = default;
        Animal(std::string species, int age, double weight);
};

Animal::Animal(string species, int age, double weight){
	this->species = species;
	this->age = age;
	this->weight = weight;
}

int main()
{
	std::vector<std::unique_ptr<Animal>> animalVector;
	std::unique_ptr<Animal> cat = std::make_unique<Animal>("Cat", 7, 3.9);
	std::unique_ptr<Animal> dog = std::make_unique<Animal>("Dog", 11, 36.4);
	std::unique_ptr<Animal> turtle = std::make_unique<Animal>("Turtle", 52, 1.5);
	animalVector.push_back(move(cat));
	animalVector.push_back(move(dog));
	animalVector.push_back(move(turtle));

	if(cat){
		std::cout << "Der Pointer `cat` existiert noch mit Inhalt: " << cat->getSpecies() << ", age: " << cat->getAge() << ", weight: " << cat->getWeight() << std::endl;
	} else {
		std::cout << "Der ursprüngliche Unique_Ptr `cat` ist jetzt nullpointer." << std::endl;
	}

	if(dog){
		std::cout << "Der Pointer `dog` existiert noch mit Inhalt: " << dog->getSpecies() << ", age: " << dog->getAge() << ", weight: " << dog->getWeight() << std::endl;
	} else {
		std::cout << "Der ursprüngliche Unique_Ptr `dog` ist jetzt nullpointer." << std::endl;
	}
	if(turtle){
		std::cout << "Der Pointer `turtle` existiert noch mit Inhalt: " << turtle->getSpecies() << ", age: " << turtle->getAge() << ", weight: " << turtle->getWeight() << std::endl;
	} else {
		std::cout << "Der ursprüngliche Unique_Ptr `turtle` ist jetzt nullpointer." << std::endl;
	}
	

	for(auto& i : animalVector){
		std::cout << "Species: " << i->getSpecies() << ", Age: " << i->getAge() << " years,  Weight: " << i->getWeight() << " kg" << std::endl;
	}

	return 0;

}
