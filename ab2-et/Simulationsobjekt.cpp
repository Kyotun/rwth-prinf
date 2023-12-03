/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */


#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <cmath>
using namespace std;
extern double dGlobaleZeit;

#include "Simulationsobjekt.h"

//Standard-Konstruktor
Simulationsobjekt::Simulationsobjekt(){
	cout << "Ein Simulationsobjekt wurde mit der ID '" << p_iID
		 << "' erzeugt." << endl;
}

// Standard-Destruktor
Simulationsobjekt::~Simulationsobjekt(){
	cout << "Ein Simulationsobjekt wurde mit dem Name '" << p_sName
		 << "' und mit der ID " << p_iID
		 << " gelöscht." << endl;
}
Simulationsobjekt::Simulationsobjekt(string p_sName): p_sName(p_sName){
	cout << "Ein Simulationsobjekt wurde mit dem Name '" << p_sName
			 << "' und mit der ID " << p_iID
			 << " erzeugt." << endl;
}

//void Simulationsobjekt::vSimulieren(){
//
//}

void Simulationsobjekt::vAusgeben(ostream& ausgabe) const{
	ausgabe << resetiosflags(ios::adjustfield)
			 << setiosflags(ios::left)
			 << setprecision(2) << fixed
			 << setw(8) << getID()
		     << setw(15) << getName();
}

void Simulationsobjekt::vAusgeben() const{
	cout << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setprecision(2) << fixed
		 << setw(8) << getID()
		 << setw(15) << getName();
}


Simulationsobjekt& Simulationsobjekt::operator=(const Simulationsobjekt& other) {
	//Kontrolliere ob das Objekt selbst aufruft.
	if (this == &other) {
		return *this;
	}

	this->p_sName = other.getName();

	return *this;
}
bool Simulationsobjekt::operator==(const Simulationsobjekt& andere){
	if(this->p_iID == andere.p_iID){
		return true;
	}
	return false;

}

ostream& operator<<(ostream& ausgabe, const Simulationsobjekt& simulationsobjekt){
	simulationsobjekt.vAusgeben(ausgabe);
	return ausgabe;
}
