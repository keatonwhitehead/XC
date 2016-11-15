// =======================================
// Author:  Jeremy Candelaria
//   Date:  10/31/2016
//  Title:  HashTable - Separate Chaining
// =======================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "HTC.hpp"

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
	int index = HashFunc(key);

	// if the table slot is filled add to the end of the Linked List
	if (htable[index] != NULL)
	{
		Node *current = htable[index];
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new Node(key);
	}
	else // slot is empty
	{
		htable[index] = new Node(key);
	}
}
// --------------------------------------------------------------------------
// Display HashTable
void HashTab::display()
{
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

		while (current != NULL)
		{
			cout << current->key << "-->";
			current = current->next;
		}
		cout << endl;
	}
}
// --------------------------------------------------------------------------
// Search an element
int HashTab::Find(int key)
{
	int index = HashFunc(key);
	int c = 0;
	if (htable[index] == NULL)
	{
		return -1;
	}
	else
	{
		Node *current = htable[index];
		while (current->next != NULL && current->key != key)
		{
			current = current->next;
			c++;
		}

		if (current->key == key)
		{
			return c;
		}
		else
		{
			return -1;
		}
	}
}
// --------------------------------------------------------------------------
// Delete an element
void HashTab::Delete(int key)
{
	int index = HashFunc(key);

	if (htable[index] != NULL)
	{
		Node *current = htable[index];
		Node *prev = NULL;
		while (current != NULL && current->key != key)
		{
			prev = current;
			current = current->next;
		}

		// delete head node
		if (prev == NULL)
		{
			htable[index] = current->next;
			delete current;
		}
		else
		{
			prev->next = current->next;
			delete current;
		}
	}
}
