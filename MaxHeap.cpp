#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MaxHeap
{
	vector<int> v;
	int N;

	void swim(int k)
	{
		while(k > 1)
		{
			if(less(k/2,k))
				swap(v[k/2],v[k]);
			else break;
			k = k/2;
		}
	}
	void sink(int k)
	{
		int j;
		while(2*k <= N)
		{
			j = 2*k;
			if(j < N && less(j,j+1))
				j++;
			if(!less(k,j)) break;
			swap(v[k],v[j]);
			k = j;
		}
	}
	bool less(int i,int j)
	{
		return (v[i] < v[j]);
	}
public:
	MaxHeap()
	{
		v.push_back(0);
		N = 0;
	}
	bool isempty()
	{
		return (N==0);
	}
	int getMax()
	{
		if(N == 0)
		{
			cout << "Heap Empty!!!\n";
			return INT_MIN;
		}
		return v[1];
	}
	void insert(int val)
	{
		if(v.size() > N+1)
			v[N+1] = val;
		else
			v.push_back(val);
		N++;
		swim(N);
	}
	int delMax()
	{
		swap(v[1],v[N]);
		N--;
		sink(1);
		return v[N+1];
	}
};
int main()
{
	MaxHeap pq;
	pq.insert(2);
	pq.insert(5);
	pq.insert(4);
	pq.insert(6);
	pq.insert(3);
	cout << pq.delMax() << ' ';
	cout << pq.delMax() << ' ';
	pq.insert(10);
	pq.insert(8);
	cout << pq.delMax() << ' ';
	cout << pq.delMax() << ' ';
	// 6 5 10 8
}