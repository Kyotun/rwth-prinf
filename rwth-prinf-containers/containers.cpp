/*
 * containers.cpp
 *
 *  Created on: 01.12.2023
 *      Author: kyotun
 */

#include <iterator>
#include <vector>
#include <iostream>
#include <list>
#include <map>

using namespace std;

void vVector();
void vList();
void vList2();
void vArray();
void vMap();
void vIterator1();
void vIterator2();

int main(){
//	vVector();
//	vList();
//	vList2();
//	vArray();
//	vMap();
//	vIterator1();
//	vIterator2();
	return 0;
}

void vIterator2(){
	vector<int> vector1;
	for(int i = 0; i < 10; i++){
		vector1.push_back(i);
	}

	vector<int>::iterator it;
	vector<int>::reverse_iterator revIt;

	cout << "Vector is now forward iterated: ";
	for(it = vector1.begin(); it < vector1.end(); it++){
		cout << *it << ' ';
	}
	cout << endl << endl;

	cout << "Vector is now backward iterated:";
	for(revIt = vector1.rbegin(); revIt != vector1.rend(); revIt++){
		cout << *revIt << ' ';
	}
	cout << endl << endl;

}

void vIterator1(){
	vector<int> vector1(3,1);
	vector1.push_back(7);
	int sum = 0;

	cout << "Vector: ";
	for(auto element: vector1){
		cout << element << ' ';
		sum += element;
	}
	cout << endl;
	cout << "Sum is: " << sum << endl;
}

void vMap(){
	map<long, string> studi_map;
	studi_map[123123] = "Mustermann";
	studi_map[461047] = "Pisirici";
	studi_map[452443] = "Solak";

	cout << "Students with their student numbers: " << endl;
	for(const auto& element: studi_map){
		cout << element.first << " -> " << element.second << endl;

	}
	cout << endl;

	map<string, int> numbers;

	numbers["eins"] = 1;
	numbers["zwei"] = 2;
	numbers["drei"] = 3;

	cout << "Number map looks like this: " << endl;
	for(const auto& it: numbers){
		cout << it.first << ": " << it.second << endl;
	}

	auto lookUp1 = numbers.find("eins");

	if(lookUp1 != numbers.end()){
		numbers.erase(lookUp1);
	}

	cout << endl;
	cout << "Nachdem wir die 1 gelöscht haben, sieht die map so aus: " << endl;
	for(const auto& it: numbers){
		cout << it.first << ": " << it.second << endl;
	}

}

void vArray(){
//	array<int, 42> feld1; //ist ein Array namens feld, welches 42 int-Werte speichern kann.
//	array<int, 3> feld2 = {1, 2, 3}; //ist ein Array, das bereits mit Werten initialisiert wurde.

	array<int,4> array1 = {0,1,2,3};
	cout << "Content of array1: " << endl;
	for(auto element: array1){
		cout << element << ' ';
	}
	cout << endl; cout << endl;

	array<int,4> swap_array = {0,0,0,0};

	cout << "Content of swap_array: " << endl;
	for(auto element : swap_array){
		cout << element << ' ';
	}
	cout << endl << endl;

	swap_array.swap(array1);

	cout << "Swap_array has been swapped with Array1.\n(Arrays are directly swapped.)" << endl;
	cout << "Swap_array: " << endl;
	for (auto element: swap_array){
		cout << element << ' ';
	}
	cout << endl << endl;

	cout << "Array1: " << endl;
	for(auto element: array1){
		cout << element << ' ';
	}
	cout << endl << endl;


}

void vList(){
	list<int> list1;

	list1.push_back(10);
	cout << "10 has been added. "
			"List looks like this: ";
	for(auto element : list1){
		cout << element << ' ';
	}
	cout << endl << endl;

	list1.insert(list1.begin(),3);
	cout << "Beginning of the list is 3 added."
			"List looks like this: ";
	for(auto element : list1){
		cout << element << ' ';
	}
	cout << endl << endl;

	list1.insert(list1.end(), 8);
	cout << "Add 8 at the end. List: ";
	for(auto element: list1){
		cout << element << ' ';
	}
	cout << endl << endl;

	list1.push_front(15);
	cout << "Add 15 at the front of the list. List: ";
	for(auto element: list1){
		cout << element << ' ';
	}
	cout << endl << endl;

	list1.pop_front();

	cout << "Pop element from the front of the list. List: ";
	for(auto element: list1){
		cout << element << ' ';
	}
	cout << endl << endl;
}

void vList2(){
	list<string> list1, list2;

	list1.push_back("gelb");
	list1.push_back("blau");
	list1.push_back("rot");

	cout << "List1 looks like this: " << endl;
	for(const auto& element: list1){
		cout << element << ' '; //Ausgabe: gelb blau rot
	}
	cout << endl << endl;

	list2.push_front("weiß");
	list2.push_front("lila");
	list2.push_front("schwarz");

	cout << "List2 looks like this: " << endl;
	for(const auto& element: list2){
		cout << element << ' '; //Ausgabe: gelb blau rot
	}
	cout << endl << endl;

	auto start = list2.begin();
	list1.insert(list1.begin(),start, list2.end());

	cout << "Merged list looks like this: " << endl;
	for(const auto& element : list1){
		cout << element << ' ';
	}
	cout << endl << endl;

	list1.erase(list1.begin());
	cout << "List1.begin has been erased. List1 looks like this: " << endl;
	for(auto element: list1){
		cout << element << ' ';
	}
	cout << endl << endl;


}

void vVector(){
	vector<int> v1 = {0,1,2};
//	vector<int> v2(3, -1); // Initialized 3 number -1
//	vector<int> v1(5); // Initial capacity is 5

	cout << "Vector: ";
	for(auto element : v1){
		cout << element << ' ';
	}
	cout << endl;

	v1.pop_back();

	cout << "Last element has been removed.\nVector: ";
	for(auto element : v1){
		cout << element << ' ';
	}
	cout << endl << endl;

	v1.push_back(5);
	v1.insert(v1.begin(),6);

	cout << "At the end 5 and "
			"the beginning 6 have been added." << endl;
	for(auto element : v1){
		cout << element << ' ';
	}
	cout << endl << endl;

	v1.insert(v1.begin()+1,10);

	cout << "At begin+1 has the number 10 been added." << endl;
	for(auto element : v1){
		cout << element << ' ';
	}
	cout << endl;

}

