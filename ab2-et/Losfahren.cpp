/*
 * Losfahren.cpp
 *
 *  Created on: 03.12.2023
 *      Author: kyotun
 */
#include <iostream>
#include <memory>
#include "Losfahren.h"
#include "Weg.h"
#include "Fahrzeug.h"

void Losfahren::vBearbeiten(){
	cout << "Das Fahrzeug " << p_pFahrzeug.getName()
			<< " fangt jetzt auf dem Weg " << p_pWeg.getName()
			<< " zu fahren." << endl;
	unique_ptr<Fahrzeug> lokal_ptr = p_pWeg.pAbgabe(p_pFahrzeug);
	p_pWeg.vAnnahme(std::move(lokal_ptr));
}



