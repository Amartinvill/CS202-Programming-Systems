/*
Angel Martinez
CS202
Program #: 2
File name: Tansportation.h

The purpose of this file is to be able to create a system 
that' sbe able to support different types of transportation 
systems where each system deals with a period of time 
diferently. This file will have such class header where
we well be experienceing a hirerachy and dynamic bynding
*/
#include "node.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>

//The purpose of this class of to be use as a base class
//We already know what the derive classes need and data
//that share similarities therefore we can make this class
//ass the hub for all types of tansportations
class transit
{
	public:
		transit();
		transit(const transit & form);
		transit(double price);
		virtual ~transit();
		virtual bool check_status();
		virtual double set_cost(double cost) =  0;
		virtual int average_time();
		virtual int set_time_intervals();
		virtual int  display(); 
	protected:
		bool status;
		double cost;
		node * head;
};

class bus: public transit
{
	public:
		bus();
		bus(const transit & from);
		bus(int mid_day_intervals, double price);
		double set_cost(double cost);	
		int set_times_intervals();		
		int average_time();
		int display();
		
	protected:
		node * head;
		int average_time(node *& head);
		int times;
		int mid_day;

};

class train: public transit
{
	public:	
		train();
		train(const transit & form);
		train(int range, double price);
		double set_cost(double cost);
		int set_times_intervals();
		int average_time();
		int display();
		
	protected:
		node * head;
		int average_time(node *& head);
		int weekly;
		int times;
};
/*
class uber: public transit
{
	public:
		uber();
		uber(char * name);
		uber(const transit & );
		~uber();
		void display();
		
	protected:
		int weekend_volume;
		char * uber_cost;
} 
*/
