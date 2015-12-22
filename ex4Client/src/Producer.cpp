/*
 * Producer.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "Producer.h"
using namespace std;

/*******************************************************************************
* function name : Producer												       *
* input : all the Producer parameters: id, age and gender as int,		       *
*		  name as string.												       *
* output : nothing.														       *
* explanation : constructor of a Producer, fill the members with the input.	   *
*******************************************************************************/
Producer::Producer(int id , int age, string specificDesc, string gender, string name):
		Professional(id, age, specificDesc, gender, name){
	this->id = id;
	this->specificDesc = specificDesc;
	this->name = name;
	this->age = age;
	this->gender = gender;
}

/*******************************************************************************
* function name : ~Producer												       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a Producer.									   *
*******************************************************************************/
Producer::~Producer() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : printProfessional										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : the function printing the Producer details as Producer		   *
*		        need to print it.										       *
*******************************************************************************/

void Producer::printProfessional() {
	cout << this->name << endl;
}
