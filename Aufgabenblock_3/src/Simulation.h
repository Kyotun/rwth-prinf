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

using namespace std;

class Simulation{
public:
	// Voids
	void vSimulieren(double dDauer, double dZeitschritt);
	void vEinlesen(istream& is, bool bMitGrafik=false);
	void addKreuzung(const string& name, const Kreuzung& kreuzung);
	void vCheckKreuzung(const string& name);
	void vCheckDoppelKreuzung(const string& name);

	// Setters


	// Getters
	const map<string, Kreuzung>& getKreuzungenMap() const;
	const Kreuzung& getKreuzung(const string& name);

private:
	map<string, Kreuzung> kreuzungenMap;
};



#endif /* SIMULATION_H_ */
