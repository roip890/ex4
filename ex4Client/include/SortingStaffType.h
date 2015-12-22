/*
 * SortingStaffType.h
 *
 *  Created on: Dec 5, 2015
 *      Author: roi
 */

#ifndef SORTINGSTAFFTYPE_H_
#define SORTINGSTAFFTYPE_H_

#include "vector"
class Professional;
using namespace std;

/*******************************************************************************
* class name : SortingStaffType											       *
* explanation : SortingStaffType is an abstract comparator.					   *
*******************************************************************************/
class SortingStaffType {
public:
	/*******************************************************************************
	* function name : SortingStaffType										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : constructor of SortingStaffType object.					       *
	*******************************************************************************/
	SortingStaffType();

	/*******************************************************************************
	* function name : ~SortingStaffType										       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a SortingStaffType.							   *
	*******************************************************************************/
	virtual ~SortingStaffType();

	/*******************************************************************************
	* function name : compare												       *
	* input : two pointers of objects Professional.							       *
	* output : bool.														       *
	* explanation : pure virtual function that return true if the 				   *
	* 				first professional's is smaller than seccond professional	   *
	* 				 and false if it is	bigger(depend the inherit class).	       *
	*******************************************************************************/
	virtual bool compare (Professional* firstPro, Professional* seccondPro) = 0;

};

#endif /* SORTINGSTAFFTYPE_H_ */
