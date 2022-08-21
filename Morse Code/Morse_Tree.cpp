#include "Morse_Tree.h"
#include <iostream>
#include <string>
using namespace std;

//Default Constructor, places node with a space as the root
Morse_Tree::Morse_Tree() 
{
	root = new BTNode<char>(' ',NULL,NULL);		//Create an node with a blank space as root
}

//Wrapper function for add_to_tree
//@param char the letter to add to the morse tree
//@param string the morse code
void Morse_Tree::add_to_tree_wrap(char letter, string path)
{
	add_to_tree(letter, path, 0, this->root);			
}

//Function used to add a node to the morse tree
//@param char letter to be added to the tree
//@param int the morse code expression used to locate where the letter should be placed in the tree
//@param BTNode * the root of the tree or subtree
//@return BTNode<char> * returns the root of the current tree or subtree
BTNode<char> *Morse_Tree::add_to_tree(char letter, string path, int count, BTNode<char>* root)
{
	if (root == NULL)									//If the root is null create a new node with a blank space as the root
	{
		root = new BTNode<char>(' ', NULL, NULL);
	}
	if (path[count] == '.')												//If the current character in the path is '.' move onto the left subtree
		root->left = add_to_tree(letter, path, ++count, root->left);
	else if (path[count] == '_')
		root->right = add_to_tree(letter, path, ++count, root->right);	//If the current character in the path is '-' move onto the right subtree
	else
		 root->data = letter;											//Put the letter in the data field of the current root
	return root;
}

//Wrapper function for decode_message
//@param string the morse code
void Morse_Tree::decode_message_wrap(string code)
{
	decode_message(code, 0, this->root);
}

//Function for decoding using the tree
//@param string the morse code to be decoded
//@param int the index of the current character in the morse string
//@param BTNode<char> * the root of the current morse tree or subtree
//@return BTNode<char> * the root of the current morse tree or subtree
BTNode<char>* Morse_Tree::decode_message(string code, int index, BTNode<char>* root) 
{
	if (code[index] == '.')
		root = decode_message(code, ++index,root->left);	//If the current character in the path is '.' move onto the left subtree
	else if (code[index] == '_')
		root = decode_message(code, ++index,root->right);	//If the current character in the path is '-' move onto the right subtree
	else
		cout << root->data;									//Once you have found the node where the morse code leads print the data in that node
	return root;
}