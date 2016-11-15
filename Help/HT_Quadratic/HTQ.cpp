// =======================================
// Author:  Jeremy Candelaria
//   Date:  10/31/2016
//  Title:  HashTable - Quadratic Probing
// =======================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "HTQ.hpp"

using namespace std;

// Hash Function
int HashTab::HashFunc(int key)
{
	return key % TABLE_SIZE;
}
// --------------------------------------------------------------------------
// Insert an element in HashTable
void HashTab::Insert(int key)
{
/* hashtable[] is an integer hash table; empty[] is another array which indicates whether the key space is occupied;
       If an empty key space is found, the function inserts the key */

	int index, x;

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		x = std::pow((double)(i), 2);
		index = HashFunc(key + x);
		if (htable[index] == NULL)
		{
			htable[index] = new Node(key);
			break;
		}
	}
}

// ALTERNATE VERSION (WORKS DIFFERENTLY)

	// void HashTab::Insert(int key)
	// {
	// 	int index = HashFunc(key);
	// 	int i = index;
	// 	int x = 1;
	// 	if (htable[index] != NULL)
	// 	{
	// 		while (htable[index] != NULL)
	// 		{
	// 			int y = std::pow((double)(x), 2);
	// 			index = i + y;
	// 			i++;
	// 			x++;
	// 		}
	// 	}
	// 	htable[index] = new Node(key);
	// }

	// Insert an element in HashTable
	//	currently inserts repeated keys (should they have subkeys?)

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
	/* If the key is found in the hash table, the function returns the index of the hashtable where the key is inserted, otherwise it
	 returns (-1) if the key is not found */

	int index, x;

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		x = std::pow((double)(i), 2);
		index = HashFunc(key + x);
		if (htable[index]->key == key)
		{
			return index;
			//break;
		}
		else if (htable[index] == NULL)
		{
			break;
		}
	}
	return -1;
}
// --------------------------------------------------------------------------
// Delete an element
//	currently deletes first index of a repeated key
void HashTab::Delete(int key)  // ********* Does not handle case for repeated keys *********
{
	int index, x;

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		x = std::pow((double)(i), 2);
		index = HashFunc(key + x);

		if (htable[index]->key == key)
		{
			delete htable[index];
			htable[index] = NULL;
			//break;
			return;
		}
		else if (htable[index] == NULL)
		{
			break;
		}
	}

	// if (htable[index] != NULL)
	// {
	// 	delete htable[index];
	// 	//htable[index] = NULL;
	// }
}
