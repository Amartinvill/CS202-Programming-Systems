/*
Angel Martinez
CS202
Program #:2 
File name: experience.cpp

The purpose of this class is to be able to implement the 
prototypes for experience class and create the dynamic
memory respectiveley. This class is also a node of experiences
where each node have a pointer to a list of reviews
*/
#include "experience.h"
using namespace std;
//The purpose of this function is to be used as a default
//constructor for this node of reviews
experience::experience(int size)
{
	review = NULL;
	rate = 0;
	index = 0;
	list_size = size;
	next =NULL;
}

//The purpose of this function is to be used as a copy constroctor
//for this class so it can performed a deep copy.
experience::experience(const experience & from): review(NULL), rate(from.rate), next(NULL),index(from.index), list_size(from.list_size)
{
	if(from.review == NULL) return;
	review = new char * [list_size];
	
	for(int i=0; i<list_size; ++i)
	{
		review[i] = new char[strlen(from.review[i]) + 1];
		strcpy(review[i], from.review[i]);
	}	
	
	if(from.next)
		next = new experience(*(from.next));
	//else next = NULL;
}

//the purpose of this function is to be able to as a constructor
//where it passes data to initialized the ones in this class
experience::experience(char * new_review, int new_rate)
{
	add_data(new_review, new_rate);
}

//The purpose of this function is to be used as a deconstructor
//that allowes to dealocate data that has been dynamically allocated
experience::~experience()
{
	remove_dyn_mem();
}

//This is a copy function that makes a copy of the arguments been 
//passed in to the data member of this class.
int experience::add_data(char * new_review, int new_rate)
{
	
	rate = new_rate;
	if(!review)
	{
		index = 0;
		review = new char * [list_size];
		review[index] = new char[strlen(new_review) + 1];
		strcpy(review[index], new_review);
		++index;
	}	
	else if(index<list_size)
	{
		review[index] = new char[strlen(new_review) + 1];
		strcpy(review[index], new_review);
		++index;
	}
	else if(index==list_size)
		return -1;
   return 1;
}

//the purpose of this fucntion is to create a deep coppy of an 
//object of the class for the right data memebers
void experience::deep_copy(const experience & to_copy)
{

}
//The purpose of this fucntion is to be use as a display function
//that will allow to display the review's data
int experience::display_review()
{
	if(!review) return 0;
	cout<<"Experience: " << review[index] << endl;
   return 1;
}

//The purpose of this function is similar to our previous function
//the diference is that this function displays all the data;
int experience::display_all()
{
	if(!review) return 0;

	for(int i = 0; i<list_size; ++i)
	{	
		cout<<"Experinece: " << review[i] << endl;
		//cout<<"Rate 1-10: " << rate << endl;
	}
   return 1;
}
/*
//The purpose of this fucntion is to be use as comparison of data
//If the data is a match, it returns true.
bool experience::compare(char * comp_rider)
{
	if(strcmp(rider, comp) ==0);
	return true;
   return false;
}
*/
//the purpose of this function is to be able to delete the allocated
//Memory we have create so we can realiese it.
int experience::remove_dyn_mem()
{
	if(!review) return 0;

	for(int i = 0; i<list_size; ++i)
	{
		if(review[i])
			delete [] review[i];
		review[i] = NULL;
	}
	review = NULL;
   return 1;
}

//the purpose of this fucntion is to be able to return the next ptr
//the this node such that we can ble able to build a list of them
experience *& experience::go_next()
{
	return next;
}

//the purpose of this fucntion is to be able to connect the nodes.
//this function makes this happend by passing in a point to connect with
void experience::connect_next(experience * connection)
{
	next = connection;
}

