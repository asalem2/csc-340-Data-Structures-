/* Ahmed Salem
* 910017087
* ahmeds@mail.sfsu.edu
* Class:Hui Yang 340-01
* Date:December 10, 2014
* IDE/Compiler: Netbeans
* This program is the exception header file for the linkedList ADT
*/

#ifndef _LIST_EXCEPTIONS_H
#define _LIST_EXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;

class ListIndexOutOfRangeException : public out_of_range
{
public:

	/**/
	ListIndexOutOfRangeException(const string & message = "")
		: out_of_range(message.c_str())
	{ }  // end constructor
	/**/
	//virtual const char* what() const throw()
	//{return "list: out of range";}
}; // end ListIndexOutOfRangeException


class ListException : public logic_error
{
public:

	/**/
	ListException(const string & message = "")
		: logic_error(message.c_str())
	{ }  // end constructor
	/**/
	// virtual const char* what() const throw()
	//{return "list: logic error";}  //list is full
}; // end ListException

#endif