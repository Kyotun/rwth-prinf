/*
 * main.cpp
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#include "Station.h"
#include "Train.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "TrainException.h"

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <iterator>

using namespace std;

int main(){
	try{
		std::unique_ptr<PassengerTrain> aTrain;
		aTrain =  std::make_unique<PassengerTrain>();

		auto bTrain = std::make_unique<FreightTrain>(2, "tons of wood");

		std::cout << std::endl << "Eigenschaften 'aTrain':" << std::endl;
		std::cout << *aTrain;

		std::cout << std::endl << "Eigenschaften 'bTrain':" << std::endl;
		std::cout << *bTrain;

		// alter Test: gleiches Verhalten wie in 04_smartpointer
		/*
		auto berlin = std::make_shared<Station>("Berlin");
		auto hamburg = std::make_shared<Station>("Hamburg");
		auto frankfurt = std::make_shared<Station>("Frankfurt");

		berlin->vAddNeighbor(hamburg);
		hamburg->vAddNeighbor(berlin);

		aTrain->vGoTo(berlin);
		aTrain->vGoTo(hamburg);
		aTrain->vGoTo(frankfurt);
		*/

		// neu: Strecken"netz"
		auto berlin = std::make_shared<Station>("Berlin");
		auto hamburg = std::make_shared<Station>("Hamburg");
		auto frankfurt = std::make_shared<Station>("Frankfurt");
		auto koeln = std::make_shared<Station>("Koeln");
		auto muenchen = std::make_shared<Station>("Muenchen");

		berlin->vAddNeighbor(hamburg);
		berlin->vAddNeighbor(frankfurt);

		hamburg->vAddNeighbor(berlin);
		hamburg->vAddNeighbor(koeln);

		// Strecke nur in eine Richtung
		koeln->vAddNeighbor(frankfurt);

		frankfurt->vAddNeighbor(koeln);
		frankfurt->vAddNeighbor(berlin);
		frankfurt->vAddNeighbor(muenchen);

		muenchen->vAddNeighbor(frankfurt);

		// Zeige Liste der bekannten Nachbarn
		berlin->vPrintNeighbors();
		hamburg->vPrintNeighbors();
		koeln->vPrintNeighbors();
		frankfurt->vPrintNeighbors();
		muenchen->vPrintNeighbors();




		std::cout<< "\n\n\nZuege fahren lassen: \n\n";

		try{aTrain->vGoTo(berlin); }
		catch(TrainException &e) { e.vExplain();}

		try{aTrain->vGoTo(hamburg); }
		catch(TrainException &e) { e.vExplain();}

		try{aTrain->vGoTo(frankfurt); }
		catch(TrainException &e) { e.vExplain();}

		try{aTrain->vGoTo(koeln); }
		catch(TrainException &e) { e.vExplain();}

		try{aTrain->vGoTo(frankfurt); }
		catch(TrainException &e) { e.vExplain();}

		try{aTrain->vGoTo(hamburg); }
		catch(TrainException &e) { e.vExplain();}

		try{aTrain->vGoTo(berlin); }
		catch(TrainException &e) { e.vExplain();}
	}
	catch(const TrainException &e){
		e.vExplain();
	}
	return 0;
}



