#include "stdafx.h"
#include "HashTable.h"

#include <cassert>

template<class KeyType, class DataType>
TableCell<KeyType, DataType>* HashMap<KeyType, DataType>::locate(const KeyType &_key) const
{
	size_t hashCode = hashFn(_key, tableSize);

	TableCell<KeyType, DataType>* curr = table[hashCode];
	while (curr && curr->key != _key)
	{
		curr = curr->next;
	}

	return curr;
}

template<class KeyType, class DataType>
HashMap<KeyType, DataType>::HashMap(size_t ts, hashFn<KeyType> hashFunc) : hashFn(hashFunc), tableSize(ts)
{
	table = new TableCell<KeyType, DataType>*[tableSize];
	for (size_t i = 0; i < tableSize; i++)
	{
		table[i] = nullptr;
	}
}

template<class KeyType, class DataType>
void HashMap<KeyType, DataType>::update(const KeyType &_key, const DataType &_data)
{
	TableCell<KeyType, DataType>* cell = locate(_key);

	if (cell)
	{
		cell->data = _data;
	}
	else
	{
		size_t hashCode = hashFn(_key, tableSize);
		table[hashCode] = new TableCell<KeyType, DataType>(_key, _data, table[hashCode]);
	}
}

template<class KeyType, class DataType>
bool HashMap<KeyType, DataType>::hasKey(const KeyType &_key) const
{
	return (locate(_key) != nullptr);
}

template<class KeyType, class DataType>
DataType HashMap<KeyType, DataType>::get(const KeyType &_key) const
{
	TableCell<KeyType, DataType>* cell = locate(_key);
	assert(cell != nullptr);
	return cell->data;
}

template<class KeyType, class DataType>
void HashMap<KeyType, DataType>::remove(const KeyType &_key)
{
	size_t hashCode = hashFn(_key, tableSize);

	TableCell<KeyType, DataType>* curr = table[hashCode];
	assert(curr != nullptr);
	while (curr->next && curr->key != _key)
	{
		curr = curr->next;
	}

	assert(crr->next != nullptr);

	TableElement<KeyType, DataType> *toDelete = curr->next;
	curr->next = curr->next->next;
	delete toDelete;
}