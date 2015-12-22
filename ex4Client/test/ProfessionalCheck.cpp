/*
 * ProfessionalCheck.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: roi
 */

#include "gtest.h"
#include "Actor.h"
#include <vector>
#include <string>
#include "Movie.h"
using namespace std;

/*******************************************************************************
 * class name : ProfessionalCheck										       *
 * explanation : class for check the Professional functions.				   *
 *******************************************************************************/
class ProfessionalCheck: public ::testing::Test {
protected:
	Actor* actor;
	Movie* movie;
	vector<Type*> types;
	Type* type;
	Type* type2;
public:
	virtual void SetUp() {
		types = vector<Type*>();
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
		type = new Type("action");
		type2 = new Type("drama");
		types.push_back(type);
		types.push_back(type2);
		movie = new Movie("123456", "fast7", 90, 2015, 10, "good movie");
	}

	virtual void TearDown() {
		delete actor;
		delete movie;
		delete type;
		delete type2;
	}
};

/*******************************************************************************
 * test name : addMovie													       *
 * explanation : adding a movie to a movies vector of the professional and	   *
 * 				 than try to check thet it is on the vector only once.		   *
 *******************************************************************************/
TEST_F(ProfessionalCheck, addMovie) {
	actor->addMovie(movie);
	actor->addMovie(movie);
	int findMovie = 0;
	int size = (int) (actor->getMovies().size());
	for (int i = 0; i < size; i++) {
		if (actor->getMovies().back() == movie) {
			findMovie++;
		}
		actor->getMovies().pop_back();
	}
	EXPECT_EQ(findMovie, 1);
}
/*******************************************************************************
 * test name : removeMovie													   *
 * explanation : adding a movie to a movies vector of the professional with	   *
 * 				 push_back for make sure it will be on the vector and than	   *
 * 				 try to remove with this function removeMovie				   *
 * 				 than try to check thet it is on the vector only once.		   *
 *******************************************************************************/
TEST_F(ProfessionalCheck, removeMovie) {
	int sizeBeforeAdding = actor->getMovies().size();
	actor->getMovies().push_back(movie);
	actor->removeMovie("123456");
	int findMovie = 0;
	int size = (int) (actor->getMovies().size());
	for (int i = 0; i < size; i++) {
		if (actor->getMovies().back() == movie) {
			findMovie++;
		}
		actor->getMovies().pop_back();
	}
	EXPECT_EQ(findMovie, 0);
	EXPECT_EQ(sizeBeforeAdding, (int )(actor->getMovies().size()));
}

