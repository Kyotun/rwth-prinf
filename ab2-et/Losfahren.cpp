/*
 * Losfahren.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */
#include "Losfahren.h"

void Losfahren::vBearbeiten()const{
	cout << "Das Fahrzeug " << p_pFahrzeug.getID() << " fangt jetzt auf dem Weg " << p_pWeg.getID() << " zu fahren." << endl;
}



