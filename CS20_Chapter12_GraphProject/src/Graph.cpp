//
//  Graph.cpp
//  STL_DirGraph
//
//  Created by Bill Komanetsky on 11/27/17.
//  Copyright © 2017 Bill Komanetsky. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph() {
    initGraph();
}//Graph()

//The Destructor will go through each array entry and delete the vertex at that array
//position if it has been created.  It will then clear the vector of adjacent vertecies
//You don't need to worry about loosing those vertices because they will be deleted
//when we get to their position in the array
Graph::~Graph() {
    for (int i=0; i<STARTSIZE; i++) {
        if (edgeArray[i].first != nullptr) {
            delete edgeArray[i].first;      //Delete the vertex
            edgeArray[i].first = nullptr;   //Set its poiner to nullptr since it's been deleted
            edgeArray[i].second->clear();   //Clear the vector of adjacent vertices
            delete edgeArray[i].second;     //Now, delete the dynamically allocated vector
        }//if
        else {}
    }//for i
}//~Graph()

//Set everything up in the array so we can store vertices and their adjacent vertices (edges)
//Each of the array's memory locations shall contain a pair of data
//      first:  A vertex structure
//      second: A vector of vertex structures
//              Each of these will be the end-point of an edge eminating from the vertex (first)
void Graph::initGraph(void) {
    for (int i=0; i<STARTSIZE; i++) {
        edgeArray[i].first = nullptr;
        edgeArray[i].second = new vector<GraphVertex*>;
    }//for
}//initGraph

//Return the pointer to a vector of vertex pointers which shall contain all
//of the end-points for each edge eminating from the vertex (first) in that pair
vector<GraphVertex*>* Graph::getDestVertex(int sourceVertex) {
    if (sourceVertex >= STARTSIZE) {
        return nullptr;
    }//if
    else {
        return edgeArray[sourceVertex].second;
    }//else
}//getDestVertex(int)

//Add a vertex to the array if that vertex hasn't yet been created
//Will return doing nothing if that vertex has already been setup, or, if the value
//which the vertex shall contain is greater than the arrayt capacity or less than zero
void Graph::addVertex(int vertexValue) {
    //If the vertex value is larger than the graph capacity or
    //  the vertex already exists, then leave.
    if (vertexValue >= STARTSIZE || vertexValue < 0 || this->edgeArray[vertexValue].first != nullptr) {
        return;
    }//if
    else {
        //Create a new vertex and populate its value
        GraphVertex* tempVertex = new GraphVertex;
        tempVertex->Value = vertexValue;
        tempVertex->Visited = false;
        //Now, add it to the first of the pair
        edgeArray[vertexValue].first = tempVertex;
    }//else
}//addVertex

//Add a directed edge
//Will do nothing if the range of the source or destination values are beyond the size of the
//array, or, if the source or destination vertices have not yet been added, in other words, if
//you try to create an edge for a vertex that does not yet exist, this function will do nothing
void Graph::addEdgeDir(int source, int destination) {
    //if the source or destination vertex values are grater than the size of the array of vectors
    //or if the soruce or destination vertecis do not exist, then return
    if (source >= STARTSIZE || source < 0 || destination >= STARTSIZE || destination < 0 ||
        edgeArray[source].first == nullptr ||
        edgeArray[destination].first == nullptr) {
        return;
    }//if
    else {
        //Add to the source vector an existing vertex located at destination in the array
        edgeArray[source].second->push_back(edgeArray[destination].first);
    }//else
}//adEdge(int, int)

