/*
 * SortingStaffType.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: roi
 */

#include "SortingStaffType.h"
using namespace std;





/*******************************************************************************
* function name : SortingStaffType										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : constructor of a SortingStaffType.							   *
*******************************************************************************/
SortingStaffType::SortingStaffType() { }

/*******************************************************************************
* function name : ~SortingStaffType										       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a SortingStaffType.							   *
*******************************************************************************/
SortingStaffType::~SortingStaffType() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : compare												       *
* input : two pointers of objects Professional.							       *
* output : bool.														       *
* explanation : pure virtual function that return true if the 				   *
* 				first professional's is smaller than seccond professional	   *
* 				 and false if it is	bigger(depend the inherit class).	       *
*******************************************************************************/
bool SortingStaffType::compare (Professional* firstPro, Professional* seccondPro) {
	return true;
}
