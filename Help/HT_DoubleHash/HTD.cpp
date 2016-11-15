// =======================================
// Author:  Jeremy Candelaria
//   Date:  10/31/2016
//  Title:  HashTable - Double Hashing
// =======================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "HTD.hpp"

using namespace std;

// Hash Function
int HashTab::HashFunc(int key)
{
	return key % TABLE_SIZE;
}
// --------------------------------------------------------------------------
// Double Hash Function
int HashTab::DoubleHashFunc(int key, int index)
{
	int newIndex, newKey, nextPrime = 7;

	newKey = (index + (nextPrime - (key % nextPrime)));
	newIndex = HashFunc(newKey);
	return newIndex;
}
// --------------------------------------------------------------------------
// Insert an element in HashTable
//	currently inserts repeated keys (should they have subkeys?)
void HashTab::Insert(int key)
{
	// 22, 1, 13, 11, 24, 33, 18, 42, 31
	int index = HashFunc(key);
	int newIndex;

	if (htable[index] != NULL)
	{
		while (htable[index] != NULL)
		{
			// try double hash
			newIndex = DoubleHashFunc(key, index);

			if (htable[newIndex] == NULL)
			{
				htable[newIndex] = new Node(key);
				return;
			}
			else // add linearly
			{
				// try double hash with newIndex
				index = newIndex;
			}
		}
	}
	htable[index] = new Node(key);
}
// --------------------------------------------------------------------------
// Display HashTable
void HashTab::display()
{
	cout << "\n--- HashTable ---" << endl; // space

	for (int i = 0; i < TABLE_SIZE ; i++)
	{
		Node *current = htable[i];
		if (i < 10)
		{
			cout << " " << i << ": ";
		}
		else
		{
			cout << i << ": ";
		}

		if (current != NULL)
		{
			cout << current->key << endl;
		}
		else
		{
			cout << endl;
		}
	}
}
// --------------------------------------------------------------------------
// Search an element
//	currently finds first index of a repeated key
int HashTab::Find(int key)  // ********* Does not handle case for repeated keys *********
{
	// int index = HashFunc(key);
	//
	// if (htable[index] != NULL && htable[index]->key != key)
	// {
	// 	while (htable[index] != NULL && htable[index]->key != key)
	// 	{
	// 		if (index < TABLE_SIZE - 1)
	// 		{
	// 			index++;
	// 		}
	// 		else
	// 		{
	// 			index = 0;
	// 		}
	// 	}
	// }
	//
	// if (htable[index] != NULL)
	// {
	// 	return index;
	// }
	// else
	// {
	// 	return -1;
	// }
}
// --------------------------------------------------------------------------
// Delete an element
//	currently deletes first index of a repeated key
void HashTab::Delete(int key)  // ********* Does not handle case for repeated keys *********
{
	// int index = HashFunc(key);
	//
	// if (htable[index] != NULL && htable[index]->key != key)
	// {
	// 	while (htable[index] != NULL && htable[index]->key != key)
	// 	{
	// 		index++;
	// 	}
	// }
	//
	// if (htable[index] != NULL)
	// {
	// 	delete htable[index];
	// 	htable[index] = NULL;
	// }
}
