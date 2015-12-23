#include "Director.h"
using namespace std;

/*******************************************************************************
* function name : Director												       *
* input : all the Director parameters: id, age and gender as int,		       *
*		  name as string.												       *
* output : nothing.														       *
* explanation : constructor of a Director, fill the members with the input.	   *
*******************************************************************************/
Director::Director(int id , int age, string specificDesc, string gender, string name):
						Professional(id, age, specificDesc, gender, name){
	this->id = id;
	this->specificDesc = specificDesc;
	this->name = name;
	this->age = age;
	this->gender = gender;
}

/*******************************************************************************
* function name : ~Director												       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a Director.									   *
*******************************************************************************/
Director::~Director() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
 * function name : toString												       *
 * input : nothing.														       *
 * output : screenWriter as string.										       *
 * explanation : the function return the Director details as director		   *
 *		        need to print it.										       *
 *******************************************************************************/

string Director::toString() {
	return this->name + "\n";
}
