/*
 * Parken.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <cmath>
using namespace std;
extern double dGlobaleZeit;

#include "Parken.h"
#include "Fahrzeug.h"
#include "Losfahren.h"

// dStrecke Ausrechnen fuer das parkendes Fahrzeug.
// Wartet auf seine Zeit zum Fahren.
// Wenn die Zeit gekommen ist, werft einen Ausnahme "Losfahren"
double Parken::dStrecke(Fahrzeug& aFahrzeug, double dStartZeit){
	if(dGlobaleZeit >= p_dStartZeit){
		throw new Losfahren(aFahrzeug, *p_pWeg);
	}
	return 0.0;
}



