/*
Angel Martinez
CS202
Assignmnet #3
File Name: bst_node.cpp
*/


#include "bst_node.h"
using namespace std;
//this is a default constructor that allows to invoke
//the right constructor and this uses initialization list
rb_node::rb_node():left(NULL), right(NULL), flag(true)
{}

//This is a getter function that allows to get the right
//pointer
rb_node *& rb_node::go_right()
{

	return right;
}

//similarly this is a getter function that get the
//left pointer
rb_node *& rb_node::go_left()
{
	return left;
}

//this is also a getter function that allows to be 
//able to get the parent ponter
rb_node *& rb_node::go_parent()
{
	return parent;
}

//this is a setter funtion for this node class that
//allows to se the parent pointer to another pointer
void rb_node::connect_parent(rb_node * connect)
{
	parent = connect;
}

//this is a setter funtion for this node class that
//allow to set the left pointer to another pointer 
void rb_node::connect_left(rb_node * connect)
{
	left = connect;
}

//
void rb_node::connect_right(rb_node * connect)
{
	right = connect;
}

//this is a getter function that allows to get the
//color of the flag.
bool rb_node::flag_is_red()
{
	return flag;
}

//this is a setter that set the color of the flag
void rb_node::set_flag(bool color)
{
	flag = color;
}

//this is a wrapper function for a display that 
//allows me to call in the display function for
//the list class containing the members
void rb_node::display_list()
{
	head.display_all();
}
