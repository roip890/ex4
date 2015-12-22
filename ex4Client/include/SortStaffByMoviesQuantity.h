/*
 * SortStaffByMoviesQuantity.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef SORTSTAFFBYMOVIESQUANTITY_H_
#define SORTSTAFFBYMOVIESQUANTITY_H
#include <vector>
#include "Professional.h"
#include "SortingStaffType.h"
using namespace std;

/*******************************************************************************
* class name : SortStaffByMoviesQuantity								       *
* explanation : SortStaffByMoviesQuantity is a comparator that				   *
* 				inherit	from SortingStaffType.								   *
*******************************************************************************/
class SortStaffByMoviesQuantity:public SortingStaffType {
public:
	/*******************************************************************************
	* function name : SortStaffByMoviesQuantity								       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : constructor of a SortStaffByMoviesQuantity.					   *
	*******************************************************************************/
	SortStaffByMoviesQuantity();

	/*******************************************************************************
	* function name : ~SortStaffByMoviesQuantity							       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a SortStaffByMoviesQuantity.					   *
	*******************************************************************************/
	virtual ~SortStaffByMoviesQuantity();

	/*******************************************************************************
	* function name : compare												       *
	* input : two pointers of objects Professional.							       *
	* output : bool.														       *
	* explanation : pure virtual function that return true if the 				   *
	* 				first professional's movies quantity is smaller than 		   *
	* 				seccond professional and false if it is	bigger.			       *
	*******************************************************************************/
	bool compare(Professional* firstPro, Professional* seccondPro);
};

#endif /* SORTSTAFFBYMOVIESQUANTITY_H*/
