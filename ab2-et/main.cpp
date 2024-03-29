/*
 * Fahrzeug.cpp
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */

// Gui, boost klasor erisim

#include <iostream>
#include <memory>
#include <iomanip>
#include <vector>
#include <cmath>
#include <random>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
#include "Weg.h"
#include "Simulationsobjekt.h"
#include "Tempolimit.h"
//#include "SimuClient.h"
#include "vertagt_liste.h"

using namespace std;
double dGlobaleZeit = 0.0;

void vAufgabe_1();
void vAufgabe_1a();
void vAufgabe_2();
void vAufgabe_3();
//void vAufgabe_AB1();
void vAufgabe_4();
void vAufgabe_5();
void vAufgabe_6();
void vAufgabe_6a();

int main(){
//	vAufgabe_1();
	vAufgabe_1a();
//	vAufgabe_2();
//	vAufgabe_3();
//	vAufgabe_AB1();
//	vAufgabe_4();
//	vAufgabe_5();
//	vAufgabe_6();
//	vAufgabe_6a();
	return 0;
}


void vAufgabe_1(){
	// Statisches Erzeugen eines Elements
	Fahrzeug fahrrad1("fahrrad1", 25.3);

	// Dynamisch erzeugtes Element
	Fahrzeug* fahrrad2 = new Fahrzeug("fahrrad2(p)", 30.9);

	// Loeschen des dynamisch erzeugteten Elements
	delete fahrrad2;

	// Erzeugen der Smart Pointern
	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>("fahrzeug1(up)", 33.3);
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<Fahrzeug>("fahrzeug2(up)", 29.7);
	shared_ptr<Fahrzeug> fahrzeug3 = make_shared<Fahrzeug>("fahrzeug3(sp)", 22.5);
	shared_ptr<Fahrzeug> fahrzeug4 = make_shared<Fahrzeug>("fahrzeug4(sp)", 19.1);
	cout << "\nVor dem Erzeugen des neues Objekts(Shared-Ptr) durch die Zuweisung, Count von fahrzeug4: " << fahrzeug4.use_count() << endl;

	// Speichern des Objekts, das vom fahrzeug4 shared ptr gezeigt wird, im Shared-Ptr fahrzeug_s
	shared_ptr<Fahrzeug> fahrzeug_s = fahrzeug4;
	cout << "Nach dem Erzeugen des neues Objekts(Shared-Ptr) durch die Zuweisung, Count von fahrzeug4: " << fahrzeug_s.use_count() << endl << endl;

	// Error: Unique-Ptr darf nicht zugewiesen werden.
	//unique_ptr<Fahrzeug> fahrzeug_u = fahrzeug2;

	cout << "Vor dem Speichern der Unique-Ptrs in der Unique-Vector:" << endl;
	cout << *fahrzeug1 << endl; // das Objekt
	cout << *fahrzeug2 << endl;
	cout << "Fahrzeug1: " << fahrzeug1 << endl;  // Adresse vom Objekt
	cout << "Fahrzeug2: " << fahrzeug2 << endl;
	cout << "Fahrzeug1&: " << &fahrzeug1 << endl; // Adresse vom Pointer
	cout << "Fahrzeug2&: " << &fahrzeug2 << endl << endl;


	//In einer Unique-Vektor dürfen nur die Objekte, die von Unique-Pointers gezeigt werden, gespeichert werden.
	//Da andernsfall würde das Objekt durch zwei Unique-Ptrs gleichzeigit angezeigt werden.
	vector<unique_ptr<Fahrzeug>> vectorFahrzeuge;
	vectorFahrzeuge.push_back(std::move(fahrzeug1));
	vectorFahrzeuge.push_back(std::move(fahrzeug2));


	// Kompilier weist diese Unique-Ptrs nach dem Speichern kein Speichernpplatz mehr zu.
	// Aber Sie existieren noch. Nur zeigen ihre Zeigern auf eine leere.
	cout << "Nach dem Speichern der Unique-Ptrs in der Unique-Vector:" << endl;
	cout << "Fahrzeug1: " << fahrzeug1 << endl;
	cout << "Fahrzeug2: " << fahrzeug2 << endl << endl;


	//cout << *fahrzeug1 << endl; -> Nach dieser Zeile dürfen die andere Code nicht gezeigt werden.
	cout << "Objekte aus der Unique-Vector: " << endl;
	cout << *vectorFahrzeuge[0] << endl; // -> Fahrzeug1 Objekt.
	cout << *vectorFahrzeuge[1] << endl << endl; // -> Fahrzeug2 Objekt.


//	Diese Zeilen würden error ausgeben.
//	vectorFahrzeuge.push_back(fahrzeug1);
//	vectorFahrzeuge.push_back(fahrzeug3);
//	vectorFahrzeuge.push_back(fahrzeug4);
//	vectorFahrzeuge.push_back(fahrzeug_s);




	// Loesche den Intahl des Vektors. Die Objekte werden durch der Destruktor gelöscht.
	vectorFahrzeuge.clear();


	// Count von fahrzeug3 wird sich erhöhen, weil ohne move Funktion die Ptrs Ihren Besitz aufm Objekt nicht verlieren.
	// Deswegen gewinnt dieses Objekt noch einen Pointer.
	// Mit "Count" wird gemeint, von wie viele Pointers dieses Objekt gezeigt wird.

	// Mit move Funktion verliert der Zeiger seinen Besitz aufm Objekt.
	// Der Besitzsrecht wird aufm neuen Zeiger übertragen, der eigentlich eine Vektor ist.
	// Shared-Ptr Fahrzeug4 zeigt nun auf die Leere.
	cout << "\nVor dem Speichern des Objekts, Count von fahrzeug3: " << fahrzeug3.use_count() << endl;
	cout << "Vor dem Speichern des Objekts mit move(), Count von fahrzeug4: " << fahrzeug4.use_count() << endl;

	vector<shared_ptr<Fahrzeug>> vectorSharedFahrzeuge;
	vectorSharedFahrzeuge.push_back(fahrzeug3);
	vectorSharedFahrzeuge.push_back(std::move(fahrzeug4));

	cout << "Nach dem Speichern des Objekts, Count von fahrzeug3: " << fahrzeug3.use_count() << endl;
	cout << "Nach dem Speichern des Objekts, Count von fahrzeug4: " << fahrzeug4.use_count() << endl << endl;


	// Hier kann man eine Unique-Ptr in einer Shared-Vector speichern. Da die Shared-Typ flexibler als Unique-Typ ist.
	// Bei Unique-Ptr & Unique-Vector war das Gegenteil.
	cout << endl << "Erzeugen einer Unique-Ptr." << endl;
	unique_ptr<Fahrzeug> fahrzeug5 = make_unique<Fahrzeug>("fahrzeug5(up)", 35.7);
	vectorSharedFahrzeuge.push_back(std::move(fahrzeug5));
	cout << "Unique-Ptr wird in Shared-Vektor verschoben." << endl << endl;
	vectorSharedFahrzeuge.clear();
}



