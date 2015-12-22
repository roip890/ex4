/*
 * SortStaffByIdComperatorCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "SortStaffById.h"
#include "gtest.h"
#include "Actor.h"
#include "Director.h"
#include "Producer.h"
using namespace std;

/*******************************************************************************
 * class name : SortStaffByIdComperatorCheck							       *
 * explanation : class for check the SortStaffByIdComperator functions.		   *
 *******************************************************************************/
class SortStaffByIdCheck: public ::testing::Test {
protected:
	Actor* actor;
	Director* director;
	Producer* producer;
	SortStaffById* staffComparator;

public:
	virtual void SetUp() {
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
		director = new Director(222222, 50, "super director", "male", "spilberg");
		producer = new Producer(333333, 30, "senior producer", "male", "jimmy");
		staffComparator = new SortStaffById();
	}

	virtual void TearDown() {
		delete actor;
		delete director;
		delete producer;
		delete staffComparator;
	}
};

/*******************************************************************************
 * test name : operatorBracket												   *
 * explanation : checking if the operator brackets is returning the right	   *
 * 				 number with the input of two professionals					   *
 * 				 (by the quantity of their movies).							   *
 *******************************************************************************/
TEST_F(SortStaffByIdCheck, compare) {
	EXPECT_TRUE(staffComparator->compare(actor,director));
	EXPECT_TRUE(staffComparator->compare(actor,producer));
}
