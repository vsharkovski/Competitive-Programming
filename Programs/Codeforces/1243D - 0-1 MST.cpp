#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int n;
	vector<int> p, rank, size;
	DSU(int n) : n(n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		rank.assign(n, 0);
		size.assign(n, 1);
	}
	inline int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}
	inline bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y);
		if (rank[x] == rank[y]) ++rank[x];
		size[x] += size[y];
		p[y] = x;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	DSU dsu(n);
	vector<int> cnt(n, -1);
	vector<int> last(n, -1);
	vector<int> ccs;
	for (int u = 0; u < n; ++u) {
		for (int v : adj[u]) {
			if (v < u) {
				int b = dsu.get(v);
				if (last[b] == u) {
					++cnt[b];
				} else {
					last[b] = u;
					cnt[b] = 1;
				}
			}
		}
		vector<int> ccs2;
		int uf = u;
		for (int b : ccs) {
			if (last[b] != u) {
				cnt[b] = 0;
			}
			if (cnt[b] < dsu.size[b]) {
				dsu.unite(uf, b);
				uf = dsu.get(uf);
			} else {
				ccs2.push_back(b);
			}
		}
		ccs2.push_back(uf);
		ccs2.swap(ccs);
	}
	cout << ccs.size() - 1 << '\n';
}
