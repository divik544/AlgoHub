// Program to find Longest Increasing Subsequence in O(nlgn)
// tested on GFG Practice
// Caution: This program finds the length of Longest Increasing Subsequence not Longest Non-Decreasing Subsequence
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	vector<int> l(n,1),a(n+1,INT_MAX);
	a[0] = -INT_MAX;
	int id;
	for(int i = 0; i < n; i++)
	{
		id = lower_bound(a.begin(), a.end(),v[i])-a.begin();
		l[i] = id;
		a[id] = v[i];
	}
	int lis = *max_element(l.begin(), l.end());
	cout << lis << '\n';
}
