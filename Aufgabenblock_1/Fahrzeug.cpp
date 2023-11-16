/*
 * Fahrzeug.cpp
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */

#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
extern double GlobaleZeit;

Fahrzeug::Fahrzeug(){
	cout << "Ein Fahrzeug wurde mit der ID '" << p_iID
				<< "' erzeugt." << endl;
}

Fahrzeug::~Fahrzeug(){
	cout << "Ein Fahrzeug wurde mit dem Name '" << p_sName
			<< "' und mit der ID " << p_iID
			<< " gelöscht." << endl;
}

Fahrzeug::Fahrzeug(string p_sName): p_sName(p_sName){
	cout << "Ein Fahrzeug wurde mit dem Name '" << p_sName
			<< "' und mit der ID " << p_iID
			<< " erzeugt." << endl;
}


Fahrzeug::Fahrzeug(string p_sName, double p_dMaxGeschwindigkeit): p_sName(p_sName),
		p_dMaxGeschwindigkeit((p_dMaxGeschwindigkeit > 0) ? p_dMaxGeschwindigkeit : 0){
	cout << "Ein Fahrzeug wurde mit dem Name '" << p_sName
			<< "', der ID '" << p_iID << "' und der MaxGeschwindigkeit '"
			<< p_dMaxGeschwindigkeit <<"' erzeugt." << endl;

}

void Fahrzeug::vAusgeben(std::ostream& ausgabe) const{
	ausgabe << p_iID << "\t"
		 << p_sName << "\t"
		 << p_dMaxGeschwindigkeit << "\t\t\t"
		 << p_dGesamtstrecke << "\n";
}

void Fahrzeug::vKopf(){
	cout << "ID\tName\tMaxGeschwindigkeit\tGesamtstrecke\n";
	cout << "------------------------------------------------------\n";

}

void Fahrzeug::vSimulieren(){
	// 1 km/h -> 2,77 m/s
	if(p_dZeit == GlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
	}else{
		p_dZeit = GlobaleZeit;
		p_dGesamtZeit++;
		p_dGesamtstrecke = p_dMaxGeschwindigkeit * p_dGesamtZeit;
	}

}


