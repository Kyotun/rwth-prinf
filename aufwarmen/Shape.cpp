/*
 * Shape.cpp
 *
 *  Created on: 29.11.2023
 *      Author: kyotun
 */

#include <iostream>
#include "Shape.h"
using namespace std;

Shape::Shape(){
	cout << "Shape Objekt wurde erzeugt." << endl;
}

Shape::~Shape(){
	cout << "Shape Objekt wurde geloescht." << endl;
}

void Shape::setHeight(int dHeight){
	this->p_dHeight = dHeight;
}

void Shape::setWidth(int dWidth){
	this->p_dWidth = dWidth;
}

/*
int Shape::Area(){
	return 0;
}*/



