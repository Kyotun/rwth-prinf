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
			// string name;
			// int dTankstelle;
			// iss >> name;
			// vCheckDoppelKreuzung(name);
			// Kreuzung object olustur
			// iss >> dTankstelle
			// Kreuzung.setName(), Kreuzung.setTankstelle()
			// Mape ekle

		}else if(firstWord == "STRASSE"){
			// 2 Kreuzung olustur shared_ptr
			// string Hingweg;
			// string Rueckweg;
			// double Laenge;
			// bool Ueberholverbot;
			// int Tempolimit;
			// iss >> Name der ersten Kreuzung
			// >> Name der zweiten Kreuzung
			// >> Hinweg >> Rueckweg >> Laenge
			// >> Tempolimit(need conversion function)
			// Kreuzung::vVerbinde(Hinweg, Rueckweg,
			// Startkreuzung, Zielkreuzung, Tempolimit, Ueberholverbot)
		}else if(firstWord == "PKW"){
			// PKW Object olustur
			// string name;
			// double maxgeschwindigkeit;
			// double verbrauch;
			// double Tankvolumen;
			// string StartkreuzungName;
			// double Startzeit;
			// iss >> name >> maxgeschwidngiekit >> verbrauch
			// >> Tankvolumen >> StartkreuzungName >> StartZeit;
			// PKW.setS() ...
			// getKreuzung(StartkreuzungName)->vAnnahme(PKW, Startzeit)

		}else if(firstWord == "FAHRRAD"){
			// FAHRRAD Object olustur
			// string name;
			// double maxgeschwindigkeit;
			// string StartkreuzungName;
			// double Startzeit;
			// iss >> name >> maxgeschwidngiekit
			// >> StartkreuzungName >> StartZeit;
			// FAHRRAD.setS() ...
			// getKreuzung(StartkreuzungName)->vAnnahme(Fahrrad, Startzeit)
		}else{
			throw runtime_error("Kein Objekt kann fuer dieses Schluesselwort erzeugt werden." + to_string(lineNumber));
		}
	}
}

void Simulation::vSimulieren(double dDauer, double dZeitschritt){
	for(dGlobaleZeit = dZeitschritt; dGlobaleZeit < dDauer; dGlobaleZeit += dZeitschritt){
		for(auto& pair : kreuzungenMap){
			pair.second.vSimulieren();
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


