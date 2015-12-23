/*
 * Producer.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef PRODUCER_H_
#define PRODUCER_H_
#include <vector>
#include <string>
#include <iostream>
#include "Professional.h"
using namespace std;

/*******************************************************************************
 * class name : Producer												       *
 * explanation : Producer is class that inherit from professional.			   *
 *******************************************************************************/
class Producer: public Professional {
public:
	/*******************************************************************************
	 * function name : Producer												       *
	 * input : all the Producer parameters: id, age and gender as int,		       *
	 *		  name as string.												       *
	 * output : nothing.													       *
	 * explanation : constructor of a Producer, fill the members with the input.   *
	 *******************************************************************************/
	Producer(int id, int age, string specificDesc, string gender, string name);

	/*******************************************************************************
	 * function name : ~Producer											       *
	 * input : nothing														       *
	 * output : nothing.													       *
	 * explanation : destructor of a Producer.									   *
	 *******************************************************************************/
	virtual ~Producer();

	/*******************************************************************************
	 * function name : toString												       *
	 * input : nothing.														       *
	 * output : screenWriter as string.										       *
	 * explanation : the function return the Producer details as producer		   *
	 *		        need to print it.										       *
	 *******************************************************************************/

	string toString();

};

#endif /* PRODUCER_H_ */
