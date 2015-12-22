/*
 * SortStaffById.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "SortStaffById.h"

/*******************************************************************************
* function name : SortStaffById											       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : constructor of a SortStaffById.								   *
*******************************************************************************/
SortStaffById::SortStaffById():SortingStaffType() { }

/*******************************************************************************
* function name : ~SortStaffById										       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a SortStaffById.								   *
*******************************************************************************/
SortStaffById::~SortStaffById() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : compare												       *
* input : two pointers of objects Professional.							       *
* output : bool.														       *
* explanation : pure virtual function that return true if the 				   *
* 				first professional's id is smaller than the					   *
* 				seccond professional and false if it is	bigger.			       *
*******************************************************************************/
bool SortStaffById::compare(Professional* firstPro, Professional* seccondPro) {
	return ((*firstPro).getId() < (*seccondPro).getId());
}
