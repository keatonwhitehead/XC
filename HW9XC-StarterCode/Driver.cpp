// =========================================
// Instructor:	Elle Boese
//     Editor:  Jeremy Candelaria
//      Title:  HW9XC -> Driver.cpp
//       Date:
//       Team:
// =========================================

#include <iostream>
#include <fstream>  //allows istream/ostream
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <queue>
#include <sstream>      // std::stringstream, std::stringbuf

#include "Graph.hpp"

using namespace std;

// =========================== INITIALIZATION ===============================
void readUsersIntoGraph(Graph &g, char* fileName);
void readFilesIntoGraph(Graph & g, char* directoryName);
// --------------------------------------------------------------------------

// =========================== MAIN =========================================
int main(int argc, char*argv[])
{
	if (argc != 3)
	{
		cout << "Usage: " << argv[0] << " datasetDirectoryName idlistFilename" << endl;
		return -1;
	}

  // Create a graph
  Graph graph;

  // Read file into graph
	readUsersIntoGraph(graph, argv[2]);	// file is just a list of all userids
  readFilesIntoGraph(graph, argv[1]); // each userid's detailed info

	graph.assignSocialCircles();

	cout << "========================================\n";
	cout << "GRAPH CONNECTIONS ====================== " << endl;
	graph.displayEdges();

	graph.displayHobbies();

  return 0;
}
// --------------------------------------------------------------------------
/* Function to read in all the ids in the social network.
  Does not have access to their name and hobbies, just a list of ids
  Reads in from the filename listed in command-line arguments
  @param network the graph data structure of the social network
  @param fileName is the file with a list of IDs in the social network
  */
void readUsersIntoGraph(Graph & network, char* fileName)
{
	cout << "Creating graph of social network ids from file: " << fileName << endl;
}
// --------------------------------------------------------------------------
/*
 * reads all files (one at a time) from the dataset into the graph
 * @param directoryName name of the directory with all the dataset files
 * @param fileName name of file with a list of IDs needed to process in directory
 */
void readFilesIntoGraph(Graph & g, char* directoryName)
{
  cout << "Processing dataset: " << directoryName << " (";
	cout << g.vertices.size() << " files)" << endl;
	int numCollisions = 0;

	// loop through each vertex and read in its detailed information
	// each vertex in the graph has the userid which you can create the filename to read
	// hint: create a string with directoryname/userid.txt to open each file


	// close files when done with each!!
	cout << "========================================\n";
	cout << " NUMBER OF COLLISIONS ON ADDING HOBBIES: " << numCollisions << endl;
}
// --------------------------------------------------------------------------
