/*
 * movieSystemCheck.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: roi
 */

#include "MoviesSystem.h"
#include "Actor.h"
#include "Director.h"
#include "Producer.h"
#include "ScreenWriter.h"
#include "gtest.h"
#include "vector"
#include "Movie.h"
#include "Professional.h"
using namespace std;
/*******************************************************************************
 * class name : MoviesSystemCheck										       *
 * explanation : class for check the MovieSystem functions.					   *
 *******************************************************************************/
class MoviesSystemCheck: public ::testing::Test {
protected:


	Actor* actor;
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
	MoviesSystem* system;
public:
	virtual void SetUp() {
		types = vector<Type*>();
		types2 = vector<Type*>();
		type = new Type("action");
		type2 = new Type("drama");
		type3 = new Type("sport");
		actor = new Actor(111111, 40, "main actor", "male", "vin diesel");
		director = new Director(222222, 50, "super director", "male", "spilberg");
		producer = new Producer(333333, 30, "senior producer", "male", "jimmy");
		screenWriter = new ScreenWriter(444444, 28, "drama screen writer", "female", "anna");
		movie = new Movie("123456", "fast7", 90, 2015, 10, "good movie");
		movie2 = new Movie("456789", "fast8", 100, 2016, 9, "best movie ever");
		system = new MoviesSystem();
		types.push_back(type);
		types.push_back(type2);
		types2.push_back(type3);
	}

	virtual void TearDown() {

		delete actor;
		delete director;
		delete producer;
		delete screenWriter;
		delete movie;
		delete movie2;
		delete type;
		delete type2;
		delete type3;
		delete system;
	}
};
/*******************************************************************************
 * test name : findProfessional											       *
 * explanation : adding a professional to the MovieSystem professionals vector	   *
 * 				with push_back for make sure it will be on the vector and trying*
 * 				to find it with findProfessional function.					   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, findProfessional) {
	system->getProfessionals().push_back(actor);
	int find = 0;
	int size = (int) (system->getProfessionals().size());
	for (int i = 0; i < size; i++) {
		if (system->findProfessional(111111) == actor) {
			find++;
		}
		system->getProfessionals().pop_back();
	}
	EXPECT_EQ(find, 1);
}

/*******************************************************************************
 * test name : findMovie													       *
 * explanation : adding a movie to the MovieSystem movies vector				   *
 * 				with push_back for make sure it will be on the vector and trying*
 * 				to find it with findMovie function.							   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, findMovie) {
	system->getMovies().push_back(movie);
	int find = 0;
	int size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		if (system->findMovie("123456") == movie) {
			find++;
		}
		system->getMovies().pop_back();
	}
	EXPECT_EQ(find, 1);
}

/*******************************************************************************
 * test name : addProfessionalToMovie									       *
 * explanation : adding a professional to a movie staff vector				   *
 * 				with push_back for make sure it will be on the vector and	   *
 * 				checking the size of the vector and if the professional is in	   *
 * 				the vector after the function is working.						   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, addProfessionalToMovie) {
	int sizeBeforeAdding = (int) (movie->getStaff().size());
	system->getMovies().push_back(movie);
	system->getProfessionals().push_back(actor);
	system->addProfessionalToMovie(111111, "123456");
	system->addProfessionalToMovie(111111, "123456");
	EXPECT_EQ((int)(movie->getStaff().size()), (sizeBeforeAdding + 1));
	EXPECT_EQ(movie->getStaff().back()->getId(), 111111);
	int findProfessional = 0;
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		if (movie->getStaff().back() == actor) {
			findProfessional++;
		}
		system->getProfessionals().pop_back();
	}
	EXPECT_EQ(findProfessional, 1);
	size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		system->getMovies().pop_back();
	}
	size = (int) (system->getProfessionals().size());
	for (int i = 0; i < size; i++) {
		system->getProfessionals().pop_back();
	}
}

/*******************************************************************************
 * test name : addTypeToMovie											       *
 * explanation : adding a type to a movie types vector						   *
 * 				with push_back for make sure it will be on the vector and	   *
 * 				checking the size of the vector and if the type is in			   *
 * 				the vector after the function is working.						   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, addTypeToMovie) {
	int sizeBeforeAdding = (int) (movie->getTypes().size());
	system->getMovies().push_back(movie);
	system->getProfessionals().push_back(actor);
	system->addTypeToMovie("123456", "sport");
	system->addTypeToMovie("123456", "sport");
	int findType = 0;
	int size = (int) ((*(system->getMovies().back())).getTypes().size());
	for (int i = 0; i < size; i++) {
		if ((*(system->getMovies().back())).getTypes().back()->getType() == "sport") {
			findType = 1;
		}
		system->getMovies().pop_back();
	}
	EXPECT_EQ(movie->getTypes().size(), sizeBeforeAdding + 1);
	EXPECT_EQ(findType, 1);
	size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		system->getMovies().pop_back();
	}
	size = (int) (system->getProfessionals().size());
	for (int i = 0; i < size; i++) {
		system->getProfessionals().pop_back();
	}
	size = (int) (system->getTypes().size());
	for (int i = 0; i < size; i++) {
		system->getTypes().pop_back();
	}
}

/*******************************************************************************
 * test name : deleteMovie												       *
 * explanation : adding a a movie to the movies vector with push_back for	   *
 * 				 make sure it will be on the vector and then try to delete with  *
 * 				 the function and check if the movie is not longer on the vector.*
 *******************************************************************************/
