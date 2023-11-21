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


using namespace std;
double GlobaleZeit = 0.0;

void vAufgabe_1();
void vAufgabe_1a();
void vAufgabe_2();
void vAufgabe_3();
ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug);

int main(){
	vAufgabe_1();
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
	vectorFahrzeuge.push_back(move(fahrzeug1));
	vectorFahrzeuge.push_back(move(fahrzeug2));
	//fahrzeug1 und fahrzeug2 werden nun geloescht und in der Vektor gespeichert.

	//Diese Zeilen würden error ausgeben.
	/*
	vectorFahrzeuge.push_back(fahrrad1);
	vectorFahrzeuge.push_back(fahrzeug3);
	vectorFahrzeuge.push_back(fahrzeug4);
	vectorFahrzeuge.push_back(fahrzeug_s);
	*/

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
	vectorSharedFahrzeuge.push_back(move(fahrzeug4));
	cout << "Nach dem Speichern des Objekts, Count von fahrzeug3: " << fahrzeug3.use_count() << endl;
	cout << "Nach dem Speichern des Objekts, Count von fahrzeug4: " << fahrzeug4.use_count() << endl << endl;
	vectorSharedFahrzeuge.clear();
}


// Lass Benutzer Eigenschaften der 3 Objekte eingeben.
// Erzeuge die Objekte(im Smart-Pointer Format) nach den gegebenen Eigenschaften.
// Speichere diese Objekte in einer Unique(Smart Pointer Typ) Vektor
// Simuliere diese Objekte und gibt die Eigenschaften dieser Objekte in jeder Zeittakt aufm Bildschirm aus.
void vAufgabe_1a(){

	double dMaxGeschwindigkeit = 0.0;
	string name = "";

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des erstes Fahrzeuges:" << endl;
	cin >> name;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des zweites Fahrzeuges" << endl;
	cin >> name;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des drittes Fahrzeuges" << endl;
	cin >> name;
	cin >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug3 = make_unique<Fahrzeug>(name,dMaxGeschwindigkeit);

	vector<unique_ptr<Fahrzeug>>fahrzeuge;
	fahrzeuge.push_back(std::move(fahrzeug1));
	fahrzeuge.push_back(std::move(fahrzeug2));
	fahrzeuge.push_back(std::move(fahrzeug3));

	Fahrzeug::vKopf();

	for(double Epsilon = 0.0; Epsilon < 10; Epsilon+= 0.3){
		GlobaleZeit+=0.3;
		for(const auto& i : fahrzeuge){
			GlobaleZeit += Epsilon;
			i->vSimulieren(Epsilon);
			cout << *i << endl;
		}

	}

}

