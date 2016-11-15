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
using namespace std;

//Node class
class Node
{
	public:
        int key;
        Node *next;

          Node(int key)
        {
            this->key = key;
            this->next = NULL;
        }
};

//  HashTab(Our HashTable) Class Declaration

class HashTab
{
    private:
        Node **htable;
        int TABLE_SIZE;
    public:
        HashTab(int size)
        {
            TABLE_SIZE = size;
            htable = new Node*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                htable[i] = NULL;
            }
        }
        ~HashTab()
        {
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (htable[i] != NULL)
                {
                    Node *prev = NULL;
                    Node *current = htable[i];
                    while (current != NULL)
                    {
                        prev = current;
                        current = current->next;
                        delete prev;
                    }
                }
                delete[] htable;
            }
        }

        //Hash Function
        int HashFunc(int key);

        //insert an element in HashTable
        void Insert(int key);

       //Display HashTable
        void display();

       //Search an element.
        int Find(int key);

        // Delete an Element
        void Delete(int key);

};
