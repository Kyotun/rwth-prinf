//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Train
{
	private:
		int p_iPassengerCounter = 0;
		float p_fDelay = 0;
		static inline int p_iIDcounter = 0; // Wie funktioniert diese Zeile?
		const int p_iID = p_iIDcounter++; // Wie funktioniert diese Zeile?

	public:
		Train() = default;
		Train(int passengers);
		virtual ~Train() = default;

		static int getTotaleID()
		{
			return p_iIDcounter;
		}
		int getID();
		void vPrintProperties() const;
		float fStation(int passengersIn, int passengersOut);
};

Train::Train(int passengerCounter)
{
	cout << "Ein neuer Train Objekt mit Passengercounter wurde erzeugt" << endl;
	this->p_iPassengerCounter = passengerCounter;
}


int Train::getID()
{
	return p_iID;
}
void Train::vPrintProperties() const
{
	cout << "Passenger counter: " << p_iPassengerCounter << endl;
	cout << "Delay: " << p_fDelay << " Minuten" << endl;
	cout << "Totale ID's: " << p_iIDcounter << endl;
	cout << "ID: " << p_iID << endl;
}

float Train::fStation(int passengersIn, int passengersOut)
{
	int personen_zahl = p_iPassengerCounter + passengersIn - passengersOut;
	if(personen_zahl < 0)
	{
		return 0;
	}else
	{
		p_iPassengerCounter = p_iPassengerCounter + passengersIn - passengersOut;
		float verbringte_Zeit = 120 - passengersIn*10 + passengersOut*5;
		p_fDelay = (p_fDelay - verbringte_Zeit < 0) ? 0 : (p_fDelay - verbringte_Zeit)/60;
		return p_fDelay;
	}
}

int main()
{
	Train objekt_standard;
	cout << "Totale ID's: " << Train::getTotaleID() << endl;
	cout << "Totale ID's mit einem Objekt: " << objekt_standard.getTotaleID() << endl << endl;
	Train objekt_mit_counter(10);
	cout << "Train mit counter:" << endl;
	objekt_mit_counter.vPrintProperties();
	cout << endl;

	cout << "Standard Train" << endl;
	objekt_standard.vPrintProperties();
	cout << endl;

	objekt_mit_counter.fStation(15, 10);
	cout << "Train mit counter:" << endl;
	objekt_mit_counter.vPrintProperties();
	cout << endl;

	objekt_standard.fStation(3,12);
	cout << "Standard Train" << endl;
	objekt_standard.vPrintProperties();
	cout << endl;

	return 0;

}
