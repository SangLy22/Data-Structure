#pragma once
#include <iostream>
#include "Binary_Tree.h"
using namespace std;

//Class for a morse tree
class Morse_Tree:public Binary_Tree<char>
{
private:
	//Function used to add a node to the morse tree
	//@param char letter to be added to the tree
	//@param int the morse code expression used to locate where the letter should be placed in the tree
	//@param BTNode * the root of the tree or subtree
	//@return BTNode<char> * returns the root of the current tree or subtree
	BTNode<char>* add_to_tree(char letter, string path, int counter, BTNode<char> *rt);

	//Function for decoding using the tree
	//@param string the morse code to be decoded
	//@param int the index of the current character in the morse string
	//@param BTNode<char> * the root of the current morse tree or subtree
	//@return BTNode<char> * the root of the current morse tree or subtree
	BTNode<char>* decode_message(string code, int index, BTNode<char> * root);
public:
	//Default Constructor, places node with a space as the root
	Morse_Tree();

	//Wrapper function for add_to_tree
	//@param char the letter to add to the morse tree
	//@param string the morse code
	void add_to_tree_wrap(char letter, string path);

	//Wrapper function for decode_message
	//@param string the morse code
	void decode_message_wrap(string code);
	
};