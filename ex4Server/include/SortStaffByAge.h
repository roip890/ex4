/*
 * SortStaffByAge.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef SORTSTAFFBYAGE_H_
#define SORTSTAFFBYAGE_H_
#include <vector>
#include "Professional.h"
#include "SortingStaffType.h"
using namespace std;

/*******************************************************************************
* class name : SortStaffByAge											       *
* explanation : SortStaffByAge is a comparator that inherit					   *
* 				from SortingStaffType.										   *
*******************************************************************************/
class SortStaffByAge:public SortingStaffType{
public:
	/*******************************************************************************
	* function name : SortStaffByAge										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : constructor of a SortStaffByAge.							   *
	*******************************************************************************/
	SortStaffByAge();

	/*******************************************************************************
	* function name : ~SortStaffByAge										       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a SortStaffByAge.								   *
	*******************************************************************************/
	virtual ~SortStaffByAge();

	/*******************************************************************************
	* function name : compare												       *
	* input : two pointers of objects Professional.							       *
	* output : bool.														       *
	* explanation : pure virtual function that return true if the 				   *
	* 				first professional's age is smaller than the				   *
	* 				seccond professional and false if it is	bigger.			       *
	*******************************************************************************/

	bool compare(Professional* firstPro, Professional* seccondPro);
};

#endif /* SORTSTAFFBYAGE_H_ */
