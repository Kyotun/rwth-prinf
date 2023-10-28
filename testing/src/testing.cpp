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

class Person
{
    public :
        Person() = delete ;
        Person(std::string name , std::shared_ptr<Person> father = nullptr , std::shared_ptr<Person> mother = nullptr) ;
        virtual ~Person() ;
        void setSibling(std::weak_ptr<Person> sibling);
    private :
        std::shared_ptr<Person> p_father;
        std::shared_ptr<Person> p_mother;
        std::string p_sName;
        std::vector<std::weak_ptr<Person>> p_siblings;
};

Person::Person(string name, shared_ptr<Person> father, shared_ptr<Person> mother){
	p_sName = name;
	p_father = father;
	p_mother = mother;
}

void Person::setSibling(weak_ptr<Person> brosis){
	p_siblings.push_back(brosis);
}

Person::~Person(){
	p_siblings.clear();
	std::cout << "Geloescht: " << p_sName << std::endl;
}

void test1 ()
{
    auto m1 = std::make_shared<Person>("Josef");
    auto f1 = std::make_shared<Person>("Maria");
    auto m2 = std::make_shared<Person>("Peter", m1 , f1 );
    auto f2 = std::make_shared<Person>("Birgit", m1 , f1 );
    m2->setSibling(f2);
    f2->setSibling(m2);
}


int main()
{

	std::cout << "Anfang" << std::endl;
	test1();
	std::cout << "Ende" << std::endl;

	return 0;

}
