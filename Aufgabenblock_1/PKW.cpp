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

PKW::PKW(string p_sName): Fahrzeug(p_sName){}
PKW::PKW(string p_sName, double p_dMaxGeschwindigkeit): Fahrzeug(p_sName, p_dMaxGeschwindigkeit){}

PKW::PKW(double p_dVerbrauch, double p_dTankvolumen):
		p_dVerbrauch(p_dVerbrauch), p_dTankvolumen(p_dTankvolumen){
	cout << "Ein PKW wurde mit dem Verbrauch '" << p_dVerbrauch
			<<"' und der Tankvolumen '" << p_dTankvolumen << "' erzeugt" << endl;
}

PKW::PKW(string p_sName, double p_dMaxGeschwindigkeit,
				double p_dVerbrauch, double p_dTankvolumen):
					Fahrzeug(p_sName, p_dMaxGeschwindigkeit),
					p_dVerbrauch(p_dVerbrauch), p_dTankvolumen(p_dTankvolumen){}

double PKW::dTanken(double dMenge){

	if(!(0.0 <= dMenge && dMenge <= 1.0)){
		cout << "Die getankte Menge soll zwischen 0 und 1 legen." << endl;
	} else{
		p_dTankinhalt = dMenge;
	}

	return p_dTankvolumen*p_dTankinhalt;
}

void PKW::vSimulieren() {
	// 1 km/h -> 2,77 m/s
	if(p_dZeit == GlobaleZeit){
		//throw runtime_error("Ein Fahrzeug darf in einer Zyklus nur einmal simuliert werden.\n");
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
	} else {
		if(p_dTankinhalt > 0){
			p_dZeit = GlobaleZeit;
			p_dGesamtZeit++;
			p_dTankinhalt -= 0.1;
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

void PKW::vAusgeben(std::ostream& ausgabe) const{
	//p_iID, p_sName, p_dMaxGeschwindigkeit, p_dGesamtstrecke

	ausgabe << "Verbrauch: " << p_dVerbrauch << ", "
			<< "Tankvolumen: " << p_dTankvolumen
			<< " ,Tankinhalt: " << p_dTankinhalt << endl;
}


