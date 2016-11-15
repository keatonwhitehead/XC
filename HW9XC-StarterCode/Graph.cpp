// =========================================
// Instructor:	Elle Boese
//     Editor:  Jeremy Candelaria
//      Title:  HW9XC -> Graph.cpp
//       Date:
//       Team:
// =========================================

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

#include "Graph.hpp"

using namespace std;

// =========================== PUBLIC FUNCTIONS =============================
Graph::Graph()
{
	// better do something here or seg faults await!
}
// --------------------------------------------------------------------------
Graph::~Graph()
{
	// Free hash table
}
// --------------------------------------------------------------------------
void Graph::addEdge(string v1, string v2)
{
	if(v1 == v2) 	// don't add self
		return;

	vertex *vertex1 = findVertex(v1);
	vertex *vertex2 = findVertex(v2);

	// make sure not already in the list
	bool found = false;







	if(!found)	// add edge to both vertices
	{





  }
}
// --------------------------------------------------------------------------
/* add the person to the graph */
void Graph::addVertex(string id)
{
}
// --------------------------------------------------------------------------
void Graph::displayEdges()
{
	// very much like previous homework
  cout << vertices[i].networkID << ": [" << vertices[i].id << "] ";
	cout << vertices[i].name << "-->";
}
// --------------------------------------------------------------------------
void Graph::assignSocialCircles()
{
	// very much like previous homework
}
// --------------------------------------------------------------------------
int Graph::addUserToHobby(std::string hobby, std::string id)
{
	//cout << "Adding to hobby: " << hobby << " user: " << id << endl;
	vertex *user = findVertex(id);
	// initial key is based on the first 2 characters of the hobby name
	int key = (hobby[0] + hobby[1]) % HASHMAP_SIZE;
	//cout << " initial hashmap key " << key << endl;
	int collisions = 0;


	return collisions;
}
// --------------------------------------------------------------------------
void Graph::displayHobbies()
{
	cout << "========================================\n";
	cout << "DISPLAYING HOBBY INTERESTS =============" << endl;
	for( int i=0; i<HASHMAP_SIZE; i++)
	{

	}
}
// --------------------------------------------------------------------------

// =========================== PRIVATE FUNCTIONS ============================
/* return pointer to the correct vertex (person)  */
vertex * Graph::findVertex(std::string id)
{
	// very much like previous homework
}
// --------------------------------------------------------------------------
void Graph::BFTraversalLabel(std::string userid, int groupID)
{
	// very much like previous homework
}
// --------------------------------------------------------------------------
