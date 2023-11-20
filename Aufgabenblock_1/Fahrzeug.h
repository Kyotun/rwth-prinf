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
extern double GlobaleZeit;

class Fahrzeug {
public:
	//Konstruktoren
	Fahrzeug(); // @suppress("Class members should be properly initialized")
	Fahrzeug(string p_sName); // @suppress("Class members should be properly initialized")
	Fahrzeug(string p_sName, double p_dMaxGeschwindigkeit);

	//Destruktoren
	virtual ~Fahrzeug();

	Fahrzeug(const Fahrzeug&) = delete;

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
	virtual double dGeschwindigkeit(){return p_dMaxGeschwindigkeit;}; // @suppress("No return")
	virtual double dTanken(double dMenge = 1.0){return 0.0;};

	//Void&Print Funktionen
	virtual void vAusgeben(std::ostream& ausgabe) const;
	static void vKopf();
	virtual void vSimulieren(double Zeitdifferenz);

	//Überladen
	bool operator<(const Fahrzeug& andere) const {
		return this->p_dGesamtstrecke < andere.p_dGesamtstrecke;
	}

	Fahrzeug& operator=(const Fahrzeug& other) {
		//Kontrolliere ob das Objekt selbst aufruft.
		if (this == &other) {
			return *this;
		}

		this->p_sName = other.p_sName;
		this->p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
		this->p_dGesamtstrecke = other.p_dGesamtstrecke;
		this->p_dZeit = other.p_dZeit;
		this->p_dGesamtZeit = other.p_dGesamtZeit;

		return *this;
	}

protected:
	//Strings
	string p_sName = "";

	//Doubles
	double p_dMaxGeschwindigkeit = 0.0;
	double p_dGesamtstrecke = 0.0;
	double p_dZeit = 0.0;
	double p_dGesamtZeit = 0.0;

	//Integers
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;

private:

};

std::ostream& operator<<(std::ostream& ausgabe, const Fahrzeug& fahrzeug);

#endif /* FAHRZEUG_H_ */

