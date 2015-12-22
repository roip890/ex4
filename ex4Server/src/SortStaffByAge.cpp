/*
 * SortStaffByAge.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "SortStaffByAge.h"

/*******************************************************************************
* function name : SortStaffByAge										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : constructor of a SortStaffByAge.							   *
*******************************************************************************/
SortStaffByAge::SortStaffByAge():SortingStaffType() { }

/*******************************************************************************
* function name : ~SortStaffByAge										       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a SortStaffByAge.								   *
*******************************************************************************/
SortStaffByAge::~SortStaffByAge() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : compare												       *
* input : two pointers of objects Professional.							       *
* output : bool.														       *
* explanation : pure virtual function that return true if the 				   *
* 				first professional's age is smaller than the				   *
* 				seccond professional and false if it is	bigger.			       *
*******************************************************************************/
bool SortStaffByAge::compare(Professional* firstPro, Professional* seccondPro) {
	return ((*firstPro).getAge() > (*seccondPro).getAge());
}
