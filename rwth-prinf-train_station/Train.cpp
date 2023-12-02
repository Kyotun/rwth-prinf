/*
 * Train.cpp
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */

#include "Train.h"
#include "Station.h"

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;


void Train::vPrintProperties(ostream& ausgabe) const
{
	ausgabe << "ID: " << p_iID << endl;
	ausgabe << "momentane Verspeatung: " << p_fDelay << " Minuten" << endl;
}

void Train::vGoTo(shared_ptr<Station> to)
{
	if(p_pIsAt==nullptr || p_pIsAt->isNeighbor(to))
	{
		p_pIsAt = to;
		cout << "Zug ist nach " << p_pIsAt->getName() << " gefahren." << endl;
	} else{
		cout << "Der Zug kann nicht nach " << to->getName() << " fahren, das es keine Verbindung gibt." << endl;
	}
}


ostream & operator<<(ostream& out, const Train& train)
{
    train.vPrintProperties(out);
    return out;
}
