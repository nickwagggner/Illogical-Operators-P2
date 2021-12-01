#include <iostream>
#include <queue>
using namespace std;

bool bfs(vector<int>adjacent[], int color[], int place){
	
	queue<int>q;
	q.push(place);
	color[place]=1;


	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int i:adjacent[f]){
			if(color[i]==-1){//checking if the element isn't colored yet
				color[i]=1-color[f];
				q.push(i);
			}

			if(color[i]==color[f]){//bipartite graph isn't possible if it has the same color as the vertex
				return false;
			}
		}

	}

	
	return true;

}
bool bipartite(vector<int>adjacent[], int s){
	int color[s];

	for(int i=0;i<s;i++){
		color[i]=-1; //setting all elements of color to -1
	}				// -1 signifies element that hasn't been checked yet

	for(int i=0;i<s;i++){
		if(color[i]==-1){//looking only for elements that haven't already been checked
			if(bfs(adjacent,color,i)==false){//using bfs algorithm to check if
				return false;
			}
		}
	}


	return true;
}

int main(int argc, char *argv[]){
	int nodes=4;

	vector<int> adj[nodes];//initializing vector that holds the edges
	
//bipartite 
//	adj[2].push_back(1);
//	adj[1].push_back(2);
//	
//	adj[2].push_back(0);
//	adj[0].push_back(2);
//
//	adj[2].push_back(1);
//	adj[1].push_back(2);
//	
//	adj[2].push_back(0);
//	adj[0].push_back(2);


//not bipartite
	adj[2].push_back(1);
	adj[1].push_back(2);
	
	adj[2].push_back(0);
	adj[0].push_back(2);

	adj[2].push_back(1);
	adj[1].push_back(2);
	
	adj[1].push_back(0);
	adj[0].push_back(1);
	

	if(bipartite(adj, nodes)){
		cout << "yes" << endl;

	}else{
		cout << "no" << endl;
	}
	return 0;
}