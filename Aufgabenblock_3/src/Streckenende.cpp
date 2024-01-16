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
extern double dGlobaleZeit;

// Ausnahme Streckenende
// Wenn ein Fahrzeug am Ende eines Wegs gefahren ist, wird diese Methode von der Methode des Wegs vSimulieren aufgerufen.
// Durch try-catch Block.
void Streckenende::vBearbeiten(){
	cout << "Das Fahrzeug " << p_pFahrzeug.getName()
		 << " ist jetzt am Ende des Wegs " << p_pWeg.getName()
		 << " im Zeitpunkt " << dGlobaleZeit <<"." << endl;
	unique_ptr<Fahrzeug> lokalFahrzeug = p_pWeg.pAbgabe(p_pFahrzeug);
	lokalFahrzeug->setAbschnittStrecke(0.0);
	shared_ptr<Kreuzung> lokalKreuzung = p_pWeg.getKreuzung();
	shared_ptr<Weg> lokalZufaelligerWeg = lokalKreuzung->pZufaelligerWeg(p_pWeg);
	lokalKreuzung->vTanken(*lokalFahrzeug);
	lokalZufaelligerWeg->vAnnahme(move(lokalFahrzeug));

	cout << "Das Fahrzeug mit der ID " << p_pFahrzeug.getID()
		 << " hat auf dem Weg mit der ID " << p_pWeg.getID()
		 << " das Streckenede erreicht." << std::endl;

	cout << "ZEIT     " << ":" << dGlobaleZeit << endl;
	cout << "KREUZUNG " << ":" << lokalKreuzung->getName() << " " << lokalKreuzung->getTankstelle() << endl;
	cout << "WECHSEL  " << ":" << p_pWeg.getName() << " -> " << lokalZufaelligerWeg->getName() << endl;
	Fahrzeug::vKopf();
	cout << p_pFahrzeug;
}



