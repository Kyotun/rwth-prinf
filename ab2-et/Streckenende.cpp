/*
 * Streckenende.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */
#include "Streckenende.h"

void Streckenende::vBearbeiten()const{
	cout << "Das Fahrzeug " << p_pFahrzeug.getID() << " ist jetzt am Ende des Wegs " << p_pWeg.getID() << "." << endl;
}



