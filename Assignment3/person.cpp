/*
Angel Martinez
CS202
Assignment #3
File name:person.cpp
*/
#include "person.h"
using namespace std;


//default constructor that uses initialization list
Person::Person():first_n(NULL),last_n(NULL)
{
}

//constructor that takes two arguments and copies it to out 
//own data memebers
Person::Person(char * first, char * last)
{
	copy_data(first,last);
	
}

//this is a copy constructor that take makes a copy of the
//class, a close sort of speak to another object of the same
//class type
Person::Person(const Person & copy_from)
{
	deep_copy(copy_from);	
}

//This is the destructor that allows for the memory to be
//remove form this class
Person::~Person()
{
	remove_dyn_mem();
}

//what this function does is that it allows us to have arguments
//passed and be copies to the data member of the class
void Person::copy_data(char * first, char * last)
{
	if(first_n)
		delete [] first_n;
	first_n = new char[strlen(first) + 1];
	strcpy(first_n, first);

	if(last_n)
		delete [] last_n;
	last_n = new char[strlen(last) + 1];
	strcpy(last_n, last);
}

//this is a copy function that allows data to be copied form a 
//seperate object of the same class type
void Person::deep_copy(const Person & copy_from)
{
	if(first_n)
	delete [] first_n;
	first_n = new char[strlen(copy_from.first_n) + 1];
	strcpy(first_n, copy_from.first_n);

	if(last_n)
		delete [] last_n;
	last_n = new char[strlen(copy_from.last_n) + 1];
	strcpy(last_n, copy_from.last_n);
}

//This allowes to display all the data in the class
void Person::display_all()
{
	cout <<"First name: " << first_n <<endl;
	cout <<"Last name: " << last_n <<endl;
}

//the purpose of this function is to be use as a remove all
//where it dealocated all memory that was used
void Person::remove_dyn_mem()
{
	if(first_n)
		delete [] first_n;
	
	if(last_n)
		delete [] last_n;
}

//what this function does is allow us to compare an object with 
//the right data member to see if we have it in the list
bool Person::compare_first_name(const Person & to_comp)
{
	if(strcmp(first_n, to_comp.first_n) > 0)
		return true;	//data being compare is greater
				//lets assume david is been compare
				//and angel is already a in our class
				//angel goes before david alpabetically
   return false; //Just return 0 we the data to compare is the same
}

//what this function does is allow us to compare an object with 
//the right data member to see if we have it in the list
bool Person::compare_last_name(const Person & to_comp)
{
	if(strcmp(last_n, to_comp.last_n) == 0)
		return true;
   return false;
}

//the purpose of this function is to be able to retrieve data that
//we are interested in
bool Person::retrieve()
{
	
   return false;
}

/************************lll_node class**************************/	

//a default constructor for a node class using initialization list
lll_node::lll_node():next(NULL)
{
}

//this is a constructor that takes arguments and uses initialization list
//aswell as a wrapper so we can also initialize the object of class 
//E_contact
lll_node::lll_node(char * first, char * last, char * method_1, char * method_2, char * method_3):Person(first,last), next(NULL)
{
	methods = E_contact(method_1,method_2,method_3);
}

//the use of this function is to have a copy constructor that
//allows to make clone of itself
lll_node::lll_node(const Person & copy_from):Person(copy_from)
{
}

//The purpose of this function is to get the next pointer
lll_node *& lll_node::get_next()
{
	return next;
}

//the purpose of this function is to be able to connect the next pointer
void lll_node::connect_next(lll_node * connection)
{
	next = connection;
}

//the purpose of this function is to be used as a wrapper function that 
//allows the if of E_contact to be used in the node
void lll_node::copy_methods(const E_contact & to_copy)
{
	methods.deep_copy(to_copy);
}

//The purpose of this function is to be able to display the methods and
//used as a wrapper function so we can access the data in the class
void lll_node::display_methods()
{
	methods.display_info();
}
