/*
 * ScreeanWriter.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef SCREEANWRITER_H_
#define SCREEANWRITER_H_
#include <vector>
#include <string>
#include <iostream>
#include "Professional.h"
using namespace std;

/*******************************************************************************
* class name : ScreenWriter												       *
* explanation : ScreenWriter is class that inherit from professional.		   *
*******************************************************************************/
class ScreenWriter:public Professional{
public:
	/*******************************************************************************
	* function name : ScreenWriter											       *
	* input : all the ScreenWriter parameters: id, age and gender as int,	       *
	*		  name as string.												       *
	* output : nothing.														       *
	* explanation : constructor of a ScreenWriter,								   *
	* 				fill the members with the input.							   *
	*******************************************************************************/
	ScreenWriter(int id , int age, string specificDesc, string gender, string name);

	/*******************************************************************************
	* function name : ~ScreenWriter											       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a ScreenWriter.								   *
	*******************************************************************************/
	virtual ~ScreenWriter();

	/*******************************************************************************
	* function name : printProfessional										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : the function printing the ScreenWriter details as ScreenWriter *
	*		        need to print it.										       *
	*******************************************************************************/

	void printProfessional();
};

#endif /* SCREEANWRITER_H_ */
