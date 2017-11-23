/*
Angel Martinez
CS 202
Program #: 2
File name: Manager.cpp

The purpose of this file is to be able to 


*/

#include "manager.h"
//the purpose of this function is ot be used as a default
//constructor where we can initialized my own data
stack_reviews::stack_reviews()
{
	//no need of body, since initialization list
	head = new experience(3);
}

//the purpose of this function is to be able to use
//as a copy constructor such that we're able to copy
//taht from the other classes that we're using.
stack_reviews::stack_reviews(const stack_reviews & copy)
{
	deep_copy(copy.head);
}	

//the purpuse of this fucntion is to be use as a destructor that will
//allowed us to free memory we have created.
stack_reviews::~stack_reviews()
{
	remove_all(head);
}

//the purpose of this class is to be able to create a linear linked 
//list of arrays of review. 
int stack_reviews::create_push(char * comment, int rate)
{
	if(!head)
	{
		head = new experience;
		head->add_data(comment,rate);
		head->connect_next(NULL);
	}
	else if(head->add_data(comment,rate) == -1)
	{
		
		experience * temp = new experience(comment,rate);
		temp->connect_next(head);
		head = temp;
	}
	else{
		head->add_data(comment,rate);
	}

  return 1;
}

//the purpose of this function is to be able to remove all dynamic
//memeory that we have use in this class so we can free memory.
int stack_reviews::remove_all(experience *& head)
{
	if(!head) return 0;
	experience  * temp = head->go_next();
	delete head;
	head = temp;

   return remove_all(head);
}
//the purpose of this function is to be use for a display function
//that will allow to display everything in the list.
int stack_reviews::display_all(experience * head)
{
	if(!head) return 0;
	head->display_all();
	
   return display_all(head->go_next());
}

//This is a function that works as a wrapper funtion to display
//all items in the list
int stack_reviews::display_all()
{
	return display_all(head);
}

//the purpose of this function is to be able to create a deep copy
//function that will allow to meke a clean copy of my data onto my
//experience class
int stack_reviews::deep_copy(const experience * from)
{
	if(!from)
	{
		if(!head){
			head = NULL;
			return 0;
		}else{
			remove_all(head);
		}
	}
		head = new experience(*from);
		head->connect_next(NULL);
   return 1;
}

//
//
int stack_reviews::retrieve(const experience & from)
{

   return 0;
}
		
