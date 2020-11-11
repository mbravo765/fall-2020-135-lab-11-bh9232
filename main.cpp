#include <iostream>
#include "profile.h"


int main(){
	
	//Task A
	Profile p1 = Profile("Brian","Brain");
	std::cout << p1.Profile::getUsername() << "\n";
	std::cout << p1.Profile::getFullName() << "\n";
	p1.Profile::setDisplayName("Zyselia");
	std::cout << p1.Profile::getFullName() << "\n";

	return 0;
}