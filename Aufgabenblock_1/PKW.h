/*
 * PKW.h
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
extern double GlobaleZeit;

class PKW : public Fahrzeug {

	public:
		//Konstruktoren
		PKW() = default;
		PKW(string p_sName);
		PKW(string p_sName, double p_dMaxGeschwindigkeit);
		PKW(double p_dVerbrauch, double p_dTankvolumen = 55.0);
		PKW(string p_sName, double p_dMaxGeschwindigkeit,
				double p_dVerbrauch, double p_dTankvolumen = 55.0);

		//Destruktoren
		virtual ~PKW() = default;

		//Double
		double dTanken(double dMenge = 1.0) override;

		//Void&Print Funktionen
		void vSimulieren() override;
		void vAusgeben(std::ostream& ausgabe) const override;

	private:
		double p_dVerbrauch = 0.0; // Liter / 100 km
		double p_dTankvolumen = 55.0; // Default = 55 Liter
		double p_dTankinhalt = 0.5; // 0.5 = 27.5 Liter

};


#endif /* PKW_H_ */
