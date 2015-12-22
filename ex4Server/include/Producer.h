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
* class name : Producer													       *
* explanation : Producer is class that inherit from professional.			   *
*******************************************************************************/
class Producer:public Professional {
public:
	/*******************************************************************************
	* function name : Producer												       *
	* input : all the Producer parameters: id, age and gender as int,		       *
	*		  name as string.												       *
	* output : nothing.														       *
	* explanation : constructor of a Producer, fill the members with the input.	   *
	*******************************************************************************/
	Producer(int id , int age, string specificDesc, string gender, string name);


	/*******************************************************************************
	* function name : ~Producer												       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a Producer.									   *
	*******************************************************************************/
	virtual ~Producer();

	/*******************************************************************************
	* function name : printProfessional										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : the function printing the Producer details as Producer		   *
	*		        need to print it.										       *
	*******************************************************************************/

	void printProfessional();

};

#endif /* PRODUCER_H_ */
