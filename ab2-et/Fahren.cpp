/*
 * Fahren.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include "Fahren.h"
#include "Verhalten.h"
#include "Streckenende.h"

double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeitDifferenz)const{
	double dTeilStrecke = fahrzeug.dGeschwindigkeit()*dZeitDifferenz;

	if(fahrzeug.getAbschnittStrecke() >= p_pWeg->getLaenge()){
		throw new Streckenende(fahrzeug, *p_pWeg);
	}
	return dTeilStrecke;

}



