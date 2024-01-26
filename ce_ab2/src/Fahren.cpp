/*
 * Fahren.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"

// Ausrechnen der aktuelle zuruckgelegten Strecke des fahrenden Fahrzeuges
double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeitDifferenz){
	double dTeilStrecke = fahrzeug.dGeschwindigkeit()*dZeitDifferenz;
	double dLaenge = p_pWeg->getLaenge();
	double dAbschnittStrecke = fahrzeug.getAbschnittStrecke();

	// Kontrolliere, was wuerde passieren, wenn der letzte Teil auch gefahren wuerde?
	// Wenn der noch gefahren werden kann, return einfach die TeilStrecke
	// Wenn nicht, gibt eine Meldung durch die Ausnahmeklasse Streckenende aus,
	// waehrend das Fahrzeug am Ende des Wegs gestellt wird.
	if(dLaenge-dAbschnittStrecke < dTeilStrecke){
		fahrzeug.setAbschnittStrecke(dLaenge);
		throw new Streckenende(fahrzeug, *p_pWeg);
	}
	return dTeilStrecke;

}



