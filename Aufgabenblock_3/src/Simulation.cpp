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


void Simulation::vEinlesen(istream& is, bool bMitGrafik=false){
	return;
}

void Simulation::vSimulieren(double dDauer, double dZeitschritt){
	return;
}

void Simulation::vCheckKreuzung(const string& name){
	if(kreuzungenMap.find(name) == kreuzungenMap.end()){
		throw runtime_error("Es gibt keine Kreuzung unter diesen Name.");
	}
}

void Simulation::vCheckDoppelKreuzung(const string& name){
	if(kreuzungenMap.find(name) != kreuzungenMap.end()){
		throw runtime_error("Es gibt bereits eine andere Kreuzunge unter der Name: " + name);
	}
}

// Function to add a Kreuzung to the map
void Simulation::addKreuzung(const string& name, const Kreuzung& kreuzung) {
	vCheckDoppelKreuzung(name);
	kreuzungenMap[name] = kreuzung;
}

const map<string, Kreuzung>& Simulation::getKreuzungenMap() const{
	return kreuzungenMap;
}

const Kreuzung& Simulation::getKreuzung(const string& name) {
	vCheckKreuzung(name);
    auto it = getKreuzungenMap().find(name);
    return it->second;
}