void vAufgabe_1a(){

	double dStunden = 0.0;
	// Lese die gewünschte Simulationzeit ein.(Benutzerfreundlciher)
	cout << "Bitte geben Sie die Simulationzeit in Stunden ein: ";
	cin >> dStunden;
	double dMaxGeschwindigkeit = 0.0;
	string sName;


	// Lass Benutzer Eigenschaften der 3 Objekte eingeben.
	// Erzeuge die Objekte(im Smart-Pointer Format) nach den gegebenen Eigenschaften.
	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des erstes Fahrzeuges:" << endl;
	cin >> sName >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>(sName,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des zweites Fahrzeuges" << endl;
	cin >> sName >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<Fahrzeug>(sName,dMaxGeschwindigkeit);

	cout << "Geben Sie bitte den Namen und MaxGeschwindigkeit des drittes Fahrzeuges" << endl;
	cin >> sName >> dMaxGeschwindigkeit;
	unique_ptr<Fahrzeug> fahrzeug3 = make_unique<Fahrzeug>(sName,dMaxGeschwindigkeit);

	// Speichere diese Objekte, die von der Smart-Pointern gezeigt werden, in einer Unique Vektor
	// Da die Unique Pointers in einer Unique-Vektor gespeichert werden dürfen.
	vector<unique_ptr<Fahrzeug>>fahrzeuge;
	fahrzeuge.push_back(std::move(fahrzeug1));
	fahrzeuge.push_back(std::move(fahrzeug2));
	fahrzeuge.push_back(std::move(fahrzeug3));

	double dEpsilon = 0.0;
	// Einlesen der Zeittakt vom Benutzer.
	cout << endl << "Bitte geben Sie eine Period für die Simulation(lieber als Bruchteile von Studen): ";
	cin >> dEpsilon;

	// Simuliere diese Objekte und gibt die Eigenschaften dieser Objekte in jeder Zeittakt aufm Bildschirm aus.
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dEpsilon; dGlobaleZeit < dStunden; dGlobaleZeit += dEpsilon){
		for(const auto& fahrzeug: fahrzeuge){
			cout << *fahrzeug << endl;
			fahrzeug->vSimulieren();
		}
	}

}



