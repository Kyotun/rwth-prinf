//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int matrix[5][5] = {};
	cout << matrix << endl;

	for (int i = 0; i < 5; i++) {
	    for (int j = 0; j < 5; j++) {
	        cout << matrix[i][j] << " ";
	        if(j == 4){
	        	cout << endl;
	        }
	    }
	}


	return 0;
}
