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

	int n = 0;

	if((p_dMaxGeschwindigkeit*(0.9)) < 12){
		p_dMaxGeschwindigkeit = 12;
	} else{
		n = p_dGesamtstrecke / 20;
		if(p_iZeahler == n){
			;
		} else{
			p_iZeahler = n;
			p_dMaxGeschwindigkeit = p_dMaxGeschwindigkeit * (0.9);
		}
	}
	return p_dMaxGeschwindigkeit;
}

void Fahrrad::vAusgeben(std::ostream& ausgabe) const{
	ausgabe << p_iID << "\t"
			<< p_sName << "\t"
			<< p_dMaxGeschwindigkeit << "\t\t\t"
			<< p_dGesamtstrecke << "\n";
}

void Fahrrad::vSimulieren(){

	if(p_dZeit == GlobaleZeit){
		cout << "Farhzeug '" << p_sName << "' wurde vorher schon einmal simuliert." << endl;
	}else{
		p_dZeit = GlobaleZeit;
		p_dGesamtZeit++;
		dGeschwindigkeit();
		p_dGesamtstrecke = p_dMaxGeschwindigkeit * p_dGesamtZeit;
	}
}
