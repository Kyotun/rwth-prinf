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
#include <vector>


using namespace std;
double GlobaleZeit = 0.0;

void vAufgabe_1();
void vAufgabe_1a();
void vAufgabe_2();
ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug);

int main(){
	return 0;
}

void vAufgabe_1(){
	cout << "Hey" << endl;
	int* dynamicElement = new int;
	static int staticElement = 1;
	int* dynamicElement2 = new int;
	static int staticElement2 = 2;
	delete dynamicElement;
	delete dynamicElement2;
	cout << "Bye" << endl;
}


void vAufgabe_1a(){

	double dMaxGeschwindigkeit = 0.0;
	string name = "";

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des erstes Fahrzeuges:" << endl;
	cin >> name;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des zweites Fahrzeuges" << endl;
	cin >> name;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des drittes Fahrzeuges" << endl;
	cin >> name;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug3 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

	vector<unique_ptr<Fahrzeug>>fahrzeuge;
	fahrzeuge.push_back(std::move(fahrzeug1));
	fahrzeuge.push_back(std::move(fahrzeug2));
	fahrzeuge.push_back(std::move(fahrzeug3));

	Fahrzeug::vKopf();

	for(double Epsilon = 0.0; Epsilon < 10; Epsilon+= 0.3){
		GlobaleZeit+=0.3;
		for(const auto& i : fahrzeuge){
			GlobaleZeit += Epsilon;
			i->vSimulieren(Epsilon);
			cout << *i << endl;
		}

	}

}

void vAufgabe_2(){
	int pkw_anzahl = 0;
	int fahrrad_anzahl = 0;

	string name = "";
	double geschwindigkeit = 0.0;
	double verbrauch = 0.0;
	string tankVolumen = "";

	vector<unique_ptr<Fahrzeug>> fahrzeuge;

	cout << "Wie viele PKWs möchten Sie erstellen?" << endl;
	cin >> pkw_anzahl;

	cout << "Wie viele Fahrräder möchten Sie erstellen?" << endl;
	cin >> fahrrad_anzahl;

	cout << "Bitte geben Sie jetzt die Eigenschaften der PKWs vom Ersten bis Letzem ein.\n";
	for(int i = 0; i < pkw_anzahl; i++){
		cout << "1) Name: ";
		cin >> name;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> geschwindigkeit;

		cout << "3) Verbrauch: ";
		cin >> verbrauch;

		getline(cin, tankVolumen);
		cout << "4) Tankvolumen(optinal, default 55 liter angenommen.): ";
		getline(cin, tankVolumen);

		if(tankVolumen == ""){
			unique_ptr<PKW> pkw = make_unique<PKW>(name, geschwindigkeit, verbrauch);
			fahrzeuge.push_back(std::move(pkw));
		} else{
			unique_ptr<PKW> pkw = make_unique<PKW>(name, geschwindigkeit, verbrauch, stod(tankVolumen));
			fahrzeuge.push_back(std::move(pkw));
		}
	}

	cout << "Bitte geben Sie nun die Eigenschaften der Fahrräder vom Ersten bis Letzem ein.\n";
	for(int j = 0; j < fahrrad_anzahl; j++){
		cout << "1) Name: ";
		cin >> name;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> geschwindigkeit;

		unique_ptr<Fahrrad> fahrrad = make_unique<Fahrrad>(name, geschwindigkeit);
		fahrzeuge.push_back(std::move(fahrrad));
	}

	Fahrzeug::vKopf();
	GlobaleZeit = 0.1;
	for(double Epsilon = 0.0; Epsilon < 10; Epsilon+=0.3){
		GlobaleZeit+=0.3;

		for(const auto& i : fahrzeuge){
			i->vSimulieren(GlobaleZeit-Epsilon);
			cout << *i;
		}

		if((int)GlobaleZeit % 3 == 0 && GlobaleZeit >= 3.0){
			for(const auto& i : fahrzeuge){
				i->dTanken();
			}
		}

	}
}

ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug){
	fahrzeug.vAusgeben(ausgabe);
	return ausgabe;
}
