/*
Angel Martinez
CS202
Assignment #3
File name: family.h
*/
#ifndef FAMILY
#define FAMILY

#include <iostream>
#include <cctype>
#include <cstring>
#include "person.h"

//the purpose of this class is to be able to create the proper
//prototypes so can can be able to create a liner link list of 
//family memebrs
class family
{
	public:
		family();
		family(const family & copy_from);
		~family();
		//bool compare_first_n(char * to_comp);
		//bool compare_last_n(char * to_comp);	
		int insert_member(const Person & to_add, const E_contact & copy_from); 
		int display_all();
		bool check_list4_last_name(const Person & to_add);
		
	protected:
		//all this function must be protected because we can 
		//see what data structure we are using and the point of
		//is so that the programmer does not know what data 
		//structure we are using
		int deep_copy(lll_node *& dest, lll_node * head);
		int remove_all(lll_node *& head);
		int insert_member(const Person & to_add, const E_contact & copy_from, lll_node *& head);
		int display_all(lll_node *& head);
		lll_node * head;
};
#endif

