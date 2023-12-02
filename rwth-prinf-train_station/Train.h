/*
 * Train.h
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */

#ifndef TRAIN_STATION_TRAIN_H_
#define TRAIN_STATION_TRAIN_H_

#include "Station.h"

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Train
{
    private:
        static inline int p_iIDCounter = 0;
        shared_ptr<Station> p_pIsAt = nullptr;
        const int p_iID = p_iIDCounter++;

    protected:
        float p_fDelay = 0;

    public:
        Train() = default;
        virtual ~Train() = default;

        virtual void vPrintProperties(ostream& ausgabe) const;
        void vGoTo(shared_ptr<Station> to);

};



ostream & operator<<(ostream& out, const Train& train);


#endif /* TRAIN_STATION_TRAIN_H_ */
