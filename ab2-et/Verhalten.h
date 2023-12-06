/*
 * Verhalten.h
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */
#include "Fahrzeug.h"

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

using namespace std;

class Weg;

class Verhalten{
public:
	//Konstruktoren
	Verhalten() = default;
	Verhalten(Weg& weg): p_pWeg(&weg){}

	//Destruktor
	virtual ~Verhalten() = default;

	//Getters
	Weg* getpWeg() const{return p_pWeg;}

	//Double
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;

protected:
	Weg* p_pWeg;
private:
};



#endif /* VERHALTEN_H_ */
