#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>

using namespace std; 

	int n,m;
	int a,b; 



struct edge{
	int w;
	int v; 


	edge(int _v, int _w){
		v = _v;
		w = _w;
	}

};

struct node{
	vector<edge> list;
	int id;
	int dist;

	node(int _id, int _dist){
		id = _id;
		dist = _dist; 
	}

    bool operator < (node e) const {
        return dist < e.dist;
    }
}; 


vector<node> graph;  

int main(){

	cin >> n >> m; 
	int source = 0; 
	

	graph.push_back(node(0,0)); 

	for(int i = 1; i<n; i++)
		graph.push_back(node(i,10001)); 
	

	int weight; 
	for(int i = 0; i<m; i++){
		cin >> a >> b >> weight; 

		graph[a].list.push_back(edge(b,weight)); 	
	}


 


	priority_queue<node> q; 

	for(int i = 0; i<n; i++)
		q.push(graph[i]); 

	while(!q.empty()){
		node min = q.top(); 
		q.pop();

		for(int i = 0; i<min.list.size(); i++){
			int alt = min.dist + min.list[i].w; 

			if(alt < graph[min.list[i].v].dist){
				graph[min.list[i].v].dist = alt; 
				q.push(graph[min.list[i].v]);
			}
		}
	}

	for(int i = 0; i<n; i++)
		cout << "from " << source << " to " << i << " "<< graph[i].dist << endl; 

	return 0; 
} 