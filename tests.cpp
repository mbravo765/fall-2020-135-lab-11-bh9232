#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "profile.h"
#include "network.h"


TEST_CASE("TASK A"){

	Profile p1("Zyselia","Brian");
	CHECK(p1.Profile::getUsername() == "Zyselia");
	CHECK(p1.Profile::getFullName() == "Brian (@Zyselia)");
	p1.Profile::setDisplayName("Zyselia");
	CHECK(p1.Profile::getFullName() == "Zyselia (@Zyselia)");

	Profile p2("brian123","brian");
	CHECK(p2.getUsername() == "brian123");
	CHECK(p2.getFullName() == "brian (@brian123)");
	p2.setDisplayName("Brian");
	CHECK(p2.getFullName() == "Brian (@brian123)");
}

TEST_CASE("TASK B and C"){

	//TASK B
	Network nw;
	CHECK(nw.addUser("brian123","Zyselia") == true);
	CHECK(nw.addUser("thelegend27","TheLegend") == true);
	CHECK(nw.addUser("brian123","Homer") == false);
	CHECK(nw.addUser("brian_123","Zyselia") == false);
	CHECK(nw.addUser("brian 123","Homer") == false);

	//TASK C
	CHECK(nw.follow("brian123","thelegend27") == true);
	CHECK(nw.follow("thelegend27","brian123") == true);
	CHECK(nw.follow("brian_123","brian123") == false);
	CHECK(nw.follow("thelegend27", "brian_123") == false);
} 