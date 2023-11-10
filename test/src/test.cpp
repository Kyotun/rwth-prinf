//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <memory>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

unique_ptr<int[]> reverseArray(unique_ptr<int[]> unique_array)
{
    auto reversed_array = make_unique<int[]>(10);
    for(int i = 0; i < 10; i++){
        reversed_array[i] = 9 - unique_array[i];
    }

    return reversed_array;
}

int main()
{

	auto unique_array = make_unique<int[]>(10);
	for(int i = 0; i < 10; i++){
		unique_array[i] = i;
	}

	cout << "Das ursprüngliche Array:" << endl;
	for(int i = 0; i < 10; i++){
		cout << "Stelle: " << i << " Inhalt: " << unique_array[i] << endl;
	}

	auto reversed_array = reverseArray(move(unique_array));

	cout << "Das umgedrehte neue Array:" << std::endl;

	for(int i = 0; i < 10; i++){
		cout << "Stelle: " << i << " Inhalt: " << reversed_array[i] << endl;
		}
	return 0;

}
