/*
 * Fahrzeug.cpp
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */

#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;
double dGlobaleZeit = 0.0;

void vAufgabe_1();
void vAufgabe_1a();
void vAufgabe_2();
void vAufgabe_3();

int main(){
	//vAufgabe_1();
	//vAufgabe_1a();
	//vAufgabe_2();
	//vAufgabe_3();

	return 0;
}



void vAufgabe_1(){
	Fahrzeug fahrrad1("fahrrad1", 25.3);
	Fahrzeug* fahrrad2 = new Fahrzeug("fahrrad2(p)", 30.9);
	delete fahrrad2;

	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>("fahrzeug1(up)", 33.3);
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<Fahrzeug>("fahrzeug2(up)", 29.7);
	shared_ptr<Fahrzeug> fahrzeug3 = make_shared<Fahrzeug>("fahrzeug3(sp)", 22.5);
	shared_ptr<Fahrzeug> fahrzeug4 = make_shared<Fahrzeug>("fahrzeug4(sp)", 19.1);
	cout << "\nVor dem Erzeugen des neues Objekts(Shared-Ptr) durch die Zuweisung, Count von fahrzeug4: " << fahrzeug4.use_count() << endl;
	shared_ptr<Fahrzeug> fahrzeug_s = fahrzeug4;
	cout << "Nach dem Erzeugen des neues Objekts(Shared-Ptr) durch die Zuweisung, Count von fahrzeug4: " << fahrzeug4.use_count() << endl << endl;

	//unique_ptr<Fahrzeug> fahrzeug_u = fahrzeug2;

	//In einer unique vector darf nur die Unique-Pointers speichert werden.
	vector<unique_ptr<Fahrzeug>> vectorFahrzeuge;
	vectorFahrzeuge.push_back(std::move(fahrzeug1));
	vectorFahrzeuge.push_back(std::move(fahrzeug2));
	//fahrzeug1 und fahrzeug2 werden nun geloescht und in der Vektor gespeichert.

	//Diese Zeilen würden error ausgeben.
	/*
	vectorFahrzeuge.push_back(fahrzeug1);
	vectorFahrzeuge.push_back(fahrzeug3);
	vectorFahrzeuge.push_back(fahrzeug4);
	vectorFahrzeuge.push_back(fahrzeug_s);
	*/

	// Lösche den Intahl des Vektors. Die Objekte werden durch der Destruktor gelöscht.
	vectorFahrzeuge.clear();



	// Count von fahrzeug3 wird sich erhöhen, weil ohne move Funktion die Objekte nicht verschoben werden können.
	// Deswegen gewinnt dieses Objekt noch einen Pointer.
	// Mit "Count" wird gemeint, von wie viele Pointers dieses Objekt gezeigt wird?

	// Es gibt kein fahrzeug4 Pointer Objekt mehr,
	// da es geloescht und das Objekt, das vom Pointer gezeigt wurde, nun im Shared_Ptr Vektor gespeichert wurde.

	cout << "\nVor dem Speichern des Objekts, Count von fahrzeug3: " << fahrzeug3.use_count() << endl;
	cout << "Vor dem Speichern des Objekts, Count von fahrzeug4: " << fahrzeug4.use_count() << endl;
	vector<shared_ptr<Fahrzeug>> vectorSharedFahrzeuge;
	vectorSharedFahrzeuge.push_back(fahrzeug3);
	vectorSharedFahrzeuge.push_back(std::move(fahrzeug4));
	cout << "Nach dem Speichern des Objekts, Count von fahrzeug3: " << fahrzeug3.use_count() << endl;
	cout << "Nach dem Speichern des Objekts, Count von fahrzeug4: " << fahrzeug4.use_count() << endl << endl;
	vectorSharedFahrzeuge.clear();
}



