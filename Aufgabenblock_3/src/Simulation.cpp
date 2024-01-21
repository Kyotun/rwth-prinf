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
extern double dGlobaleZeit;

void Simulation::vEinlesen(istream& is, bool bMitGrafik){
	string line;
	string firstWord;
	int lineNumber = 0;

	while (getline(is, line)) {
		lineNumber++;
		istringstream iss(line);
		iss >> firstWord;

		if(firstWord == "KREUZUNG"){
			string name;
			int dTankstelle;
			iss >> name;
			vCheckDoppelKreuzung(name);
			vCheckKreuzungName(name);
			shared_ptr<Kreuzung> kreuzung;
			iss >> dTankstelle;
			kreuzung->setName(name);
			kreuzung->setTankstelle(dTankstelle);
			addKreuzung(name, kreuzung);

		}else if(firstWord == "STRASSE"){
			string sHinwegName;
			string sRueckwegName;
			string sStartkreuzungName;
			string sZielkreuzungName;
			double dLaenge;
			bool bUeberholverbot;
			int iTempolimit;
			iss >> sStartkreuzungName >> sZielkreuzungName >> sHinwegName >> sRueckwegName >> dLaenge >> iTempolimit >> bUeberholverbot;
			vCheckKreuzungName(sStartkreuzungName);
			vCheckKreuzungName(sZielkreuzungName);
			Kreuzung::vVerbinde(sHinwegName, sRueckwegName, dLaenge,
					getKreuzung(sStartkreuzungName),
					getKreuzung(sZielkreuzungName),
					convertTempolimit(iTempolimit),
					bUeberholverbot);
		}else if(firstWord == "PKW"){
			unique_ptr<PKW> pkw;
			string sName;
			double dMaxgeschwindigkeit;
			double dVerbrauch;
			double dTankvolumen;
			string sStartkreuzungName;
			double dStartzeit;
			iss >> sName >> dMaxgeschwindigkeit >> dVerbrauch
			>> dTankvolumen >> sStartkreuzungName >> dStartzeit;
			pkw->setMaxGeschwindigkeit(dMaxgeschwindigkeit);
			pkw->setName(sName);
			pkw->setVerbrauch(dVerbrauch);
			pkw->setTankvolumen(dTankvolumen);
			getKreuzung(sStartkreuzungName)->vAnnahme(std::move(pkw), dStartzeit);
		}else if(firstWord == "FAHRRAD"){
			unique_ptr<Fahrrad> fahrrad;
			string sName;
			double dMaxgeschwindigkeit;
			string sStartkreuzungName;
			double dStartzeit;
			iss >> sName >> dMaxgeschwindigkeit >> sStartkreuzungName >> dStartzeit;
			fahrrad->setMaxGeschwindigkeit(dMaxgeschwindigkeit);
			fahrrad->setName(sName);
			getKreuzung(sStartkreuzungName)->vAnnahme(std::move(fahrrad), dStartzeit);
		}else{
			throw runtime_error("Kein Objekt kann fuer dieses Schluesselwort erzeugt werden." + to_string(lineNumber));
		}
	}
}

void Simulation::vSimulieren(double dDauer, double dZeitschritt){
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dZeitschritt; dGlobaleZeit < dDauer; dGlobaleZeit += dZeitschritt){
		for(auto& pair : kreuzungenMap){
			pair.second->vSimulieren();
		}
	}
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
void Simulation::addKreuzung(const string& name, shared_ptr<Kreuzung> kreuzung) {
	vCheckDoppelKreuzung(name);
	kreuzungenMap[name] = kreuzung;
}

shared_ptr<Kreuzung> Simulation::getKreuzung(const string& name) {
	vCheckKreuzung(name);
    auto it = kreuzungenMap.find(name);
    return it->second;
}

void Simulation::vCheckKreuzungName(string name){
	if(name.length() != 3){
		throw runtime_error("Name der Kreuzung soll wie Kr1 aussehen.");
	}
}

Tempolimit Simulation::convertTempolimit(int iTempolimit){
	switch(iTempolimit){
		case 1:
			return Innerorts;
			break;
		case 2:
			return Landstrasse;
			break;
		case 3:
			return Autobahn;
			break;
		default:
			return Autobahn;
			break;
	}
}


