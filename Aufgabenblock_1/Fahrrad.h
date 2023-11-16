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

using namespace std;
extern double GlobaleZeit;


class Fahrrad : public Fahrzeug {

	public:
		//Konstruktoren
		Fahrrad() = default;
		Fahrrad(string p_sName);
		Fahrrad(string p_sName, double p_dMaxGeschwindigkeit);

		//Destruktoren
		virtual ~Fahrrad() = default;

		//Double
		double dGeschwindigkeit() override; // Minimal 12km /h , pro 20km %10 Abnahme

		//Void&Print
		void vAusgeben(std::ostream& ausgabe) const override;
		void vSimulieren() override;


	private:
		int p_iZeahler = 0;

};




#endif /* FAHRRAD_H_ */
