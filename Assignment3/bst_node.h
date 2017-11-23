/*
Angel Martinez
CS202
Assignment #3
File Name: bst_node.h
*/


#ifndef BST_NODE
#define BST_NODE
#include <iostream>
#include <cctype>
#include <cstring>
#include "family.h"


//this is the node class that to build the balance tree
//i am going to be buindign a red black tree.
//this node will require a previous pointer wich will 
//be calling parent. Aside of this its just like a 
//normal balance tree
class rb_node
{
	public:
		//default constructor
		rb_node();
		//what this functions do are to return the right
		//left and parent
		rb_node *& go_right();
		rb_node *& go_left();
		rb_node *& go_parent();

		//these next funtion allow us to be connect our
		//pointer to some rb_node pointer that get
		//passed in.
		void connect_parent(rb_node * connect);
		void connect_left(rb_node * connect);
		void connect_right(rb_node * connect);
		
		//this is a display function that displays the list
		void display_list();
		

		//this are setters and getter for the flag to set
		//and get a flag  color
		bool flag_is_red();
		void set_flag(bool color);
	private:
		//this are all the pointer that we will be using
		rb_node * left;
		rb_node * right;
		//this works as a previous pointer
		rb_node * parent;
		
		bool flag;
		lll_node head;
};
#endif
