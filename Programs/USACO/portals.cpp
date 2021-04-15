#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct DSU {
	int p[N], rank[N];
	DSU() {
		for (int i = 0; i < N; ++i) {
			p[i] = i;
			rank[i] = 0;
		}
	}
	inline int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}
	inline bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y);
		if (rank[x] == rank[y]) ++rank[x];
		p[y] = x;
		return true;
	}
} dsu;

int n;
tuple<int, int, int, int, int> edges[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int w, a, b, c, d;
		cin >> w >> a >> b >> c >> d;
		dsu.unite(a, b);
		dsu.unite(c, d);
		edges[i] = make_tuple(w, a, b, c, d);
	}
	sort(edges, edges+n);
	int ans = 0;
	for (auto& edge : edges) {
		int w, a, b, c, d;
		tie(w, a, b, c, d) = edge;
		if (dsu.unite(a, c) || dsu.unite(b, d)) {
//			cout << "using w="<<w<<", now "<<a<<"-"<<c<<", "<<b<<"-"<<d<<"\n";
			ans += w;
		}
	}
	cout << ans << '\n';
}
