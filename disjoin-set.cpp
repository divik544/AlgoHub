class union_find {
	public:
	vector<int> parent,size;
	union_find(int n) {
		parent = vector<int>(n);
		size = vector<int>(n,1);
		for(int i=0;i<n;i++)
			parent[i]=i;
	}
	int root(int a) {
		return parent[a]==a?a:parent[a]=root(parent[a]);
	}
	void unionset(int a,int b) {
		int aroot=root(a);
		int broot=root(b);
		if(size[aroot]<size[broot]) {
			parent[aroot]=broot;
			size[broot]+=size[aroot];
		}
		else {
			parent[broot]=aroot;
			size[aroot]+=size[broot];
		}
	}
};
