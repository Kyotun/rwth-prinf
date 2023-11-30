/*
 * Shape.h
 *
 *  Created on: 29.11.2023
 *      Author: kyotun
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
using namespace std;

class Shape
{
public:

	Shape();
	~Shape();

	virtual int Area(){return 0;};
//	virtual void Area() = 0;


	void setWidth(int dWidth);
	void setHeight(int dHeight);

	double getWidth(){return p_dWidth;};
	double getHeight(){return p_dHeight;};

	friend void vAddHeight(Shape& shape, double dMenge);

protected:
	double p_dHeight = 0.0;
	double p_dWidth = 0.0;

private:

};


#endif /* SHAPE_H_ */
