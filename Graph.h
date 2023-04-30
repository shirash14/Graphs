//Shira Cohen 211485198
//Mivne Netunim 2
//Targil 5- Graphs

#include <iostream>
#include <list>
#include <string>
#include <map>
#pragma once
using namespace std;

class Vertex;

class Edge//this class represent a edge includes:two vertexes
{
public:
	Vertex* source;
	Vertex* destination;
public:
	Edge(Vertex* source, Vertex* destination) : source(source), destination(destination) {}
	bool operator==(Edge & v); //Comparison operator between two Edges
};

//this class represents a vertex includes:key ,list of his edges
enum Color { White, Gray, Black };
class Vertex
{
	string Key;
	Color color;
	list<Edge> EdgeListFrom;
	list<Edge> EdgeListTo;
public:
	Vertex(string key) : Key(key) {} //Ctor
	~Vertex(); //Dtor
	void adde(Edge); //Adds an edge to the vertex
	void dele(Edge); //Deletes an edge from the vertex
	bool destinationExists(Vertex* v); //Checks if there is an edge that connects to the given vertex
	void print(); //Prints a vertex
	friend class Graph;
};

class Graph
{
	map<string,Vertex*> vertexes;
public:
	Graph();
	~Graph();

	void addv(string v); //Add a vertex to the graph
	bool delv(string v); //delete a vertex from the graph
	bool adde(string v1, string v2); //Add an edge in the graph
	bool dele(string v1, string v2); //delete an edge from the graph
	void printNeighbors(string v); //Prints all vertices that have an edge from the vertex given to them
	void printFollowers(string v); //Prints all the vertices that have an edge to the given vertex
	void printAllReached(string v); //Prints all reachable vertices from the given vertex
	void printAll(); //Prints the entire graph
private:
	void printRecursive(Vertex* v); //Auxiliary function for printing the reachable vertices
};