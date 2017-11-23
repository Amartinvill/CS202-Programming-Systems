/*
Angel Martinez
CS202 
Assignment #: 2
File Name: node.cpp

The purpose of this file is to be able to create a node class
with just a next pointer that will alow us to have an int
as its data member. This node's purpopse is so we can make a 
linear linked list of int times for future transportations
*/
#include "node.h"
using namespace std;

//The purpose of this function is to be use as a default
//constructor for the use of this class
node::node():times(0), next(NULL)
{
	//no body needed because of initializatio list
}

//the purpose of this function is to be use as a constructor
//that takes an integer as an argument in the case that we 
//was to use this constructor with an integer as an argument
node::node(int new_time)
{
	//no body needed yet again becaus of the power
	//of initialzation list
	times = new_time;
	next = NULL;
}

//This function just return the next pointer so we can be
//able to dereference our next pointer.
node *& node::go_next()
{
	return next;
}


//This only functionality of this fucntion is to our next
//pointer can be connected or set to.
void node::connect_next(node * connect)
{
	next = connect;
}

void node::set_int(int time)
{
	times = time;
}

int node::get_int()
{
	return times;
}
