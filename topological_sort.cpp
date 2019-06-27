#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int> > &graph,stack<int> &s, vector<bool> &vis, int u)
{
	vis[u] = true;
	for(int i : graph[u])
		if(!vis[i])
			dfs(graph,s,vis,i);

	s.push(u);
}

int main()
{
	cout << "Enter No. of vertices: ";
	int V;	cin >> V;
	vector<vector<int> > graph(V);
	int u,v;
	while(true)
	{
		cin >> u >> v;
		if(u == -1)
			break;
		graph[u].push_back(v);
	}
	stack<int> s;
	vector<bool> vis(V,false);
	for(int i = 0; i < V; i++)
		if(!vis[i])
			dfs(graph,s,vis,i);
	cout << "Topological ordering is: ";
	while(!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
}
