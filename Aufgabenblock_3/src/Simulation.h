/*
 * Simulation.h
 *
 *  Created on: 20.01.2024
 *      Author: kyotun
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "Kreuzung.h"
#include "Tempolimit.h"
#include "PKW.h"
#include "Fahrrad.h"

using namespace std;

class Simulation{
public:
	// Voids
	void vSimulieren(double dDauer, double dZeitschritt);
	void vEinlesen(istream& is, bool bMitGrafik = false);
	void vAddKreuzung(const string& name, shared_ptr<Kreuzung> kreuzung);
	void vCheckKreuzung(const string& name);
	void vCheckDoppelKreuzung(const string& name);
	void vAktualisiereKreuzung(const string& name, shared_ptr<Kreuzung> kreuzung);

	// Setters

	// Getters
	shared_ptr<Kreuzung> getKreuzung(const string& name);

	// Checkers
	void vCheckKreuzungName(string name);

	// Converters
	Tempolimit convertTempolimit(int iTempolimit);

private:
	map<string, shared_ptr<Kreuzung>> kreuzungenMap;
};



#endif /* SIMULATION_H_ */
