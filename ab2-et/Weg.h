/*
 * Weg.h
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#ifndef WEG_H_
#define WEG_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <list>
#include <cmath>
using namespace std;
extern double dGlobaleZeit;

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Tempolimit.h"

class Weg : public Simulationsobjekt{
public:
	Weg() = default; // @suppress("Class members should be properly initialized")
	Weg(string p_sName, double p_dLaenge, Tempolimit p_eTempolimit=Tempolimit::Autobahn);
	~Weg() = default;

	//Getters
	double getTempolimit() const;
	double getLaenge() const{return p_dLaenge;};
	void getFahrzeuge() const;

	//Setters
	void setFahrzeug(unique_ptr<Fahrzeug> fahrzeug);
	void setFahrzeugList(list<unique_ptr<Fahrzeug>> fahrzeugList);

	//String

	//Void
	void vAusgeben() const override;

protected:
private:
	//Double
	double p_dLaenge = 0.0;
	list<unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;

};




#endif /* WEG_H_ */
