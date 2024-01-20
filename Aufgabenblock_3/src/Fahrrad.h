/*
 * Fahrrad.h
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */

#pragma once
#include "Fahrzeug.h"

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

using namespace std;

class Fahrrad : public Fahrzeug {
public:
	// Konstruktoren
	Fahrrad() : Fahrzeug(){}
	Fahrrad(string p_sName);
	Fahrrad(string p_sName, double p_dMaxGeschwindigkeit);

	// Doubles
	double dGeschwindigkeit() const override; // Minimal 12km /h , pro 20km %10 Abnahme

	// Void&Print
	void vAusgeben() const override;
	void vAusgeben(ostream& ausgabe) const override;
	void vSimulieren() override;
	void vZeichnen(const Weg& weg) override;
	void vEinlesen(istream& is) override;

private:

};
#endif /* FAHRRAD_H_ */
