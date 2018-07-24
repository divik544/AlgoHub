#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
	int V;
	cout << "Enter No. of vertices: ";
	cin >> V;
	// edge list
	vector< pair<pair<int,int>,int> > edges;
	int u,v,w;
	cout << "Enter Edges(source destination weight)(-1 -1 -1 to terminate)\n";
	while(1)
	{
		cin >> u >> v >> w;
		if(u == -1)
			break;
		edges.push_back({{u,v},w});
	}
	//initialize distances with infinity
	vector<int> dis(V,INF);
	int src;
	cout << "Enter source: ";
	cin >> src;
	vector<int> prev(V,src);
	dis[src] = 0;

	// relax edges |V|-1 times
	for(int i = 0; i < V-1; i++)
	{
		for(auto &edge : edges)
		{
			u = edge.first.first;
			v = edge.first.second;
			w = edge.second;
			if(dis[v] > dis[u]+w)
			{
				dis[v] = dis[u]+w;
				prev[v] = u;
			}
		}
	}

	for(auto &edge : edges)
	{
		u = edge.first.first;
		v = edge.first.second;
		w = edge.second;
		if(dis[v] > dis[u]+w)
		{
			cout << "Graph contains negative weight cycle." << endl;
			return 0;
		}
	}
	for(int i = 0; i < V; i++)
		cout << "Distance["<<i<<"] is "<< dis[i] << '\n';

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
