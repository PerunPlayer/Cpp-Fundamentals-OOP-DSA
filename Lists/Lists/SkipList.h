#pragma once

template <class T>
struct Node
{
	T data;
	Node next[2];
	Node(const T &_data, Node* _next, Node* _skip);
};

//template <class T>
//class Iterator

template <class T>
class SkipList
{
private:
	Node<T> *first, *last;
	size_t crrsize;
	size_t skipLength;

	void copy(const SkipList<T> &other);
	void destroy();
	void optimize();

public:
	SkipList();
	SkipList(const SkipList<T> &other);
	SkipList& operator= (const SkipList<T> &other);
	~SkipList();

	void push(const T&);
	size_t size();

	/*SListIterator<T> begin();
	SListIterator<T> find(const T&);
	SListIterator<T> end();*/

	//friend class SListIterator<T>;
};