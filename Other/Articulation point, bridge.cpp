#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int n, m;
vector<int> adj[N];

int timer;
int tin[N]; // time entered with dfs
int low[N]; // min{tin[u], tin[p] (u-p is back edge), low[v] (u-v is tree edge)}

void dfs(int node, int parent) {
	tin[node] = low[node] = timer++;
	int children = 0;
	for (int v : adj[node]) {
		if (tin[v] == -1) {
			++children;
			dfs(v, node);
			low[node] = min(low[node], low[v]);
			if (low[v] > num[node]) {
				// this edge is bridge
			}
			if (parent != -1 && low[v] >= num[node]) {
				// node is cut point
			}
		} else if (v != parent) {
			// back edge
			low[node] = min(low[node], tin[v]);
		}
	}
	if (parent == -1 && children > 1) {
		// node is cut point
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
	timer = 0;
	for (int i = 1; i <= n; ++i) {
		if (tin[i] == -1) {
			dfs(i, -1);
		}
	}
}
