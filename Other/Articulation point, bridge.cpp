#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
vector<int> adj[N];

int timer;
int tin[N];
int low[N];

void dfs(int u, int p) {
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v] != -1) {
            // back edge
            low[u] = min(low[u], tin[v]);
        } else {
            ++children;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                // u-v is bridge
                cout << "bridge: " << u << " - " << v << "\n";
            }
            if (p != -1 && low[v] >= tin[u]) {
                // u is cut node
                cout << "cut node: " << u << "\n";
            }
        }
    }
    if (p == -1 && children >= 2) {
        // u is root and cut node
        cout << "cut node (root): " << u << "\n";
    }
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	timer = 0;
	for (int i = 1; i <= n; ++i) {
        tin[i] = -1;
	}
	dfs(1, -1);
}
