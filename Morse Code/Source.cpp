#include <iostream>
#include "Morse_Manipulator.h"
using namespace std;

int main() 
{
	string message_1 = "_.. __.";
	string message_2 = "ac";

	Morse_Manipulator code;

	code.decode(message_1);
	cout << endl;
	code.encode(message_2);
	
	cout << endl;
	system("pause");
	return 0;

}