/*
 * Fahrzeug.cpp
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */

#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>


using namespace std;
double GlobaleZeit = 0.0;

/*void vAufgabe_1(){
	int* dynamicElement = new int;
	static int staticElement = 1;
	int* dynamicElement2 = new int;
	static int staticElement2 = 2;
	delete dynamicElement;
	delete dynamicElement2;
}*/


void vAufgabe_1a(){
}

ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug){
	fahrzeug.vAusgeben(ausgabe);
	return ausgabe;
}


int main(){
	try{
		Fahrrad fahrrad1("Fahrrad1", 20);
		Fahrrad fahrrad2 = fahrrad1;
		cout << fahrrad2;

		//fahrrad.getMaxGeschwindigkeit();
		/*double dMaxGeschwindigkeit = 0.0;
		string name = "";

		cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des erstes Fahrzeuges:" << endl;
		cin >> name;
		cout << endl;
		cin >> dMaxGeschwindigkeit;
		cout << endl;
		unique_ptr<Fahrzeug> f1 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

		cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des zweites Fahrzeuges" << endl;
		cin >> name;
		cout << endl;
		cin >> dMaxGeschwindigkeit;
		cout << endl;
		unique_ptr<Fahrzeug> f2 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

		cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des drittes Fahrzeuges" << endl;
		cin >> name;
		cout << endl;
		cin >> dMaxGeschwindigkeit;
		cout << endl;
		unique_ptr<Fahrzeug> f3 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

		vector<unique_ptr<Fahrzeug>> vectorFahrzeuge;

		vectorFahrzeuge.push_back(std::move(f1));
		vectorFahrzeuge.push_back(std::move(f2));
		vectorFahrzeuge.push_back(std::move(f3));

		Fahrzeug::vKopf();

		for(auto &i : vectorFahrzeuge){
			i->vSimulieren();
			i->vAusgeben();
		}*/

	} catch (const std::invalid_argument& e){
		cerr << "Fehler: " << e.what() << endl;
	}


	return 0;
}
