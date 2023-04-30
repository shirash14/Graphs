//Shira Cohen 211485198
//Mivne Netunim 2
//Targil 5- Graphs

#include "Graph.h"

//Ctor
Graph::Graph()
{
}

//Dtor
Graph::~Graph()
{
	vertexes.clear();
}

//Add a vertex to the graph
void Graph::addv(string v)
{
	if (vertexes.find(v) == vertexes.end())
		vertexes.insert(pair<string, Vertex*>(v, new Vertex(v)));
}

//delete a vertex from the graph
bool Graph::delv(string v)
{
	if (vertexes.find(v) != vertexes.end()) //if v exist in the graph
	{
		vertexes.erase(v);
		return true;
	}
	return false;
}

//Add an edge in the graph
bool Graph::adde(string v1, string v2)
{
	//if v1 and v2 exist in the graph and there isn't edge between them
	if (vertexes.find(v1) != vertexes.end() && vertexes.find(v2) != vertexes.end() && !vertexes[v1]->destinationExists(vertexes[v2]))
	{
		vertexes[v1]->adde(Edge(vertexes[v1], vertexes[v2]));
		return true;
	}
	return false;
}

//delete an edge from the graph
bool Graph::dele(string v1, string v2)
{
	//if v1 and v2 exist in the graph and there is edge between them
	if (vertexes.find(v1) != vertexes.end() && vertexes.find(v2) != vertexes.end() && vertexes[v1]->destinationExists(vertexes[v2]))
	{
		vertexes[v1]->dele(Edge(vertexes[v1], vertexes[v2]));
		return true;
	}
	return false;
}

//Prints all vertices that have an edge from the vertex given to them
void Graph::printNeighbors(string v)
{
	if (vertexes.find(v) != vertexes.end())
	{
		for (list<Edge>::iterator it = vertexes[v]->EdgeListFrom.begin(); it != vertexes[v]->EdgeListFrom.end(); ++it)
			it->destination->print();
		cout << endl;
	}
}

//Prints all the vertices that have an edge to the given vertex
void Graph::printFollowers(string v)
{
	if (vertexes.find(v) != vertexes.end())
	{
		for (list<Edge>::iterator it = vertexes[v]->EdgeListTo.begin(); it != vertexes[v]->EdgeListTo.end(); ++it)
			it->source->print();
		cout << endl;
	}
	else
		cout << "ERROR\n";
}

//Prints all reachable vertices from the given vertex
void Graph::printAllReached(string v)
{
	if (vertexes.find(v) != vertexes.end())
	{
		//Initializes all vertices to be white
		for (map<string, Vertex*>::iterator it = vertexes.begin(); it != vertexes.end(); it++)
			it->second->color = White;
		printRecursive(vertexes[v]);
		cout << endl;
	}
	else
		cout << "ERROR\n";
}

//Auxiliary function for printing the reachable vertices
void Graph::printRecursive(Vertex * v)
{
	if (v->color == White || v->color == Gray)
	{
		if (v->color == Gray)
			v->color = Black;
		else // if (v->color == White)
		{
			v->print();
			v->color = Gray;
		}
		for (list<Edge>::iterator it = v->EdgeListFrom.begin(); it != v->EdgeListFrom.end(); ++it)
		{ 
		//Prints all the vertices that have a edge to them and paints them gray
			if (it->destination->color == White)
			{
				it->destination->print();
				it->destination->color = Gray;
			}
		}
		for (list<Edge>::iterator it = v->EdgeListFrom.begin(); it != v->EdgeListFrom.end(); ++it)
		{
			printRecursive(it->destination);
		}
	}
}

//Prints the entire graph
void Graph::printAll()
{
	for (map<string, Vertex*>::iterator it1 = vertexes.begin(); it1 != vertexes.end(); it1++)
	{
		cout << it1->first << ": ";
		for (list<Edge>::iterator it2 = it1->second->EdgeListFrom.begin(); it2 != it1->second->EdgeListFrom.end(); ++it2)
			it2->destination->print();
		cout << endl;
	}
}

//Dtor
Vertex::~Vertex()
{
	//delete all the edge from the vertex in destination vertex
	for(list<Edge>::iterator it=EdgeListFrom.begin(); it != EdgeListTo.end(); ++it)
		dele(Edge(this, it->destination));
	//delete all the edge to the vertex
	for (list<Edge>::iterator it = EdgeListTo.begin(); it != EdgeListTo.end(); ++it)
		it->source->dele(Edge(it->source, this));
}

//Adds an edge to the vertex
void Vertex::adde(Edge e)
{
	EdgeListFrom.push_back(e);
	e.destination->EdgeListTo.push_back(e);
}

//Deletes an edge from the vertex
void Vertex::dele(Edge e)
{
	for (list<Edge>::iterator it = EdgeListFrom.begin(); it != EdgeListFrom.end(); it++)
		if (*it == e)
		{
			EdgeListFrom.erase(it);
			break;
		}
	for (list<Edge>::iterator it =e.destination->EdgeListTo.begin(); it != e.destination->EdgeListTo.end(); it++)
		if (*it == e)
		{
			e.destination->EdgeListTo.erase(it);
			break;
		}
}

//Checks if there is an edge that connects to the given vertex
bool Vertex::destinationExists(Vertex * v)
{
	for (list<Edge>::iterator it = EdgeListFrom.begin(); it != EdgeListFrom.end(); ++it)
		if (it->destination == v)
			return true;
	return false;
}

//Prints a vertex
void Vertex::print()
{
	cout << Key << ' ';
}

//Comparison operator between two Edge
bool Edge::operator==(Edge & v)
{
	if (source == v.source && destination == v.destination)
		return true;
	return false;
}