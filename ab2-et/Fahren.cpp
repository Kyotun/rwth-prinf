/*
 * Fahren.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include "Fahren.h"
#include "Verhalten.h"
#include "Streckenende.h"

double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeitDifferenz){
	double dTeilStrecke = fahrzeug.dGeschwindigkeit()*dZeitDifferenz;
	double dLaenge = p_pWeg->getLaenge();
	double dAbschnittStrecke = fahrzeug.getAbschnittStrecke();

	if(dLaenge-dAbschnittStrecke < dTeilStrecke){
		fahrzeug.setAbschnittStrecke(dLaenge);
		throw new Streckenende(fahrzeug, *p_pWeg);
	}
	return dTeilStrecke;

}



