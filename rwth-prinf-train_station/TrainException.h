/*
 * TrainException.h
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */

#ifndef TRAINEXCEPTION_H_
#define TRAINEXCEPTION_H_

#include "Station.h"

#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

class TrainException : public exception
{
private:
	shared_ptr<Station> p_pDestination;
public:
	TrainException(shared_ptr<Station> destination);
	virtual ~TrainException() = default;

	void vExplain() const;

	shared_ptr<Station> getDestination() const{return p_pDestination;};

};



#endif /* TRAINEXCEPTION_H_ */
