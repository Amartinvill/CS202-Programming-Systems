/*
Angel Martinez
CS202
Assignment #3
file name: methods.cpp
*/
#include "methods.h"
using namespace std;

//this is a default constructor
//it uses initialization list
E_contact::E_contact():method_1(NULL), method_2(NULL),method_3(NULL)
{
}

//this is also a constructo, but this one take in 
//arguments and get copies directly to out data members
E_contact::E_contact(char * method_one, char * method_two, char * method_three)
{
        copy_data(method_one, method_two, method_two);
}

//This is a copy constructor that make a clone of our data
//and transfers it to another list.
E_contact::E_contact(const E_contact & copy_from)
{
        deep_copy(copy_from);
}

//This is a destructor that removes all dynamic memory we have 
//created in this class
E_contact::~E_contact()
{
        remove_all_mem();
}

//the purpose of this class is to be able to copy the data passed in 
//and copy it to our data members of this class
void E_contact::copy_data(char * method_one, char * method_two, char * method_three)
{
        if(method_1)
            delete [] method_1;
        method_1 = new char[strlen(method_one) + 1];
        strcpy(method_1,method_one);
    
        if(method_2)
            delete [] method_2;
        method_2 = new char[strlen(method_two) + 1];
        strcpy(method_2, method_two);
    
        if(method_3)
            delete [] method_3;
        method_3 = new char[strlen(method_three) + 1];
        strcpy(method_3, method_three);

}

//the purpose of this function is to be able to create a copy
//function that allowed an object of the same class to be passed
//in and copied
void E_contact::deep_copy(const E_contact & copy_from)
{
        if(method_1)
            delete [] method_1;
        method_1 = new char[strlen(copy_from.method_1) + 1];
        strcpy(method_1, copy_from.method_1);
    
        if(method_2)
            delete [] method_2;
        method_2 = new char[strlen(copy_from.method_2) + 1];
        strcpy(method_2, copy_from.method_2);
    
        if(method_3)
            delete [] method_3;
        method_3 = new char[strlen(copy_from.method_3) + 1];
        strcpy(method_3, copy_from.method_3);
}

//this is a display funtion that allows for all our data to be
//display
void E_contact::display_info()
{
        cout << "First method to contact: " << method_1 << endl;
        cout << "Second method to contact: "<< method_2 << endl;
        cout << "Last method to contact: "  << method_3 << endl;
}

//this is a remove all function that remove all memory being use
void E_contact::remove_all_mem()
{
        if(method_1)
            delete [] method_1;
        if(method_2)
            delete [] method_2;
        if(method_3)
            delete [] method_3;
}
