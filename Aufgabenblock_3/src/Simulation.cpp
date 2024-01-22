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

void Simulation::vSimulieren(double dDauer, double dZeitschritt){
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dZeitschritt; dGlobaleZeit < dDauer; dGlobaleZeit += dZeitschritt){
		for(auto& pair : kreuzungenMap){
			pair.second->vSimulieren();
		}
	}
}

void Simulation::vEinlesen(istream& is){
	string line;
	string firstWord;
	int lineNumber = 0;

	try{
		while (getline(is, line)) {
			lineNumber++;
			istringstream iss(line);
			iss >> firstWord;
			if(firstWord == "KREUZUNG"){
				string sName;
				int dTankstelle;
				iss >> sName;
				vCheckDoppelKreuzung(sName);
				vCheckKreuzungName(sName);
				iss >> dTankstelle;
				shared_ptr<Kreuzung> kreuzung = make_shared<Kreuzung>(sName, dTankstelle);
				vAddKreuzung(sName, std::move(kreuzung));

			}else if(firstWord == "STRASSE"){
				string sHinwegName;
				string sRueckwegName;
				string sStartkreuzungName;
				string sZielkreuzungName;
				double dLaenge;
				bool bUeberholverbot;
				int iTempolimit;
				iss >> sStartkreuzungName >> sZielkreuzungName >> sHinwegName >> sRueckwegName >> dLaenge >> iTempolimit >> bUeberholverbot;
				vCheckKreuzung(sStartkreuzungName);
				vCheckKreuzung(sZielkreuzungName);
				Kreuzung::vVerbinde(sHinwegName, sRueckwegName, dLaenge,
						getKreuzung(sStartkreuzungName),
						getKreuzung(sZielkreuzungName),
						convertTempolimit(iTempolimit),
						bUeberholverbot);
			}else if(firstWord == "PKW"){
				string sName;
				double dMaxgeschwindigkeit;
				double dVerbrauch;
				double dTankvolumen;
				string sStartkreuzungName;
				double dStartzeit;
				iss >> sName >> dMaxgeschwindigkeit >> dVerbrauch
				>> dTankvolumen >> sStartkreuzungName >> dStartzeit;
				unique_ptr<PKW> pkw = make_unique<PKW>(sName, dMaxgeschwindigkeit, dVerbrauch, dTankvolumen);
				getKreuzung(sStartkreuzungName)->vAnnahme(std::move(pkw), dStartzeit);
			}else if(firstWord == "FAHRRAD"){
				string sName;
				double dMaxgeschwindigkeit;
				string sStartkreuzungName;
				double dStartzeit;
				iss >> sName >> dMaxgeschwindigkeit >> sStartkreuzungName >> dStartzeit;
				unique_ptr<Fahrrad> fahrrad = make_unique<Fahrrad>(sName, dMaxgeschwindigkeit);
				getKreuzung(sStartkreuzungName)->vAnnahme(std::move(fahrrad), dStartzeit);
			}else{
				throw runtime_error("\nKein Objekt kann fuer dieses Schluesselwort erzeugt werden. Schluesselwort: " + firstWord
						+ "\nZuerst soll das Objekt beschrieben(Schluesselwort fuer Objekt) werden. Z.B: 'FAHRRAD', 'STARSSE', 'PKW', 'KREUZUNG'");
			}
		}
	}catch(const runtime_error& message){
		cerr << "Aufgefangene runtime error: " << message.what() << endl;
		cerr << "Zeilennummer: " << lineNumber << endl;

	}
}

void Simulation::vAddKreuzung(const string& name, shared_ptr<Kreuzung> kreuzung) {
	vCheckDoppelKreuzung(name);
	kreuzungenMap[name] = kreuzung;
}

void Simulation::vCheckKreuzung(const string& name){
	if(kreuzungenMap.find(name) == kreuzungenMap.end()){
		throw runtime_error("Es gibt keine Kreuzung unter diesen Name: " + name);
	}
}

void Simulation::vCheckDoppelKreuzung(const string& name){
	if(kreuzungenMap.find(name) != kreuzungenMap.end()){
		throw runtime_error("Es gibt bereits eine andere Kreuzunge unter der Name: " + name);
	}
}

void Simulation::vAktualisiereKreuzung(const string& name, shared_ptr<Kreuzung> kreuzung){
	vCheckKreuzung(name);
	kreuzungenMap.erase(name);
	vAddKreuzung(name, kreuzung);

}

shared_ptr<Kreuzung> Simulation::getKreuzung(const string& name) {
	vCheckKreuzung(name);
    auto it = kreuzungenMap.find(name);
    return it->second;
}

void Simulation::vCheckKreuzungName(string name){
	if(name.length() != 3){
		throw runtime_error("Name der Kreuzung soll wie Kr1 aussehen. Gegeben: " + name);
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


