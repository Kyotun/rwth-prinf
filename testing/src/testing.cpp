//============================================================================
// Name        : testing.cpp
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

void doesWeakExistProperly(std::weak_ptr<int> weak){
    if(weak.lock()){
        std::cout << "Der Pointer wurde erfolgreich gelocked und hat den Inhalt: " << *weak.lock() << std::endl;
    } else {
        std::cout << "Der Pointer konnte nicht gelocked werden." << std::endl;
    }
}


int main()
{
	std::weak_ptr<int> weak;
	    doesWeakExistProperly(weak);
	    {
	        auto shared = std::make_shared<int>(42);
	        weak = shared;
	        std::cout << "Der Pointer `weak` ist jetzt mit `shared` gepaired." << std::endl;
	        doesWeakExistProperly(weak);
	        cout << "Noch in scope" << endl;
	        cout << "Versuche nochmal doeskWeakExistProperly" << endl;
	        doesWeakExistProperly(weak);
	    }
	    std::cout << "Der Pointer `shared` ist jetzt out of scope." << std::endl;
	    doesWeakExistProperly(weak);
	return 0;

}
