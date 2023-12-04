/*
 * Fahren.cpp
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

#include "Fahren.h"
#include "Verhalten.h"

double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeitDifferenz)const{
	return fahrzeug.dGeschwindigkeit()*dZeitDifferenz;
}



