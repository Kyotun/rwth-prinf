/*
 * Fahrzeug.cpp
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */

#include "Fahrzeug.h"
#include <iostream>
using namespace std;

Fahrzeug::Fahrzeug() { // @suppress("Class members should be properly initialized")

	cout << "Standard Konstruktor Fahrzeug" << endl;

}

Fahrzeug::~Fahrzeug() {
	cout << "Standard Destruktor Fahrzeug" << endl;
}

Fahrzeug::Fahrzeug(string p_sName){ // @suppress("Class members should be properly initialized")
	this->p_sName = p_sName;
	cout << "Ein Fahrzeug wurde mit dem Name " << p_sName <<  " erzeugt." << endl;
}

Fahrzeug::Fahrzeug(string p_sName, int p_iID): p_sName(p_sName), p_iID(p_iID) // @suppress("Class members should be properly initialized")
{
}

void vAufgabe_1(){
	int* dynamicElement = new int;
	static int staticElement = 1;
	int* dynamicElement2 = new int;
	static int staticElement2 = 2;
	delete dynamicElement;
	delete dynamicElement2;
}
int main(){
	vAufgabe_1();
	vector<unique_ptr<Fahrzeug>> unique_vector;
	unique_ptr<Fahrzeug> unique_1 = make_unique<Fahrzeug>("unique_1");
	unique_ptr<Fahrzeug> unique_2 = make_unique<Fahrzeug>("unique_2");

	shared_ptr<Fahrzeug> shared_1 = make_shared<Fahrzeug>("shared_1");
	shared_ptr<Fahrzeug> shared_2 = make_shared<Fahrzeug>("shared_2");
	shared_ptr<Fahrzeug> shared_speichern = shared_2;

	unique_vector.push_back(move(unique_1));
	unique_vector.push_back(move(unique_2));


	cout << "Count of shared_1: " << shared_1.use_count() << endl;
	cout << "Count of shared_2: " << shared_2.use_count() << endl;
	cout << "Count of shared_speichern: " << shared_speichern.use_count() << endl;


	Fahrzeug a("emir", 5);
	cout << a.getName() << endl;
	if(unique_vector.front()){
		cout << "in" << endl;
		unique_vector.clear();
		if(unique_vector.front()){
			for(auto& i : unique_vector){
					cout << i->getName() << endl;
				}
		}
	}

	return 0;
}
