/*
 * Fahrrad.cpp
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */


#include "Fahrrad.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
extern double GlobaleZeit;

// Konstruktor mit dem Name, erbt von der Klasse Fahrzeug
Fahrrad::Fahrrad(string p_sName): Fahrzeug(p_sName){
}

// Konstruktor mit dem Name und der Geschwindigkeit, erbt von der Klasse Fahrzeug
Fahrrad::Fahrrad(string p_sName, double p_dMaxGeschwindigkeit):
		Fahrzeug(p_sName, p_dMaxGeschwindigkeit){}

// Geschwindigkeitfunktion, die die aktuelle Geschwindigkeit der Fahrräder aktualisiert.
// Wenn es schon kleiner gleich 12 ist, bleibt es 12.
// Wenn nicht, soll die aktuelle Geschwinidkgiet mit 0.9 in jeder Zeittakt multipliziert werden,
// um die aktuelle Geschwindigkeit aktualisieren zu können
double Fahrrad::dGeschwindigkeit() const{

	double d_aktuelleGeschwindigkeit = 0.0;
	int i_anzahl20kms = (int)p_dGesamtstrecke/20;

	d_aktuelleGeschwindigkeit = dMehrfachMultiplikation(p_dMaxGeschwindigkeit, 0.9, i_anzahl20kms);

	if(d_aktuelleGeschwindigkeit <= 12.0){
		d_aktuelleGeschwindigkeit = 12.0;
	}

	return d_aktuelleGeschwindigkeit;
}

// Berehcne 0.9 fach von MaxGeschwindigkeit des Fahrrads, basiert auf die Anzahl(p_dGesamtstrecke/20)
double Fahrrad::dMehrfachMultiplikation(double base, double konstant, int mal) const{

	double result = this->p_dMaxGeschwindigkeit;

	for(int i = 0; i < mal; i++){
		result *= konstant;
	}

	return result;
}


// Ausgabefunktion der Klasse Fahrrad, erbt von Fahrzeug und werden einige Fahrradspezifische Eigenschaften addiert.
void Fahrrad::vAusgeben(std::ostream& ausgabe) const{
	Fahrzeug::vAusgeben(ausgabe);
	cout << setw(20) << this->dGeschwindigkeit()
		<< setw(20) << "-"
			<< setw(15) << "-" << endl;
}


// Simulationfunktion der Klasse Fahrrad.
// In jeder Zeittakt soll die aktuelle Geschwindigkeit mit der Funktion dGeschwindigkeit() erneut berechnet werden.
void Fahrrad::vSimulieren(double Zeitdifferenz){

	if(p_dZeit == GlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
	}else{
		p_dGesamtZeit += Zeitdifferenz;
		p_dGesamtstrecke = p_dMaxGeschwindigkeit * p_dGesamtZeit;
		dGeschwindigkeit();
		p_dZeit = GlobaleZeit;
	}
}
