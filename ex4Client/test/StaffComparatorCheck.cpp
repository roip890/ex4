/*
 * StaffComparatorCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "gtest.h"
#include "Actor.h"
#include "Director.h"
#include "Producer.h"
#include "ScreenWriter.h"
#include "Movie.h"
#include "Professional.h"

using namespace std;

class StaffComparatorCheck: public ::testing::Test {
protected:
	Movie* movie;
	Movie* movie2;
	Movie* movie3;
	Actor* actor;
	Director* director;
	Producer* producer;
	ScreenWriter* screenWriter;
	StaffComparator* staffComparator;
	vector<Professional*> staff;
public:
	virtual void SetUp() {
		movie = new Movie("123456", "fast7", 90, 2015, 10, "good movie");
		movie2 = new Movie("456789", "fast8", 100, 2016, 9, "best movie ever");
		movie3 = new Movie("135791", "taken", 110, 2013, 10, "pretty goodmovie");
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
		director = new Director(222222, 50, "super director", "male", "spilberg");
		producer = new Producer(333333, 30, "senior producer", "male", "jimmy");
		screenWriter = new ScreenWriter(444444, 28, "drama screen writer", "female" ,"anna");
		staffComparator = new StaffComparator(1);
	}

	virtual void TearDown() {
		delete movie;
		delete movie2;
		delete movie3;
		delete actor;
		delete director;
		delete producer;
		delete screenWriter;
		delete staffComparator;
	}
};

/*******************************************************************************
 * test name : sort															   *
 * explanation : pushing four professionals to a staff vector and than		   *
 * 				 try to sort the vector with this function					   *
 * 				 (using the virtual overloading operator brackets).			   *
 *******************************************************************************/
TEST_F(StaffComparatorCheck, sort) {
	staff.push_back(producer);
	staff.push_back(actor);
	staff.push_back(screenWriter);
	staff.push_back(director);
	actor->getMovies().push_back(movie);
	director->getMovies().push_back(movie2);
	director->getMovies().push_back(movie3);
	staffComparator->setSortingType(1);
	EXPECT_TRUE(staffComparator->operator ()(actor,director));
	EXPECT_TRUE(staffComparator->operator ()(actor,producer));
	staffComparator->setSortingType(2);
	EXPECT_TRUE(staffComparator->operator ()(director,actor));
	EXPECT_TRUE(staffComparator->operator ()(actor,producer));
	staffComparator->setSortingType(3);
	EXPECT_TRUE(staffComparator->operator ()(actor,producer));
	EXPECT_TRUE(staffComparator->operator ()(director,actor));
	sort(staff.begin(), staff.end(), *staffComparator);
	int size = (int)(staff.size());
	for (int i = 0; i < size; i++) {
		staff.pop_back();
	}
}
