/*
 * FreightTrain.cpp
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */


#include "FreightTrain.h"
#include "Train.h"

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

FreightTrain::FreightTrain(float chargeQuantitiy, string chargeType)
{
	this->p_fChargeQuantity = chargeQuantitiy;
	this->p_sChargeType = chargeType;
}

void FreightTrain::vPrintProperties(ostream& ausgabe) const
{
	Train::vPrintProperties(ausgabe);
    ausgabe << "Ladung: " << p_fChargeQuantity << " " << p_sChargeType << std::endl;
}

void FreightTrain::vLoadCharge(float amount)
{
	if (p_fChargeQuantity + amount < 0)
	{
		cout << "Es kann nicht mehr abgeladen werden als geladen ist. Abbruch." << std::endl;
		return;
	}

	p_fChargeQuantity += amount;
	cout << "Es wurden " << amount << " " << p_sChargeType;

	if (amount > 0) {
		cout << " aufgeladen.";
	}
	else
	{
		cout << " abgeladen.";
	}
}
