// Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
A palindrome is a word that reads the same backward or forward.

Write a function that checks if a given word is a palindrome. Character case should be ignored.

For example, isPalindrome("Deleveled") should return true as character case should be ignored, 
resulting in "deleveled", which is a palindrome since it reads the same backward and forward.
*/

#include "pch.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(const std::string& word)
{
	bool returnVal = false;
	//throw std::logic_error("Waiting to be implemented");
	if (word.empty())
	{
		return false;
	}
	
	if (word.size() == 1)
	{
		if (!isalpha(word[0]))
		{
			returnVal = true;
		}
	}

	int trackerFromBehind = word.size() - 1;
	for (int i = 0; i < trackerFromBehind; i++)
	{
		if (! isalpha( word[i] ) )
		{
			while (!isalpha(word[i]))
			{
				i++;
				continue;
			}
		}
		if (! isalpha( word[trackerFromBehind] ) )
		{
			while (!isalpha(word[trackerFromBehind]))
			{
				trackerFromBehind--;
			}
		}

		if (tolower(word[i]) == tolower(word[trackerFromBehind]))
		{
			returnVal = true;
		}
		else
		{
			returnVal = false;
			break;
		}

		trackerFromBehind--;
	}

	return returnVal;

}

int main()
{
	std::cout << isPalindrome(" ");
}