void vAufgabe_2(){
	int iPkwAnzahl, iFahrradAnzahl;

	string sName;
	double dGeschwindigkeit = 0.0;
	double dVerbrauch = 0.0;
	string sTankVolumen;

	vector<unique_ptr<Fahrzeug>> fahrzeuge;

	// Fragt nach dem Benutzer, wie viele Anzahl der Objekte er erzeugen will.
	// Einlesen der Anzahlen von PKWs und Fahrräder
	cout << "Wie viele PKWs möchten Sie erstellen?" << endl;
	cin >> iPkwAnzahl;

	cout << "Wie viele Fahrräder möchten Sie erstellen?" << endl;
	cin >> iFahrradAnzahl;

	// Erzeuge die Objekte mit der eingelesenen Eigenschaften und nach gegebenen Typen.
	cout << "Bitte geben Sie jetzt die Eigenschaften der PKWs vom Ersten bis Letzem ein.\n";
	for(int i = 0; i < iPkwAnzahl; i++){
		cout << "1) Name: ";
		cin >> sName;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> dGeschwindigkeit;

		cout << "3) Verbrauch: ";
		cin >> dVerbrauch;

		//Mann muss vorsicht sein, wenn die Stringeingaben eingelesen werden.
		//Das Verhalten des cin Operators ist anders fuer Strings.
		//Hier soll getline Methode benutzt werden.
		getline(cin, sTankVolumen);
		cout << "4) Tankvolumen(optinal, default 55 liter angenommen.): ";
		getline(cin, sTankVolumen);

		//Kontrolliere ob der Benutzer optionalen Eingabe eingegeben hat.
		//Wenn ja, erzeuge das PKW mit 3 Parametern.
		//Wenn nein, formt den Eingabe von string um den double Wert um und dann erzeuge das PKW.
		//Letztes gibt das Objekt in die Vektor ein.
		if(sTankVolumen == ""){
			unique_ptr<PKW> pkw = make_unique<PKW>(sName, dGeschwindigkeit, dVerbrauch);
			fahrzeuge.push_back(std::move(pkw));
		} else{
			unique_ptr<PKW> pkw = make_unique<PKW>(sName, dGeschwindigkeit, dVerbrauch, stod(sTankVolumen));
			fahrzeuge.push_back(std::move(pkw));
		}
	}

	// Erzeuge die Objekte mit der eingelesene Eigenschaften nach gegebenen Typen.
	cout << "Bitte geben Sie nun die Eigenschaften der Fahrräder vom Ersten bis Letzem ein.\n";
	for(int j = 0; j < iFahrradAnzahl; j++){
		cout << "1) Name: ";
		cin >> sName;

		cout << "2) Maximale Geschwindigkeit: ";
		cin >> dGeschwindigkeit;

		//Erzeuge das Fahrrad Objekt.
		//Dann gibt das Objekt in die Vektor ein.
		unique_ptr<Fahrrad> fahrrad = make_unique<Fahrrad>(sName, dGeschwindigkeit);
		fahrzeuge.push_back(std::move(fahrrad));
	}

	// In jeder x.x Stunden werden die Tänke der PKWs aufgefüllt.
	double dTankZeit = 0.0;
	cout << endl << "Bitte geben Sie eine Period für Tanken der PKWs: ";
	cin >> dTankZeit;

	// Wie lange eine Simulationsschritt dauert? -> dEpsilon
	double dEpsilon = 0.0; // Zeittakt.
	cout << endl << "Bitte geben Sie eine Period für die Simulation(lieber als Bruchteile von Studen): ";
	cin >> dEpsilon;

	// Gibt die Eigenschaften der Objekte aufm Bildschrim formatiert aus.
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dEpsilon; dGlobaleZeit < 5; dGlobaleZeit += dEpsilon){
		for(const auto& fahrzeug : fahrzeuge){
			cout << *fahrzeug;
			fahrzeug->vSimulieren();
			if(fmod(dGlobaleZeit,dTankZeit) < dEpsilon){
				fahrzeug->dTanken(fahrzeug->getTankvolumen());
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

	cout << "Adresse von pkw1: " << &pkw1 << endl;
	cout << "Adresse von pkw2: " << &pkw2 << endl;


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

	cout << fahrrad1 << endl;
	cout << fahrrad2 << endl;

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

//void vAufgabe_AB1() {
//
//    int l = 0; // Laufindex für gezielte AUsgabe
//    vector<int> ausgabe{15};
//    double dTakt = 0.3;
//
//    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
//    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 229, 9.6));
//    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 24.7));
//    for (dGlobaleZeit = 0; dGlobaleZeit < 5; dGlobaleZeit += dTakt)
//    {
//        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
//        if (itL != ausgabe.end()) {
//            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
//            Fahrzeug::vKopf();
//        }
//
//        for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
//        {
//            vecFahrzeuge[i]->vSimulieren();
//            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
//            {
//                vecFahrzeuge[i]->dTanken();
//            }
//            if (itL != ausgabe.end()) {
//                std::cout << *vecFahrzeuge[i] << endl;
//            }
//        }
//        l++;
//    }
//    char c;
//    std::cin >> c;
//}

void vAufgabe_4(){

	//Statisches erzeugen eines Wegs "Innerorts"
	Weg weg1("weg", 105.99, Innerorts);

	//Dynamisches erzeugen(mit Smart-Ptr) eines wegs "Autobahn"
	unique_ptr<Weg> weg_ptr = make_unique<Weg>("weg_ptr", 287.34, Autobahn);

	//Dynamisches erzeugen eines Fahrzeugs.
	unique_ptr<Fahrzeug> fahrzeug1 = make_unique<Fahrzeug>("fahrzeug1");

	//Weg sollte leer sein.
	cout << "\nVor dem Annahme:";
	Weg::vKopf();
	cout << weg1 << endl;
	cout << *weg_ptr << endl << endl;

	//Nach diesen Zeilen soll Weg fahrzeug1 enthalten.
	cout << "Nach dem Annahme von fahrzeug1 im weg1:" << endl;
	weg1.vAnnahme(std::move(fahrzeug1));
	Weg::vKopf();
	cout << weg1 << endl;
	cout << *weg_ptr << endl << endl;
}

void vAufgabe_5(){

	//Dynamisches Erzeugen verschiedenen Elementen
	unique_ptr<Weg> weg_ptr1 = make_unique<Weg>("WEG", 255.55, Innerorts);

	unique_ptr<Fahrzeug> fahrzeug = make_unique<PKW>("PKW1", 123.35, 13.37);
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<PKW>("PKW2", 155.37, 15.55, 62.37);
	unique_ptr<Fahrzeug> fahrzeug3 = make_unique<Fahrrad>("Fahrrad", 27.89);
	unique_ptr<Fahrzeug> fahrzeug4 = make_unique<PKW>("PKW3", 121.3, 12.33, 34.37);

	//Weg akzeptiert die Fahrzeuge.
	cout << endl;
	weg_ptr1->vAnnahme(std::move(fahrzeug));
	weg_ptr1->vAnnahme(std::move(fahrzeug2));
	weg_ptr1->vAnnahme(std::move(fahrzeug3));
	weg_ptr1->vAnnahme(std::move(fahrzeug4),2);



	// In jeder x.x Stunden werden die Tänke der PKWs aufgefüllt.
	double dTankZeit = 0.0;
	cout << endl << "Bitte geben Sie eine Period für Tanken der PKWs: ";
	cin >> dTankZeit;

	// Wie lange eine Simulationsschritt dauert? -> dEpsilon
	double dEpsilon = 0.0; // Zeittakt.
	cout << endl << "Bitte geben Sie eine Period für die Simulation(lieber als Bruchteile von Studen): ";
	cin >> dEpsilon;

	// Gibt die Eigenschaften der Objekte aufm Bildschrim formatiert aus.
	// In jeder Zeittakt, gibt die Informationen der Fahrzeugen vor dem Simulieren aus.
	// Dann simuliere alle Fahrzeuge.
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dEpsilon; dGlobaleZeit < 5; dGlobaleZeit += dEpsilon){
		for(const auto& fahrzeug : *weg_ptr1->getFahrzeugList()){
			cout << *fahrzeug;

			if(fmod(dGlobaleZeit,dTankZeit) < dEpsilon){
				fahrzeug->dTanken(fahrzeug->getTankvolumen());
			}
		}
		weg_ptr1->vSimulieren();
	}
}

void vAufgabe_6(){

	//Dynamisches Erzeugen aller Objekte.
	unique_ptr<Weg> autobahn = make_unique<Weg>("Autobahn", 250);
	unique_ptr<Weg> innerort = make_unique<Weg>("Innerort", 250, Innerorts);

	unique_ptr<Fahrzeug> fahrzeug = make_unique<PKW>("PKW1", 123.35, 13.37);
	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<PKW>("PKW2", 155.37, 15.55, 62.37);
	unique_ptr<Fahrzeug> fahrzeug3 = make_unique<PKW>("PKW3", 133.39, 12.22);
	unique_ptr<Fahrzeug> fahrzeug4 = make_unique<PKW>("PKW4", 188.32, 16.37);

	unique_ptr<Fahrzeug> fahrzeug5 = make_unique<Fahrrad>("Fahrrad1", 30.33);
	unique_ptr<Fahrzeug> fahrzeug6 = make_unique<Fahrrad>("Fahrrad2", 25.35);


	//Wege akzeptieren die Fahrzeuge.
	cout << endl;
	autobahn->vAnnahme(std::move(fahrzeug));
	autobahn->vAnnahme(std::move(fahrzeug2),2);
	autobahn->vAnnahme(std::move(fahrzeug5));

	innerort->vAnnahme(std::move(fahrzeug3));
	innerort->vAnnahme(std::move(fahrzeug4),3);
	innerort->vAnnahme(std::move(fahrzeug6));



	// In jeder x.x Stunden werden die Tänke der PKWs aufgefüllt.
	double dTankZeit = 0.0;
	cout << endl << "Bitte geben Sie eine Period für Tanken der PKWs: ";
	cin >> dTankZeit;

	// Wie lange eine Simulationsschritt dauert? -> dEpsilon
	double dEpsilon = 0.0; // Zeittakt.
	cout << endl << "Bitte geben Sie eine Period für die Simulation(lieber als Bruchteile von Studen): ";
	cin >> dEpsilon;

	// Gibt die Eigenschaften der Objekte aufm Bildschrim formatiert aus.
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dEpsilon; dGlobaleZeit < 5; dGlobaleZeit += dEpsilon){
		for(const auto& fahrzeug : *autobahn->getFahrzeugList()){
			//Gibt die Fahrzeuge aus.
			cout << *fahrzeug;

			//Kontrolliere ob die TankZeit gekommen ist.
			if(fmod(dGlobaleZeit,dTankZeit) < dEpsilon){
				fahrzeug->dTanken(fahrzeug->getTankvolumen());
			}
		}
		//Simuliere den Weg.
		autobahn->vSimulieren();
	}
	dGlobaleZeit = 0;

	// Gibt die Eigenschaften der Objekte aufm Bildschrim formatiert aus.
	cout << "\n\nAutobahn wurde Simuliert. Nun wird der Innerort simuliert." << endl;
	Fahrzeug::vKopf();
	for(dGlobaleZeit = dEpsilon; dGlobaleZeit < 5; dGlobaleZeit += dEpsilon){
		for(const auto& fahrzeug : *innerort->getFahrzeugList()){
			//Gibt die Fahrzeuge aus.
			cout << *fahrzeug;

			//Kontrolliere ob die TankZeit gekommen ist.
			if(fmod(dGlobaleZeit,dTankZeit) < dEpsilon){
				fahrzeug->dTanken(fahrzeug->getTankvolumen());
			}
		}
		//Simuliere den Weg.
		innerort->vSimulieren();
	}
}

//void vAufgabe_6(){
//
//	//Dynamisches Erzeugen der Elementen
//	unique_ptr<Weg> autobahn = make_unique<Weg>("Autobahn", 500.0);
//	unique_ptr<Weg> innerort = make_unique<Weg>("Innerort", 500.0, Innerorts);
//
//	unique_ptr<Fahrzeug> fahrzeug = make_unique<PKW>("PKW1", 123.35, 13.37);
//	unique_ptr<Fahrzeug> fahrzeug2 = make_unique<PKW>("PKW2", 155.37, 15.55, 62.37);
//	unique_ptr<Fahrzeug> fahrzeug3 = make_unique<PKW>("PKW3", 133.39, 12.22);
//	unique_ptr<Fahrzeug> fahrzeug4 = make_unique<PKW>("PKW4", 188.32, 16.37);
//
//	unique_ptr<Fahrzeug> fahrzeug5 = make_unique<Fahrrad>("Fahrrad1", 30.33);
//	unique_ptr<Fahrzeug> fahrzeug6 = make_unique<Fahrrad>("Fahrrad2", 25.35);
//
//	// Intialisierung der Grafik auf dem SimuServer
//	bInitialisiereGrafik(800, 500);
//
//	// Setzen der Koordinaten für die Straße, gerade Linie
//	int koordinaten[4] = { 700, 250, 100, 250 };
//
//	// Zeichnen der Straße
//	bZeichneStrasse(autobahn->getName(), innerort->getName(), autobahn->getLaenge(), 2, koordinaten);
//
//
//	//Annehmen der Fahrzeuge in die Wege.
//	cout << endl;
//	autobahn->vAnnahme(std::move(fahrzeug));
//	autobahn->vAnnahme(std::move(fahrzeug2),2);
//	autobahn->vAnnahme(std::move(fahrzeug5));
//
//	innerort->vAnnahme(std::move(fahrzeug3));
//	innerort->vAnnahme(std::move(fahrzeug4),1.5);
//	innerort->vAnnahme(std::move(fahrzeug6));
//
//
//
//	// In jeder x.x Stunden werden die Tänke der PKWs aufgefüllt.
//	double dTankZeit = 0.0;
//	cout << endl << "Bitte geben Sie eine Period für Tanken der PKWs: ";
//	cin >> dTankZeit;
//
//	// Wie lange eine Simulationsschritt dauert? -> dEpsilon
//	double dEpsilon = 0.0; // Zeittakt.
//	cout << endl << "Bitte geben Sie eine Period für die Simulation(lieber als Bruchteile von Studen): ";
//	cin >> dEpsilon;
//
//	// Gibt die Eigenschaften der Objekte aufm Bildschrim formatiert aus.
//	Fahrzeug::vKopf();
//	for(dGlobaleZeit = dEpsilon; dGlobaleZeit < 4; dGlobaleZeit += dEpsilon){
//		vSetzeZeit(dGlobaleZeit);
//
//		//Printen des Autobahns
//		for(const auto& fahrzeug : autobahn->getFahrzeugList()){
//
//			//Gibt die Eigenschaften der Fahrzeuge aus.
//			cout << *fahrzeug;
//
//			//Kontrolliere ob die TankZeit gekommen ist.
//			if(fmod(dGlobaleZeit,dTankZeit) < dEpsilon){
//				fahrzeug->dTanken(fahrzeug->getTankvolumen());
//			}
//		}
//
//		//Printen des Innerorts
//		for(const auto& fahrzeug : innerort->getFahrzeugList()){
//
//			//Gibt die Eigensschaften der Fahrzeuge aus.
//			cout << *fahrzeug;
//
//
//			//Kontrolliere ob die TankZeit gekommen ist.
//			if(fmod(dGlobaleZeit,dTankZeit) < dEpsilon){
//				fahrzeug->dTanken(fahrzeug->getTankvolumen());
//			}
//		}
//
//		innerort->vSimulieren();
//		autobahn->vSimulieren();
//		vSleep(100);
//	}
//	vBeendeGrafik();
//}

void vAufgabe_6a(){

	//Wir mochten namespace vertagt benutzen, da alle Angaben unter diesem Name definiert wurden.
	using namespace vertagt;

	//Erstellen eine Liste vom Typ VListe
	VListe<int> VListe;

	//Zur Erstellung einer zufaelligen Zahl
	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);

	//Zahlen in die Liste eingeben.
	cout << "Zahlen werden in die Liste eingetragen.:\n\n";
	for(int i = 1; i < 10; i++){
		VListe.push_back(dist(device));
	}

	//Zahlen ausgeben
	cout << "Liste vor dem Aktualisieren:\n";
	for(auto it = VListe.begin(); it != VListe.end(); it++) {
		std::cout << (*it) << " ";
	}

	//Liste soll aktualisiert wernde, sonst konnten die Zahlen in die Liste nicht rein.
	cout << "\nListe wurde aktualisiert.\n\n";
	VListe.vAktualisieren();

	//Ausgeben nach dem Aktualisieren, soll sich gaeendert worden sein.
	cout << "Liste nach dem aktualiseren:\n";
	for(auto it = VListe.begin(); it != VListe.end(); it++) {
		std::cout << (*it) << " ";
	}

	//Loeschen der Elementen grosser als 5 sind.
	for(auto it = VListe.begin(); it != VListe.end(); it++) {
		if((*it) > 5) {
			VListe.erase(it);
		}
	}

	cout << "\n\nElemente groeßer als 5 wurden geloescht aber nicht aktualisiert..\n";
	cout << "Liste:\n";
	// Ausgabe sollte die gleiche sein, da vAktualisieren noch nicht durchgeführt wurde
	for(auto it = VListe.begin(); it != VListe.end(); it++) {
		std::cout << (*it) << " ";
	}

	VListe.vAktualisieren();

	cout << "\n\nListe wurde aktualisiert. Liste:\n";
	//Ausgeben nach dem Aktualisieren, soll sich gaeendert worden sein.
	for(auto it = VListe.begin(); it != VListe.end(); it++) {
		cout << (*it) << " ";
	}

	//Eingeben in die Liste zwei mehr zufaellige Zahlen
	VListe.push_back(dist(device));
	VListe.push_front(dist(device));

	cout << "\n\nEine Zahl vorne und eine Zahl hinter werden hinzugefuegt.\n";
	cout << "Vor dem aktualiseren:\n";
	for(auto it = VListe.begin(); it != VListe.end(); it++) {
		cout << (*it) << " ";
	}

	//Liste soll aktualisiert werden.
	VListe.vAktualisieren();

	cout << "\n\nNach dem aktualisieren. Liste:\n";
	// Ausgabe sollte sich geändert haben
	for(auto it = VListe.begin(); it != VListe.end(); it++) {
		std::cout << (*it) << " ";
	}


}

