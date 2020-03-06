#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 100100;

int n, m;
vector<int> adj[N];

int timer;
int tin[N], low[N];
vector<pii> edgestack;

vector<int> adj2[N]; // for the current biconnected component

void solve_bcc(int finalnode1, int finalnode2) {
	// we will remove edges from edgestack
	// until the edge finalnode1 - finalnode2 (inclusive)
	// all edges that we removed form the bcc
	vector<int> nodes; // might contain copies
	while (!edgestack.empty()) {
		int u = edgestack.back().first, v = edgestack.back().second;
		nodes.push_back(u);
		nodes.push_back(v);
		adj2[u].push_back(v);
		adj2[v].push_back(u);
		edgestack.pop_back();
		cout << u << " - " << v << ", ";
		if (u == finalnode1 && v == finalnode2) break;
	}
	cout << '\n';
	// do stuff
	// ...
	// clear out the adjacency list
	while (!nodes.empty()) {
		adj2[nodes.back()].clear();
		nodes.pop_back();
	}
}

void dfs_bcc(int u, int parent) {
	tin[u] = low[u] = timer++;
	for (int v : adj[u]) {
		if (tin[v] == -1) {
			edgestack.emplace_back(u, v);
			dfs_bcc(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u]) {
				solve_bcc(u, v);
			}
		} else if (v != parent && tin[v] < low[u]) {
			low[u] = tin[v];
			edgestack.emplace_back(u, v);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		tin[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		if (tin[i] == -1) {}
		dfs_bcc(i, -1);
	}
	/*
	example input:
	6 7
	1 2
	2 5
	5 4
	4 1
	2 3
	3 6
	6 2
	*/
}
