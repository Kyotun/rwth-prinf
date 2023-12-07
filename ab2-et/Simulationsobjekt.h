/*
 * Simulationsobjekt.h
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_

#include <string>

using namespace std;

class Simulationsobjekt{
public:
	//Konstruktoren
	Simulationsobjekt();
	Simulationsobjekt(string p_sName);

	// Verbieten von Copy-Konstruktor
	Simulationsobjekt(const Simulationsobjekt&) = delete;

	//Destruktor
	virtual ~Simulationsobjekt();

	//Getters
	string getName() const{return p_sName;};
	double getZeit() const {return p_dZeit;};
	int getID() const {return p_iID;};


	//Setters
	void setName(string p_sName){ this->p_sName = p_sName;};
	void setZeit(double p_dZeit){this->p_dZeit = p_dZeit;};

	//Void
	virtual void vAusgeben() const;
	virtual void vAusgeben(ostream& ausgabe) const;
	virtual void vSimulieren() = 0;

	//Operatoren Überladen
	bool operator==(const Simulationsobjekt& andere);
	Simulationsobjekt& operator=(const Simulationsobjekt& other);

protected:
	//Strings
	string p_sName = "";

	//Integers
	const int p_iID = ++p_iMaxID;

	//Doubles
	double p_dZeit = 0.0;

private:
	// Inline = To be able to initialize
	// const != cause we want to increment ID value. Cannot assign the const to a const.
	static inline int p_iMaxID = 0;
};


ostream& operator<<(ostream& ausgabe,const Simulationsobjekt& simuobjekt);


#endif /* SIMULATIONSOBJEKT_H_ */
