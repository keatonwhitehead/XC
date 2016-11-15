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
#include <stdlib.h>
#include "HTC.cpp"

using namespace std;

// Declare functions
void displayMenu();

// --------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  int size = atoi(argv[1]), element, ch, index, position;
  HashTab hash(size);

  bool quit = false;
  while(!quit)
  {
    displayMenu();
    cout << "Input: ";
    cin >> ch;

    switch(ch)
    {
      case 1:
      {
        cout << "Enter element to be inserted: ";
        cin >> element;
        hash.Insert(element);
        break;
      }
      case 2:
      {
        cout << "Enter element you want to find: ";
        cin >> element;
        index = hash.HashFunc(element);
        position = hash.Find(element);

        if (hash.Find(element) == -1)
        {
          cout << element << " was not found in the table."<< endl;
        }
        else
        {
          cout << element << " was found at index " << index << " : ";
          cout << "position " << position << endl;
        }
        break;
      }
      case 3:
      {
        cout << "Enter the element to be deleted: ";
        cin >> element;
        if (hash.Find(element) == -1)
        {
          cout << element << " was not found in the table." << endl;
        }
        else
        {
          hash.Delete(element);
          cout << element << " was deleted from the table." << endl;
        }
        break;
      }
      case 4:
      {
        hash.display();
        break;
      }
      case 5:
      {
        cout << "Goodbye!" << endl;
        exit(1);
      }
      default:
      {
        cout << "\nEnter valid option\n";
      }
    }
  }
  return 0;
}
// --------------------------------------------------------------------------
void displayMenu()
{
  cout << "\n----------------------" << endl;
  cout << "Operations on Hash Table" << endl;
  cout << "----------------------\n" << endl;
  cout << "1. Insert element into the table" << endl;
  cout << "2. Search an element " << endl;
  cout << "3. Delete element " << endl;
  cout << "4. Display HashTable" << endl;
  cout << "5. Exit\n" << endl;
}
