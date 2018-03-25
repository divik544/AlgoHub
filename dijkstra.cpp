#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int INF = 0x3f3f3f3f;

vector<int> dijkstra(int source, vector< vector< pair<int,int> > >& graph)
{
	int V = graph.size();
	set< pair<int,int> > ds;		//first val is weight second is destination
	vector<int> dis(V,INF);
	dis[source] = 0;
	ds.insert({dis[source],source});
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
				ds.insert({dis[v],v});
			}
		}
	}
	return dis;
}
int main()
{
	int V; 
	cout << "Enter No. of Vertices: ";
	cin >> V;
	vector< vector< pair<int,int> > > graph(V);
	cout << "Enter Edges(source destination weight)(-1 -1 -1 to terminate)\n";
	int u,v,w;
	while(true)
	{
		cin >> u >> v >> w;
		if(u == -1)
			break;
		graph[u].push_back({w,v});
		graph[v].push_back({w,u});	//comment this line if graph is directed
	}
	cout << "Enter source: ";
	int source;
	cin >> source;
	vector<int> dis = dijkstra(source, graph);
	for(int i = 0; i < V; i++)
	{
		cout << "Distance[" << i << "] = " << dis[i] << '\n';
	}
}