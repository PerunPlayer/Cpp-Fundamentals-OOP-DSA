#include "stdafx.h"
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* left, *right;

	Node<T>(const T& _data, Node<T>* _left = nullptr, Node<T>* _right = nullptr)
	{
		data = _data;
		left = _left;
		right = _right;
	}
};

Node<int>* createBST(int* sortedArr, int start, int end)
{
	if (start > end)
	{
		return nullptr;
	}

	int midIndex = (start + end) / 2;

	Node<int>* left = createBST(sortedArr, start, midIndex - 1);
	Node<int>* right = createBST(sortedArr, midIndex + 1, end);

	Node<int>* root = new Node<int>(sortedArr[midIndex], left, right);

	return root;
}

void printBST(Node<int>* root)
{
	if (!root)
	{
		return;
	}
	printBST(root->left);
	std::cout << root->data << " ";
	printBST(root->right);
}

int height(Node<int>* root)
{
	if (!root)
	{
		return 0;
	}

	return (1 + ((height(root->left) <= height(root->right)) ? height(root->right) : height(root->left)));
}

bool isBalanced(Node<int>* root)
{
	if (!root)
	{
		return 1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return ((abs(leftHeight - rightHeight) <= 1) && isBalanced(root->left) && isBalanced(root->right));
}

bool isBSTreeHelper(Node<int>* root, const int& min, const int& max)
{
	if (!root)
	{
		return true;
	}

	return (root->data >= min) &&
		(root->data < max) &&
		isBSTreeHelper(root->left, min, root->data) &&
		isBSTreeHelper(root->right, root->data, max);
}

bool isBSTree(Node<int>* root)
{
	if (!root)
	{
		return false;
	}
	if (!root->left && !root->right)
	{
		return true;
	}

	int max, min;
	return isBSTreeHelper(root, INT_MAX, INT_MIN);
}

int main()
{
	int sortedArr[10] = { 1, 2, 4, 5, 6, 7, 40, 90, 100, 1024 };
	Node<int>* root = createBST(sortedArr, 0, 9);
	printBST(root);
	std::cout << std::endl;
	if (isBalanced(root))
	{
		std::cout << "It's balanced!\n";
	}
	else
	{
		std::cout << "It isn't balanced!\n";
	}

	return 0;
}