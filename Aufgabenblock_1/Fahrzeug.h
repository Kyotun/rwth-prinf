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

	//Getters
	string getName() const{return p_sName;};
	virtual double getMaxGeschwindigkeit() const{return p_dMaxGeschwindigkeit;};
	double getGesamtstrecke() const {return p_dGesamtstrecke;};
	double getGesamtZeit() const {return p_dGesamtZeit;};
	double getZeit() const {return p_dZeit;};
	int getID() const {return p_iID;};

	//Setters
	void setName(string p_sName){ this->p_sName = p_sName;};
	void setMaxGeschwindigkeit(double p_dMaxGeschwindigkeit){this->p_dMaxGeschwindigkeit = p_dMaxGeschwindigkeit;};
	void setGesamtstrecke(double p_dGesamtstrecke){this->p_dGesamtstrecke = p_dGesamtstrecke;};
	void setZeit(double p_dZeit){this->p_dZeit = p_dZeit;};

	//Double
	virtual double dGeschwindigkeit(){return p_dMaxGeschwindigkeit;}; // @suppress("No return")
	virtual double dTanken(double dMenge){return 0.0;};

	//Void&Print Funktionen
	virtual void vAusgeben(std::ostream& ausgabe) const;
	static void vKopf();
	virtual void vSimulieren();

	//Überladen
	bool operator<(const Fahrzeug& other) const {
		return this->p_dGesamtstrecke < other.p_dGesamtstrecke;
	}

protected:
	//Strings
	string p_sName = "";

	//Doubles
	double p_dMaxGeschwindigkeit = 0;
	double p_dGesamtstrecke = 0;
	double p_dZeit = 0;
	double p_dGesamtZeit = 0;

	//Integers
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;

private:

};


#endif /* FAHRZEUG_H_ */

