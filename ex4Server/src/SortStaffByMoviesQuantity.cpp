/*
 * SortStaffByMoviesQuantity.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "SortStaffByMoviesQuantity.h"

/*******************************************************************************
* function name : SortStaffByMoviesQuantity								       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : constructor of a SortStaffByMoviesQuantity.					   *
*******************************************************************************/
SortStaffByMoviesQuantity::SortStaffByMoviesQuantity():SortingStaffType() { }

/*******************************************************************************
* function name : ~SortStaffByMoviesQuantity							       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a SortStaffByMoviesQuantity.					   *
*******************************************************************************/
SortStaffByMoviesQuantity::~SortStaffByMoviesQuantity() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : compare												       *
* input : two pointers of objects Professional.							       *
* output : bool.														       *
* explanation : pure virtual function that return true if the 				   *
* 				first professional's movies quantity is smaller than 		   *
* 				seccond professional and false if it is	bigger.			       *
*******************************************************************************/
bool SortStaffByMoviesQuantity::compare(Professional* firstPro, Professional* seccondPro) {
	return ((*firstPro).getMovies().size() > (*seccondPro).getMovies().size());
}

