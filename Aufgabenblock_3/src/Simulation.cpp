/*
 * Simulation.cpp
 *
 *  Created on: 20.01.2024
 *      Author: kyotun
 */

#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <sstream>

#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "Kreuzung.h"
#include "PKW.h"
#include "Simulation.h"
#include "SimuClient.h"
#include "Tempolimit.h"
#include "Weg.h"

using namespace std;
extern double dGlobaleZeit;

// Simulieren der Kreuzungen fuer gegebene Dauer und Zeitschritt.
void Simulation::vSimulieren(double dDauer, double dZeitschritt){
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dZeitschritt; dGlobaleZeit < dDauer; dGlobaleZeit += dZeitschritt){
		vSetzeZeit(dGlobaleZeit);
		for(auto& pair : kreuzungenMap){
			pair.second->vSimulieren();
		}
		vSleep(1000);
	}
}

// Nimmt als parameter die Daten von draussen an.
// Liest Zeile fuer Zeile und kontrolliere das erste Wort, ob es ein gueltiges Schlusselwoert ist.
// Setzt die Parametern nach dem gegebenen Schluesselwort ein.
// Wenn etwas schief lauft, gibt eine Ausnahme aus.
// Gueltige Schlusselwoerter fuer dieses Projekt -> STARRSE, KREUZUNG, PKW, FAHRRAD
void Simulation::vEinlesen(istream& is, bool bMitGrafik){
	string line;
	string firstWord;
	int lineNumber = 0;
	if(bMitGrafik){
		bInitialisiereGrafik(1000, 1000);
	}

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
				if(bMitGrafik){
					int x;
					int y;
					iss >> x >> y;
					bZeichneKreuzung(x, y);
				}
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
				if(bMitGrafik){
					int iAnzahlPairs;
					iss >> iAnzahlPairs;
					int koordinatenStrasse[iAnzahlPairs*2];
					for(int i = 0; i < 2*iAnzahlPairs; i++){
						iss >> koordinatenStrasse[i];
					}
						bZeichneStrasse(sHinwegName, sRueckwegName, dLaenge, iAnzahlPairs, koordinatenStrasse);
				}
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

// Kontrolliere, ob der gegebene Name nicht im Map ist.
void Simulation::vCheckKreuzung(const string& name){
	if(kreuzungenMap.find(name) == kreuzungenMap.end()){
		throw runtime_error("Es gibt keine Kreuzung unter diesen Name: " + name);
	}
}

// Kontrolliere, ob der gegebene Name sich im Map schon befindet.
void Simulation::vCheckDoppelKreuzung(const string& name){
	if(kreuzungenMap.find(name) != kreuzungenMap.end()){
		throw runtime_error("Es gibt bereits eine andere Kreuzunge unter der Name: " + name);
	}
}

// Aktualisiert die gegebene Kreuzung.
// Zuerst loescht die gegebene Kreuzung, dann addiert wieder in die Map.
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

// Wenn die Laenge des Names der Kreuzung nicht drei ist, gibt eine Ausnahme zurueck.
void Simulation::vCheckKreuzungName(string name){
	if(name.length() != 3){
		throw runtime_error("Name der Kreuzung soll wie Kr1 aussehen. Gegeben: " + name);
	}
}

// Waehlt ein Tempolimit aus, nach der gegebenen integer Zahl.
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


