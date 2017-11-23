/*
Angel Martinez
CS202
Assignmnet #:2
File Name: Transportation.cpp

The purpose of this file is to be able to implement a hub 
class/abstract base class of mass transportation. This
will allowed us to experience that use of dynamic biding 
will the keyword virtual. We will also create the devied 
classes such that we have multiple derive transportation
systems
*/

#include "transportation.h"
using namespace std;

//The purpose of this function is to be use as a default
//constructor for our hub class so it can be invoke in time
//as needed.
transit::transit():cost(0)
{
	//no body needed because of the power of initilization
	//list. 
}

//This is yet another constructor where in this case it
//takes an object of the same class as an argumnet. This
//then become a copy constructor
transit::transit(const transit & from):cost(0)
{
	//create a deep copy funtion
	//similar to what i have done in experience class.
}

//The purpose of this function is to have a constroctor
//that takes a integer as an argument
transit::transit(double price):cost(price)
{
}

//I think is a rule whenever we have an abstract base class
//that we should make the distructor virtual which means that
//derive class will be inplementing it
transit::~transit()
{
	//node body need since is virtual
}

//This function will not be abailable for this class, though 
//the derive class should be implementing it. This will let us
//now the staus of the transportation
bool transit::check_status(){return false;}

//same as previous function, this will not be implemented in
//this perticular class but derive classes will handed it.
//*****double transit::set_cost(double cost){ return 0;}

//last but not least we will be using a display function
//that only will be implemeneter in the derive calsses;
int transit::display(){ return 0;}
int transit::average_time(){ return 0;}
int transit::set_time_intervals(){ return 0;}
/*8888888888888888888888-bus_derive_class-888888888888888888888888888*/

//the use of this function is to be able to use it a default
//constructor that will allowed to be invoked at due time
bus::bus():head(NULL),times(0),mid_day(0)
{
	//no code needed, because of initialization list
}

//the purpose of this function is to be able to use as a
//constructor for the bus derive class that initializes and
//invokes the correct constructor
bus::bus(int mid_day_intervals, double price):transit(price)
{
	head = NULL;
	//again, no body is need, power of initialization list
	times = mid_day_intervals;
	//cost = price;
}

//from here on now in this class, this is where the magic happens
//we will be implementing the set cost for the use of the base class
double bus::set_cost(double price = 2.50)
{
	cost = price;
   return cost;
}


//the purpose of this function is to be able to create a function
//that sets the the time intervall for of the transit for this class
int bus::set_times_intervals()
{
	int delay = 0;
	if(times >= 8  && times <12)
	{
		delay = rand() % 25 + 10;
		 return mid_day = delay;
	}
	if(times >= 12 && times<16)
	{
		delay = rand() % 18 + 8;
		return mid_day = delay;
	}	
	if(times >=16 && times < 19)
	{
		delay = rand() % 35 + 15;
		return mid_day = delay;
	}
	else
		cout<< "Please enter the right intervals!" <<endl;
return -1;
}

//the purpose of this class is to be able to create a linear linked
//list of averages of the times.
int bus::average_time(node *& head)
{
	if(!head)
	{
		int time = set_times_intervals();
		head = new node(time);
		head->connect_next(NULL);
		return 0;
	}
	
	int time = set_time_intervals();
	node * temp = new node(time);
	temp->connect_next(head);
	head = temp;

   return 1;
}

//this is is a wrapper function that allow us to have a head pointer
//passed so we can create the list of LLL of average times
int bus::average_time()
{
	return average_time(head);
}	

//this function functionality is so that I can be able to display
//the datat in the linked list as well as display what status of 
//the transit chossen;
int bus::display()
{
	
	cout<<"Cost of Bus fair: " <<cost<<endl;
	if(head->get_int() <=10)
		cout<<"Busses are running at their normal time!"<<head->get_int()<<endl;
	else if(head->get_int() > 10 && head->get_int() <=18)
		cout<<"Busses are moderatly runnig late!"<<endl;
	else
		cout<<"Busses will be delayed, traffic is at this peek" <<endl;	
	
   return 0;
}

/***********************Train derive class***********************/
//the purpose of this function is to be used as a constructor for
//for the train class
train::train():head(NULL),weekly(0), times(0)
{
	//no body needed, initialization list
}

//the purpose of this function is to be use a a constructor that
//takes argument so they can initialized out data
train::train(int range, double price):transit(price)
{
	head = NULL;
	weekly = range;
}

//the purpose of this class is to be able to create a function that
//allows us to set an specific rate for the class
double train::set_cost(double price = 23.50)
{
	cost = 	price;

   return cost;
}

//the purpose of this class is to be abel to create a function that
//created an average volume of times for this class
int train::set_times_intervals()
{
	int delay = 0;
	if(weekly == 4 || weekly == 5)
	{
		delay = rand() % 5 + 2;
		 return times = delay;
	}
	if(weekly == 6 || weekly == 7)
	{
		delay = rand() % 8 + 3;
		return times = delay;
	}	
	if(weekly == 1 || weekly == 2 || weekly == 3)
	{
		delay = rand() % 4 + 1;
		return times = delay;
	}
	else
		cout<< "Please enter the right dates!" <<endl;
return -1;
}

//the purpose of this function is to be able to create a wrapper function
//that will allowed me to passed a head pointer as the argument so i 
//can call it in the main with out the programer to know what data
//strcuture i am using
int train::average_time()
{
	return average_time(head);
}

//This function then does the magic and creat the list of link list 
//of averages volume for the train class
int train::average_time(node *& head)
{
	int holder = 0;
	if(!head)
	{
		holder = set_times_intervals();
		head = new node(holder);
		return 0;
	}
	
	holder = set_times_intervals();
	node * temp = new node(holder);
	temp->connect_next(head);
	head = temp;

   return 1;
}

//the purpose of this fucntion is to be able to display the data 
//that I havein the list and be able to display with the availavilities
int train::display()
{
	cout<<"Cost of train fair: " <<cost <<endl;
	if(head->get_int() <= 3)
	{
		cout<<"This days are light, not much busness!" <<endl;
		cout<<"Average trains available during this days: "<<head->get_int() <<endl;
	}
	else if(head->get_int() >3 && head->get_int() <= 6)
	{
		cout<<"This days have normal time, and good bussines!"<<endl;
		cout<<"The average number of trains on this days: "<<head->get_int() <<endl;
	}
	else{
		cout <<"Bussiness is good! multiple trins available" << endl;
		cout <<"Average number of trains available are: "<< head->get_int() <<endl;
	}

   return 0;
}
	
