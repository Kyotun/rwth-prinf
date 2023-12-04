/*
 * Weg.cpp
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#include "Weg.h"
#include "Fahrzeug.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <cmath>
using namespace std;
extern double dGlobaleZeit;


Weg::Weg(string p_sName, double p_dLaenge, Tempolimit p_eTempolimit):
		Simulationsobjekt(p_sName), p_dLaenge(p_dLaenge), p_eTempolimit(p_eTempolimit){}

void Weg::vAusgeben(ostream& ausgabe) const{
	Simulationsobjekt::vAusgeben(ausgabe);
	ausgabe << setw(0) << ": "
			<< setw(15) << getLaenge()
			<< setw(0) << "( "
			<< setw(0);
			getFahrzeuge();
	ausgabe << ")";
}

void Weg::vAusgeben() const{
	Simulationsobjekt::vAusgeben();
	cout << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setw(10) << ": " << getLaenge()
		 << setw(10) << "( ";
			getFahrzeuge();
	cout << ")";
}

void Weg::vKopf(){
	cout << endl << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setw(5) << "ID"
		 << setw(15) << "| Name"
		 << setw(15) << "| Laenge"
		 << setw(15) << "| Fahrzeuge" << endl;

	cout << setw(8+15*3) << setfill('-') << '-' << setfill(' ') << endl;

}

void Weg::vAnnahme(unique_ptr<Fahrzeug>fahrzeug){
	fahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(std::move(fahrzeug));
}

void Weg::vAnnahme(unique_ptr<Fahrzeug>fahrzeug, double dStartZeitpunkt){
	fahrzeug->vNeueStrecke(*this, dStartZeitpunkt);
	p_pFahrzeuge.push_front(std::move(fahrzeug));
}

void Weg::setFahrzeug(unique_ptr<Fahrzeug> fahrzeug){
	p_pFahrzeuge.push_back(std::move(fahrzeug));
}

void Weg::setFahrzeugList(list<unique_ptr<Fahrzeug>> fahrzeugList){
	for(auto&& fahrzeugPtr : fahrzeugList){
		p_pFahrzeuge.push_back(std::move(fahrzeugPtr));
	}

//	p_pFahrzeuge.insert(p_pFahrzeuge.end(),
//			make_move_iterator(fahrzeugList.begin()),
//			make_move_iterator(fahrzeugList.end()));
}
void Weg::getFahrzeuge() const{
	for(auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++){
		const Fahrzeug* fahrzeug = it->get();
		if(it == --p_pFahrzeuge.end()){
			cout << fahrzeug->getName() << " ";
		} else{
			cout << fahrzeug->getName() << ", ";
		}
	}
}

double Weg::getTempolimit() const{
	cout << fixed << setprecision(2);
	return (double)p_eTempolimit;
}



