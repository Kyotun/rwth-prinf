/*
 * Fahrzeug.h
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */
#pragma once
#include <iostream>
#include "Weg.h"
#include "Verhalten.h"

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

extern double dGlobaleZeit;

class Fahrzeug : public Simulationsobjekt{
public:
	//Konstruktoren
	Fahrzeug() = default;
	Fahrzeug(string p_sName); // @suppress("Class members should be properly initialized")
	Fahrzeug(string p_sName, double p_dMaxGeschwindigkeit);

	// Verbieten von Copy-Konstruktor
	Fahrzeug(const Fahrzeug&) = delete;

	//Destruktor
	virtual ~Fahrzeug() = default;

	//Getters
	virtual double getMaxGeschwindigkeit() const{return p_dMaxGeschwindigkeit;};
	double getGesamtstrecke() const {return p_dGesamtstrecke;};
	double getGesamtZeit() const {return p_dGesamtZeit;};
	virtual double getGesamtVerbrauch() const {return 0.0;};
	virtual double getTankinhalt() const {return 0.0;};
	virtual double getTankvolumen() const {return 0.0;};
	double getAbschnittStrecke() const{return p_dAbschnittStrecke;};

	//Setters
	void setMaxGeschwindigkeit(double p_dMaxGeschwindigkeit){this->p_dMaxGeschwindigkeit = p_dMaxGeschwindigkeit;};
	void setGesamtstrecke(double p_dGesamtstrecke){this->p_dGesamtstrecke = p_dGesamtstrecke;};

	//Double
	virtual double dGeschwindigkeit() const{return p_dMaxGeschwindigkeit;}; // @suppress("No return")
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity()){return 0.0;};
	virtual double dMehrfachMultiplikation(double base, double konstant, int mal) const{return 0.0;}

	//Void&Print Funktionen

		//Fuer fahrendes Fahrzeug
	void vNeueStrecke(Weg& weg);
		//Fuer parkendes Fahrzeug
	void vNeueStrecke(Weg& weg, double dStartZeitpunkt);

	virtual void vAusgeben() const override;
	virtual void vAusgeben(std::ostream& ausgabe) const override;
	static void vKopf();
	virtual void vSimulieren() override;
	//void operator =(const Fahrzeug& fahrzeug);

	//Überladen
	bool operator<(const Fahrzeug& andere) const;

	Fahrzeug& operator=(const Fahrzeug& other);

protected:
	//Doubles
	double p_dMaxGeschwindigkeit = 0.0;
	double p_dGesamtstrecke = 0.0;
	double p_dGesamtZeit = 0.0;

	// Speichern auf dem aktuellen Weg zurückgelegte Strecke
	// Wenn Fahrzeug in einen neuen Weg eintritt, beträgt dieser Wert zu 0.
	double p_dAbschnittStrecke = 0.0;


	//Parkendes oder fahrendes Fahrzeug?
	unique_ptr<Verhalten> p_pVerhalten;

private:

};

// Überladung von '<<' (Ausgabe) Operator.
// Dekleration außerhalb der Klasse. Auf diese Weise kann der Ausgabeoperator die private bzw. protected Bereiche
// nicht erreichen kann.
// Also keine friend Dekleration.
// Aber getters werden benötigt, um die private bzw. protected Bereiche erreichen zu können.

ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug);

#endif /* FAHRZEUG_H_ */

