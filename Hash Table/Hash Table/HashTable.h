#pragma once

#include <vector>

template<class KeyType, class DataType>
struct TableCell
{
	KeyType key;
	DataType data;
	TableCell<KeyType, DataType>* next;

	TableCell(KeyType _key, DataType _data, TableCell<KeyType, DataType>* _next = nullptr) 
		: key(_key), data(_data), next(_next) { }
};

template <class KeyType, class DataType>
class HashMapIterator
{
public:
	HashMapIterator(TableElement<KeyType, DataType> **, size_t, bool end = false);

	KeyType operator * ();
	HashMapIterator<KeyType, DataType>& operator ++ ();		//++it;
	bool operator == (const HashMapIterator<KeyType, DataType>&) const;
	bool operator != (const HashMapIterator<KeyType, DataType>&) const;

private:
	//findNextKeyValuePair: намира следващата стойност на (elementIndex,element), която указва същински елемент или достига края на таблицата.
	void findNextKeyValuePair();

	TableCell<KeyType, DataType> ** table;
	size_t tableSize;

	size_t elementIndex;
	TableCell<KeyType, DataType> *element;
};

template <class KeyType>
using hashFunc = size_t(*) (const KeyType&, size_t);

template<class KeyType, class DataType>
class HashMap
{
private:
	TableCell<KeyType, DataType>** table;
	hashFunc<KeyType> hashFn;
	size_t tableSize;

	TableCell<KeyType, DataType> *locate(const KeyType&) const;

public:
	HashMap(size_t ts, hashFn<KeyType>);

	void update(const KeyType&, const DataType&);
	bool hasKey(const KeyType&) const;
	DataType get(const KeyType&) const;
	void remove(const KeyType&);

	HashMapIterator<KeyType, DataType> begin();
	HashMapIterator<KeyType, DataType> end();
};
