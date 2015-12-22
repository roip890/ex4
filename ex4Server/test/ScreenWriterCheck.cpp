/*
 * ScreenWriterCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "gtest.h"
#include "ScreenWriter.h"
using namespace std;

/*******************************************************************************
 * class name : ScreenWriterCheck										       *
 * explanation : class for check the ScreenWriter functions.				   *
 *******************************************************************************/
class ScreenWriterCheck: public ::testing::Test {
protected:
	ScreenWriter* screenWriter;
public:
	virtual void SetUp() {
		screenWriter = new ScreenWriter(444444, 28, "drama screen writer", "female", "anna");
	}

	virtual void TearDown() {
		delete screenWriter;
	}
};

/*******************************************************************************
 * test name : printProfessional											   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as						   *
 * 				 the screenWriter details.									   *
 *******************************************************************************/
TEST_F(ScreenWriterCheck, printProfessional) {
	string expected = "anna drama screen writer\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	screenWriter->printProfessional();
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
}
