/*
 * Fahrzeug.cpp
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */
#include <iostream>
#include <iomanip>
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Parken.h"
#include "Fahren.h"
#include "Fahrausnahme.h"

using namespace std;
extern double dGlobaleZeit;



// Fahrzeug-Objekt mit dem Name
Fahrzeug::Fahrzeug(string p_sName): Simulationsobjekt(p_sName){
}

// Fahrzeug-Objekt Konstruktor mit dem Name und der Geschwindigkeit
Fahrzeug::Fahrzeug(string p_sName, double p_dMaxGeschwindigkeit): Simulationsobjekt(p_sName),
		p_dMaxGeschwindigkeit((p_dMaxGeschwindigkeit > 0) ? p_dMaxGeschwindigkeit : 0){}

// Ausgabe Funktion, die zum Ausgeben von der Eigenschaften der Objekten dient.
// Es reicht nur das Objekt zu cout zu geben.
void Fahrzeug::vAusgeben(ostream& ausgabe) const {

	Simulationsobjekt::vAusgeben(ausgabe);
	ausgabe << resetiosflags(ios::left)
			<< setiosflags(ios::right)
			<< setw(20) << getMaxGeschwindigkeit()
			<< setw(20) << getGesamtstrecke()
			<< setw(20) << dGeschwindigkeit();
}

// Ausgabe Funktion, die zum Ausgeben von der Eigenschaften der Objekten dient.
// Es ist eine Objektmethode.
void Fahrzeug::vAusgeben() const{

	Simulationsobjekt::vAusgeben();
	cout << resetiosflags(ios::left)
		 << setiosflags(ios::right)
		 << setw(20) << getMaxGeschwindigkeit()
		 << setw(20) << getGesamtstrecke()
		 << setw(20) << dGeschwindigkeit();
}

// Kopf Funktion wird vor der Funktion Ausgeben aufgerufen,
// damit ist die Ausgaben(Eigenschaften der Objekten) besser und deutlich zu sehen.
void Fahrzeug::vKopf(){
	cout << endl << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setw(8) << "ID"
		 << setw(15) << "Name"
		 << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::right)
		 << setw(20) << "MaxGeschwindigkeit"
		 << setw(20) << "Gesamtstrecke"
		 << setw(20) << "Geschwindigkeit"
		 << setw(20) << "Gesamtverbrauch"
		 << setw(15) << "Tankinhalt"
		 << setw(10) << "Zeit"
		 << setw(15) << "GlobaleZeit" << endl;

	cout << setw(8+10+15*3+20*4) << setfill('-') << '-' << setfill(' ') << endl;

}

// Simulation-Funktion. Wenn die von einem Objekt aufgerufen wird, wird das Objekt eine Zeittakt(Zeitdiffernez) simuliert.
void Fahrzeug::vSimulieren(){
	// 1 km/h -> 2,77 m/s
	// Zeitdifferenz ist der Differenz zwischen t(t) und t(t+1)
	if(p_dZeit == dGlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
		return;
	}else{
		//Zeitdifferenz zwischen Globalezeit und letzte simulierende Zeit.
		double dZeitdifferenz = dGlobaleZeit - p_dZeit;

		//Aktuell gefahrende Strecke

		//wenn es ein Verhalten gibt, soll die Geschwindigkeit nach diesem Verhalten ausrechnet werden.
		if(p_pVerhalten){
			double dTeilStrecke = p_pVerhalten->dStrecke(*this, dZeitdifferenz);
			p_dAbschnittStrecke += dTeilStrecke;
			p_dGesamtstrecke += dTeilStrecke;
			Weg* pWeg = p_pVerhalten->getpWeg();
			if(pWeg->bSuchtFahrzeug(*this)){
				pWeg->setSchranke(0.0);
			}else{
				pWeg->setSchranke(p_dAbschnittStrecke);
			}
		}else{
			double dTeilStrecke = dGeschwindigkeit()*dZeitdifferenz;
			p_dAbschnittStrecke += dTeilStrecke;
			p_dGesamtstrecke += dTeilStrecke;
		}

		p_dGesamtZeit += dZeitdifferenz;
		p_dZeit = dGlobaleZeit; // Die Letzte Zeit, in der das Fahrzeug sich bewegt hat.

	}
}

//Wenn ein Fahrzeug von einem Weg akzeptiert wurde, soll es auch diesen Weg in sich selbst anerkannt machen.
//Diese Method für die fahrende Fahrzeuge
void Fahrzeug::vNeueStrecke(Weg& weg){
	p_pVerhalten = make_unique<Fahren>(weg);
	this->vResetAbschnittStrecke();
	cout << "Fahrzeug " << p_sName << " ist in den Weg " << weg.getName() << " zum Fahren angekommen." << endl;
}

//Wenn ein Fahrzeug von einem Weg akzeptiert wurde, soll es auch diesen Weg in sich selbst anerkannt machen.
//Diese Method für die parkende Fahrzeuge.
//Parkende Fahrzeuge warten bis die Globalezeit gleich Startzeitpunkt ist.
void Fahrzeug::vNeueStrecke(Weg& weg, double dStartZeitpunkt){
	if(p_pVerhalten){
		p_pVerhalten.reset();
	}
	p_pVerhalten = make_unique<Parken>(weg, dStartZeitpunkt);
	this->vResetAbschnittStrecke();
	cout << "Fahrzeug " << p_sName << " ist in den Weg " << weg.getName() << " zum Parken angekommen." << endl;
}

void Fahrzeug::vEinlesen(istream& is){
	Simulationsobjekt::vEinlesen(is);

	if (p_dMaxGeschwindigkeit != 0.0) {
		throw runtime_error("Object already initialized");
	}

	cout << "Please enter the maximale Geschwindigkeit des Objekts " << this->getID() << ":";
	is >> p_dMaxGeschwindigkeit;

	if(is.fail()){
		throw runtime_error("Error reading from input stream.");
	}
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
	Simulationsobjekt::operator =(other);
	this->p_dMaxGeschwindigkeit = other.getMaxGeschwindigkeit();
	this->p_dGesamtstrecke = other.getGesamtstrecke();
	this->p_dZeit = other.getZeit();
	this->p_dGesamtZeit = other.getGesamtZeit();

	return *this;
}


// Überladung von '<<' (Ausgabe) Operator.
// Nun können die Objekte der Klasse Fahrzeug(und die Unterkalsse Objekte davon)
// einfach mit "cout << Objekt" ausgegeben werden. Ohne die Ausgabefunktion zu nutzen.

ostream& operator<<(ostream& ausgabe,const Fahrzeug& fahrzeug) {
	fahrzeug.vAusgeben(ausgabe);
	return ausgabe;
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

