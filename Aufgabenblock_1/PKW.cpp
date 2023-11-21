/*
 * PKW.cpp
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */

#include "PKW.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
extern double GlobaleZeit;

// Konstruktor mit dem Name, erbt von Fahrzeug
PKW::PKW(string p_sName): Fahrzeug(p_sName){}

// Konstruktor mit dem Name und  der Geschwindigkeit, erbt von Fahrzeug
PKW::PKW(string p_sName, double p_dMaxGeschwindigkeit): Fahrzeug(p_sName, p_dMaxGeschwindigkeit){}

// Konstruktor mit dem Verbrauch und Tankvolumen
PKW::PKW(double p_dVerbrauch, double p_dTankvolumen):
		p_dVerbrauch(p_dVerbrauch), p_dTankvolumen(p_dTankvolumen){
	cout << "Ein PKW wurde mit dem Verbrauch '" << p_dVerbrauch
			<<"' und der Tankvolumen '" << p_dTankvolumen << "' erzeugt" << endl;
}

// Konstruktor mit dem Name, der Geschwindigkeit, dem Verbrauch und dem Tankvolumen.
// Der erbt den Name und die Geschwindigkeit von der Fahrzeugklasse
PKW::PKW(string p_sName, double p_dMaxGeschwindigkeit,
				double p_dVerbrauch, double p_dTankvolumen):
					Fahrzeug(p_sName, p_dMaxGeschwindigkeit),
					p_dVerbrauch(p_dVerbrauch), p_dTankvolumen(p_dTankvolumen){}

// Rechne den Gesamtverbrauch und gibt es zurück.
double PKW::getGesamtVerbrauch() const{
	// Gesamtstrecke in km erste Klammer
	// Zweite Klammer = Gesamtverbrauch in 1 km
	return (p_dMaxGeschwindigkeit*p_dGesamtZeit)*(p_dVerbrauch/100);
}

// Gibt den aktuellen Tankinhalt zurück
double PKW::getTankinhalt() const{
	return p_dTankinhalt;
}

// Tanken Funktion, die zur Tanken von PKWs dient.
// Im Laufe der Zeit nimmt der Tankinhalt der PKWs ab,
// die aber noch wieder gefüllt werden sollen, um weitersimuliert werden zu können.
double PKW::dTanken(double dMenge){

	if(!(0.0 <= dMenge && dMenge <= 1.0)){
		cout << "Die getankte Menge soll zwischen 0 und 1 legen." << endl;
	} else{
		p_dTankinhalt = dMenge;
	}

	return p_dTankvolumen*p_dTankinhalt;
}

// Simulationfunktion von PKWs.
// In jeder Zeittakt, in der die PKWs similuert werden, nimmt der aktuelle Tankvolumen ab.
// Kontrolliere ob es größer null ist, wenn nicht, darf das PKW nicht weiter simuliert.
void PKW::vSimulieren(double Zeitdifferenz) {

	double d_aktuelleVolumen = p_dTankinhalt*p_dTankvolumen;
	// 1 km/h -> 2,77 m/s
	if(p_dZeit == GlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
	} else {
		if(p_dTankinhalt > 0){
			p_dZeit = GlobaleZeit;
			p_dGesamtZeit += Zeitdifferenz;
			d_aktuelleVolumen -= (p_dMaxGeschwindigkeit*Zeitdifferenz)*(p_dVerbrauch/100);
			p_dTankinhalt = d_aktuelleVolumen/p_dTankvolumen;
			p_dGesamtstrecke = p_dMaxGeschwindigkeit * p_dGesamtZeit;
		} else{
			p_dZeit = GlobaleZeit;
			cout << "Der Tank des Fahrzeugs '"
				 << p_sName
				 << "' ist leer. Es darf nicht fahren und soll getankt werden."
				 << endl;
		}
	}
}

// Erbt die Ausgebenfunktion von der Fahrzeugklasse und f
// üge in der Ausgabefunktion die besondere Einheiten von PKws hinzu.
void PKW::vAusgeben(std::ostream& ausgabe) const{
	Fahrzeug::vAusgeben(ausgabe);
	cout << setw(20) << getMaxGeschwindigkeit()
			<< setw(20) << getGesamtVerbrauch()
			<< setw(15) << getTankinhalt() << endl;
}


