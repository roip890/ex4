/*
 * Professional.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef PROFESSIONAL_H_
#define PROFESSIONAL_H_
#include <vector>
#include <string>
#include <iostream>
class Movie;
using namespace std;

/*******************************************************************************
 * class name : Professional											       *
 * explanation : Professional is an abstract class.							   *
 *******************************************************************************/
class Professional {
protected:
	int id;
	string specificDesc;
	string name;
	int age;
	string gender;
	vector<Movie*> movies;
public:
	/*******************************************************************************
	 * function name : ~professional										       *
	 * input : nothing														       *
	 * output : nothing.													       *
	 * explanation : destructor of a professional.								   *
	 *******************************************************************************/
	virtual ~Professional();

	/*******************************************************************************
	 * function name : professional											       *
	 * input : all the professional parameters: id, age and gender as int,	       *
	 *		  name as string.												       *
	 * output : nothing.													       *
	 * explanation : constructor of a professional, fill the members with the input.*
	 *******************************************************************************/
	Professional(int id, int age, string specificDesc, string gender,
			string name);

	/*******************************************************************************
	 * function name : getId												       *
	 * input : nothing.														       *
	 * output : id as int.													       *
	 * explanation : return the member of the id as int.					       *
	 *******************************************************************************/
	int getId();

	/*******************************************************************************
	 * function name : getProfession										       *
	 * input : nothing.														       *
	 * output : profession as string.										       *
	 * explanation : return the member of the professi*on as string.		       *
	 *******************************************************************************/
	string getProfession();

	/*******************************************************************************
	 * function name : getName												       *
	 * input : nothing.														       *
	 * output : name as string.												       *
	 * explanation : return the member of the name as string.				       *
	 *******************************************************************************/
	string getName();

	/*******************************************************************************
	 * function name : getAge												       *
	 * input : nothing.														       *
	 * output : age as int.													       *
	 * explanation : return the member of the age as int.						   *
	 *******************************************************************************/
	int getAge();

	/*******************************************************************************
	 * function name : getGender											       *
	 * input : nothing.														       *
	 * output : gender as int.												       *
	 * explanation : return the member of the gender as int (0 - for male,	       *
	 *		        1 - for female).										       *
	 *******************************************************************************/
	string getGender();

	/*******************************************************************************
	 * function name : getMovies											       *
	 * input : nothing.														       *
	 * output : vector of movies as vector.									       *
	 * explanation : return the vector of all the movies that the professional is a*
	 *		        member in them.											       *
	 *******************************************************************************/
	vector<Movie*>& getMovies();

	/*******************************************************************************
	 * function name : addMovie												       *
	 * input : a movie object.												       *
	 * output : nothing.													       *
	 * explanation : the function add the movie object to the movies vector.       *
	 *******************************************************************************/
	void addMovie(Movie* movieToAdd);

	/*******************************************************************************
	 * function name : removeMovie											       *
	 * input : a movie id as int.											       *
	 * output : nothing.														   *
	 * explanation : the function remove the movie object from the movies vector.  *
	 *******************************************************************************/
	void removeMovie(string movieToRemoveId);

	/*******************************************************************************
	 * function name : findMovie											       *
	 * input : a movie id as string.										       *
	 * output : nothing.													       *
	 * explanation : the function find the movie with that id in the movies vector.*
	 *******************************************************************************/
	Movie* findMovie(string movieToAddId);

	/*******************************************************************************
	 * function name : printProfessional										   *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : the function printing the proffesional details. this function *
	 *				is pure virtual function and each Professional inheriting      *
	 *				object implement it in other way.						       *
	 *******************************************************************************/
	virtual void printProfessional() = 0;

};

#endif /* PROFESSIONAL_H_ */