//Add a directed edge
//Will do nothing if the range of the source or destination values are beyond the size of the
//array, or, if the source or destination vertices have not yet been added, in other words, if
//you try to create an edge for a vertex that does not yet exist, this function will do nothing
void Graph::addEdgeUnDir(int source, int destination) {
    //if the source or destination vertex values are grater than the size of the array of vectors
    //or if the soruce or destination vertecis do not exist, then return
    if (source >= STARTSIZE || source < 0 || destination >= STARTSIZE || destination < 0 ||
        edgeArray[source].first == nullptr ||
        edgeArray[destination].first == nullptr) {
        return;
    }//if
    else {
        //Add to the source vector an existing vertex located at destination in the array
        edgeArray[source].second->push_back(edgeArray[destination].first);
        //Add to the destination vector an existing vertex located at source in the array
        edgeArray[destination].second->push_back(edgeArray[source].first);
    }//else
}//adEdge(int, int)

#include <stack>
#include <iostream>

//Do a Depth first Search for the graph
//This function will return a vector of vertices showing how the graph was navigated
//If you try to start with a vertex which does not exist, this function will return
//an empty vector
vector<GraphVertex*> Graph::searchDFS(int start) {
    vector<GraphVertex*> returnVector;

    cout << "Graph::searchDFS" << endl;

    /*
     Create a Stack<Node> of nodes to visit;
     Add v to the stack;
     while (The stack is not empty) {
     Pop a node from the stack, let it be u;
     if (u has been visited) continue;
     Add u to the visited set;
     for (Node w connected to u)
     Push w onto the stack;
     }
     */
    
    stack<GraphVertex*> Stack;
    vector<GraphVertex*> Visited;
    GraphVertex* v;
    GraphVertex* u;
    GraphVertex* w;

    cout << "Graph::searchDFS | Calling Graph::clearAllVisited()" << endl;
    this->clearAllVisited();

    cout << "Graph::searchDFS | Setting v to edgeArray[start].first" << endl;
    v = edgeArray[start].first;

    cout << "Graph::searchDFS | Pushing v to Stack." << endl;
    Stack.push(v);

    cout << "Graph::searchDFS | While Stack is not empty" << endl;
    while (!Stack.empty())
    {
        //cout << "Graph::searchDFS | While Stack is not empty | Set u to Stack.top()" << endl;
    	u = Stack.top();

    	//cout << "Graph::searchDFS | While Stack is not empty | Call Stack.pop()" << endl;
    	Stack.pop();

    	//cout << "Graph::searchDFS | While Stack is not empty | Set u->Visited to true" << endl;
    	u->Visited = true;

    	//cout << "Graph::searchDFS | While Stack is not empty | If u->Visited, continue to next loop." << endl;
    	if (u->Visited) continue;

        //cout << "Graph::searchDFS | While Stack is not empty | push_back u to Visited vector." << endl;
    	Visited.push_back(u);

        //cout << "Graph::searchDFS | While Stack is not empty | Push adjacent GraphVertex's onto Stack." << endl;
        for (int i=0; i<this->getDestVertex(start)->size(); i++)
    	{
    	    //cout << "Graph::searchDFS | While Stack is not empty | For | Print adjacent GraphVertex Value." << endl;
    		w = getDestVertex(start)[i].at(i);
    		Stack.push(w);
    	}
    }

    return Visited;
}//searchDFS

//Do a Breadth first Search for the graph
//This function will return a vector of vertices showing how the graph was navigated
//If you try to start with a vertex which does not exist, this function will return
//an empty vector
vector<GraphVertex*> Graph::searchBFS(int start) {
    vector<GraphVertex*> returnVector;
    
    /*
     Create a Queue<Node> of nodes to visit;
     Add v to the stack;
     while (The stack is not empty) {
     Pop a node from the stack, let it be u;
     if (u has been visited) continue;
     Add u to the visited set;
     for (Node w connected to u)
     Push w onto the stack;
     }
     */
    
    return returnVector;
}//searchBFS

//This function shall set to false all vertices visited variable to false
void Graph::clearAllVisited(void) {
    for (int i=0; i<STARTSIZE; i++) {
        if (edgeArray[i].first != nullptr) {
            edgeArray[i].first->Visited = false;
        }//if
        else {}
    }//for
}//clearAllVisited

