
// Problem : Problem 3. The Great Revegetation
// Contest : USACO 2019 February Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=920
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int M = 100010;

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

int n, m;
pii edge[M];
vector<int> adj[N];
int color[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		char ch;
		int a, b;
		cin >> ch >> a >> b;
		if (ch == 'S') {
			dsu.unite(a, b);
			edge[i] = make_pair(0, 0);
		} else {
			edge[i] = make_pair(a, b);
		}
	}
	for (int i = 0; i < m; ++i) {
		int a = dsu.get(edge[i].first);
		int b = dsu.get(edge[i].second);
		if (a == 0) continue;
		if (a == b) {
			cout << 0 << '\n';
			return 0;
		}
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		color[i] = -1;
	}
	int numcc = 0;
	for (int i = 1; i <= n; ++i) {
		int src = dsu.get(i);
		if (color[src] != -1) continue;
		++numcc;
		color[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : adj[u]) {
				if (color[v] == -1) {
					color[v] = 1 - color[u];
					q.push(v);
				} else if (color[v] == color[u]) {
					cout << 0 << '\n';
					return 0;
				}
			}
		}
	}
	cout << 1;
	for (int i = 0; i < numcc; ++i) {
		cout << 0;
	}
}
