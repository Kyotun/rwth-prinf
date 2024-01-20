/*
 * Simulation.h
 *
 *  Created on: 20.01.2024
 *      Author: kyotun
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <string>

using namespace std;

class Simulation{
public:
	void vSimulieren();
	void vEinlesen(istream& is, bool bMitGrafik=false);
};



#endif /* SIMULATION_H_ */
