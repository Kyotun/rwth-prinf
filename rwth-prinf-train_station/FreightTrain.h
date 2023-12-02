/*
 * FreightTrain.h
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */

#ifndef TRAIN_STATION_FREIGHTTRAIN_H_
#define TRAIN_STATION_FREIGHTTRAIN_H_

#include "Train.h"

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

class FreightTrain : public Train
{
    private:
        float p_fChargeQuantity = 0.0;
        string p_sChargeType;

    public:
        FreightTrain() = default;
        FreightTrain(float chargeQuantity, string chargeType);
        virtual ~FreightTrain() = default;

        void vPrintProperties(ostream& ausgabe) const override;
        void vLoadCharge(float amount);
};


#endif /* TRAIN_STATION_FREIGHTTRAIN_H_ */
