#pragma once

#include <iostream>

template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode(const T& _data, ListNode<T>* _next = nullptr) : data(_data), next(_next) {}

	void print(std::ostream& out)
	{
		data.print(out);
	}
};

template <class T>
class LinkedList
{
private:
	ListNode<T>* first;
	ListNode<T>* last;
	unsigned int size;

	void copy(const LinkedList<T>& other)
	{
		ListNode<T>* temp = other.first;
		while (temp)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}

	void destroy()
	{
		while (size > 0)
		{
			pop_front();
		}
	}

public:

	LinkedList()
	{
		first = last = nullptr;
		size = 0;
	}

	LinkedList(const LinkedList<T>& other)
	{
		first = last = nullptr;
		size = 0;
		copy(other);
	}

	LinkedList& operator=(const LinkedList<T>& other)
	{
		if (this != &other)
		{
			destroy();
			first = last = nullptr;
			copy(other);
		}

		return *this;
	}

	~LinkedList()
	{
		destroy();
	}

	void push_back(const T& elem)
	{
		ListNode<T>* temp = new ListNode<T>(elem, nullptr);
		if (temp)
		{
			if (size == 0)
			{
				first = temp;
				last = temp;
			}
			else
			{
				last->next = temp;
				last = temp;
			}

			size++;
		}
	}

	void push_front(T data)
	{
		ListNode<T>* temp = new ListNode<T>(data, first);
		first = temp;
		size++;
	}

	void pushAfter(T data, int index)
	{
		ListNode<T>* temp2 = first;
		ListNode<T>* temp = new ListNode<T>(data, nullptr);
		while (index != 0)
		{
			temp2 = temp2->next;
			index--;
		}
		temp->next = temp2->next;
		temp2->next = temp;
		size++;
	}

	T get(int index)
	{
		ListNode<T>* temp = first;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}

	void pop_front()
	{
		ListNode<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}

	void pop_back()
	{
		ListNode<T>* temp = last;
		ListNode<T>* start = first;
		while (start->next != last)
		{
			start = start->next;
		}
		last = start;
		delete temp;
		size--;
	}

	void print(std::ostream& out)
	{
		ListNode<T>* curr = first;

		out << "{ ";
		for (size_t i = 0; i < size - 1; i++)
		{
			out << *curr->data;
			out << "\n";
			curr = curr->next;
		}
		out << *curr->data;
		out << " }\n";
	}

	void printPrimitives(std::ostream& out)
	{
		ListNode<T>* curr = first;

		out << "{ ";
		for (size_t i = 0; i < size - 1; i++)
		{
			out << curr->data;
			out << "\n";
			curr = curr->next;
		}
		out << curr->data;
		out << " }\n";
	}
};