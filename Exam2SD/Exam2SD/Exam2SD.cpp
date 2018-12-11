#include "stdafx.h"
#include <iostream>

const unsigned int SIZE = 1000;

template<typename T>
struct Node
{
	T data;
	Node<T>* left, *right;
	Node(T _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr)
	{
		data = _data;
		left = _left;
		right = _right;
	}
};

template<typename T>
struct Cell
{
	T data;
	Cell<T>* right, *down;
	Cell(T _data, Cell<T>* _right = nullptr, Cell<T>* _down = nullptr)
	{
		data = _data;
		right = _right;
		down = _down;
	}
};


//Task 1
bool containsHelper(Node<int> *firstTreeRoot, Node<int> *secondTreeRoot, bool isRootFound)
{
	if (!secondTreeRoot)
	{
		return true;
	}
	if (!firstTreeRoot)
	{
		return false;
	}
	if (firstTreeRoot->data != secondTreeRoot->data)
	{
		if (isRootFound)
		{
			return false;
		}
		return containsHelper(firstTreeRoot->left, secondTreeRoot, isRootFound) ||
			containsHelper(firstTreeRoot->right, secondTreeRoot, isRootFound);

	}
	else
	{
		if (!isRootFound)
		{
			isRootFound = true;
		}
		return containsHelper(firstTreeRoot->left, secondTreeRoot->left, isRootFound) &&
			containsHelper(firstTreeRoot->right, secondTreeRoot->right, isRootFound);
	}
}

bool contains(Node<int> *firstTreeRoot, Node<int> *secondTreeRoot)
{
	if (!(firstTreeRoot && secondTreeRoot))
	{
		return false;
	}

	return containsHelper(firstTreeRoot, secondTreeRoot, false);
}

//Task 2
template<typename T>
Cell<T>* copySubMatrixHelper(T matrix[][SIZE], int n, Cell<T>* root, unsigned int rows, unsigned int cols, char c)
{
	//the last element is skipped 
	if ((cols == n) && (c == 'r')) // r = right
	{
		return nullptr;
	}
	if ((rows == n) && (c == 'd')) // d = down
	{
		return nullptr;
	}
	/*if (rows == n && cols == n)
	{

	}*/

	Cell<T>* right = new Cell<T>(matrix[0][0]);
	Cell<T>* down = new Cell<T>(matrix[0][0]);
	root->right = copySubMatrixHelper(matrix, n, right, rows, cols++, 'r');
	root->down = copySubMatrixHelper(matrix, n, down, rows++, cols, 'd');
	root->data = matrix[rows][cols];
	return root;
}


template<typename T>
Cell<T>* copySubMatrix(T matrix[][SIZE], int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	Cell<T>* root = new Cell<T>(matrix[0][0]);

	copySubMatrixHelper(matrix, n, root, 0, 0, 'n'); //n = neutral
	return root;
}

int main()
{
	Node<int>* ll = new Node<int>(3, nullptr, nullptr);
	Node<int>* lr = new Node<int>(5, nullptr, nullptr);
	Node<int>* l = new Node<int>(4, ll, lr);
	Node<int>* rl = new Node<int>(7, nullptr, nullptr);
	Node<int>* rr = new Node<int>(10, nullptr, nullptr);
	Node<int>* r = new Node<int>(8, rl, rr);
	Node<int>* root = new Node<int>(6, l, r);

	std::cout << contains(root, l) << std::endl;

	std::cout << contains(root, ll->left) << std::endl;

	Node<int>* test = new Node<int>(245, nullptr, nullptr);

	std::cout << contains(root, test) << std::endl;



	return 0;
}