void vAufgabe_1a(){

	double dStunden = 0.0;
	// Lese die gewünschte Simulationzeit ein.(Benutzerfreundlciher)
	cout << "Bitte geben Sie die Simulationzeit in Stunden ein: ";
	cin >> dStunden;
	double Epsilon = 0.3;
	double dMaxGeschwindigkeit = 0.0;
	string sName = "";


	// Lass Benutzer Eigenschaften der 3 Objekte eingeben.
	// Erzeuge die Objekte(im Smart-Pointer Format) nach den gegebenen Eigenschaften.
	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des erstes Fahrzeuges:" << endl;
	cin >> sName;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>(sName,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des zweites Fahrzeuges" << endl;
	cin >> sName;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<Fahrzeug>(sName,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des drittes Fahrzeuges" << endl;
	cin >> sName;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug3 = make_unique<Fahrzeug>(sName,dMaxGeschwindigkeit);

	// Speichere diese Objekte, die von der Smart-Pointern gezeigt werden, in einer Unique Vektor
	// Da die Unique Pointers in einer Unique-Vektor gespeichert werden dürfen.
	vector<unique_ptr<Fahrzeug>>fahrzeuge;
	fahrzeuge.push_back(std::move(fahrzeug1));
	fahrzeuge.push_back(std::move(fahrzeug2));
	fahrzeuge.push_back(std::move(fahrzeug3));

	// Simuliere diese Objekte und gibt die Eigenschaften dieser Objekte in jeder Zeittakt aufm Bildschirm aus.
	Fahrzeug::vKopf();
	for(dGlobaleZeit = Epsilon; dGlobaleZeit < dStunden; dGlobaleZeit += Epsilon){
		for(const auto& fahrzeug: fahrzeuge){
			fahrzeug->vSimulieren();
			cout << *fahrzeug << endl;
		}
	}

}



void vAufgabe_2(){
	int iPkwAnzahl, iFahrradAnzahl;

	string sName = "";
	double dGeschwindigkeit = 0.0;
	double dVerbrauch = 0.0;
	string sTankVolumen = "";

	vector<unique_ptr<Fahrzeug>> fahrzeuge;

	// Fragt nach dem Benutzer, wie viele Anzahl der Objekte er erzeugen will.
	cout << "Wie viele PKWs möchten Sie erstellen?" << endl;
	cin >> iPkwAnzahl;

	cout << "Wie viele Fahrräder möchten Sie erstellen?" << endl;
	cin >> iFahrradAnzahl;

	// Erzeuge die Objekte mit der gegebenen Eigenschaften und nach gegebenen Typen.
	cout << "Bitte geben Sie jetzt die Eigenschaften der PKWs vom Ersten bis Letzem ein.\n";
	for(int i = 0; i < iPkwAnzahl; i++){
		cout << "1) Name: ";
		cin >> sName;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> dGeschwindigkeit;

		cout << "3) Verbrauch: ";
		cin >> dVerbrauch;

		getline(cin, sTankVolumen);
		cout << "4) Tankvolumen(optinal, default 55 liter angenommen.): ";
		getline(cin, sTankVolumen);

		if(sTankVolumen == ""){
			unique_ptr<PKW> pkw = make_unique<PKW>(sName, dGeschwindigkeit, dVerbrauch);
			fahrzeuge.push_back(std::move(pkw));
		} else{
			unique_ptr<PKW> pkw = make_unique<PKW>(sName, dGeschwindigkeit, dVerbrauch, stod(sTankVolumen));
			fahrzeuge.push_back(std::move(pkw));
		}
	}

	// Erzeuge die Objekte mit der gegebenen Eigenschaften und nach gegebenen Typen.
	cout << "Bitte geben Sie nun die Eigenschaften der Fahrräder vom Ersten bis Letzem ein.\n";
	for(int j = 0; j < iFahrradAnzahl; j++){
		cout << "1) Name: ";
		cin >> sName;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> dGeschwindigkeit;

		unique_ptr<Fahrrad> fahrrad = make_unique<Fahrrad>(sName, dGeschwindigkeit);
		fahrzeuge.push_back(std::move(fahrrad));
	}


	double dTankZeit = 3.0; // In jeder 3 Stunden sollen die PKWs getankt werden.
	double Epsilon = 0.247; // Zeittakt.
	// Gibt die Eigenschaften der Objekte aufm Bildschrim formatiert aus.
	Fahrzeug::vKopf();
	for(dGlobaleZeit = Epsilon; dGlobaleZeit < 10; dGlobaleZeit += Epsilon){
		for(const auto& fahrzeug : fahrzeuge){
			cout << *fahrzeug;
			fahrzeug->vSimulieren();
			if(fmod(dGlobaleZeit,dTankZeit)<Epsilon){
				fahrzeug->dTanken();
			}
		}
	}

}



void vAufgabe_3(){
	//Unterschied zwischen ptr Objekt(fahrrad1, fahrrad2, fahrzeug2) und nicht ptr Objekt(pkw1, pkw2) zu beachten.
	//Es ist nicht gut, traditionaller Pointer zu nutzen. Lieber kann man smart Pointers benutzen.

	//Erzeuge einige Fahrzeuge/PKWs und Fahrräder Objekte.
	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>("fahrzeug1", 200.3);
	Fahrrad* fahrrad1 = new Fahrrad("fahrrad1", 25.3);
	Fahrrad* fahrrad2 = new Fahrrad("fahrrad2", 22.9);
	PKW pkw1("pkw1", 159.3, 8.3, 44.9);
	PKW pkw2("pkw2", 100.5, 8, 32.5);
	Fahrzeug* fahrzeug2 = new Fahrzeug("fahrzeug2", 88.3);

	// Gibt die Eigenschaften dieser Objekte aufm Bildschrim aus.
	Fahrzeug::vKopf();
	cout << *fahrzeug1 << endl << endl;
	cout << *fahrrad1 << endl;
	cout << *fahrrad2 << endl;
	cout << pkw1 << endl;
	cout << pkw2 << endl;
	cout << *fahrzeug2 << endl << endl;

	// Set die Gesamtstrecke von zwei PKWs, um das Verhealtnis des überladenden operator< beobachten zu können.
	pkw1.setGesamtstrecke(100);
	pkw2.setGesamtstrecke(200);

	// Gibt die Eigenschaften dieser Objekte aufm Bildschrim aus.
	Fahrzeug::vKopf();
	cout << *fahrzeug1 << endl << endl;
	cout << *fahrrad1 << endl;
	cout << *fahrrad2 << endl;
	cout << pkw1 << endl;
	cout << pkw2 << endl;
	cout << *fahrzeug2 << endl << endl;

	//Beachte der operator<
	if(pkw1 < pkw2){
		cout << "\nGesamtstrecke von pkw1: " << pkw1.getGesamtstrecke() << endl;
		cout << "GesamStstrecke von pkw2: " << pkw2.getGesamtstrecke() << endl;
		cout << "Bedingung war pkw1 < pkw2. Die Bedingung wurde erfüllt und diese Zeile ist im If-Block\n" << endl;
	}

	// Beachte der operator=
	// Da pkw1 und pkw1 Objekte sind, können die alle Eigenschaften außer ID übertragen werden.
	cout << "Operation: pkw1=pkw2" << endl << endl;
	pkw1 = pkw2;


	// Gibt die Eigenschaften dieser Objekte aufm Bildschrim aus.
	Fahrzeug::vKopf();
	cout << *fahrzeug1 << endl << endl;
	cout << *fahrrad1 << endl;
	cout << *fahrrad2 << endl;
	cout << pkw1 << endl;
	cout << pkw2 << endl;
	cout << *fahrzeug2 << endl << endl;

	//Da die Fahrräder Pointers sind, kann die Übertragung der IDs nicht vermieden werden.
	cout << "Operation: fahrrad1=fahrrad2\n" << endl;
	fahrrad1 = fahrrad2;

	// Gibt die Eigenschaften dieser Objekte aufm Bildschrim aus.
	Fahrzeug::vKopf();
	cout << *fahrzeug1 << endl << endl;
	cout << *fahrrad1 << endl;
	cout << *fahrrad2 << endl;
	cout << pkw1 << endl;
	cout << pkw2 << endl;
	cout << *fahrzeug2 << endl << endl;

	// Löschen der dynamischen Objekte(Pointers, um von der undefinierten Verhealtnissen vermeiden zu können.)
	delete fahrrad1;
	delete fahrrad2;
	delete fahrzeug2;
}
