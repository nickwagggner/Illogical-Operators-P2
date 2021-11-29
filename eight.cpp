#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

map<int, map<int, int> > genGraph() { //generate a graph with 20 vertices and randomly decide edges
	int random;
	map<int, map<int, int> > Graph;
	for(int i = 0; i < 20; i++) {
		for(int j = i+1; j < 20; j++) {
			random = rand()%2; // 1 = true and 0 = false
			Graph[i][j] = random;
			Graph[j][i] = random;
		}
	}
	return Graph;	
}

bool isConnected(map<int, map<int, int> > graph) { //find if a graph is fully connected
	int visited[20];
	int visIndHold = 1;
	visited[1] = 0;
	for(int i = 1; i < 20; i++) { //check everything connected to vertex 0
		if(graph[0][i] == 1) {
			visited[visIndHold] = i;
			visIndHold++;
		}
	}
	if(visited[1] == 0) //if we don't find anything connected to vertex 0
		return false;
		
	visited[0] = 0; //add vertex 0 to the list of visited vertices
	
	int indexHold = 0; //start the index at 0 for the next part

		indexHold ++; //go to the next index of the visited list
		for(int i = 0; i < 20; i++) { //check everything connected to the current vertex
			//only check if a vertex is connected if it hasn't already been visited
			for(int j = 0; j < 20; j++) { //walk through the visited list
				if(i == visited[j]) 
					break; //break out to i++
			}
			
			if(graph[visited[indexHold]][i] == 1) { //if we find a connection
				visited[visIndHold] = i; //add the connected vertex to the visited list
				visIndHold++;
			}
			//check if we have already connected to all vertices
			if(visIndHold == 20)
				return true;
		}
	return false;
}

int connectedComponents(map<int, map<int, int> > graph) { //determine the number of connected components if a graph is not fully connected
	int array[20];
	for(int i = 0; i < 20; i++) 
		array[i] = 1; //initially set everything to 1
	//int indexHold = 0;
	//check if each vertex is connected to anything
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			if(graph[i][j] == 1) //if there is a connection
				break;
			if(j == 19) //if we have made it all the way through and not found anything connected to i
				array[i] = 0;
		}
	}
	
	//now that we only have verticies that are connected to something else
	//go through and remove the connected verticies
	for(int i = 0; i < 20; i++) {
		if(array[i] == 1) { //if there is at least 1 connection to this vertex
			for(int j = 0; j < 20; j++) {
				if(graph[i][j] == 1)
					array[j] = 0;
			}
		}
	}
	
	int count = 0;
	//now, count all the 1's in the array
	for(int i = 0; i < 20; i++) {
		if(array[i] == 1)
			count ++;
	}
	return count;
}


int main() {
	
	map<int, map<int, int> > graph1;
	graph1 = genGraph();
	
	map<int, map<int, int> > graph2;
	graph2 = genGraph();
	
	map<int, map<int, int> > graph3;
	graph3 = genGraph();
	
	map<int, map<int, int> > graph4;
	graph4 = genGraph();
	
	map<int, map<int, int> > graph5;
	graph5 = genGraph();
	
	map<int, map<int, int> > graph6;
	graph6 = genGraph();
	
	map<int, map<int, int> > graph7;
	graph7 = genGraph();
	
	map<int, map<int, int> > graph8;
	graph8 = genGraph();
	
	map<int, map<int, int> > graph9;
	graph9 = genGraph();
	
	map<int, map<int, int> > graph10;
	graph10 = genGraph();
	
	
	bool con = isConnected(graph1);
	if(con)
		cout << "Graph 1 is connected." << endl;
	else {
		int components = connectedComponents(graph1);
		cout << "Graph 1 is not connected. There are " << components << " connected components." << endl;
	}
	
	con = isConnected(graph2);
	if(con)
		cout << "Graph 2 is connected." << endl;
	else {
		int components = connectedComponents(graph2);
		cout << "Graph 2 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph3);
	if(con)
		cout << "Graph 3 is connected." << endl;
	else {
		int components = connectedComponents(graph3);
		cout << "Graph 3 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph4);
	if(con)
		cout << "Graph 4 is connected." << endl;
	else {
		int components = connectedComponents(graph4);
		cout << "Graph 4 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph5);
	if(con)
		cout << "Graph 5 is connected." << endl;
	else {
		int components = connectedComponents(graph5);
		cout << "Graph 5 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph6);
	if(con)
		cout << "Graph 6 is connected." << endl;
	else {
		int components = connectedComponents(graph6);
		cout << "Graph 6 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph7);
	if(con)
		cout << "Graph 7 is connected." << endl;
	else {
		int components = connectedComponents(graph7);
		cout << "Graph 7 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph8);
	if(con)
		cout << "Graph 8 is connected." << endl;
	else {
		int components = connectedComponents(graph8);
		cout << "Graph 8 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph9);
	if(con)
		cout << "Graph 9 is connected." << endl;
	else {
		int components = connectedComponents(graph9);
		cout << "Graph 9 is not connected. There are " << components << " connected components." << endl;
	}
		
	con = isConnected(graph10);
	if(con)
		cout << "Graph 10 is connected." << endl;
	else {
		int components = connectedComponents(graph10);
		cout << "Graph 10 is not connected. There are " << components << " connected components." << endl;
	}
		
	return 0;
}






