/*
 * Rechtangle.h
 *
 *  Created on: 29.11.2023
 *      Author: kyotun
 */

#ifndef RECHTANGLE_H_
#define RECHTANGLE_H_

#include <iostream>
#include "Shape.h"
using namespace std;

class Rechtangle : public Shape
{
public:
	Rechtangle() = default;
	~Rechtangle() = default;
	int Area() override;

protected:
private:
};
#endif /* RECHTANGLE_H_ */
