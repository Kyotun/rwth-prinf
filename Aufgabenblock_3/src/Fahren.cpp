/*
 * Fahren.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include "Fahren.h"
#include "Verhalten.h"
#include "Streckenende.h"

// Ausrechnen der aktuelle zuruckgelegten Strecke des fahrenden Fahrzeuges
double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeitDifferenz){
	double dTeilStrecke = fahrzeug.dGeschwindigkeit()*dZeitDifferenz;
	double dLaenge = p_pWeg->getLaenge();
	double dAbschnittStrecke = fahrzeug.getAbschnittStrecke();

	// Wenn der Weg einen Ueberholverbot besitzt
	// soll man auch die Schranke kontrollieren.
	// Falls die Schranke noch nicht gesetzt ist, das heisst, dass das Fahrzeug auf der ersten Stelle der Liste steht.
	// Es faehrt dann bis, wo es fahren kann.
	// Aber wenn es die Schranke schon gesetzt ist, das Fahrzeug darf nur bis die Schranke fahren.
	if (p_pWeg->getUeberholverbot()){
		double dSchranke = p_pWeg->getSchranke();
		if(dSchranke > 0){
			double dNeuAbschnittStrecke = dAbschnittStrecke + dTeilStrecke;
			if(dNeuAbschnittStrecke > dSchranke){
				dTeilStrecke = dSchranke - dAbschnittStrecke;
			}
		}
	}

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



