/*
Angel Martinez
CS202
Assignment #3
*/
#include "bst_node.h"

//the purpose of this class is to be able to have the right
//prototypes to was can create a red black tree balance tree
class balance_tree
{
	public:
		//constructor
		balance_tree();
		//copy constructor
		balance_tree(const balance_tree & copy_from);
		//this is a distructor to remove all dynamic memory 
		~balance_tree();
		//this function displays all the information in the tree
		int display_all();
		//this is an insert function to add data from the user
		int insert_person(const Person & to_add, const E_contact & to_copy);
	
	protected:
		//this is a root pointer to make the red black tree
		rb_node * root;
		//this is a remove all function
		int remove_all(rb_node *& root);
		//this function makes a copy of the class 
		int deep_copy(rb_node *& dest, rb_node * root, rb_node * parent);
		//this function display all data from the tree
		int display_all(rb_node * root);
		//this function insert the the tree
		int insert_person(const Person & to_add, const E_contact & to_copy, rb_node *& root, rb_node * parent);
		//these fuctions serve as cases to help the red black tree
		//self rotate
		void insert_case_1(rb_node * root);
		void insert_case_2(rb_node * root);
		void insert_case_3(rb_node * root);
		void rotate_left(rb_node * rotating_node);
		void rotate_right(rb_node * rotating_node);
		void insert_case_4(rb_node * root);
		void insert_case_5(rb_node * root);
		rb_node * uncle(rb_node * root);
		rb_node * grandpa(rb_node * root);
};
