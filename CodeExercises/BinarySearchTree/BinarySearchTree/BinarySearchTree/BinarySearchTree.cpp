// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}

	int getValue() const
	{
		return value;
	}

	Node* getLeft() const
	{
		return left;
	}

	Node* getRight() const
	{
		return right;
	}

private:
	int value;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
public:
	static bool contains(const Node& root, int value)
	{
		if (root.getValue() == value)
		{
			return true;
		}
		else
		{
			if (root.getLeft() != nullptr && root.getValue() >= value)
			{

				if (contains(*root.getLeft(), value))  // If we have found the value, return and don't continue anymore
					return true;
			}
			if (root.getRight() != nullptr &&  root.getValue() < value)
			{
				if (contains(*root.getRight(), value)) // If we have found the value, return and don't continue anymore
					return true;
			}
		}

		return false;
	}
};

#ifndef RunTests
int main()
{
	Node n1(1, NULL, NULL);
	Node n3(4, NULL, NULL);
	Node n2(2, &n1, &n3);

	std::cout << BinarySearchTree::contains(n2, 3);
}
#endif