/*
 * Fahren.h
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include "Verhalten.h"
class Weg;
class Fahrzeug;

using namespace std;

class Fahren : public Verhalten {
public:
	Fahren() = default;
	Fahren(Weg& weg): Verhalten(weg){}

	virtual double dStrecke(Fahrzeug& fahrzeug, double dZeitDifferenz) override;
	virtual ~Fahren() = default;

protected:
private:
};


#endif /* FAHREN_H_ */
