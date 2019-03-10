// Sorted Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Implement function countNumbers that accepts a sorted vector of unique integers and, efficiently with 
respect to time used, counts the number of vector elements that are less than the parameter lessThan.

For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should return 2 because there 
are two vector elements less than 4.
*/
#include "pch.h"
#include <vector>
#include <stdexcept>
#include <iostream>

int recurseSearch(const std::vector<int>& sortedVector, int lessThan, int begIndex, int endIndex)
{

	if (endIndex >= sortedVector.size())
	{
		endIndex = sortedVector.size() - 1;
	}

	if (endIndex - begIndex == 0)
	{
		return sortedVector[endIndex] < lessThan ? endIndex + 1 : 0;
	}

	if (endIndex - begIndex == 1)
	{
		if (sortedVector[endIndex] < lessThan)
			return endIndex + 1;
		else if (sortedVector[begIndex] < lessThan)
			return begIndex + 1;
		else
			return 0;
	}

	if (sortedVector[endIndex] < lessThan)
	{
		int newEndIndex = endIndex + ((endIndex - begIndex) / 2);
		if (sortedVector[newEndIndex] == lessThan)
		{
			return newEndIndex;
		}
		return recurseSearch(sortedVector, lessThan, endIndex, newEndIndex);
	}
	else
	{
		int newEndIndex = begIndex + ((endIndex - begIndex) / 2);
		if (sortedVector[newEndIndex] == lessThan)
		{
			return newEndIndex;
		}
		return recurseSearch(sortedVector, lessThan, begIndex, newEndIndex);
	}



}

int LinearSearch(const std::vector<int>& sortedVector, int lessThan)
{

	if (sortedVector[0] >= lessThan)
	{
		return 0;
	}

	for (int i = 1; i < sortedVector.size(); ++i)
	{
		if (sortedVector[i] >= lessThan)
		{
			return i;
		}
	}

	return sortedVector.size();
}


int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{

	if (sortedVector.size() == 0)
	{
		if (sortedVector[0] >= lessThan)
		{
			return 0;
		}

		for (int i = 1; i < sortedVector.size(); ++i)
		{
			if (sortedVector[i] >= lessThan)
			{
				return i;
			}
		}

		return sortedVector.size();
	}


	if (sortedVector.size() == 1 && sortedVector[0] < lessThan)
	{
		if (sortedVector[0] < lessThan)
			return 1;
		else
			return 0;
	}


	if (sortedVector.size() < 16)
	{
		return LinearSearch(sortedVector, lessThan);
	}
	else
	{
		return recurseSearch(sortedVector, lessThan, 0, (sortedVector.size() - 1));
	}
	
}

#ifndef RunTests
int main()
{
	std::vector<int> v{ 1, 3, 5, 7, 8, 9 };
	std::cout << countNumbers(v, 10);
}
#endif