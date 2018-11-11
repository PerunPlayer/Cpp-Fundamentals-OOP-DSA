#include "stdafx.h"
#include "SkipList.h"

template <class T>
Node<T>::Node(const T &_data, Node *_next, Node *_skip) : data(_data)
{
	next[0] = _next;
	next[1] = _skip;
}

template <class T>
SkipList<T>::SkipList()
{
	first = last = nullptr;
	crrsize = 0;
	skipLength = 0;
}