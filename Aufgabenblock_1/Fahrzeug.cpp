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
extern double dGlobaleZeit;

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

// Ausgabe Funktion, die zum Ausgeben von der Eigenschaften der Objekten dient.
// Es reicht nur das Objekt zu cout zu geben.
void Fahrzeug::vAusgeben(ostream& ausgabe) const{
	ausgabe << resetiosflags(ios::adjustfield)
			<< setiosflags(ios::left)
			<< setprecision(2) << fixed
			<< setw(8) << getID()
			<< setw(15) << getName()
			<< setiosflags(ios::right)
			<< setw(20) << getMaxGeschwindigkeit()
			<< setw(20) << getGesamtstrecke()
			<< setw(20) << dGeschwindigkeit();
}

// Ausgabe Funktion, die zum Ausgeben von der Eigenschaften der Objekten dient.
// Es ist eine Objektmethode.
void Fahrzeug::vAusgeben() const{

	cout << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setprecision(2) << fixed
		 << setw(8) << getID()
	     << setw(15) << getName()
		 << setiosflags(ios::right)
		 << setw(20) << getMaxGeschwindigkeit()
		 << setw(20) << getGesamtstrecke()
		 << setw(20) << dGeschwindigkeit();
}

// Kopf Funktion wird vor der Funktion Ausgeben aufgerufen,
// damit ist die Ausgaben(Eigenschaften der Objekten) besser und deutlich zu sehen.
void Fahrzeug::vKopf(){
	cout << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setw(8) << "ID"
		 << setw(10) << "Name"
		 << setiosflags(ios::right)
		 << setw(20) << "MaxGeschwindigkeit"
		 << setw(20) << "Gesamtstrecke"
		 << setw(20) << "Geschwindigkeit"
		 << setw(20) << "Gesamtverbrauch"
		 << setw(15) << "Tankinhalt" << endl;

	cout << setw(8+10+20*4+15) << setfill('-') << '-' << setfill(' ') << endl;

}

// Simulation-Funktion. Wenn die von einem Objekt aufgerufen wird, wird das Objekt eine Zeittakt(Zeitdiffernez) simuliert.
void Fahrzeug::vSimulieren(){
	// 1 km/h -> 2,77 m/s
	// Zeitdifferenz ist der Differenz zwischen t(t) und t(t+1)
	if(p_dZeit == dGlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
	}else{
		double dZeitdifferenz = dGlobaleZeit - p_dZeit;
		p_dGesamtZeit += dZeitdifferenz;
		p_dGesamtstrecke += dGeschwindigkeit() * dZeitdifferenz;
		p_dZeit = dGlobaleZeit; // Die Letzte Zeit, in der das Fahrzeug sich bewegt hat.
	}

}

// Überladung von '<<' (Ausgabe) Operator.
// Nun können die Objekte der Klasse Fahrzeug(und die Unterkalsse Objekte davon)
// einfach mit "cout << Objekt" ausgegeben werden. Ohne die Ausgabefunktion zu nutzen.
ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug){
	fahrzeug.vAusgeben(ausgabe);
	return ausgabe;
}

// Überladen des '<' (kleiner als) operators
// Wenn das Vergleichobjekt größer ist, ist diese Bedingung richtig.
bool Fahrzeug::operator<(const Fahrzeug& andere)const{
	if(this->getGesamtstrecke() < andere.getGesamtstrecke()){
		return true;
	} else{
		return false;
	}
}

// Überladen des Operators '='
// Außer ID Attribute, wird alles kopiert und übertragen.
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& other) {
	//Kontrolliere ob das Objekt selbst aufruft.
	if (this == &other) {
		return *this;
	}

	this->p_sName = other.getName();
	this->p_dMaxGeschwindigkeit = other.getMaxGeschwindigkeit();
	this->p_dGesamtstrecke = other.getGesamtstrecke();
	this->p_dZeit = other.getZeit();
	this->p_dGesamtZeit = other.getGesamtZeit();

	return *this;
}

/*
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
*/

