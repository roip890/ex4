/*
 * SortStaffByMoviesQuantityComperatorCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "gtest.h"
#include "Actor.h"
#include "Director.h"
#include "Producer.h"
#include "Movie.h"
#include "Professional.h"
using namespace std;

/*******************************************************************************
 * class name : SortStaffByMoviesQuantityComperatorCheck				       *
 * explanation : class for check the SortStaffByMoviesQuantityComperator	   *
 * 				 functions.													   *
 *******************************************************************************/
class SortStaffByMoviesQuantityCheck: public ::testing::Test {
protected:
	Movie* movie;
	Movie* movie2;
	Movie* movie3;
	Actor* actor;
	Director* director;
	SortStaffByMoviesQuantity* staffComparator;

public:
	virtual void SetUp() {
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
		director = new Director(222222, 50, "super director", "male", "spilberg");
		staffComparator = new SortStaffByMoviesQuantity();
		movie = new Movie("123456", "fast7", 90, 2015, 10, "good movie");
		movie2 = new Movie("456789", "fast8", 100, 2016, 9, "best movie ever");
		movie3 = new Movie("135791", "taken", 110, 2013, 10, "pretty goodmovie");
	}

	virtual void TearDown() {
		delete movie;
		delete movie2;
		delete movie3;
		delete actor;
		delete director;
		delete staffComparator;
	}
};

/*******************************************************************************
 * test name : operatorBracket												   *
 * explanation : checking if the operator brackets is returning the right	   *
 * 				 number with the input of two professionals					   *
 * 				 (by the quantity of their movies).							   *
 *******************************************************************************/
TEST_F(SortStaffByMoviesQuantityCheck, compare) {
	actor->getMovies().push_back(movie);
	EXPECT_TRUE(staffComparator->compare(actor,director));
	director->getMovies().push_back(movie2);
	director->getMovies().push_back(movie3);
	EXPECT_TRUE(staffComparator->compare(director,actor));
}
