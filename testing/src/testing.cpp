//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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

class Train
{
    private:
        static inline int p_iIDCounter = 0;
        const int p_iID = p_iIDCounter++;
        shared_ptr<Station> p_pIsAt = nullptr;

    protected:
        float p_fDelay = 0;

    public:
        Train() = default;
        Train(int speed, bool electric);
        virtual ~Train() = default;

        virtual void vPrintProperties(ostream& ausgabe) const;
        void vGoTo(shared_ptr<Station> to);

};

void Train::vPrintProperties(ostream& ausgabe) const
{
	ausgabe << "ID: " << p_iID << endl;
	ausgabe << "momentane Verspeatung: " << p_fDelay << " Minuten" << endl;
}

void Train::vGoTo(shared_ptr<Station> to)
{
	if(p_pIsAt==nullptr)
	{
		p_pIsAt = to;
		cout << "Zug wurde auf " << p_pIsAt->getName() << " gesetzt." << endl;
	}
	else if((p_pIsAt->getDestination())->getName() == to->getName())
	{
		p_pIsAt = to;
		cout << "Zug ist nach " << p_pIsAt->getName() << " gefahren." << endl;
	}
	else
	{
		cout << "Der Zug kann nicht nach " << to->getName() << " fahren, das es keine Verbindung gibt." << endl;
	}
}

class PassengerTrain : public Train
{
    public:
        PassengerTrain() = default;
        PassengerTrain(int p_iPassengerCounter);
        virtual ~PassengerTrain() = default;

        void vPrintProperties(ostream& ausgabe) const;
        float fStation(int passengersIn, int passengersOut);

    private:
        int p_iPassengerCounter = 0;

};

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

class FreightTrain : public Train
{
    private:
        float p_fChargeQuantity = 0.0;
        string p_sChargeType;

    public:
        FreightTrain() = default;
        FreightTrain(float chargeQuantity, string chargeType);
        virtual ~FreightTrain() = default;

        void vPrintProperties(ostream& ausgabe) const;
        void vLoadCharge(float amount);
};

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

#define OPERATOR operator<<

std::ostream & OPERATOR(std::ostream& out, const Train& train)
{
    train.vPrintProperties(out);
    return out;
}

#undef OPERATOR


int main()
{
	std::unique_ptr<PassengerTrain> aTrain;
	aTrain =  std::make_unique<PassengerTrain>();

	auto bTrain = std::make_unique<FreightTrain>(2, "tons of wood");

	std::cout << std::endl << "Eigenschaften 'aTrain':" << std::endl;
	std::cout << *aTrain;

	std::cout << std::endl << "Eigenschaften 'bTrain':" << std::endl;
	std::cout << *bTrain << std::endl;


	    auto berlin = std::make_shared<Station>("Berlin");
	    auto hamburg = std::make_shared<Station>("Hamburg");
	    auto frankfurt = std::make_shared<Station>("Frankfurt");
	    auto koeln = std::make_shared<Station>("Köln");
	    auto muenchen = std::make_shared<Station>("München");

	//rudimentäre Linie aufbauen (die bekannte Ringbahn Hamburg-Hamburg)
	hamburg->vSetDestination(koeln);
	koeln->vSetDestination(frankfurt);
	frankfurt->vSetDestination(berlin);
	berlin->vSetDestination(hamburg);

	std::cout << "Guten Tag meine Damen und Herren, herzlich willkommen im Zug der Deutschen Bahn von Hamburg nach Hamburg über Köln Hbf, Frankfurt Hbf und Berlin Gesundbrunnen!" << std::endl;
	std::cout << std::endl;
	std::cout << "Sehr geehrte Fahrgäste, in wenigen Minuten erreichen wir Köln Hauptbahnhof. Wir verabschieden uns von allen Fahrgästen, die dort aus- und umsteigen und wünschen eine angenehme Weiterreise. Bitte denken Sie beim Aussteigen daran, Ihre persönlichen Wertgegenstände mitzunehmen. Vielen Dank!" << std::endl;
	aTrain->vGoTo(koeln);
	std::cout << std::endl;
	aTrain->vGoTo(muenchen); //Sollte nicht funktionieren, nicht Teil der Ringbahn
	std::cout << std::endl;
	std::cout << "Sehr geehrte Fahrgäste, in wenigen Minuten erreichen wir Frankfurt Hauptbahnhof. Wir verabschieden uns von allen Fahrgästen, die dort aus- und umsteigen und wünschen eine angenehme Weiterreise. Bitte denken Sie beim Aussteigen daran, Ihre persönlichen Wertgegenstände mitzunehmen. Vielen Dank!" << std::endl;
	aTrain->vGoTo(frankfurt);
	std::cout << std::endl;
	std::cout << "Sehr geehrte Fahrgäste, in wenigen Minuten erreichen wir Berlin Gesundbrunnen. Wir verabschieden uns von allen Fahrgästen, die dort aus- und umsteigen und wünschen eine angenehme Weiterreise. Bitte denken Sie beim Aussteigen daran, Ihre persönlichen Wertgegenstände mitzunehmen. Vielen Dank!" << std::endl;
	aTrain->vGoTo(berlin);
	std::cout << std::endl;
	std::cout << "Sehr geehrte Fahrgäste, in wenigen Minuten erreichen wir Hamburg Hauptbahnhof. Unsere Fahrt endet dort, wir bitten alle Fahrgäste, auszusteigen." << std::endl;
	aTrain->vGoTo(hamburg);
	std::cout << "Wir bedanken uns für Ihre Reise mit der Deutschen Bahn." << std::endl;

	return 0;
}
