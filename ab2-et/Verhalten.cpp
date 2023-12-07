/*
 * Verhalten.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include "Verhalten.h"

using namespace std;
extern double dGlobaleZeit;

// dStrecke Funktion, die ermittelt, wie weit ein Fahrzeug innerhalb des ubergebenen Zeitintervalls fahren kann,
// ohne das Wegende zu uberschreiten
double Verhalten::dStrecke(Fahrzeug& fahrzeug, double dZeitIntervall){
	return fahrzeug.dGeschwindigkeit()*dZeitIntervall;
}


