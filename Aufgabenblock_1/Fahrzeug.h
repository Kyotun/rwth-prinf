/*
 * Fahrzeug.h
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <string>
using namespace std;

class Fahrzeug {
public:
	Fahrzeug();
	Fahrzeug(string p_sName);
	Fahrzeug(string p_sName, double p_dMaxGeschwindigkeit);
	Fahrzeug(string p_sName, int p_iID);
	virtual ~Fahrzeug();

	string getName() const {return p_sName;};
	double getMaxGeschwindigkeit() const {return p_dMaxGeschwindigkeit;};
	double getGesamtstrecke() const {return p_dGesamtstrecke;};
	double getZeit() const {return p_dZeit;};
	int getID() const {return p_iID;};
	void vAusgeben();
	void vKopf();
private:
	string p_sName = "";
	const int p_iID = 0;
	int p_iMaxID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtstrecke;
	double p_dZeit;
};
#endif /* FAHRZEUG_H_ */

