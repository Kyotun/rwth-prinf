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
#include <vector>
#include <cmath>


using namespace std;
extern double dGlobaleZeit;

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

		//Getter
		double getGesamtVerbrauch() const override;
		double getTankinhalt() const override;
		double getTankvolumen() const override{return p_dTankvolumen;};
		double getVerbrauch(){return p_dVerbrauch;};

		//Double
		double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;

		//Void&Print Funktionen
		void vSimulieren() override;
		void vAusgeben() const override;
		void vAusgeben(std::ostream& ausgabe) const override;

	private:
		double p_dVerbrauch = 0.0; // Liter / 100 km
		double p_dTankvolumen = 55.0; // Default = 55 Liter
		double p_dTankinhalt = p_dTankvolumen / 2; // Default = 27.5 Liter
};

#endif /* PKW_H_ */
