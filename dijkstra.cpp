#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;

void dijkstra(int src, vector< vector< pair<int,int> > >& graph, vector<int> &prev)
{
	int V = graph.size();
	set< pair<int,int> > ds;		//first val is weight second is destination
	vector<int> dis(V,INF);
	dis[src] = 0;
	ds.insert({dis[src],src});
	while(!ds.empty())
	{
		pair<int,int> p = *(ds.begin());
		ds.erase(ds.begin());
		int u = p.second;
		for(auto &i : graph[u])
		{
			int v = i.second;
			int w = i.first;
			if(dis[v] > dis[u]+w)
			{
				if(dis[v] != INF)
					ds.erase(ds.find({dis[v], v}));
				dis[v] = dis[u] + w;
				prev[v] = u;
				ds.insert({dis[v],v});
			}
		}
	}
	for(int i = 0; i < V; i++)
	{
		cout << "Distance[" << i << "] = " << dis[i] << '\n';
	}
}
int main()
{
	int V; 
	cout << "Enter No. of Vertices: ";
	cin >> V;
	vector< vector< pair<int,int> > > graph(V);
	cout << "Enter Edges(src destination weight)(-1 -1 -1 to terminate)\n";
	int u,v,w;
	while(true)
	{
		cin >> u >> v >> w;
		if(u == -1)
			break;
		graph[u].push_back({w,v});
		// graph[v].push_back({w,u});	//uncomment this line if graph is undirected
	}
	cout << "Enter src: ";
	int src;
	cin >> src;
	vector<int> prev(V,0);
	dijkstra(src, graph, prev);

	cout << "Enter Destination: ";
	int des;
	cin >> des;
	stack<int> s;
	s.push(des);
	while(prev[des] != des)
	{
		s.push(prev[des]);
		des = prev[des];
	}
	while(!s.empty())
	{
		cout << s.top() << "->";
		s.pop();
	}
}
