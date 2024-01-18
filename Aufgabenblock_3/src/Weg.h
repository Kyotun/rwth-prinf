/*
 * Weg.h
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#include <iostream>
#include <list>
#include "Simulationsobjekt.h"
#include "vertagt_liste.h"
#include "Tempolimit.h"
#include "Fahrzeug.h"
#include "Kreuzung.h"

#ifndef WEG_H_
#define WEG_H_

class Fahrzeug;
class Kreuzung;

using namespace std;
using namespace vertagt;
extern double dGlobaleZeit;


class Weg : public Simulationsobjekt{
public:
	// Konstruktoren
	Weg(string sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);
	Weg(string sName, double dLaenge, weak_ptr<Kreuzung>pZielkreuzung ,Tempolimit eTempolimit= Tempolimit::Autobahn, bool bUeberholverbot = true);

	// Getters
	double getTempolimit() const;
	double getLaenge() const{return p_dLaenge;}
	double getSchranke()const{return this->p_dSchranke;}
	double getTempolimit(){return this->p_eTempolimit;}
	Tempolimit gettTempolimit();
	void getFahrzeuge() const;
	VListe<unique_ptr<Fahrzeug>>* getFahrzeugList(){return &p_pFahrzeuge;}
	shared_ptr<Weg> getRueckweg();
	shared_ptr<Kreuzung> getKreuzung() const;
	bool getUeberholverbot()const{return this->p_bUeberholverbot;}

	// Setters
	void setLaenge(double dLaenge){this->p_dLaenge = dLaenge;}
	void setFahrzeug(unique_ptr<Fahrzeug> fahrzeug);
	void setFahrzeugList(list<unique_ptr<Fahrzeug>> fahrzeugList);
	void setRueckweg(weak_ptr<Weg> pRueckweg){this->p_pRueckweg = pRueckweg;}
	void setUeberholverbot(bool bUeberholverbot){this->p_bUeberholverbot = bUeberholverbot;}
	void setSchranke(double dSchranke){this->p_dSchranke = dSchranke;}
	void setTempolimit(Tempolimit eTempolimit){this->p_eTempolimit = eTempolimit;}

	// Bools
	bool bIsLetzteFahrzeug(Fahrzeug& fahrzeug_gesucht);

	// Voids
	void vSimulieren() override;
	void vAusgeben() const override;
	void vAusgeben(ostream& ausgabes) const override;
	void static vKopf();
	void vAnnahme(unique_ptr<Fahrzeug> fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug>, double dStartZeitpunkt);

	// Pointers
	unique_ptr<Fahrzeug> pAbgabe(Fahrzeug& fahrzeug_gesucht);

protected:
private:
	double p_dLaenge = 0.0;
	VListe<unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;
	bool p_bUeberholverbot;
	double p_dSchranke;

	weak_ptr<Weg> p_pRueckweg;
	const weak_ptr<Kreuzung> p_pZielkreuzung;

};

ostream& operator<<(ostream& ausgabe,const Weg& weg);


#endif /* WEG_H_ */
