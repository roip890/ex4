/*
 * producerCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "gtest.h"
#include "Producer.h"
using namespace std;

/*******************************************************************************
 * class name : ProducerCheck											       *
 * explanation : class for check the Producer functions.					   *
 *******************************************************************************/
class ProducerCheck: public ::testing::Test {
protected:
	Producer* producer;
public:
	virtual void SetUp() {
		producer = new Producer(333333, 30, "senior producer", "male", "jimmy");
	}
	virtual void TearDown() {
		delete producer;
	}
};

/*******************************************************************************
 * test name : printProfessional											   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as the producer details.   *
 *******************************************************************************/
TEST_F(ProducerCheck, printProfessional) {
	string expected = "jimmy\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	producer->printProfessional();
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
}
