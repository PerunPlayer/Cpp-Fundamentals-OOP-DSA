#pragma once

template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode(T _data, ListNode<T> _next = nullptr) : data(_data), next(_next) {}
};

template <class T>
class LinkedList
{
	ListNode<T>* start;
	ListNode<T>* end;
	int size;

private:
	void copy(const LinkedList<T>* other)
	{
		ListNode<T>* other_holder = other.start;
		start = end = nullptr;
		size = other.size;
		while (other_holder)
		{
			if (!start)
			{
				start = new ListNode<T>(other_holder->data);
				end = start;
			}
			else
			{
				end->next = new ListNode<T>(other_holder->data);
				end = end->next;
			}
			other_holder = other_holder->next;
		}
	}

	void destroy()
	{
		while (start)
		{
			ListNode<T>* tmp = start;
			start = start->next;
			delete tmp;
		}
	}

	void toEnd(const T& elem)
	{
		if (!start)
		{
			start->next = new ListNode<T>(elem);
			end = start->next;
			size++;
		}
		else
		{
			end->next = new ListNode<T>(elem);
			end = end->next;
			size++;
		}
	}

	void print()
	{
		ListNode<T>* 
		while ()
		{

		}
	}


public:
	LinkedList()
	{
		start = end = nullptr;
		size = 0;
	}
	LinkedList(const LinkedList<T>* other)
	{
		copy(other);

	}
	~LinkedList()
	{
		destroy();
	}

};