#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "profile.h"


TEST_CASE("TASK A"){
	Profile::Profile("Brian","Brian")
	CHECK(Profile::getUsername() == "Brian");
	CHECK(Profile::getFullName() == "Brian");
}