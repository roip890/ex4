/*
 * SortStaffById.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef SORTSTAFFBYID_H_
#define SORTSTAFFBYID_H_
#include <vector>
#include "Professional.h"
#include "SortingStaffType.h"

/*******************************************************************************
* class name : SortStaffById											       *
* explanation : SortStaffById is a comparator that inherit					   *
* 				from SortingStaffType.										   *
*******************************************************************************/
using namespace std;
class SortStaffById :public SortingStaffType {
public:
	/*******************************************************************************
	* function name : SortStaffById											       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : constructor of a SortStaffById.								   *
	*******************************************************************************/
	SortStaffById();

	/*******************************************************************************
	* function name : ~SortStaffById										       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a SortStaffById.								   *
	*******************************************************************************/
	virtual ~SortStaffById();

	/*******************************************************************************
	* function name : compare												       *
	* input : two pointers of objects Professional.							       *
	* output : bool.														       *
	* explanation : pure virtual function that return true if the 				   *
	* 				first professional's id is smaller than the					   *
	* 				seccond professional and false if it is	bigger.			       *
	*******************************************************************************/
	bool compare(Professional* firstPro, Professional* seccondPro);

};

#endif /* SORTSTAFFBYID_H_ */
