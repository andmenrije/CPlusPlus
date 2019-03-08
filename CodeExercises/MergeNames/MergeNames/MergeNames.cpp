// MergeNames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Implement the unique_names method.When passed two vectors of names, it will return a vector containing 
the names that appear in either or both vectors.The returned vector should have no duplicates.

For example, calling unique_names(std::vector<std::string>{"Ava", "Emma", "Olivia"}, 
std::vector<std::string>{"Olivia", "Sophia", "Emma"}) should return a vector containing Ava, Emma, 
Olivia, and Sophia in any order.
*/

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
	//throw std::logic_error("Waiting to be implemented");
	std::vector<std::string> returnVector;
	std::map<std::string, int> nameHash;
	for (int i = 0; i < names1.size(); ++i)
	{
		nameHash.insert(std::pair<std::string, int>(names1[i], 1));
	}

	for (int i = 0; i < names2.size(); ++i)
	{
		if (nameHash.find(names2[i]) == nameHash.end())
		{
			nameHash.insert(std::pair<std::string, int>(names2[i], 1));
		}
	}

	for (auto element : nameHash)
	{
		returnVector.push_back(element.first);
	}

	return returnVector;

}

int main()
{
	std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
	std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };

	std::vector<std::string> result = unique_names(names1, names2);
	for (auto element : result)
	{
		std::cout << element << ' '; // should print Ava Emma Olivia Sophia
	}
}