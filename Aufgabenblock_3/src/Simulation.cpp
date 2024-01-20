/*
 * Simulation.cpp
 *
 *  Created on: 20.01.2024
 *      Author: kyotun
 */

#include <iostream>
#include <map>
#include "Simulation.h"

using namespace std;


//void Simulation::vEinlesen(istream& is, bool bMitGrafik=false){
//
//
//}

// Getter for a specific Kreuzung by name
const Kreuzung& getKreuzung(const string& name){
	// Check if the requested Kreuzung exists
	auto it = getKreuzungenMap().find(name);
	if (it == getKreuzungenMap().end()) {
		throw std::runtime_error("Kreuzung not found: " + name);
	}

	return it->second;
}

