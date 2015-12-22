/*
 * Actor.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "Actor.h"
#include "vector"
using namespace std;

/*******************************************************************************
* function name : Actor													       *
* input : all the Actor parameters: id, age and gender as int,			       *
*		  name as string.												       *
* output : nothing.														       *
* explanation : constructor of a Actor, fill the members with the input.	   *
*******************************************************************************/
Actor::Actor(int id , int age, string specificDesc, string gender, string name):
				Professional(id, age, specificDesc, gender, name){
	this->id = id;
	this->specificDesc = specificDesc;
	this->name = name;
	this->age = age;
	this->gender = gender;
}
/*******************************************************************************
* function name : ~Actor												       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a actor.										   *
*******************************************************************************/
Actor::~Actor() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : printProfessional										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : the function printing the Actor details as Actor			   *
*		        need to print it.										       *
*******************************************************************************/

void Actor::printProfessional() {
	cout << this->name << " " << this->age << endl;
}
