#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std; 

vector<bool> visited(10001); //Avoid passing in pointers to functions

bool dfs(vector<vector<int>> graph, int s, int d){

	if(s==d)
		return true; 

	visited[s] = true; 

	for(int i = 0; i<graph[s].size(); i++){
		if(!visited[graph[s][i]])
			return dfs(graph, graph[s][i], d); 
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

	cout << dfs(graph, source, dest) << endl; 

	return 0; 
}
