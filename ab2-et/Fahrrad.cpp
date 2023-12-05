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
#include <vector>
#include <cmath>

using namespace std;
extern double dGlobaleZeit;

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
	int iAnzahlAbschnitt = (int)p_dGesamtstrecke/20;

	d_aktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * pow(0.9, iAnzahlAbschnitt);

	if(d_aktuelleGeschwindigkeit <= 12.0){
		d_aktuelleGeschwindigkeit = 12.0;
	}

	return d_aktuelleGeschwindigkeit;
}

// Ausgabefunktion der Klasse Fahrrad, erbt von Fahrzeug und werden einige Fahrradspezifische Eigenschaften addiert.
void Fahrrad::vAusgeben(std::ostream& ausgabe) const{
	Fahrzeug::vAusgeben(ausgabe);
	ausgabe << setw(20) << "-"
			<< setw(15) << "-"
			<< setw(10) << getZeit()
			<< setw(15) << getGlobaleZeit() << endl;
}

void Fahrrad::vAusgeben() const{
	Fahrzeug::vAusgeben();
	cout << setw(20) << "-"
	   	 << setw(15) << "-"
		 << setw(10) << getZeit()
		 << setw(15) << getGlobaleZeit() << endl;
}


// Simulationfunktion der Klasse Fahrrad.
// In jeder Zeittakt soll die aktuelle Geschwindigkeit mit der Funktion dGeschwindigkeit() erneut berechnet werden.
void Fahrrad::vSimulieren(){
	Fahrzeug::vSimulieren();
}
