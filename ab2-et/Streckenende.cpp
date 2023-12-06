/*
 * Streckenende.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */
#include <iostream>
#include <memory>
#include "Streckenende.h"
#include "vertagt_liste.h"

void Streckenende::vBearbeiten(){
	cout << "Das Fahrzeug " << p_pFahrzeug.getName() << " ist jetzt am Ende des Wegs " << p_pWeg.getName() << "." << endl;
}



