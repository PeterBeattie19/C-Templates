#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
using namespace std; 

queue<int> q;
vector<bool> visited(10001); 

void addToQueue(vector<vector<int>> graph, int s){
	for(int i = 0; i<graph[s].size(); i++){
		q.push(graph[s][i]); 
	}
}

bool BFS(vector<vector<int>> graph, int s, int d){
	if(s==d)
		return true;

	visited.push_back(s); 
	addToQueue(graph, s); 

	while(!q.empty()){
		int u = q.front();
		q.pop();

		if(visited[u] == true)
			continue; 

		visited.push_back(u); 

		if(d==u)
			return true;

		addToQueue(graph, u); 
	}

	return false; 
}



int main(){
	
	int n,m,a,b;
	cin >> n >> m; 

	vector<vector<int>> graph(n); 

	for(int i = 0; i<m; i++){
		cin >> a >> b;
		graph[a].push_back(b); 
	}

	int source, dest;

	cin >> source >> dest; 


	cout << BFS(graph, source, dest) << endl; 

	return 0; 
}