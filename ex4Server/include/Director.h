/*
 * Director.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef DIRECTOR_H_
#define DIRECTOR_H_
#include <vector>
#include <string>
#include <iostream>
#include "Professional.h"
using namespace std;

/*******************************************************************************
* class name : Director													       *
* explanation : Director is class that inherit from professional.			   *
*******************************************************************************/
class Director:public Professional {
public:
	/*******************************************************************************
	* function name : Director												       *
	* input : all the Director parameters: id, age and gender as int,		       *
	*		  name as string.												       *
	* output : nothing.														       *
	* explanation : constructor of a Director, fill the members with the input.	   *
	*******************************************************************************/
	Director(int id , int age, string specificDesc, string gender, string name);

	/*******************************************************************************
	* function name : ~Director												       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a Director.									   *
	*******************************************************************************/
	virtual ~Director();

	/*******************************************************************************
	 * function name : toString												       *
	 * input : nothing.														       *
	 * output : screenWriter as string.										       *
	 * explanation : the function return the Director details as director		   *
	 *		        need to print it.										       *
	 *******************************************************************************/

	string toString();
};

#endif /* DIRECTOR_H_ */
