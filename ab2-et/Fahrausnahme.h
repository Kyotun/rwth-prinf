/*
 * Fahrausnahme.h
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include "Fahrzeug.h"
#include "Weg.h"
#include <exception>

class Fahrausnahme : public std::exception{
public:
	Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);

	virtual void vBearbeiten() const = 0;

	virtual ~Fahrausnahme() = default;
protected:
	Fahrzeug& p_pFahrzeug;
	Weg& p_pWeg;
private:
};




#endif /* FAHRAUSNAHME_H_ */
