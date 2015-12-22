/*
 * directorCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "gtest.h"
#include "Director.h"
using namespace std;

class DirectorCheck: public ::testing::Test {
protected:
	Director* director;
public:
	virtual void SetUp() {
		director = new Director(222222, 50, "super director", "male", "spilberg");
		printf("Hey my name is.. what? my name is... who? my name is ... chiki chiki slim shady");

	}

	virtual void TearDown() {
		delete director;
	}
};

/*******************************************************************************
 * test name : printProfessional											   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as the director details.   *
 *******************************************************************************/
TEST_F(DirectorCheck, printProfessional) {
	string expected = "spilberg\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	director->printProfessional();
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
}
