/*
 * Fahren.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include "Fahren.h"
#include "Verhalten.h"
#include "Streckenende.h"

//Ausrechnen der aktuelle zuruckgelegten Strecke des fahrenden Fahrzeuges
double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeitDifferenz){
	double dTeilStrecke = fahrzeug.dGeschwindigkeit()*dZeitDifferenz;
	double dLaenge = p_pWeg->getLaenge();
	double dAbschnittStrecke = fahrzeug.getAbschnittStrecke();

	if (p_pWeg->getUeberholverbot()){
		double dSchranke = p_pWeg->getSchranke();
		if(dSchranke > 0){
			double dNeuAbschnittStrecke = dAbschnittStrecke + dTeilStrecke;
			if(dNeuAbschnittStrecke > dSchranke){
				dTeilStrecke = dSchranke - dAbschnittStrecke;
			}
		}
	}

	//Kontrolliere, was wurde passieren, wenn der letzte Teil auch gefahren wurde?
	//Wenn der noch gefahren werden kann, return einfach die TeilStrecke
	//Wenn nicht, gibt eine Meldung durch die Ausnahmeklasse Streckenende aus.
	if(dLaenge-dAbschnittStrecke < dTeilStrecke){
		fahrzeug.setAbschnittStrecke(dLaenge);
		throw new Streckenende(fahrzeug, *p_pWeg);
	}
	return dTeilStrecke;

}

// Fahrzeugun teilstreckesini hesapla
// fahrzeug2 olma kosulu -> fahrzeug2.getTankinhalt != 0 ve fahrzeug2.getAbschnitstrecke - fahrzeug.getAbschnitstrecke 0'a en yakin
// bu kosul gerceklesirse
	// teilstrecke ile abschnittstrecke differenz kiyasla
	// if Teilstrecke > AbschnittDifferenz,
		// fahrzeug.setTeilstrecke(fahrzeug2.getTeilstrecke)
		// dTeilStrecke = dAbschnittDifferenz



