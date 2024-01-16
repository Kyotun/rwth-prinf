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
	// Konstruktoren
	Streckenende(Fahrzeug& fahrzeug, Weg& weg): Fahrausnahme(fahrzeug, weg){}

	// Voids
	virtual void vBearbeiten() override;

protected:
private:
};

#endif /* STRECKENENDE_H_ */
