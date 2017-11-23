/*
Angel Martinez
CS202 
Program #: 2
File Name: Node.h

The purpose of this file is to be able to create a header
file for a node class. we will be using this class to
construct a liner link list with integer as a data
member for times.
*/

#include <iostream>
#include <cstring>
#include <cctype>

#ifndef NODE
#define NODE 
//This is a class node
class node
{
	public: 
		node();
		node(int new_time);
		node *& go_next();
		void connect_next(node * connect);
		void set_int(int time);
		int get_int();

	protected:
		int times;
		node * next;
};
#endif

