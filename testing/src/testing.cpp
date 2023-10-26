//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Base
{
	private:
		double p_x = 0.0;
		double p_y = 0.0;
	public:
		virtual void method() const;
		virtual void method_zwei() const;
		void method_drei();
		void method_vier() const;
		virtual ~Base() = default;

};

void Base::method() const
{
	cout << "Base" << endl;
}

void Base::method_zwei() const
{
	cout << "Base_zwei" << endl;
}

void Base::method_drei()
{
	cout << "Base_drei" << endl;
}

void Base::method_vier() const
{
	cout << "Base_vier" << endl;
}
class Derived : public Base
{
	private:
		double p_x = 0.0;
		double p_y = 0.0;
	public:
		void method() const;
		void method_zwei();
		void method_drei();
		void method_vier() const;
};

void Derived::method() const
{
	cout << "Derived" << endl;
}

void Derived::method_zwei(){
	cout << "Derived_zwei" << endl;
}

void Derived::method_drei()
{
	cout << "Derived_drei" << endl;
}

void Derived::method_vier() const
{
	cout << "Derived_vier" << endl;

}

int main()
{
	Derived d;
	Base& base = d;
	base.method();
	base.method_zwei();
	base.method_drei();
	base.method_vier();

	return 0;

}
