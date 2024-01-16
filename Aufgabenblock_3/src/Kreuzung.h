/*
 * Kreuzung.h
 *
 *  Created on: 12.01.2024
 *      Author: kyotun
 */

#pragma once
#include <memory>
#include <list>
#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include "Weg.h"

#ifndef KREUZUNG_H_
#define KREUZUNG_H_

class Fahrzeug;

using namespace std;

class Kreuzung: public Simulationsobjekt{
public:
	// Konstruktoren
	Kreuzung(string sName, double dTankstelle = 0);

	// PTR Funktionen
	shared_ptr<Weg>pZufaelligerWeg(Weg& weg);

	// Void Funktionen
	static void vVerbinde(string sHinwegName, string sRuckwegName,
			double dWegLaenge, weak_ptr<Kreuzung> pStartKreuzung,
			const weak_ptr<Kreuzung> pZielKreuzung, Tempolimit eTempolimit = Tempolimit::Autobahn, bool bUeberholverbot = true);

	void vTanken(Fahrzeug& fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug> fahrzeug, double dStartzeit);
	void vSimulieren() override;
	void vEinlesen(istream& is) override;

	// Bool Funktionen
	bool istInWegList(Weg& weg);

	// Getters
	double getTankstelle() {return p_dTankstelle;}
	list<shared_ptr<Weg>> getWege() {return p_pWege;}

	// Setters
	void setTankstelle(double dTank){
		this->p_dTankstelle -= dTank;
		if(this->p_dTankstelle < 0){
			this->p_dTankstelle = 0;
		}
	}

protected:
private:
	// das Volumen, das einer Kreuzung zum Auftanken zur Verfugung steht
	double p_dTankstelle;

	// alle von ihr wegfuhrenden Wege
	list<shared_ptr<Weg>> p_pWege;


};




#endif /* KREUZUNG_H_ */