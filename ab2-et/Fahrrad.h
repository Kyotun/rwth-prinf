/*
 * Fahrrad.h
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;
extern double dGlobaleZeit;

class Fahrrad : public Fahrzeug {
	public:
		//Konstruktoren
		Fahrrad() = default;
		Fahrrad(string p_sName);
		Fahrrad(string p_sName, double p_dMaxGeschwindigkeit);

		//Destruktoren
		virtual ~Fahrrad() = default;

		//Double
		double dGeschwindigkeit() const override; // Minimal 12km /h , pro 20km %10 Abnahme

		//Void&Print
		void vAusgeben() const override;
		void vAusgeben(std::ostream& ausgabe) const override;
		void vSimulieren() override;

	private:

};
#endif /* FAHRRAD_H_ */
