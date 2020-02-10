// Problem : F. Berland Beauty
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5050;

int n;
pii edge[N];
int weight[N];
vector<int> adj[N];
int parent_edge[N];
int depth[N];
int m, target, wantminw;
pii qends[N];
int qminw[N];

inline int other(int i, int a) {
	return edge[i].first == a ? edge[i].second : edge[i].first;
}

void dfs(int u, int p) {
	for (int i : adj[u]) {
		int v = other(i, u);
		if (v == p) continue;
		parent_edge[v] = i;
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
}

void dfs2(int u, int p, int minw) {
	if (u == target) {
		if (minw != wantminw) {
			m = -1;
		}
		target = -1;
	}
	if (m == -1 || target == -1) return;
	for (int i : adj[u]) {
		int v = other(i, u);
		if (v == p) continue;
		dfs2(v, u, min(minw, weight[i]));
		if (m == -1 || target == -1) return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n-1; ++i) {
		int a, b;
		cin >> a >> b;
		edge[i] = make_pair(a, b);
		adj[a].push_back(i);
		adj[b].push_back(i);
		weight[i] = 1;
	}
	depth[1] = 0;
	dfs(1, -1);
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b, g;
		cin >> a >> b >> g;
		qends[i] = make_pair(a, b);
		qminw[i] = g;
		if (depth[a] < depth[b]) swap(a, b);
		while (depth[a] > depth[b]) {
			int i = parent_edge[a];
			weight[i] = max(weight[i], g);
			a = other(i, a);
		}
		while (a != b) {
			int i = parent_edge[a];
			weight[i] = max(weight[i], g);
			a = other(i, a);
			i = parent_edge[b];
			weight[i] = max(weight[i], g);
			b = other(i, b);
		}
	}
	for (int i = 1; i <= m; ++i) {
		wantminw = qminw[i];
		target = qends[i].second;
		dfs2(qends[i].first, -1, 1e9);
		if (m == -1) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for (int i = 1; i <= n-1; ++i) {
		cout << weight[i] << ' ';
	}
}
