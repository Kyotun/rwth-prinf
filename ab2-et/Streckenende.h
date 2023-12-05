/*
 * Streckende.h
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme{
public:
	Streckenende(Fahrzeug& fahrzeug, Weg& weg): Fahrausnahme(fahrzeug, weg){}

	void vBearbeiten() const override;
protected:
private:
};




#endif /* STRECKENENDE_H_ */
