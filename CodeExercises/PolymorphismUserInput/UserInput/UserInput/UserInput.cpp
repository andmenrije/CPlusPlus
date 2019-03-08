// UserInput.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*User interface contains two types of user input controls: TextInput, which accepts all characters and NumericInput, which accepts only digits.

Implement the following methods :

add on class TextInput - adds the given character to the current value
getValue on class TextInput - returns the current value
add on class NumericInput - overrides the base class method so that each non - numeric character is ignored
*/

#include "pch.h"
#include <iostream>
#include <string>

class TextInput
{
protected:

	std::string textInput = "";

public:
	virtual void add(char c) 
	{ 
		textInput += c;
	}

	std::string getValue() { return textInput; }
};

class NumericInput : public TextInput 
{ 


public:
	void add(char c)
	{
		if (isdigit(c))
		{
			textInput += c;
		}
	}

	//std::string getValue() { return textInput }

};

#ifndef RunTests
int main()
{
	TextInput* input = new NumericInput();
	input->add('1');
	input->add('a');
	input->add('0');
	std::cout << input->getValue();
}
#endif