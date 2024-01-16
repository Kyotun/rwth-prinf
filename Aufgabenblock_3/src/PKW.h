	/*
 * PKW.h
 *
 *  Created on: 16.11.2023
 *      Author: kyotun
 */

#pragma once
#include <limits>
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Weg.h"

#ifndef PKW_H_
#define PKW_H_

using namespace std;

class PKW : public Fahrzeug {
	public:
		//Konstruktoren
		PKW() = default;
		PKW(string p_sName);
		PKW(string p_sName, double p_dMaxGeschwindigkeit);
		PKW(double p_dVerbrauch, double p_dTankvolumen = 55.0);
		PKW(string p_sName, double p_dMaxGeschwindigkeit,
				double p_dVerbrauch, double p_dTankvolumen = 55.0);

		virtual ~PKW() = default;

		//Getter
		double getGesamtVerbrauch() const override;
		double getTankinhalt() const override;
		double getTankvolumen() const override{return p_dTankvolumen;};
		double getVerbrauch(){return p_dVerbrauch;};

		//Double
		double dGeschwindigkeit() const override;
		double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;

		//Void&Print Funktionen
		void vSimulieren() override;
		void vAusgeben()const override;
		void vAusgeben(ostream& ausgabe) const override;
		void vZeichnen(const Weg& weg) override;
		void vEinlesen(istream& is) override;

	private:
		double p_dVerbrauch = 0.0; // Liter / 100 km
		double p_dTankvolumen = 55.0; // Default = 55 Liter
		double p_dTankinhalt = p_dTankvolumen / 2; // Default = 27.5 Liter
};

#endif /* PKW_H_ */
