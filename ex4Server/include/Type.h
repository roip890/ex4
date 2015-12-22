/*
 * Type.h
 *
 *  Created on: Nov 30, 2015
 *      Author: roi
 */
#include <string>
#include <vector>
class Movie;
using namespace std;


#ifndef SRC_TYPE_H_
#define SRC_TYPE_H_

/*******************************************************************************
 * class name : Type													       *
 * explanation : Type is the movie type class.								   *
 *******************************************************************************/
class Type {
private:
	string type;
	vector<Movie*> movies;
public:
	/*******************************************************************************
	 * function name : type													       *
	 * input : type as string												       *
	 * output : nothing.													       *
	 * explanation : constructor of a Type, fill the members with the input.	   *
	 *******************************************************************************/
	Type(string type);

	/*******************************************************************************
	 * function name : getMovies											       *
	 * input : nothing.														       *
	 * output : vector of movies as vector.									       *
	 * explanation : return the vector of all the movies that the Type is a		   *
	 *		         member in them.										       *
	 *******************************************************************************/
	vector<Movie*>& getMovies();

	/*******************************************************************************
	 * function name : getType												       *
	 * input : nothing.														       *
	 * output : type as string.												       *
	 * explanation : return the member of the type as string.				       *
	 *******************************************************************************/
	string getType();

	/*******************************************************************************
	 * function name : addMovie												       *
	 * input : a movie object.												       *
	 * output : nothing.													       *
	 * explanation : the function add the movie object to the movies vector.       *
	 *******************************************************************************/
	void addMovie(Movie* movieToAdd);

	/*******************************************************************************
	 * function name : removeMovie											       *
	 * input : a movie id as string.										       *
	 * output : nothing.														   *
	 * explanation : the function remove the movie object from the movies vector.  *
	 *******************************************************************************/
	void removeMovie(string movieToRemove);

	/*******************************************************************************
	 * function name : findMovie											       *
	 * input : a movie id as string.										       *
	 * output : nothing.													       *
	 * explanation : the function find the movie with that id in the movies vector.*
	 *******************************************************************************/
	Movie* findMovie(string movieToFind);

	/*******************************************************************************
	 * function name : ~Type												       *
	 * input : nothing														       *
	 * output : nothing.													       *
	 * explanation : destructor of a Type.										   *
	 *******************************************************************************/
	virtual ~Type();
};

#endif /* SRC_TYPE_H_ */
