#include <iostream>
#include "profile.h"
#include "network.h"

using namespace std;

int main(){
	
	//Task A
	Profile p1 = Profile("Brian","Brain");
	std::cout << p1.getUsername() << "\n";
	std::cout << p1.getFullName() << "\n";
	p1.setDisplayName("Zyselia");
	std::cout << p1.getFullName() << "\n";

	//Task B
	Network nw;
	cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  	cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  	cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  	cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  	cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  	for(int i = 2; i < 20; i++)
      	cout << nw.addUser("mario" + to_string(i), 
            "Mario" + to_string(i)) << endl;   // true (1)

  	cout << nw.addUser("yoshi", "Yoshi") << endl; 

  	//Task C
  	// make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
     
	return 0;
}