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
	Streckenende() = default;
	Streckenende(Fahrzeug& fahrzeug, Weg& weg): Fahrausnahme(fahrzeug, weg){}

	virtual void vBearbeiten() override;
	virtual ~Streckenende() = default;
protected:
private:
};

#endif /* STRECKENENDE_H_ */
