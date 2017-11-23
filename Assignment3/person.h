/*
Angel Martinez
CS202
Assignment #3
File Name: Person.h
*/

#ifndef PERSON
#define PERSON

#include <iostream>
#include <cctype>
#include <cstring>
#include "methods.h"

//The purpose of this class is to be able to create a person
//whos information can be store such as thir name and last
//name.
class Person
{
	public:
		//default constructor
		Person();
		//constructor that take arguments
		Person(char * first, char * last);
		//coppy constructor that takes a persons object
		Person(const Person & copy_from);
		//destructor
		~Person();
		//allows data to be copies to the data memebers
		void copy_data(char * first, char * last);
		//creates a copy of the class, a clone
		void deep_copy(const Person & copy_from);
		//alloes to display all the data
		void display_all();
		//removes all dynamic memory
		void remove_dyn_mem();
		//compares name with a name passed in
		bool compare_first_name(const Person & to_comp);
		//compares last name with a last name passes in
		bool compare_last_name(const Person & to_comp);
		//retreives data we want
		bool retrieve();
	
	protected:
		//data members for a name and a last name
		char * first_n;
		char * last_n;
};


//this is a node class that is being derive form person
//so essentially we are a person plus more. we have this class
//so we can be able to store data intothi node
class lll_node: public Person
{
	public:
		//default constructor
		lll_node();
		//constructor that takes arguments
		lll_node(char * fist_n, char * last_m, char * method_1, char * method_2, char * method_3);
		//copy constructor
		lll_node(const Person & copy_form);
		//a function that return our next pointer
		lll_node *& get_next();
		//this allows to connect next pointer
		void connect_next(lll_node * connection);
		//wraper function to be ablet to copy data of methods
		void copy_methods(const E_contact & to_copy);
		//wrapper function for display methods
		void display_methods();

	protected:
		//objest of clas E_contact
		E_contact methods;
		//next pointer
		lll_node * next;
};
		
#endif
