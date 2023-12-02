/*
 * Station.cpp
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */

#ifndef TRAIN_STATION_STATION_CPP_
#define TRAIN_STATION_STATION_CPP_


#include "Station.h"

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

Station::Station(string station)
{
	this->p_sName = station;
}

string Station::getName() const
{
	return p_sName;
}

shared_ptr<Station> Station::getDestination() const
{
	return p_pDestination;
}

void Station::vSetDestination(shared_ptr<Station> destination)
{
	this->p_pDestination = destination;
}

void Station::vAddNeighbor(shared_ptr<Station> neighbor){
	p_pNeighbors.push_back(neighbor);
}

void Station::vPrintNeighbors() const{
	cout << "Neighbors of " << getName() << ": ";
	for (const auto& neighbor : p_pNeighbors){
		cout << neighbor->getName() << ' ';
	}
	cout << endl << endl;
}

bool Station::isNeighbor(shared_ptr<Station> gefragte_station) const{
	for(const auto& station : p_pNeighbors){
		if(station == gefragte_station){
			return true;
		}
	}
	return false;
}



#endif /* TRAIN_STATION_STATION_CPP_ */
