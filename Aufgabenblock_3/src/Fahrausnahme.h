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

//Fahrausnahme Klasse erbt von STL Exception.
class Fahrausnahme : public std::exception{
public:
	Fahrausnahme();
	Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);

	//Bearbeitung Methode für einige Faelle wie Streckenende, Losfahren etc.
	//Diese Methode wird geerbt von der Unterklasse und diese Klasse(Fahrausnahme) ist eine abstrakte Klasse.
	//Deswegen definieren wir diese Methode als eine rein virtuelle Methode.
	virtual void vBearbeiten()= 0;

	virtual ~Fahrausnahme() = default;
protected:
	//Der Weg und das Fahrzeug, deren Informationen benötigt werden, sollen gespeichert werden.
	//Nach deren Informationen funktionieren die Ausnahmeklassen.
	Fahrzeug& p_pFahrzeug;
	Weg& p_pWeg;
private:
};




#endif /* FAHRAUSNAHME_H_ */
