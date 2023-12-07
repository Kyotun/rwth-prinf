/*
 * Tempolimit.h
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */
#include <limits>
#include <iostream>

#ifndef TEMPOLIMIT_H_
#define TEMPOLIMIT_H_

//Vorhandene Tempolimits fuer unterschiedliche Wegtypen.
enum Tempolimit{
		Innerorts=50,
		Landstrasse=100,
		Autobahn=std::numeric_limits<int>::max()
	};



#endif /* TEMPOLIMIT_H_ */
