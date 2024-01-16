/*
 * Kreuzung.cpp
 *
 *  Created on: 12.01.2024
 *      Author: kyotun
 */
#include "PKW.h"
#include "Kreuzung.h"
#include "Weg.h"
#include <iostream>
#include <list>
#include <memory>
#include <random>

using namespace std;

Kreuzung::Kreuzung(string sName, double dTankstelle):
		Simulationsobjekt(sName),
		p_dTankstelle(dTankstelle){
}

// Uebergebener Weg ist Hinweg
// Kreuzung kann nicht diesen Weg in der Variable p_pWege enthalten
shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& weg){

	shared_ptr<Weg> rueckWeg = weg.getRueckweg();
	if (!rueckWeg) {
		throw runtime_error("Es gibt keinen Rueckweg fuer uebergebenen Weg.");
	}

	if(p_pWege.size() == 1){
		return rueckWeg;
	}
	// Ausfiltern die Liste vom übergebenen Weg
	list<shared_ptr<Weg>> filteredWege;
	for (const auto& wegPtr : p_pWege) {
		if (wegPtr != rueckWeg) {
			filteredWege.push_back(wegPtr);
		}
	}

	// Erzeuge einen zufaelligen Index zwischen 0 und größe von filteredWege list.
	// Dann waehle einen Index zufaelligl
	// Gibt diesen zufaellig gewaehlten Index(Weg) zurueck.
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, filteredWege.size() - 1);
	int randomIndex = dis(gen);
	auto it = filteredWege.begin();
	std::advance(it, randomIndex);
	return *it;
}

void Kreuzung::vVerbinde(string sNameHinweg, string sNameRuckweg,
		double dWegLaenge, weak_ptr<Kreuzung> pStartKreuzung,
		const weak_ptr<Kreuzung> pZielKreuzung,
		Tempolimit eTempolimit, bool bUeberholverbot) {
	return;

	shared_ptr<Weg> pHinweg = make_shared<Weg>(sNameHinweg,
			dWegLaenge,
			pZielKreuzung,
			eTempolimit,
			bUeberholverbot);
	shared_ptr<Weg> pRueckweg = make_shared<Weg>(sNameRuckweg,
			dWegLaenge,
			pStartKreuzung,
			eTempolimit,
			bUeberholverbot);

	pHinweg->setRueckweg(pRueckweg);
	pRueckweg->setRueckweg(pHinweg);

	pZielKreuzung.lock()->p_pWege.push_back(pRueckweg);
	pStartKreuzung.lock()->p_pWege.push_back(pHinweg);
}

void Kreuzung::vTanken(Fahrzeug& fahrzeug){
	double dTankvolumen = fahrzeug.getTankvolumen();
	double dTankinhalt = fahrzeug.getTankinhalt();
	double dBrauchteTank = dTankvolumen - dTankinhalt;
	fahrzeug.dTanken(dBrauchteTank);
	this->setTankstelle(dBrauchteTank);
}

void Kreuzung::vAnnahme(unique_ptr<Fahrzeug> fahrzeug, double dStartzeit){
	vTanken(*fahrzeug);
	p_pWege.back()->vAnnahme(std::move(fahrzeug), dStartzeit);
}

void Kreuzung::vSimulieren(){
	// Simulieren der Wege an einer Kreuzung
	list<shared_ptr<Weg>>::iterator it;

	for(it = p_pWege.begin(); it != p_pWege.end(); it++) {
		(*it)->vSimulieren();
	}
}

void Kreuzung::vEinlesen(istream& is){
	Simulationsobjekt::vEinlesen(is);

	if (p_dTankstelle != 0.0){
		throw runtime_error("Object already initialized");
	}

	cout << "Bitte geben Sie die Kapazitaet der Tankstelle der Kreuzung " << this->getID() << " ein: ";
	is >> p_dTankstelle;

	if(is.fail()){
		throw runtime_error("Error reading from input stream.");
	}
}

bool Kreuzung::istInWegList(Weg& weg){
	for(auto& wegPtr : p_pWege){
		if(wegPtr.get() == &weg){
			return true;
		}
	}
	return false;
}