TEST_F(MoviesSystemCheck, deleteMovie) {
	int sizeBeforeAdding = system->getMovies().size();
	system->getMovies().push_back(movie);
	system->deleteMovie("123456");
	EXPECT_EQ(sizeBeforeAdding, (int)(system->getMovies().size()));
	int findMovie = 0;
	int size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		if (system->getMovies().back() == movie) {
			findMovie++;
		}
		system->getMovies().pop_back();
	}
	EXPECT_EQ(findMovie, 0);
}

/*******************************************************************************
 * test name : deleteProfessional										       *
 * explanation : adding a professional to the vector with push_back for		   *
 * 				 make sure it will be on the vector and then try to delete with  *
 * 				 the function and check if the movie is not longer on the vector.*
 *******************************************************************************/
TEST_F(MoviesSystemCheck, deleteProfessional) {
	int sizeBeforeAdding = system->getProfessionals().size();
	system->getProfessionals().push_back(actor);
	system->deleteProfessional(111111);
	EXPECT_EQ(sizeBeforeAdding, system->getProfessionals().size());
	int findProfessional = 0;
	int size = (int) (system->getProfessionals().size());
	for (int i = 0; i < size; i++) {
		if (system->getProfessionals().back() == actor) {
			findProfessional++;
		}
		system->getProfessionals().pop_back();
	}
	EXPECT_EQ(findProfessional, 0);
}

