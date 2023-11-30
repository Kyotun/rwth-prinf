
#include <iostream>
#include "Shape.h"
#include "Rechtangle.h"
#include "Triangle.h"

using namespace std;

int main(){

		//Example-1

		Shape shape{};
		Rechtangle rechtangle{};
		Rechtangle* recht_ptr = &rechtangle;
		Shape* shape_ptr = &rechtangle;

		recht_ptr = &shape;

		//Aufrufen von der Funktion Shape::Area()
		cout << shape_ptr->Area() << endl;

		//Aufrufen von der Funktion Rechtangle::Area()
		cout << recht_ptr->Area() << endl;




			//Example-2
//	shared_ptr<Rechtangle> shared_recht = make_shared<Rechtangle>();
//	shared_recht->setHeight(15);
//
//	cout << "Use count von shared_recht vor dem Erzeugen weak_ptr: " << shared_recht.use_count() << endl;
//	weak_ptr<Rechtangle> weak_recht = shared_recht;
//	cout << "Use count von shared_recht nach dem Erzeugen weak_ptr: " << shared_recht.use_count() << endl << endl;
//
//	cout << "Get Height mit shared ptr: " << shared_recht->getHeight() << endl;
//	cout << "Get Height mit weak ptr: " << weak_recht->getHeight() << endl;
//	cout << "Benutzung von .lock Funktion auf weak_recht: " << weak_recht.lock() << endl;
//	cout << "Adresse von shared_recht: " << shared_recht << endl;
//	auto kopie_shared = weak_recht.lock();
//	cout << "Get Height durch weak_ptrs lock Funktion: " << kopie_shared->getHeight() << endl;




	/*
//	//Example-3
//	Shape shape;
//	shape.setHeight(10);
//	cout << "Height vom Shape-Objekt vor der vAddHeight Funktion: " << shape.getHeight() << endl;
//	vAddHeight(shape,5.99);
//	cout << "Height vom Shape-Objekt nach der vAddHeight Funktion: " << shape.getHeight() << endl;
	 */


	return 0;
}

void vAddHeight(Shape& shape, double dMenge){
	shape.p_dHeight += dMenge;
}
