/*
 * ScreeanWriter.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "ScreenWriter.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*******************************************************************************
* function name : ScreenWriter											       *
* input : all the ScreenWriter parameters: id, age and gender as int,	       *
*		  name as string.												       *
* output : nothing.														       *
* explanation : constructor of a ScreenWriter,								   *
* 				fill the members with the input.							   *
*******************************************************************************/
ScreenWriter::ScreenWriter(int id , int age, string specificDesc, string gender, string name):
						Professional(id, age, specificDesc, gender, name){
	this->id = id;
	this->specificDesc = specificDesc;
	this->name = name;
	this->age = age;
	this->gender = gender;
}

/*******************************************************************************
* function name : ~ScreenWriter											       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a ScreenWriter.								   *
*******************************************************************************/
ScreenWriter::~ScreenWriter() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : printProfessional										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : the function printing the ScreenWriter details as ScreenWriter *
*		        need to print it.										       *
*******************************************************************************/

void ScreenWriter::printProfessional() {
	cout << this->name << " " << this->specificDesc << endl;
}
