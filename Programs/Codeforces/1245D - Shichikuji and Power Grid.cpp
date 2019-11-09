#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct DSU {
	int n;
	vector<int> p, rank;
	DSU(int _n) {
		n = _n+1;
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		rank.assign(n, 0);
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
};

struct Edge {
	int u, v;
	ll w;
	Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> x(n+1), y(n+1), c(n+1), k(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
	}
	vector<Edge> edges;
	for (int i = 1; i <= n; ++i) {
		edges.emplace_back(0, i, c[i]);
		for (int j = 1; j <= n; ++j) {
			if (j != i) {
				edges.emplace_back(i, j, (k[i]+k[j]) * (abs(x[i]-x[j]) + abs(y[i]-y[j])));
			}
		}
	}
	sort(edges.begin(), edges.end());
	DSU dsu(n+1);
	ll cost = 0;
	vector<int> stations;
	vector<pii> wires;
	for (Edge& e : edges) {
		if (dsu.unite(e.u, e.v)) {
			cost += e.w;
			if (e.u == 0) {
				stations.push_back(e.v);
			} else {
				wires.emplace_back(e.u, e.v);
			}
		}
	}
	cout << cost << endl << stations.size() << endl;
	for (int u : stations) {
		cout << u << ' ';
	}
	cout << endl << wires.size() << endl;
	for (auto& p : wires) {
		cout << p.first << ' ' << p.second << endl;
	}
}
