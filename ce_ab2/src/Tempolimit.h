/*
 * Tempolimit.h
 *
 *  Created on: 02.12.2023
 *      Author: kyotun
 */
#ifndef TEMPOLIMIT_H_
#define TEMPOLIMIT_H_

#include <limits>

// Vorhandene Tempolimits fuer unterschiedliche Wegtypen.
enum Tempolimit{
	Innerorts=50,
	Landstrasse=100,
	Autobahn=std::numeric_limits<int>::max()
};
#endif /* TEMPOLIMIT_H_ */
