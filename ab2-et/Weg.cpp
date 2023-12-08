/*
 * Weg.cpp
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Simulationsobjekt.h"
#include "vertagt_liste.h"
#include "Weg.h"
#include "Tempolimit.h"
#include "Fahrausnahme.h"

using namespace std;
extern double dGlobaleZeit;

//Konstruktor fuer Weg Objekt mit 3 Parametern
Weg::Weg(string p_sName, double p_dLaenge, Tempolimit p_eTempolimit): // @suppress("Member declaration not found")
		Simulationsobjekt(p_sName), p_dLaenge(p_dLaenge), p_eTempolimit(p_eTempolimit){}

//Simulieren Methode fuer Wegobjekte.
void Weg::vSimulieren(){

	p_pFahrzeuge.vAktualisieren();

	//Simuliere alle vorhandene Fahrzeuge in der Liste p_pFahrzeuge
	//Waehrend des Simuliieren kontrolliere, ob es einen Ausnahme auftritt.
	//Wenn ja, bearbeite diesen Ausnahme und mache weiter.
	//Wenn nein, mach einfach weiter.
	for(auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end();){
		try{
			(*it)->vZeichnen(*this);
			(*it)->vSimulieren();
			it++;
		} catch (Fahrausnahme *fahrausnahme){
			it++;
			fahrausnahme->vBearbeiten();
		}
	}
	p_pFahrzeuge.vAktualisieren();
}

//Ausgeben der Wegobjekte einfach mit cout<<
//Erbt zuerst von der Klasse Simulationsbjekt
void Weg::vAusgeben(ostream& ausgabe) const{
	Simulationsobjekt::vAusgeben(ausgabe);
	ausgabe << setw(0) << ": "
			<< setw(15) << getLaenge()
			<< setw(0) << "( "
			<< setw(0);
			getFahrzeuge();
	ausgabe << ")";
}

//Ausgeben der Wegobjekte mit der Methode vAusgeben
//Erbt zuerst von der Klasse Simulationsbjekt
void Weg::vAusgeben() const{
	Simulationsobjekt::vAusgeben();
	cout << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setw(10) << ": " << getLaenge()
		 << setw(10) << "( ";
			getFahrzeuge();
	cout << ")";
}

//Static(Klassenfunktion vKopf) Funktion vKopf fuer tabellerarische Ausgabe
void Weg::vKopf() {
	cout << endl << resetiosflags(ios::adjustfield)
		 << setiosflags(ios::left)
		 << setw(8) << "ID"
		 << setw(15) << "| Name"
		 << setw(15) << "| Laenge"
		 << setw(15) << "| Fahrzeuge" << endl;

	cout << setw(8+15*3) << setfill('-') << '-' << setfill(' ') << endl;

}

//Annahme Funktion von der Klasse Weg
//Neue Fahrzeuge werden akzeptiert und in die Liste vom Typ "VListe" p_pFahrzeuge gespeichert.
//Diese Fahrzeuge zeigen das Verhalten "Fahren"
void Weg::vAnnahme(unique_ptr<Fahrzeug>fahrzeug){
	fahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(std::move(fahrzeug));
	p_pFahrzeuge.vAktualisieren();
}


//Annahme Funktion von der Klasse Weg
//Neue Fahrzeuge werden akzeptiert und in die Liste vom Typ "VListe" p_pFahrzeuge gespeichert.
//Diese Fahrzeuge zeigen das Verhalten "Parken"
void Weg::vAnnahme(unique_ptr<Fahrzeug>fahrzeug, double dStartZeitpunkt){
	fahrzeug->vNeueStrecke(*this, dStartZeitpunkt);
	p_pFahrzeuge.push_front(std::move(fahrzeug));
	p_pFahrzeuge.vAktualisieren();
}

//Abgabe Methode der Klasse Weg.
//Diese Methode sucht das gegebene Objekt aus der Liste.
//Wenn dieses Objekt in der Liste vorhanden ist, wird dieses Objekt geloescht.
//Loschendes Objekt wird zuruckgegeben durch return.
unique_ptr<Fahrzeug> Weg::pAbgabe(Fahrzeug& fahrzeug_gesucht){
	for(auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++) {
		// Überprüfen des Iterationselementes mit gewünschtem Fahrzeug
		if((*it).get() == &fahrzeug_gesucht) {
			// Lokale Variable zur Zwischenspeicherung
			std::unique_ptr<Fahrzeug> lokal_fahrzeug = std::move(*it);
			// Löschen des Fahrzeugs aus der Liste
			p_pFahrzeuge.erase(it);
			p_pFahrzeuge.vAktualisieren();
			return lokal_fahrzeug;
		}
	}
	return nullptr;
}

// Wird ein Fahrzeug Objekt gegeben, wird dieses gegebende Fahrzeug in die Liste p_pFahrzeuge gespeichert.
void Weg::setFahrzeug(unique_ptr<Fahrzeug> fahrzeug){
	p_pFahrzeuge.push_back(std::move(fahrzeug));
	p_pFahrzeuge.vAktualisieren();
}

// Wird ein Fahrzeuglist gegeben, wird diese gegebende Liste nach hinten der Liste p_pFahrzeuge gemerged.
void Weg::setFahrzeugList(list<unique_ptr<Fahrzeug>> fahrzeugList){
	for(auto&& fahrzeugPtr : fahrzeugList){
		p_pFahrzeuge.push_back(std::move(fahrzeugPtr));
		p_pFahrzeuge.vAktualisieren();
	}
}

//Die Namen der Fahrzeuge aus der vorhandenen Liste p_pFahrzeuge werden aufm Bildschirm ausgegeben.
void Weg::getFahrzeuge() const{
	for(auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++){
		const Fahrzeug* fahrzeug = it->get();
		if(it == --p_pFahrzeuge.end()){
			cout << fahrzeug->getName() << " ";
		} else{
			cout << fahrzeug->getName() << ", ";
		}
	}
}

// Wird die maximal erlaubende Geschwindigkeit von vorhandenem Weg ausgegeben
double Weg::getTempolimit() const{
	cout << fixed << setprecision(2);
	return (double)p_eTempolimit;
}

//Ueberladen des Ausgabeoperator <<
ostream& operator<<(ostream& ausgabe,const Weg& weg){
	weg.vAusgeben(ausgabe);
	return ausgabe;
}



