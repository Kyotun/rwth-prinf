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
#include "Verhalten.h"

double Parken::dStrecke(Fahrzeug& aFahrzeug, double dStartZeit) const{
	if(dGlobaleZeit > dStartZeit){
		cout << "Fahrzeug fangt an zu fahren." << endl;
	}
	return 0.0;
}



