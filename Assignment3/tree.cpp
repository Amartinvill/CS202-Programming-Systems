/*
Angel Martinez
CS202
assignment #3
*/

#include "tree.h"
using namespace std;
//the purpose of this  function is to be use as a constructor
//using initialization list
balance_tree::balance_tree():root(NULL)
{}

//This is a copy contructor that copies from a balance class
//object
balance_tree::balance_tree(const balance_tree & copy_from)
{
	rb_node* temp = copy_from.root;
	deep_copy(temp, root, NULL);
}

//this is a destructor that deletes all dyamic memory from
//the bst
balance_tree::~balance_tree()
{
	remove_all(root);
}

//this is a remove all function htat deletes all the data
int balance_tree::remove_all(rb_node *& root) 
{
	if(!root) return 0;
	
	remove_all(root->go_left());
	remove_all(root->go_right());

	delete root;
	root = NULL;

  return 0;
}

//this is a deep copy function that allow to make a clone of
//the data that we already have to a node tree
int balance_tree::deep_copy(rb_node *& dest, rb_node * root, rb_node * parent)
{
	if(!root)
	{
		dest = NULL;
		return 0;
	}
	
	dest = new rb_node(*root); //derefencing the pointer for construct.
	dest->connect_parent(parent);
	deep_copy(root->go_left(), dest->go_left(), dest);
	deep_copy(root->go_right(), dest->go_right(), dest);
   return 1;
}

//this function is a wrapper function that displays all the 
//information form the tree to the user interface
int balance_tree::display_all()
{

	return display_all(root);
}

//
int balance_tree::display_all(rb_node * root)
{
	if(!root) return 0;
	display_all(root->go_left());
	root->display_list();	
	display_all(root->go_right());

   return 0;
}
//do a wrapper
int balance_tree::insert_person(const Person & to_add, const E_contact & to_copy)
{
	return insert_person(to_add,to_copy,root, NULL);
}

int balance_tree::insert_person(const Person & to_add, const E_contact & to_copy, rb_node *& root, rb_node * parent)
{	
	if(!root)
	{
		root = new rb_node();
	//	root->inset_info(to_add,to_copy); //creat this function
		root->set_flag(true);
		root->connect_parent(parent);
		return 0;
	}
	insert_person(to_add,to_copy,root->go_left(), root);
	insert_person(to_add,to_copy,root->go_right(), root);
	
return 0;
}

void balance_tree::insert_case_1(rb_node * root)
{
	if(!root->go_parent())
	root->set_flag(false);
	else
	insert_case_2(root);
}

void balance_tree::insert_case_2(rb_node * root)
{
	if(root->go_parent()->flag_is_red() == false) return;
	else
	insert_case_3(root);
}
//if the grandparent exist then this function will return that
//pointer
rb_node * balance_tree::grandpa(rb_node * root)
{
	if(!root || !root->go_parent() || !root->go_parent()->go_parent())
		return NULL;
   return root->go_parent()->go_parent();	
}

//what this function does is return the sibling of the of the parent
rb_node * balance_tree::uncle(rb_node * root)
{
	rb_node * gtemp = grandpa(root);
	if(!gtemp) return NULL;
	if(root->go_parent() == gtemp->go_left())
		return gtemp->go_right();
	else
   return gtemp->go_left();
}

//case 3 would be if in the case we have an right elbow where
//we wish to reset	
void balance_tree::insert_case_3(rb_node * root)
{
	rb_node * temp = uncle(root);
	rb_node * tempg;
	
	if(temp != NULL	&& temp->flag_is_red() == true)
	{
		root->go_parent()->set_flag(false);
		temp->set_flag(false);
		tempg = grandpa(root);
		tempg->set_flag(true);
		insert_case_1(tempg);
	}
	else insert_case_4(root);
}

//a left toration would happend it we an joint node with children
//then we rotate the joint node up to where the parent used to be
void balance_tree::rotate_left(rb_node * rotating_node )
{
	if(!rotating_node) return;
	//getting a hold of pointer to move
	rb_node * rotate = rotating_node->go_right();
	rb_node * temp = rotate->go_left();
	rotate->connect_parent(rotating_node->go_parent());
	if(!rotating_node->go_parent())	
		root = rotate;
	//rearenging happens
	rotate->connect_left(rotating_node);
	rotating_node->connect_parent(rotate);
	rotating_node->connect_right(temp);
	if(temp)
		temp->connect_parent(rotating_node);	
	
}

//this is a rotating right function siimilar to the previous
//function but in this case it does the opposit
void balance_tree::rotate_right(rb_node * rotating_node)
{
	if(!rotating_node) return;
	
	//we fist want temporaty pointer to at the data we wish
	//to move
	rb_node * rotate = rotating_node->go_left();
	rb_node * temp = rotate->go_right();
	rotate->connect_parent(rotating_node->go_parent());
	if(!rotating_node->go_parent())
		root = rotate;
	//the magic happens and rearenging occurs
	rotate->connect_right(rotating_node);
	rotating_node->connect_parent(rotate);
	rotating_node->connect_right(temp);
	if(temp)
		temp->connect_parent(rotating_node);	
}

	
//in this case if, we check if we have a straigh line to the left with
//multiple reds so we chnage and case 1 would apply
void balance_tree::insert_case_4(rb_node * root)
{
	rb_node * tempg = grandpa(root);
	if(root == root->go_parent()->go_right() && root->go_parent() == tempg->go_left())
	{	
		rotate_left(root->go_parent());
		root = root->go_left();
	}

	else if(root == root->go_parent()->go_left() && root->go_parent() == tempg->go_right())
	{
		rotate_right(root->go_parent());
		root = root->go_right();
	}
	insert_case_5(root);
}

//in this case, we check if we have a straight line to the right with 
//multiple reds so we change and case 1 then would apply
void balance_tree::insert_case_5(rb_node * root)
{
	rb_node * tempg = grandpa(root);
	root->go_parent()->set_flag(false);
	tempg->set_flag(true);
	if(root == root->go_parent()->go_left())
		rotate_right(tempg);	
	else
		rotate_right(tempg);
}


