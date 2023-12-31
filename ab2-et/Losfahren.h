/*
 * Losfahren.h
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Fahrzeug;

class Losfahren : public Fahrausnahme{
public:
	Losfahren() = default;
	void vBearbeiten() override;
	Losfahren(Fahrzeug& fahrzeug, Weg& weg): Fahrausnahme(fahrzeug, weg){}
	virtual ~Losfahren() = default;
protected:
private:

};



#endif /* LOSFAHREN_H_ */
