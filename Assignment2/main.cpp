#include "manager.h"
#include "transportation.h"
using namespace std;

bool again();

int main()
{
	srand(time(NULL));
	stack_reviews obj;
	char temp[150]; char * review;
	int rate = 0;

	do{	
	cout<<"Enter a review: " ;
	cin.get(temp, 150, '\n'); cin.ignore(100,'\n');
	review = new char[strlen(temp) + 1];
	strcpy(review,temp);	
	
	cout<<"Enter a rating: ";
	cin >> rate;

	obj.create_push(review,rate);
	}while(!again());

	obj.display_all();
/*
	transit *prt[2];
		prt[1] = new train(3, 22.5);
		prt[1]->average_time();
		prt[1]->display();	
*/	
   return 0;
};

bool again()
{
	char opt = 'N';
	cout <<"Do this again?(Y/N): ";
	cin>>opt; cin.ignore(100, '\n');
	opt = toupper(opt);
	if(opt=='Y')
	return true;
return false;
}	
