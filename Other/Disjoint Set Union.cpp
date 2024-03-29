struct DSU {
	int n;
	vector<int> p, rank;
	DSU(int n) : n(n) {
		rank.assign(n, 1); // rank[i] = 1
		p.resize(n);
		iota(p.begin(), p.end(), 0); // p[i] = i
	}
	inline int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}
	inline bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false; // already in same set
		if (rank[x] < rank[y]) swap(x, y);
		if (rank[x] == rank[y]) ++rank[x];
		p[y] = x;
		return true; // success
	}
};

/*
// sample usage
DSU dsu(10);
dsu.unite(2, 5);
dsu.unite(5, 8);
dsu.unite(3, 7);
for (int i = 0; i < 10; ++i) {
	cout << "representative for " << i << " is " << dsu.get(i) << "\n";
}
*/
