#include "stdafx.h"

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


template <typename T>
struct TreeNode {
	T data;
	std::vector<TreeNode<T>*> children;
	TreeNode(const T& _data) : data(_data) {}
};

template <class T>
void areIsomorphic(TreeNode<T>* currentRoot1, TreeNode<T>* currentRoot2) {
	std::list<TreeNode<T>*> elements1;
	std::list <TreeNode<T>*> elements2;
	elements1.push_back(currentRoot1);
	elements2.push_back(currentRoot2);
	while (!elements1.empty() && !elements2.empty()) {
		TreeNode<T>* current1 = elements1.front();
		TreeNode<T>* current2 = elements2.front();
		elements1.pop_front();
		elements2.pop_front();
		std::list<int> counting1;
		std::list<int> counting2;
		for (TreeNode<T>* child : current1->children) {
			if (child) {
				elements1.push_back(child);
				counting1.push_back(child->children.size());
			}
		}
		std::reverse(current2->children.begin(), current2->children.end());
		for (TreeNode<T>* child : current2->children) {
			if (child) {
				elements2.push_back(child);
				counting2.push_back(child->children.size());
			}
		}
		if (counting1 != counting2) {
			std::cout << "NO" << std::endl;
			return;
		}
	}
	std::cout << "YES" << std::endl;

}
template <class T>
void printDFS(TreeNode<T>* root) {
	std::cout << "(" << root->data << " ";
	if (!root->children.size()) {
		std::cout << "{}) ";
		return;
	}
	std::cout << "{";
	for (TreeNode<T>* child : root->children) {
		if (child) {
			printDFS(child);
		}
	}
	std::cout << "})";
}

int main()
{
	TreeNode<int>* t1 = new TreeNode<int>(1);
	t1->children.push_back(new TreeNode<int>(2));
	t1->children.push_back(new TreeNode<int>(4));
	t1->children[0]->children.push_back(new TreeNode<int>(10));
	t1->children[1]->children.push_back(new TreeNode<int>(10));
	t1->children[1]->children.push_back(new TreeNode<int>(10));
	t1->children[1]->children.push_back(new TreeNode<int>(10));

	TreeNode<int>* t2 = new TreeNode<int>(10);
	t2->children.push_back(new TreeNode<int>(10));
	t2->children.push_back(new TreeNode<int>(10));
	t2->children[0]->children.push_back(new TreeNode<int>(10));
	t2->children[0]->children.push_back(new TreeNode<int>(10));
	t2->children[0]->children.push_back(new TreeNode<int>(10));
	t2->children[1]->children.push_back(new TreeNode<int>(10));

	areIsomorphic(t1, t2);
	printDFS(t1);
	std::cout << std::endl;

	//given example:
	TreeNode<int>* t3 = new TreeNode<int>(5);
	t3->children.push_back(new TreeNode<int>(9));
	t3->children.push_back(new TreeNode<int>(1));
	t3->children[1]->children.push_back(new TreeNode<int>(4));
	t3->children[1]->children.push_back(new TreeNode<int>(12));
	t3->children[1]->children.push_back(new TreeNode<int>(42));

	printDFS(t3);
	std::cout << std::endl;
	std::cout << "(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})" << std::endl;

	areIsomorphic(t1, t3);

	return 0;
}

