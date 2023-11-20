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

Fahrrad::Fahrrad(string p_sName): Fahrzeug(p_sName){
}

Fahrrad::Fahrrad(string p_sName, double p_dMaxGeschwindigkeit):
		Fahrzeug(p_sName, p_dMaxGeschwindigkeit){}

double Fahrrad::dGeschwindigkeit(){

	if((p_dMaxGeschwindigkeit*(0.9)) < 12){
		p_dMaxGeschwindigkeit = 12;
	} else{
		if(p_iZeahler == (int)p_dGesamtstrecke/20){
			; // Der Fahrrad konnte noch nicht die 20km zurücklegen.
		} else{
			p_iZeahler = p_dGesamtstrecke/20;
			p_dMaxGeschwindigkeit = p_dMaxGeschwindigkeit * (0.9);
		}
	}
	return p_dMaxGeschwindigkeit;
}

void Fahrrad::vAusgeben(std::ostream& ausgabe) const{
	Fahrzeug::vAusgeben(ausgabe);
}

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
