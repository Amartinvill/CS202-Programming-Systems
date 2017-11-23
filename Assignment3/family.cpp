/*
Angel Martinez
CS202
Assignment #3
File Name: family.cpp
*/

#include "family.h"
using namespace std;

//This is a default constructor that allowes the use of
//initialization list to kick start the proper constructor
family::family():head(NULL)
{
}

//this is a copy constructor that makes a close of itself
//onto a different list
family::family(const family & copy_from)
{
	lll_node * temp = copy_from.head;
	deep_copy(temp, head);
}

//this is a distructor that allowed to deallocated the momory
//we have used in the list
family::~family()
{
	remove_all(head);
}

//This is a copy function that allowed to copy of our list onto
//another list of the same type
int family::deep_copy(lll_node *& dest, lll_node * head)
{
	if(!head)
	{
		dest = NULL;
		return 0;
	}
	
	if(!dest)
	{
		dest = new lll_node(*head);
		dest = head;
		dest->connect_next(NULL);
	}
	
   return deep_copy(dest->get_next(), head->get_next());
}

//this is a function that allowed us to remove all the dynamic
//data we have used in the list recursivly
int family::remove_all(lll_node *& head)
{
	if(!head) return 0;
	int val = remove_all(head->get_next());
	if(!head->get_next())
	{
		delete head;
		head = NULL;
	}
   return val;
}

//this is a wrapper function that allowes us to use it it in the
//user interface or main and expects two object of two different 
//classes
int family::insert_member(const Person & to_add, const E_contact & copy_from)
{
	return insert_member(to_add, copy_from, head);
}

//this is a function that allowed us to create a linear linke like
//of individual of the same last name in sorted order by name
int family::insert_member(const Person & to_add, const E_contact & copy_from, lll_node *& head)
{
	if(!head)
	{
		
		head = new lll_node(to_add);
		head->copy_methods(copy_from);
		head->connect_next(NULL);
		return 0;
	}
	if(head->compare_first_name(to_add))
	{
		lll_node * temp = head;
		head = new lll_node(to_add);
		head->copy_methods(copy_from);
		head->connect_next(temp);
		return 0;
	}
	
   return insert_member(to_add, copy_from, head->get_next());
}

//this is a wrapper function that allows to diaply all the data
int family::display_all()
{
	return display_all(head);
}

//this is a diaplay function that displays all the data in the list
//using recursion
int family::display_all(lll_node *& head)
{
	if(!head) return 0;
	head->display_all();
	head->display_methods();

   return display_all(head->get_next());
}

//seeing if this function will compare if the last name is in the
//list
bool family::check_list4_last_name(const Person & to_add)
{
	if(!head)return 0;

	if(head->compare_last_name(to_add))
		return true;
   return false;
}
