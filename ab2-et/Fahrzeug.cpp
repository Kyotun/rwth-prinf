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
void Fahrzeug::vAusgeben(ostream& ausgabe) const{

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
		 << resetiosflags(ios::left)
		 << setiosflags(ios::right)
		 << setw(20) << "MaxGeschwindigkeit"
		 << setw(20) << "Gesamtstrecke"
		 << setw(20) << "Geschwindigkeit"
		 << setw(20) << "Gesamtverbrauch"
		 << setw(15) << "Tankinhalt" << endl;

	cout << setw(8+15+20*4+15) << setfill('-') << '-' << setfill(' ') << endl;

}

// Simulation-Funktion. Wenn die von einem Objekt aufgerufen wird, wird das Objekt eine Zeittakt(Zeitdiffernez) simuliert.
void Fahrzeug::vSimulieren(){
	// 1 km/h -> 2,77 m/s
	// Zeitdifferenz ist der Differenz zwischen t(t) und t(t+1)
	if(p_dZeit == dGlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
		return;
	}else{
		double dZeitdifferenz = dGlobaleZeit - p_dZeit;

		//Aktuell gefahrende Strecke
		static double dTeilStrecke = p_pVerhalten->dStrecke(*this, dZeitdifferenz);

		//Laenge des Wegs
		double dLaenge = (p_pVerhalten->getpWeg())->getLaenge();

		//Verbleibendes Weg
		double dVerbleibend = dLaenge-p_dAbschnittStrecke;

		if(dTeilStrecke > dVerbleibend){
			p_dAbschnittStrecke = (p_pVerhalten->getpWeg())->getLaenge();
		} else{
			p_dAbschnittStrecke += dTeilStrecke;
		}

		p_dGesamtstrecke += dTeilStrecke;
		p_dGesamtZeit += dZeitdifferenz;
		p_dZeit = dGlobaleZeit; // Die Letzte Zeit, in der das Fahrzeug sich bewegt hat.
	}

}

void Fahrzeug::vNeueStrecke(Weg& weg){
	if(p_pVerhalten){
		p_pVerhalten.reset();
	}
	p_pVerhalten = make_unique<Fahren>(weg);
	p_dAbschnittStrecke = 0.0;
	cout << "Fahrzeug " << p_sName << " ist in den Weg " << weg.getName() << " zum Fahren angekommen." << endl;
}

void Fahrzeug::vNeueStrecke(Weg&weg, double dStartZeitpunkt){
	if(p_pVerhalten){
		p_pVerhalten.reset();
	}
	p_pVerhalten = make_unique<Parken>(weg, dStartZeitpunkt);
	p_dAbschnittStrecke = 0.0;
	cout << "vNeueStrecke: Neuer Weg parken." << endl;

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
	Simulationsobjekt::operator =(other);
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

