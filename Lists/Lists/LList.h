#pragma once

#include <iostream>

template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode(const T& _data, ListNode<T>* _next = nullptr) : data(_data), next(_next) {}
};

template <class T>
class LinkedList
{
private:
	ListNode<T>* first;
	ListNode<T>* last;
	unsigned int size;

	void copy(const LinkedList<T>& other);
	void destroy();

public:

	LinkedList();
	LinkedList(const LinkedList<T>* other);
	LinkedList& operator=(const LinkedList<T>& other);
	~LinkedList();

	void push_back(const T& elem);
	void push_front(T data);
	void pushAfter(T data, size_t index);
	T get(int index);
	void pop_front();
	void pop_back();
	void popFrom(size_t index);
	void print() const;
	unsigned int getSize() const;

	void removeRepeatedNodes();
	void reverse();
	void removeNodesOutOfSequence();
	bool existCycle();
};