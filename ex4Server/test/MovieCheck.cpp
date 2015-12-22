/*
 * movieTest.cpp
 *
 *  Created on: Nov 19, 2015
 *      Author: roi
 */

#include "Actor.h"
#include "Director.h"
#include "Producer.h"
#include "ScreenWriter.h"
#include "Movie.h"
#include "Professional.h"
#include "Type.h"
#include "SortStaffById.h"
#include "gtest.h"
#include <vector>
using namespace std;

/*******************************************************************************
 * class name : MovieCheck												       *
 * explanation : class for check the Movie functions.						   *
 *******************************************************************************/
class MovieCheck: public ::testing::Test {
protected:
	Actor* actor;
	Actor* actor2;
	Director* director;
	Producer* producer;
	ScreenWriter* screenWriter;
	Movie* movie;
	Movie* movie2;
	vector<Type*> types;
	vector<Type*> types2;
	Type* type;
	Type* type2;
	Type* type3;

public:
	virtual void SetUp() {
		types = vector<Type*>();
		types2 = vector<Type*>();
		type = new Type("action");
		type2 = new Type("drama");
		type3 = new Type("sport");
		types.push_back(type);
		types.push_back(type2);
		types2.push_back(type3);
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
		actor2 = new Actor(555555, 35, "main actor", "male", "paul walker");
		director = new Director(222222, 50, "super director", "male", "spilberg");
		producer = new Producer(333333, 30, "senior producer", "male", "jimmy");
		screenWriter = new ScreenWriter(444444, 28, "drama screen writer", "female", "anna");
		movie = new Movie("123456", "fast7", 90, 2015, 10, "good movie");
		movie2 = new Movie("456789", "fast8", 100, 2016, 9, "best movie ever");
	}

	virtual void TearDown() {
		delete actor;
		delete actor2;
		delete director;
		delete producer;
		delete screenWriter;
		delete movie;
		delete movie2;
		delete type;
		delete type2;
		delete type3;
	}
};

/*******************************************************************************
 * test name : addProfessional											       *
 * explanation : adding a professional to a staff vector of the movie and	   *
 * 				 than try to check thet it is on the vector only once.		   *
 *******************************************************************************/
TEST_F(MovieCheck, addProfessional) {
	int sizeBeforeAdding = (int) (movie->getStaff().size());
	movie->addProfessional(actor);
	movie->addProfessional(actor);
	EXPECT_EQ((int ) (movie->getStaff().size()), sizeBeforeAdding + 1);
	EXPECT_EQ(movie->getStaff().back()->getId(), 111111);
	int findProfessional = 0;
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		if (movie->getStaff().back() == actor) {
			findProfessional++;
		}
		movie->getStaff().pop_back();
	}
	EXPECT_EQ(findProfessional, 1);
}

/*******************************************************************************
 * test name : removeProfessional										       *
 * explanation : adding a professional to a staff vector of the movie with	   *
 * 				 push_back for make sure it will be on the vector and than	   *
 * 				 try to check thet it is on the vector only once.				   *
 *******************************************************************************/
TEST_F(MovieCheck, removeProfessional) {
	int sizeBeforeAdding = (int) (movie->getStaff().size());
	movie->getStaff().push_back((Professional*) (actor));
	movie->removeProfessional(actor->getId());
	EXPECT_EQ((int )(movie->getStaff().size()), sizeBeforeAdding);
	int findProfessional = 0;
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		if (movie->getStaff().back() == actor) {
			findProfessional++;
		}
		movie->getStaff().pop_back();
	}
	EXPECT_EQ(findProfessional, 0);
}

/*******************************************************************************
 * test name : findProfessional											       *
 * explanation : adding two professionals and try to see if the function	   *
 * 				 find and return them.										   *
 *******************************************************************************/
TEST_F(MovieCheck, findProfessional) {
	movie->addProfessional(actor);
	movie->addProfessional(director);
	int find = 0;
	if (movie->findProfessional(actor->getId()) == actor) {
		find++;
	}
	if (movie->findProfessional(director->getId()) == director) {
		find++;
	}
	EXPECT_EQ(find, 2);
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie->getStaff().pop_back();
	}
}

/*******************************************************************************
 * test name : sortProfessionals										       *
 * explanation : adding four professionals not in order and see if the		   *
 * 				 function sort them.										   *
 *******************************************************************************/
TEST_F(MovieCheck, sortProfessionals) {
	movie->addProfessional(director);
	movie->addProfessional(screenWriter);
	movie->addProfessional(producer);
	movie->addProfessional(actor);
	movie->setSortingType(1);
	int find = 0;
	if (movie->getStaff().back() == screenWriter) {
		movie->getStaff().pop_back();
		find++;
	}
	if (movie->getStaff().back() == producer) {
		movie->getStaff().pop_back();
		find++;
	}
	if (movie->getStaff().back() == director) {
		movie->getStaff().pop_back();
		find++;
	}
	if (movie->getStaff().back() == actor) {
		movie->getStaff().pop_back();
		find++;
	}
	EXPECT_EQ(find, 4);
}

/*******************************************************************************
 * test name : printMovie													   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as the movie details.	   *
 *******************************************************************************/
TEST_F(MovieCheck, printMovie) {
	movie->getStaff().push_back(actor);
	movie->setTypes(types);
	string expected = "123456 fast7 90 2015 10 action,drama good movie\nvin diesel 40\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	movie->printMovie();
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie->getStaff().pop_back();
	}
	EXPECT_TRUE(output == expected);
}

/*******************************************************************************
 * test name : operatorPlus													   *
 * explanation : try to merge two movies with the operator '+' and then try to *
 * 				 check if the members of the new movie are as they should be.  *
 *******************************************************************************/
TEST_F(MovieCheck, operatorPlus) {
	movie->setTypes(types);
	movie2->setTypes(types2);
	movie->getStaff().push_back(actor);
	movie2->getStaff().push_back(actor2);
	Movie newMovie = (*movie) + (*movie2);
	int indicator = 0;
	if ((newMovie.getName() == "fast8") && (newMovie.getLength() == 100) &&
			 (newMovie.getRank() == 9) && (newMovie.getStaff().size() == 2) &&
			 (newMovie.getYear() == 2016) && (newMovie.getTypes().size() == 3) &&
			 (newMovie.getSummary() == "best movie ever")) {
		indicator = 1;
	}
	EXPECT_EQ(indicator, 1);
}
