#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>
using namespace std; 

struct edge{
	int v;
	int w;

	edge(int _v, int _w){
		v = _v;
		w = _w;
	}

    bool operator < (edge e) const {
        return w < e.w;
    }
};

priority_queue<edge> q; 
vector<vector<edge>> graph(10001); 

void addToQueue(vector<vector<edge>> graph, int n){
	for(int i = 0; i<graph[n].size(); i++){
		q.push(graph[n][i]); 
	}
}

int main(){
	
	int n,m;
	int a,b,w;

	cin >> n >> m;

	for(int i = 0; i<m; i++){
		cin >> a >> b >>w;

		graph[a].push_back(edge(b,w)); 
	}


	vector<int> sol; 

	sol.push_back(0);

	addToQueue(graph,0);

	while(sol.size()<n){
		edge e = q.top();
		q.pop();

		sol.push_back(e.v);

		addToQueue(graph,e.v); 
	}


	for(int i = 0; i<sol.size(); i++)
		cout << sol[i] << endl; 


	return 0; 
}