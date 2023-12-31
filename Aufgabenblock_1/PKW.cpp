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
#include <vector>
#include <cmath>

using namespace std;
extern double dGlobaleZeit;

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

	if(dMenge > p_dTankvolumen){
		dMenge = p_dTankvolumen;
		cout << "Der Tankvolumenlimit ist überschritten, der Tank ist voll!" << endl;
	}
	if(0.0 > dMenge){
		cout << "Die getankte Menge darf nicht kleiner als 0 sein." << endl;
		return 0.0;
	}

	double dTankinhaltVorher = p_dTankinhalt;
	p_dTankinhalt = dMenge;

	return (p_dTankinhalt - dTankinhaltVorher);
}

// Simulationfunktion von PKWs.
// In jeder Zeittakt, in der die PKWs similuert werden, nimmt der aktuelle Tankvolumen ab.
// Kontrolliere ob es größer null ist, wenn nicht, darf das PKW nicht weiter simuliert.
void PKW::vSimulieren() {

	if(p_dTankinhalt <= 0){
		p_dZeit = dGlobaleZeit;
		cout << "Der Tank des Fahrzeugs '"
			 << p_sName
			 << "' ist leer. Es darf nicht fahren und soll getankt werden."
			 << endl;
		return;
	}

	double dGesamtstreckeVorher = p_dGesamtstrecke;
	Fahrzeug::vSimulieren();
	double dVerbrauchtTankVolumen = (p_dGesamtstrecke - dGesamtstreckeVorher)*(p_dVerbrauch/100);
	double dAktuellTankVolumen = p_dTankinhalt - dVerbrauchtTankVolumen;
	if(dAktuellTankVolumen < 0){
		dAktuellTankVolumen = 0;
	}
	p_dTankinhalt = dAktuellTankVolumen;
}

// Erbt die Ausgebenfunktion von der Fahrzeugklasse und f
// üge in der Ausgabefunktion die besondere Einheiten von PKws hinzu.
void PKW::vAusgeben(std::ostream& ausgabe) const{
	Fahrzeug::vAusgeben(ausgabe);
	cout << setw(20) << getGesamtVerbrauch()
		 << setw(15) << getTankinhalt() << endl;
}

void PKW::vAusgeben() const {
	Fahrzeug::vAusgeben();
	cout << setw(20) << getGesamtVerbrauch()
		 << setw(15) << getTankinhalt() << endl;
}


