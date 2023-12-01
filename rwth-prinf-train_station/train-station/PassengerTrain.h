/*
 * PassengerTrain.h
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */

#ifndef TRAIN_STATION_PASSENGERTRAIN_H_
#define TRAIN_STATION_PASSENGERTRAIN_H_

#include "Train.h"

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

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

#endif /* TRAIN_STATION_PASSENGERTRAIN_H_ */
