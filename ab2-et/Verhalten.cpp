/*
 * Verhalten.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */

#include "Verhalten.h"
#include "Fahrzeug.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <cmath>
using namespace std;
extern double dGlobaleZeit;

// dStrecke Funktion, die ermittelt, wie weit ein Fahrzeug innerhalb des ubergebenen Zeitintervalls fahren kann,
// ohne das Wegende zu uberschreiten


