/*
 * StaffComparator.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef STAFFCOMPARATOR_H_
#define STAFFCOMPARATOR_H_
#include <vector>
#include "SortingStaffType.h"
#include "SortStaffByAge.h"
#include "SortStaffById.h"
#include "SortStaffByMoviesQuantity.h"
class Professional;
using namespace std;

/*******************************************************************************
* class name : StaffComparator											       *
* explanation : StaffComparator is an abstract comparator.					   *
*******************************************************************************/
class StaffComparator {
private:
	int sortingTypeNum;
	SortingStaffType* sortingType;
public:
	/*******************************************************************************
	* function name : StaffComparator										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : constructor of StaffComparator object.					       *
	*******************************************************************************/
	StaffComparator(int sortingType);

	/*******************************************************************************
	* function name : ~StaffComparator										       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a StaffComparator.							   *
	*******************************************************************************/
	virtual ~StaffComparator();

	/*******************************************************************************
	* function name : operator()												   *
	* input : two objects of const Professional.							       *
	* output : bool.														       *
	* explanation : pure virtual function that return true if the				   *
	* 				first professional is "smaller" (the compeerator decide the	   *
	*				implementation) than the seccond professional and 0 if it is   *
	*				"bigger".												       *
	*******************************************************************************/
	bool operator () (Professional* firstPro, Professional* seccondPro);

	/*******************************************************************************
	 * function name : setSortingType										       *
	 * input : set the type of how the staff vector will be sorted as int.	   	   *
	 * output : nothing.													       *
	 * explanation : set the type of how the staff vector will be sort:	 	       *
	 *				1 - for sorting by id.									       *
	 *				2 - for sorting by age.									       *
	 *				3 - for sorting by the movies quantity of the professional.    *
	 *******************************************************************************/
	void setSortingType(int sortingType);

	/*******************************************************************************
	 * function name : setSortingType										       *
	 * input : nothing.														       *
	 * output : the type of how the staff vector will be sorted as int.		       *
	 * explanation : return the member of type of how the staff vector will be sort*
	 *				1 - for sorting by id.									       *
	 *				2 - for sorting by age.									       *
	 *				3 - for sorting by the movies quantity of the professional.    *
	 *******************************************************************************/
	int getSortingType();
};

#endif /* STAFFCOMPARATOR_H_ */
