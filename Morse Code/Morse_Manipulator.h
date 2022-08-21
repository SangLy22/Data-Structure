#pragma once
#include <map>
#include "Morse_Tree.h"
using namespace std;

//Class to encode and decode morse code
class Morse_Manipulator
{
public:
	//Constructor that creates a map and morse tree from the "Morse Code.txt" file
	Morse_Manipulator();

	//Receives an expression in morse code, then decodes it
	//@param string the morse code to be decoded.
	//@throw std::exception
	void decode(string expression);

	//Receives an expression in english, then encodes it into morse code
	//@param string the english expression to be encoded
	//@throw std::exception
	void encode(string expression);

private:
	//Data Fields
	map<char, string> morse_Map;
	Morse_Tree tree;

	//Checks the expression for input error fordecoding
	//@param string the morse expression to be checked
	void error_check_decode(string expression);

	//Checks the expression for input error for encoding
	//@param string the english expression to be checked
	void error_check_encode(string expression);
};