// Fragt nach dem Benutzer, wie viele Anzahl der Objekte er erzeugen will.
// Erzeuge die Objekte mit der gegebenen Eigenschaften und nach gegebenen Typen.
// Gibt die Eigenschaften der Objekte aufm Bildschrim formatiert aus.
void vAufgabe_2(){
	int pkw_anzahl = 0;
	int fahrrad_anzahl = 0;

	string name = "";
	double geschwindigkeit = 0.0;
	double verbrauch = 0.0;
	string tankVolumen = "";

	vector<unique_ptr<Fahrzeug>> fahrzeuge;

	cout << "Wie viele PKWs möchten Sie erstellen?" << endl;
	cin >> pkw_anzahl;

	cout << "Wie viele Fahrräder möchten Sie erstellen?" << endl;
	cin >> fahrrad_anzahl;

	cout << "Bitte geben Sie jetzt die Eigenschaften der PKWs vom Ersten bis Letzem ein.\n";
	for(int i = 0; i < pkw_anzahl; i++){
		cout << "1) Name: ";
		cin >> name;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> geschwindigkeit;

		cout << "3) Verbrauch: ";
		cin >> verbrauch;

		getline(cin, tankVolumen);
		cout << "4) Tankvolumen(optinal, default 55 liter angenommen.): ";
		getline(cin, tankVolumen);

		if(tankVolumen == ""){
			unique_ptr<PKW> pkw = make_unique<PKW>(name, geschwindigkeit, verbrauch);
			fahrzeuge.push_back(std::move(pkw));
		} else{
			unique_ptr<PKW> pkw = make_unique<PKW>(name, geschwindigkeit, verbrauch, stod(tankVolumen));
			fahrzeuge.push_back(std::move(pkw));
		}
	}

	cout << "Bitte geben Sie nun die Eigenschaften der Fahrräder vom Ersten bis Letzem ein.\n";
	for(int j = 0; j < fahrrad_anzahl; j++){
		cout << "1) Name: ";
		cin >> name;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> geschwindigkeit;

		unique_ptr<Fahrrad> fahrrad = make_unique<Fahrrad>(name, geschwindigkeit);
		fahrzeuge.push_back(std::move(fahrrad));
	}

	Fahrzeug::vKopf();
	GlobaleZeit = 0.1;
	for(double Epsilon = 0.0; Epsilon < 10; Epsilon+=0.3){
		GlobaleZeit+=0.3;

		for(const auto& i : fahrzeuge){
			i->vSimulieren(GlobaleZeit-Epsilon);
			cout << *i;
		}

		if((int)GlobaleZeit % 3 == 0 && GlobaleZeit >= 3.0){
			for(const auto& i : fahrzeuge){
				i->dTanken();
			}
		}

	}
}


//Erzeuge einige Fahrzeuge/PKWs und Fahrräder Objekte.
//Beachte der operator< und operator=
void vAufgabe_3(){
	//Unterschied zwischen ptr Objekt und nicht ptr Objekt zu beachten.
	//Es ist nicht gut, traditionaller Pointer zu nutzen. Lieber kann man smart Pointers benutzen.

	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<Fahrzeug>("fahrzeug2", 200.3);
	Fahrrad* fahrrad1 = new Fahrrad("fahrrad1", 25.3);
	Fahrrad* fahrrad2 = new Fahrrad("fahrrad2", 22.9);
	PKW pkw1("pkw1", 159.3, 8.3, 44.9);
	PKW pkw2("pkw2", 100.5, 8, 32.5);
	Fahrzeug* fahrzeug1 = new Fahrzeug("fahrzeug1", 88.3);
	pkw1.setGesamtstrecke(100);
	pkw2.setGesamtstrecke(200);


	if(pkw1 < pkw2){
		cout << "\nGesamtstrecke von pkw1: " << pkw1.getGesamtstrecke() << endl;
		cout << "Gesamtstrecke von pkw2: " << pkw2.getGesamtstrecke() << endl;
		cout << "Bedingung war pkw1 < pkw2. Die Bedingung wurde erfüllt und diese Zeile ist im If-Block\n" << endl;
	}

	cout << "Operation: pkw1=pkw2" << endl;
	pkw1 = pkw2;

	//Da die Fahrräder Pointers sind, kann die Übertragung der IDs nicht vermieden werden.
	cout << "Operation: fahrrad1=fahrrad2\n" << endl;
	fahrrad1 = fahrrad2;

	Fahrzeug::vKopf();
	cout << pkw1 << endl;
	cout << pkw2 << endl;
	cout << *fahrrad1 << endl;
	cout << *fahrrad2 << endl;
	cout << *fahrzeug2 << endl;

	delete fahrrad1;
	delete fahrrad2;
}

// Überladung von '<<' (Ausgabe) Operator.
// Nun können die Objekte der Klasse Fahrzeug(und die Unterkalsse Objekte davon)
// einfach mit "cout << Objekt" ausgegeben werden. Ohne die Ausgabefunktion zu nutzen.
ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug){
	fahrzeug.vAusgeben(ausgabe);
	return ausgabe;
}
