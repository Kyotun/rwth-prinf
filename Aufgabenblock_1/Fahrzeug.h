/*
 * Fahrzeug.h
 *
 *  Created on: 10.11.2023
 *      Author: kyotun
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <string>
using namespace std;

class Fahrzeug {
public:
	Fahrzeug();
	Fahrzeug(string p_sName);
	Fahrzeug(string p_sName, int p_iID);
	virtual ~Fahrzeug();
	string getName(){return p_sName;};
private:
	string p_sName = "";
	const int p_iID = 0;
	int p_iMaxID;
};
#endif /* FAHRZEUG_H_ */

