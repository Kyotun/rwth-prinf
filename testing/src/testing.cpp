//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

class Train
{
	protected:
		float p_fDelay = 0.0;
	private:
		static inline int p_iIDCounter = 0;
		const int p_iID = p_iIDCounter;

	public:
		Train() = default;
		Train(int speed, bool electric);
		virtual ~Train() = default;

		virtual void vPrintProperties(std::ostream& ausgabe) const;

};

void Train::vPrintProperties(std::ostream& ausgabe) const
{
	cout << "ID: " << p_iID << endl;
	cout << "Momentane Verspeatung: " << setprecision(3) << p_fDelay << " Minuten" << endl;
}


class PassengerTrain : public Train
{
	private:
		int p_iPassengerCounter = 0;
	public:
		PassengerTrain() = default;
		PassengerTrain(int passengers);
		virtual ~PassengerTrain() = default;

		float fStation(int passengersIn, int passengersOut);
		float getVerspeatung();
		void vPrintProperties(std::ostream& ausgabe) const;
};

PassengerTrain::PassengerTrain(int passengers)
{
	cout << "Aufruf des Nicht-Standardkonstruktors(PassengerTrain)" << endl;
	this->p_iPassengerCounter = passengers;
}

float PassengerTrain::fStation(int passengersIn, int passengersOut)
{
	if(p_iPassengerCounter < passengersOut){
		cout << "Es koennen nicht mehr Personen aussteigen als sich im Zug befinden" << endl;
		return 0;
	}

	p_iPassengerCounter = p_iPassengerCounter + passengersIn - passengersOut;

	float secondsChange = 120 - passengersIn*10 - passengersOut*5;
	p_fDelay = (p_fDelay - secondsChange < 0)? 0: (p_fDelay - secondsChange)/60;

	return secondsChange/60;
}

void PassengerTrain::vPrintProperties(std::ostream& ausgabe) const
{
	Train::vPrintProperties(ausgabe);
	cout << "Anzahl der Passegiere: " << p_iPassengerCounter << endl;
}

float PassengerTrain::getVerspeatung()
{
	return p_fDelay;
}

class FreightTrain : public Train
{
	private:
		float p_fChargeQuantity = 0.0;
		string p_sChargeType = "default";

	public:
		FreightTrain() = default;
		FreightTrain(float chargeQuantity, string chargeType);
		virtual ~FreightTrain() = default;

		float fStation(int aufladendeGueter, int abzuladendeGueter);
		void vPrintProperties(std::ostream& ausgabe) const;
		void vLoadCharge(float amount);

};

FreightTrain::FreightTrain(float chargeQuantity, string chargeType)
{
	this->p_fChargeQuantity = chargeQuantity;
	this->p_sChargeType = chargeType;
}

void FreightTrain::vPrintProperties(std::ostream& ausgabe) const
{
	Train::vPrintProperties(ausgabe);
	cout << "Ladung: " << p_fChargeQuantity << " " << p_sChargeType << endl;
}

void FreightTrain::vLoadCharge(float amount)
{
	if(amount + p_fChargeQuantity < 0){
		cout << "Es kann nicht mehr abgeladen werden" << endl;
		return;
	}

	cout << "Charge Quantity war: " << p_fChargeQuantity << endl;

	p_fChargeQuantity += amount;

	if(amount < 0){
		cout << "Eine Menge von " << -amount << "  abgeladen." << endl;
		cout << "Momentane Ladung: " << p_fChargeQuantity << endl;
	}else if(amount == 0){
		cout << "Keine Auf-/Abladung." << endl;
	}else {
		cout << "Eine Menge von " << amount << " aufgeladen." << endl;
		cout << "Momentane Ladung: " << p_fChargeQuantity << endl;
	}
}

std::ostream & operator<<(std::ostream& out, Train& train)
{
	train.vPrintProperties(out);
	return out;
}

int main()
{
	PassengerTrain pt = PassengerTrain(30);
	FreightTrain ft = FreightTrain(15, "Kisten Schokolade");

	cout << endl << "Eigenschaften PT: " << endl;
	cout << pt;
	cout << endl << "10 Passagiere steigen ein und 5 Passagiere steigen ab." << endl;
	pt.fStation(20,5);
	cout << "Totale Verpseatung dafür: " << setprecision(2) << pt.getVerspeatung() << " Minuten." << endl;

	cout << endl << "Eigenschaften FT: " << endl;
	cout << ft;
	cout << endl << "Batterie Zustand des FT nach 10 Kisten Schokolade"
			"ablageden wurden: " << endl;
	ft.vLoadCharge(-10);
	cout << endl << "Batterie Zustand des FT nach 32 Kisten Schokolade "
			"auflageden wurden: " << endl;
	ft.vLoadCharge(32);



	return 0;

}
