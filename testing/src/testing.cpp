//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Shape
{
	protected:
		double p_x = 0.0;
		double p_y = 0.0;
	public:
		Shape() = default;
		Shape(double x, double y)
		{
			this->p_x = x;
			this->p_y = y;
		}
		double area() const {
			return 0.0;
		}

};

class Box : public Shape{

	private:
		double p_w = 0.0;
		double p_h = 0.0;

	public:
		Box() = default;
		Box(double x, double y, double w, double h)
		{
			Shape(x,y);
			this-> p_w = w;
			this-> p_h = h;
		}
		double area() const
		{
			return p_w * p_h;
		}


};

class Line : public Shape {
	private:
    	double p_end_x = 0.0;
    	double p_end_y = 0.0;

    public:
		Line() = default;
		Line(double x, double y, double end_x, double end_y)
		{
			Shape(x, y);
			this-> p_end_x = end_x;
			this-> p_end_y = end_y;
		}
};

int main()
{
	Box box(10.0, 10.0, 6.0, 7.0);
	Line line(10.0, 10.0, 30.0, 30.0);

	cout << "Box area:\t" << box.area() << endl << endl;
	cout << "Line area:\t" << line.area() << endl << endl;

	return 0;

}