/*******************************************************************************
 * test name : mergeMovies													   *
 * explanation : adding two movies to the movies vector and try to merge them	   *
 * 				 with the operator and then try to find if there is a new	   *
 * 				 movie from the merging on the movies vector.					   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, mergeMovies) {
	movie->setTypes(types);
	movie2->setTypes(types2);
	movie->getStaff().push_back(actor);
	movie2->getStaff().push_back(director);
	system->getMovies().push_back(movie);
	system->getMovies().push_back(movie2);
	vector<string> movieList = vector<string>();
	movieList.push_back("123456");
	movieList.push_back("456789");
	system->mergeMovies(movieList);
	Movie newMovie = *(system->getMovies().back());
	int size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		if ((system->getMovies().back() != movie) &&
				 (system->getMovies().back() != movie2)) {
			newMovie = *(system->getMovies().back());
		}
		system->getMovies().pop_back();
	}
	int indicator = 0;
	if ((newMovie.getName() == "fast8") && (newMovie.getLength() == 100) &&
			 (newMovie.getRank() == 9) && (newMovie.getStaff().size() == 2) &&
			 (newMovie.getYear() == 2016) && (newMovie.getTypes().size() == 3) &&
			 (newMovie.getSummary() == "best movie ever")) {
		indicator = 1;
	}
	size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie->getStaff().pop_back();
	}
	size = (int) (movie2->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie2->getStaff().pop_back();
	}
	EXPECT_EQ(indicator, 1);
}

/*******************************************************************************
 * test name : printAllMovieDetails											   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as the movie details.	   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, printAllMovieDetails) {
	movie->setTypes(types);
	movie->getStaff().push_back(actor);
	system->getMovies().push_back(movie);
	string expected = "123456 fast7 90 2015 10 action,drama good movie\nvin diesel 40\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	system->printAllMovieDetails("123456");
	string output = buffer.str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie->getStaff().pop_back();
	}
	size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		system->getMovies().pop_back();
	}
}

/*******************************************************************************
 * test name : printAllMovies												   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as all movies details.	   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, printAllMovies) {
	movie->setTypes(types);
	movie2->setTypes(types2);
	movie->getStaff().push_back(actor);
	system->getMovies().push_back(movie);
	movie2->getStaff().push_back(director);
	system->getMovies().push_back(movie2);
	string expected = "123456 fast7 90 2015 10 action,drama good movie\nvin diesel 40\n456789 fast8 100 2016 9 sport best movie ever\nspilberg\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	system->printAllMovies();
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie->getStaff().pop_back();
	}
	size = (int) (movie2->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie2->getStaff().pop_back();
	}
	size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		system->getMovies().pop_back();
	}
}

/*******************************************************************************
 * test name : PrintAllMoviesOfProfessional									   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as all movies			   *
 * 				 details of the actor->										   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, PrintAllMoviesOfProfessional) {
	system->getProfessionals().push_back(actor);
	actor->getMovies().push_back(movie);
	movie->getStaff().push_back(actor);
	actor->getMovies().push_back(movie2);
	movie2->getStaff().push_back(actor);
	string expected = "123456 fast7 90 2015 10 good movie\nvin diesel 40\n456789 fast8 100 2016 9 best movie ever\nvin diesel 40\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	system->printAllMoviesOfProfessional(111111);
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
	int size = (int) (actor->getMovies().size());
	for (int i = 0; i < size; i++) {
		actor->getMovies().pop_back();
	}
	size = (int) (system->getProfessionals().size());
	for (int i = 0; i < size; i++) {
		system->getProfessionals().pop_back();
	}

}

/*******************************************************************************
 * test name : printAllProfessionals										   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as all professionals.	   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, printAllProfessionals) {
	actor->getMovies().push_back(movie);
	system->getProfessionals().push_back(actor);
	director->getMovies().push_back(movie);
	system->getProfessionals().push_back(director);
	string expected = "vin diesel 40\nspilberg\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	system->printAllProfessionals();
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
	int size = (int) (actor->getMovies().size());
	for (int i = 0; i < size; i++) {
		actor->getMovies().pop_back();
	}
	size = (int) (director->getMovies().size());
	for (int i = 0; i < size; i++) {
		director->getMovies().pop_back();
	}
	size = (int) (system->getProfessionals().size());
	for (int i = 0; i < size; i++) {
		system->getProfessionals().pop_back();
	}
}

/*******************************************************************************
 * test name : printAllProfessionalsOfMovie									   *
 * explanation : catch the printing and try to compare it to a string which	   *
 * 				 is the string that should be print as all professionals	   *
 * 				 from a staff vector of movie->								   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, printAllProfessionalsOfMovie) {
	movie->getStaff().push_back(actor);
	movie->getStaff().push_back(director);
	system->getMovies().push_back(movie);
	string expected = "vin diesel 40\nspilberg\n";
	stringstream buffer;
	streambuf *sbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());
	system->printAllProfessionalsOfMovie("123456");
	string output = buffer.str().c_str();
	cout.rdbuf(sbuf);
	EXPECT_TRUE(output == expected);
	int size = (int) (movie->getStaff().size());
	for (int i = 0; i < size; i++) {
		movie->getStaff().pop_back();
	}
	size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		system->getMovies().pop_back();
	}
}

/*******************************************************************************
 * test name : setNewMovie													   *
 * explanation : setting a new movie with that function and then try to find   *
 * 				 that movie with all the details on the vector.				   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, setNewMovie) {
	int sizeBeforeAdding = system->getMovies().size();
	system->setNewMovie("135791", "taken", 110, 2013, 10,
			"pretty good movie");
	EXPECT_EQ((sizeBeforeAdding + 1), system->getMovies().size());
	int indicator = 0;
	int size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		Movie newMovie = *(system->getMovies().back());
		if ((newMovie.getId() == "135791") && (newMovie.getName() == "taken") &&
				 (newMovie.getLength() == 110) && (newMovie.getRank() == 10) &&
				 (newMovie.getStaff().size() == 0) &&
				 (newMovie.getYear() == 2013) &&
				 (newMovie.getTypes().size() == 0) &&
				 (newMovie.getSummary() == "pretty good movie")) {
			indicator = 1;
		}
	}
	for (int i = 0; i < size; i++) {
		system->getMovies().pop_back();
	}
	EXPECT_EQ(indicator, 1);
}

/*******************************************************************************
 * test name : setNewProfessional											   *
 * explanation : setting a new professional with that function and then try	   *
 * 				 to find that movie with all the details on the vector.		   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, setNewProfessional) {
	int sizeBeforeAdding = system->getProfessionals().size();
	system->setNewProfessional(1, 101010, 35, "drama actor", "male", "yehuda levi");
	EXPECT_EQ((sizeBeforeAdding + 1), system->getProfessionals().size());
	int indicator = 0;
	int size = (int) (system->getProfessionals().size());
	for (int i = 0; i < size; i++) {
		if ((system->getProfessionals().back()->getId() == 101010) &&
				 (system->getProfessionals().back()->getName()
						== "yehuda levi") &&
				 (system->getProfessionals().back()->getProfession()
						== "drama actor") &&
				 (system->getProfessionals().back()->getAge() == 35) &&
				 (system->getProfessionals().back()->getGender() == "male")) {
			indicator = 1;
		}
		system->getProfessionals().pop_back();
	}
	EXPECT_EQ(indicator, 1);
}

/*******************************************************************************
 * test name : setSortingTypeOfMovie										   *
 * explanation : pushing a new movie to the movie vector and try to set it's	   *
 * 				 sorting type with that function and then check if			   *
 * 				 it's the correct sorting type.								   *
 *******************************************************************************/
TEST_F(MoviesSystemCheck, setSortingTypeOfMovie) {
	system->getMovies().push_back(movie);
	int oldSortingType = movie->getSortingType();
	system->setSortingTypeMovie("123456", (oldSortingType + 1));
	EXPECT_EQ((*(system->getMovies().back())).getSortingType(),
			(oldSortingType + 1));
	int size = (int) (system->getMovies().size());
	for (int i = 0; i < size; i++) {
		system->getMovies().pop_back();
	}
}
