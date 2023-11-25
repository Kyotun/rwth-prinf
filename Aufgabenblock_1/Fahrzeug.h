/*
 * Fahrzeug.h
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
extern double dGlobaleZeit;

class Fahrzeug {
public:
	//Konstruktoren
	Fahrzeug(); // @suppress("Class members should be properly initialized")
	Fahrzeug(string p_sName); // @suppress("Class members should be properly initialized")
	Fahrzeug(string p_sName, double p_dMaxGeschwindigkeit);

	// Verbieten von Copy-Konstruktor
	Fahrzeug(const Fahrzeug&) = delete;

	//Destruktoren
	virtual ~Fahrzeug();

	//Getters
	string getName() const{return p_sName;};
	virtual double getMaxGeschwindigkeit() const{return p_dMaxGeschwindigkeit;};
	double getGesamtstrecke() const {return p_dGesamtstrecke;};
	double getGesamtZeit() const {return p_dGesamtZeit;};
	double getZeit() const {return p_dZeit;};
	int getID() const {return p_iID;};
	virtual double getGesamtVerbrauch() const {return 0.0;};
	virtual double getTankinhalt() const {return 0.0;};

	//Setters
	void setName(string p_sName){ this->p_sName = p_sName;};
	void setMaxGeschwindigkeit(double p_dMaxGeschwindigkeit){this->p_dMaxGeschwindigkeit = p_dMaxGeschwindigkeit;};
	void setGesamtstrecke(double p_dGesamtstrecke){this->p_dGesamtstrecke = p_dGesamtstrecke;};
	void setZeit(double p_dZeit){this->p_dZeit = p_dZeit;};

	//Double
	virtual double dGeschwindigkeit() const{return p_dMaxGeschwindigkeit;}; // @suppress("No return")
	virtual double dTanken(double dMenge = 1.0){return 0.0;};
	virtual double dMehrfachMultiplikation(double base, double konstant, int mal) const{return 0.0;}

	//Void&Print Funktionen
	virtual void vAusgeben() const;
	virtual void vAusgeben(std::ostream& ausgabe) const;
	static void vKopf();
	virtual void vSimulieren();
	//void operator =(const Fahrzeug& fahrzeug);

	//Überladen
	bool operator<(const Fahrzeug& andere) const;

	Fahrzeug& operator=(const Fahrzeug& other);

protected:
	//Strings
	string p_sName = "";

	//Doubles
	double p_dMaxGeschwindigkeit = 0.0;
	double p_dGesamtstrecke = 0.0;
	double p_dZeit = 0.0;
	double p_dGesamtZeit = 0.0;

	//Integers
	const int p_iID = ++p_iMaxID;

private:
	// Inline = To be able to initialize
	// const != cause we want to increment ID value. Cannot assign the const to a const.
	static inline int p_iMaxID = 0;

};

// Überladung von '<<' (Ausgabe) Operator.
// Dekleration außerhalb der Klasse. Auf diese Weise kann der Ausgabeoperator die private bzw. protected Bereiche
// nicht erreichen kann.
// Also keine friend Dekleration.
// Aber getters werden benötigt, um die private bzw. protected Bereiche erreichen zu können.
std::ostream& operator<<(std::ostream& ausgabe, const Fahrzeug& fahrzeug);

#endif /* FAHRZEUG_H_ */

