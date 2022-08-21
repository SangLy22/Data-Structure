#pragma once
#include "Morse_Manipulator.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Constructor that creates a map and morse tree from the "Morse Code.txt" file
Morse_Manipulator::Morse_Manipulator()
{
	ifstream inFile;
	string path;
	char letter;
	tree = Morse_Tree();
	inFile.open("Morse Code.txt");

	while (inFile.is_open() && !inFile.eof()) {			//While the file is still being read get each line, put the letter as the key of the map and the code as the value in the map
		getline(inFile, path);										
		letter = path[0];
		path = path.substr(1, path.size());
		morse_Map[letter] = path;
		tree.add_to_tree_wrap(letter, path);			//Add the letter to the morse tree
	}
	inFile.close();
}

//Receives an expression in morse code, then decodes it
//@param string the morse code to be decoded.
//@throw std::exception
void Morse_Manipulator::decode(string expression)
{
	error_check_decode(expression);											//Check for errors
	int i = 0;																
	string temp;
	while (i != expression.size()) {										//Read in the code for one letter at a time then decode it
		temp += expression[i];
		if (isspace(expression[i + 1]) || expression[i + 1] == NULL) {
			tree.decode_message_wrap(temp);
			temp = "";
			if (expression[i + 1] != NULL) 
				i++;
		}
	i++;
	}
}

//Receives an expression in english, then encodes it into morse code
//@param string the english expression to be encoded
//@throw std::exception
void Morse_Manipulator::encode(string letters) {											
	error_check_encode(letters);											//Check for errors
	string message;
	for (int i = 0; i < letters.size(); i++) {								//Read in the letters one at a time then encode it by using the letter as a key to look up the value in the map
		message += morse_Map[letters[i]] + " ";
	}
	cout << message << endl;
}

//Checks the expression for input error fordecoding
//@param string the morse expression to be checked
void Morse_Manipulator::error_check_decode(string code) 
{
	for (int i = 0; i < code.size(); i++) {
		try {
			if (code[i] == '.' || code[i] == '_' || code[i] == ' '){}
			else
				throw i;
				//throw std::exception("Invalid character at position:");
		}
		catch (int pos) {
			cout << "invalid character at position: " << pos + 1 << endl;
			break;
		}
	}
}

//Checks the expression for input error for encoding
//@param string the english expression to be checked
void Morse_Manipulator::error_check_encode(string code)
{
	for (int i = 0; i < code.size(); i++) {
		try {
			if (isalpha(code[i])){}
			else
				throw std::exception("Invalid character at position:");
		}
		catch (exception e) {
			cout << e.what() << i + 1 << endl;
			exit(0);
		}
	}
}