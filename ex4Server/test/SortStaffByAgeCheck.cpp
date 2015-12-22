/*
 * SortStaffByAgeComperatorCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "SortStaffByAge.h"
#include "gtest.h"
#include "Actor.h"
#include "Producer.h"
#include "Director.h"
using namespace std;

/*******************************************************************************
 * class name : SortStaffByAgeComperatorCheck							       *
 * explanation : class for check the SortStaffByAgeComperator functions.	   *
 *******************************************************************************/
class SortStaffByAgeCheck: public ::testing::Test {
protected:
	Actor* actor;
	Director* director;
	Producer* producer;
	SortStaffByAge* staffComparator;

public:
	virtual void SetUp() {
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
		director = new Director(222222, 50, "super director", "male", "spilberg");
		producer = new Producer(333333, 30, "senior producer", "male", "jimmy");
		staffComparator = new SortStaffByAge();
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
TEST_F(SortStaffByAgeCheck, compare) {
	EXPECT_TRUE(staffComparator->compare(director,actor));
	EXPECT_TRUE(staffComparator->compare(actor,producer));
}
