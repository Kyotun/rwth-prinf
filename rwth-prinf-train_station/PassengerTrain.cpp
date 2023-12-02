/*
 * PassengerTrain.cpp
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */


#include "PassengerTrain.h"
#include "Train.h"

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

PassengerTrain::PassengerTrain(int passenger)
{
	this->p_iPassengerCounter = passenger;
	cout << "Aufruf des Nicht-Standardkonstruktors, Passenger" << endl;
}

void PassengerTrain::vPrintProperties(ostream& ausgabe) const
{
	Train::vPrintProperties(ausgabe);
	ausgabe << "Anzahl Passagiere: " << p_iPassengerCounter << endl;
}

float PassengerTrain::fStation(int passengersIn, int passengersOut)
{
	if (p_iPassengerCounter < passengersOut)
	{
		cout << "Es koennen nicht mehr Personen aussteigen als sich im Zug befinden" << endl;
		return 0;
	}

	p_iPassengerCounter = p_iPassengerCounter + passengersIn - passengersOut;

	float secondsChange = 120 - passengersIn * 10 - passengersOut * 5;
	return secondsChange/60;
}
