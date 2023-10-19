//============================================================================
// Name        : testing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> test_scores;
	for(int i = 0; i < 5; i++){
		test_scores.push_back(i);
		cout << test_scores.at(i) << endl;
	}
	cout << test_scores.at(4) << endl;


	return 0;
}
