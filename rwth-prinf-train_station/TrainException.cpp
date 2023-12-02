/*
 * TrainException.cpp
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */


#include "TrainException.h"
#include "Station.h"

#include <exception>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

TrainException::TrainException(shared_ptr<Station> destination): p_pDestination(destination){}

void TrainException::vExplain() const{
	cout << "Der Zug kann nicht nach " << p_pDestination->getName() << " fahren: Es gibt keine Verbindung" << endl;
}

