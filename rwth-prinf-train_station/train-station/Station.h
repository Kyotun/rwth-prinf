/*
 * Station.h
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */

#ifndef TRAIN_STATION_STATION_H_
#define TRAIN_STATION_STATION_H_

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Station
{
private:
	string p_sName;
	shared_ptr<Station> p_pDestination;

public:
	Station(string station);

	void vSetDestination(shared_ptr<Station> destination);
	string getName() const;
	shared_ptr<Station> getDestination() const;
};

#endif /* TRAIN_STATION_STATION_H_ */
