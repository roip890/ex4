/*
 * Actor.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef ACTOR_H_
#define ACTOR_H_
#include <vector>
#include <string>
#include <iostream>
#include "Professional.h"
using namespace std;

/*******************************************************************************
* class name : Actor													       *
* explanation : Actor is class that inherit from professional.				   *
*******************************************************************************/
class Actor:public Professional {
public:
	/*******************************************************************************
	* function name : Actor													       *
	* input : all the Actor parameters: id, age and gender as int,			       *
	*		  name as string.												       *
	* output : nothing.														       *
	* explanation : constructor of a Actor, fill the members with the input.	   *
	*******************************************************************************/
	Actor(int id , int age, string specificDesc, string gender, string name);

	/*******************************************************************************
	* function name : ~Actor												       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a actor.										   *
	*******************************************************************************/
	virtual ~Actor();

	/*******************************************************************************
	* function name : printProfessional										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : the function printing the Actor details as Actor			   *
	*		        need to print it.										       *
	*******************************************************************************/

	void printProfessional();
};

#endif /* ACTOR_H_ */
