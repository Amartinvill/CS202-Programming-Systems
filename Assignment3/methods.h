/*
Angel Martinez
CS202
Assigment #3
file name: mathods.h
*/
#ifndef Methods_h
#define Methods_h


#include <iostream>
#include <cctype>
#include <cstring>
int const SIZE = 150;

//the purpose of this clas is to be able to create a class
//that can copy three methods of type strings
class E_contact
{
    public:
	//default constructor
        E_contact();
	//constructor that takes arguments
        E_contact(char * method_one, char * method_two, char * method_three);
	//copy constructor
        E_contact(const E_contact & copy_from);
	//destructor
        ~E_contact();
	//copies the data to the class memeber functions
        void copy_data(char * method_one, char * method_two, char * method_three);
	//make a clone of the data and copies it onto another 
	//seperate list
        void deep_copy(const E_contact & copy_from);
	//display the information
        void display_info();
	//remove all dynamic memory
        void remove_all_mem();
    
    private:
	//This are char * varialble use to ibtain the data
	//for the three different methods a person can be 
	//contacted
        char * method_1;
        char * method_2;
        char * method_3;
};
bool again();

#endif /* methods_h */
