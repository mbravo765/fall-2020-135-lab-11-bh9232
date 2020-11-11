#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "profile.h"


TEST_CASE("TASK A"){

	Profile p0 = Profile();
	CHECK(p0.Profile::getUsername() == "");
	CHECK(p0.Profile::getFullName() == "");
	p0.Profile::setDisplayName("Friend");
	CHECK(p0.Profile::getFullName() == "Friend");

	Profile p1 = Profile("Brian","Brain");
	CHECK(p1.Profile::getUsername() == "Brian");
	CHECK(p1.Profile::getFullName() == "Brain");
	p1.Profile::setDisplayName("Zyselia");
	CHECK(p1.Profile::getFullName() == "Zyselia");
}