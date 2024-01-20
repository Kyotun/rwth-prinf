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
	void vSimulieren();
	void vEinlesen(istream& is, bool bMitGrafik=false);

	// Setters


	// Getters
	const map<string, Kreuzung>& getKreuzungenMap() const{return kreuzungenMap;}
	const Kreuzung& getKreuzung(const string& name){
		// Check if the requested Kreuzung exists
		auto it = getKreuzungenMap().find(name);
		if (it == getKreuzungenMap().end()) {
			throw runtime_error("Kreuzung not found: " + name);
		}

		return it->second;
	}

private:
	map<string, Kreuzung> kreuzungenMap;
};



#endif /* SIMULATION_H_ */
