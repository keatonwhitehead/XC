// =========================================
// Instructor:	Elle Boese
//     Editor:  Jeremy Candelaria
//      Title:  HW9XC -> Graph.hpp
//       Date:
//       Team:
// =========================================

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

// =========================== INITIALIZATION ===============================
const int HASHMAP_SIZE = 71;
struct vertex;
// --------------------------------------------------------------------------

// =========================== FUNCTIONALITY ================================
/*This is the struct for the adjacent vertices for each
 vertex in the graph. */
struct adjVertex
{
	vertex *v;
};
// --------------------------------------------------------------------------
/*this is the struct for each vertex in the graph.  */
struct vertex
{
	std::string id;
	std::string name;
	int networkID;
  std::vector<adjVertex> friends;
  bool visited;
};
// --------------------------------------------------------------------------
struct hobbylist
{
	std::string hobby;
	std::vector<vertex*> list;
};
// --------------------------------------------------------------------------
class Graph
{
	public:
		Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2 );
    void addVertex(std::string id);
    void displayEdges();
		void assignSocialCircles();
		 int addUserToHobby(std::string hobby, std::string id);
		void displayHobbies();

    std::vector<vertex> vertices;

	private:
		vertex * findVertex(std::string name);
		void BFTraversalLabel(std::string startingCity, int groupID);

		hobbylist * hobbies[HASHMAP_SIZE];
};
// --------------------------------------------------------------------------
#endif // GRAPH_HPP
