/*
Angel Martinez
CS 202
Program #: 2
File name: experience.h

The purpose of this file is to create a header file for 
expereiences where I need to set the proper prototypes.
Once this is done, I can proceed in the implementation 
and this class can be used to be part of other classes
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

/*
The purpose of this class is to be able to create the
propper prototype for an experience class where I have
experience as a data member. I should be able to set 
all the basic insert,compare, retreive and display so 
I don't have a problem when i try to access this data.
*/
class experience //node
{
	public:
		experience(int size = 3);
		experience(const experience & from);
		experience(char * review, int rate);
		~experience();
		int add_data(char * review, int rate);
		void deep_copy(const experience & to_copy);
		int display_review();
		int display_all();
		//bool compare(char * comp_rider);
		bool retrieve(experience *& to_copy, char * to_find);
		int remove_dyn_mem();

		experience *& go_next();
		void connect_next(experience * connection);
	protected:
		char ** review;
		int rate;
		experience * next;
		int index;
		int list_size;
};

