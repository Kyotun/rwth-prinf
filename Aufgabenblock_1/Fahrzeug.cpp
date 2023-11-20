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
	ausgabe << setprecision(2) << fixed << setw(7) << getID()
			<< setw(10) << getName()
			<< resetiosflags(ios::left) << setiosflags(ios::right)
			<< setw(15) << getMaxGeschwindigkeit()
			<< setw(18) << getGesamtstrecke()
			<< setw(20) << getGesamtVerbrauch()
			<< setw(15) << getTankinhalt()
			<< resetiosflags(ios::right) << setiosflags(ios::left) << endl;
}

void Fahrzeug::vKopf(){
	cout << setiosflags(ios::left) << setw(7) << left << "ID"
			<< setw(10) << "Name"
			<< setw(21) << "Geschwindigkeit"
			<< setw(18) << "Gesamtstrecke"
			<< setw(20) << "Gesamtverbrauch"
			<< setw(10) << "Tankinhalt" << endl;

	cout << setw(86) << setfill('-') << '-' << setfill(' ') << endl;
}

void Fahrzeug::vSimulieren(double Zeitdifferenz){
	// 1 km/h -> 2,77 m/s
	// Zeitdifferenz ist der Differenz zwischen t(t) und t(t+1)
	if(p_dZeit == GlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
	}else{
		p_dGesamtZeit += Zeitdifferenz;
		p_dGesamtstrecke = p_dMaxGeschwindigkeit * p_dGesamtZeit;
		p_dZeit = GlobaleZeit; // Die Letzte Zeit, in der das Fahrzeug sich bewegt hat.
	}

}
