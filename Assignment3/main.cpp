/*
Angel Martinez
CS202
Assignment #3
File Name: main.cpp
*/

#include "family.h"
#include "methods.h"
#include "person.h"
#include "tree.h"
#include "bst_node.h"
using namespace std;

int main()
{
	//object for a Person Class
	Person test;
	//object for a Emergency contact class
   	E_contact obj;
	//object for a Family list class
	family member;	

	char opt = 'Y';
	char f_n [SIZE]; char * first_name;
	char l_n [SIZE]; char * last_name;
	  
    	char temp_1 [SIZE]; char * method_1;
    	char temp_2 [SIZE]; char * method_2;
    	char temp_3 [SIZE]; char * method_3;
    
	do{		
		cout <<"Enter Person's First name: ";
		cin.get(f_n, SIZE, '\n'); cin.ignore(100,'\n');
		first_name = new char[strlen(f_n) +1];
		strcpy(first_name, f_n);

		
		cout <<"Enter Person's last name: ";
		cin.get(l_n, SIZE, '\n'); cin.ignore(100,'\n');
		last_name = new char[strlen(l_n) +1];
		strcpy(last_name,l_n);

		//this ask the user to enter for the first method
  	  	cout<<"Enter priority method to contact you: ";
    		cin.get(temp_1, SIZE, '\n'); cin.ignore(100, '\n');
    		method_1 = new char[strlen(temp_1) + 1];
    		strcpy(method_1, temp_1);
    
		//this ask the user to enter for the secodn method
   	 	cout<<"Enter Secondary way of contacting you: ";
    		cin.get(temp_2, SIZE, '\n'); cin.ignore(100, '\n');
    		method_2 = new char[strlen(temp_2) + 1];
    		strcpy(method_2, temp_2);
    
		//this ask the user for to enter for the third method
   	 	cout<<"Enter Last method of contacting you: ";
    		cin.get(temp_3, SIZE, '\n');
    		method_3 = new char[strlen(temp_3) + 1];
    		strcpy(method_3, temp_3); 

    		test.copy_data(first_name, last_name); 
    		obj.copy_data(method_1, method_2, method_3);
	
	cout<<"Enter another person:(Y/N)? ";
	cin >> opt; cin.ignore(100,'\n');
	opt = toupper(opt);

	//this get the input data form the user and pass in the pointers
	member.insert_member(test,obj);
	}
	while(opt!= 'N');

	
	//display the data of the list of members
	member.display_all();

	//this will allow to dealocate the pointer where it deletes
	//the data.
	delete [] first_name;
	delete [] last_name;
	delete [] method_1;
	delete [] method_2;
	delete [] method_3;



    return 0;
}

