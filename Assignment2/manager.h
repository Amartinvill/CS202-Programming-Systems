/*
Angel Martinez
CS202 
Program #: 2
File Name: manager.h

The purpose of this file is to be able to create a management
header file, that will be able to create the program's
functionality where this class will handling multiple object to 
compose the entire problem.

*/

#include "experience.h"

/*
The purpose of this class is to be able to construct a header class
that will be used to create the list of reviews in a Linear Link list
like fashion.
*/

class stack_reviews 
{
	public:
		stack_reviews();
		stack_reviews(const stack_reviews  & copy);
		~stack_reviews();
		int create_push(char * comment, int rate);
		int create_pop();
		int deep_copy(const experience * from);
		int display_all();
		int retrieve(const experience & from);
		
	private:	
		int display_all(experience * head);
		int remove_all(experience *& head);
		experience  * head;
};


