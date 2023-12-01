/*
 * containers.cpp
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */


#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> v1 = {0,1,2};

	cout << "Vector: ";
	for(auto element : v1){
		cout << element << ' ';
	}
	cout << endl;

	v1.pop_back();

	cout << "Last element has been removed.\nVector: ";
	for(auto element : v1){
		cout << element << ' ';
	}8
	cout << endl;

	v1.push_back(5);
	v1.insert(v1.begin(),6);

	cout << "At the end the number 5 has been added.\nAt the beginning is 6.";
	for(auto element : v1){
		cout << element << ' ';
	}
	cout << endl;

	return 0;
}


