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

//Standard-Konstruktor
Fahrzeug::Fahrzeug(){
	cout << "Ein Fahrzeug wurde mit der ID '" << p_iID
				<< "' erzeugt." << endl;
}

// Standard-Destruktor
Fahrzeug::~Fahrzeug(){
	cout << "Ein Fahrzeug wurde mit dem Name '" << p_sName
			<< "' und mit der ID " << p_iID
			<< " gelöscht." << endl;
}

// Fahrzeug-Objekt mit dem Name
Fahrzeug::Fahrzeug(string p_sName): p_sName(p_sName){
	cout << "Ein Fahrzeug wurde mit dem Name '" << p_sName
			<< "' und mit der ID " << p_iID
			<< " erzeugt." << endl;
}

// Fahrzeug-Objekt Konstruktor mit dem Name und der Geschwindigkeit
Fahrzeug::Fahrzeug(string p_sName, double p_dMaxGeschwindigkeit): p_sName(p_sName),
		p_dMaxGeschwindigkeit((p_dMaxGeschwindigkeit > 0) ? p_dMaxGeschwindigkeit : 0){
	cout << "Ein Fahrzeug wurde mit dem Name '" << p_sName
			<< "', der ID '" << p_iID << "' und der MaxGeschwindigkeit '"
			<< p_dMaxGeschwindigkeit <<"' erzeugt." << endl;

}

// Ausgabe Funktion, die zum Printen von der Eigenschaften der Objekten dient.
void Fahrzeug::vAusgeben(ostream& ausgabe) const{
	ausgabe << setiosflags(ios_base::adjustfield) << left
			<< setprecision(2) << fixed
			<< setw(8) << getID()
			<< setw(15) << getName()
			<< setw(20) << getMaxGeschwindigkeit()
			<< setw(20) << getGesamtstrecke();
}

// Kopf Funktion wird vor der Funktion Ausgeben aufgerufen,
// damit ist die Ausgaben(Eigenschaften der Objekten) besser und deutlich zu sehen.
void Fahrzeug::vKopf(){
	cout << setiosflags(ios_base::adjustfield) << left
		<< setw(8) << "ID"
		<< setw(15) << "Name"
		<< setw(20) << "MaxGeschwindigkeit"
		<< setw(20) << "Gesamtstrecke"
		<< setw(20) << "Geschwindigkeit"
		<< setw(20) << "Gesamtverbrauch"
		<< setw(15) << "Tankinhalt" << endl;

	cout << setw(115) << setfill('-') << '-' << setfill(' ') << endl;
}

// Simulation-Funktion. Wenn die von einem Objekt aufgerufen wird, wird das Objekt eine Zeittakt(Zeitdiffernez) simuliert.
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

// Überladen des Operators '='
// Außer ID Attribute, wird alles kopiert und übertragen.
void Fahrzeug::operator=(const Fahrzeug& andere) {
	//Kontrolliere ob das Objekt selbst aufruft.
	if (this == &andere) {
		;
	}else {
		this->p_sName = andere.getName();
		this->p_dMaxGeschwindigkeit = andere.getMaxGeschwindigkeit();
		this->p_dGesamtstrecke = andere.getGesamtstrecke();
		this->p_dZeit = andere.getZeit();
		this->p_dGesamtZeit = andere.getGesamtZeit();
	}
}

/*Fahrzeug& operator=(const Fahrzeug& other) {
	//Kontrolliere ob das Objekt selbst aufruft.
	if (this == &other) {
		return *this;
	}

	this->p_sName = other.p_sName;
	this->p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
	this->p_dGesamtstrecke = other.p_dGesamtstrecke;
	this->p_dZeit = other.p_dZeit;
	this->p_dGesamtZeit = other.p_dGesamtZeit;

	return *this;
}*/

// Überladen des '<' (kleiner als) operators
// Wenn das Vergleichobjekt größer ist, ist diese Bedingung richtig.
bool Fahrzeug::operator<(const Fahrzeug& andere)const{
	if(this->getGesamtstrecke() < andere.getGesamtstrecke()){
		return true;
	} else{
		return false;
	}
}
