/*
 * ActorCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */
#include "Actor.h"
#include "gtest.h"
using namespace std;

/*******************************************************************************
 * class name : ActorCheck												       *
 * explanation : class for check the Actor functions.						   *
 *******************************************************************************/
class ActorCheck: public ::testing::Test {
protected:
	Actor* actor;
public:
	virtual void SetUp() {
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
	}

	virtual void TearDown() {
		delete actor;
	}
};

/*******************************************************************************
 * test name : printProfessional											   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as the actor details.	   *
 *******************************************************************************/
TEST_F(ActorCheck, printProfessional) {
	string expected = "vin diesel 40\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	actor->printProfessional();
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
}
