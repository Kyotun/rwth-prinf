/*
 * Weg.h
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#include <iostream>
#include <list>
#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include "Fahrzeug.h"

#ifndef WEG_H_
#define WEG_H_

class Fahrzeug;

using namespace std;
extern double dGlobaleZeit;


class Weg : public Simulationsobjekt{
public:
	Weg(string p_sName, double p_dLaenge, Tempolimit p_eTempolimit= Tempolimit::Autobahn);

	//Getters
	double getTempolimit() const;
	double getLaenge() const{return p_dLaenge;};
	void getFahrzeuge() const;

	//Setters
	void setFahrzeug(unique_ptr<Fahrzeug> fahrzeug);
	void setFahrzeugList(list<unique_ptr<Fahrzeug>> fahrzeugList);

	//String

	//Void
	void vAusgeben() const override;
	void vAusgeben(ostream& ausgabes) const override;
	void static vKopf();
	void vAnnahme(unique_ptr<Fahrzeug> fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug>, double dStartZeitpunkt);

protected:
private:
	//Double
	double p_dLaenge = 0.0;
	list<unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;

};




#endif /* WEG_H_ */
