/*
 * Parken.h
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */
#include "Verhalten.h"

#ifndef PARKEN_H_
#define PARKEN_H_

class Weg;
class Fahrzeug;

using namespace std;

class Parken : public Verhalten{
public:
	Parken(Weg& weg, double dStartZeit): Verhalten(weg), p_dStartZeit(dStartZeit){}
	double dStrecke(Fahrzeug& aFahrzeug, double dStartZeit) const;
protected:
private:
	double p_dStartZeit = 0.0;
};




#endif /* PARKEN_H_ */
