// Tarjan's algorithm for finding SCCs

#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int n, m;
vector<int> adj[N];

int timer;
int tin[N], low[N];
bool instack[N];
vector<int> stk;

void dfs(int u, int p) {
	tin[u] = low[u] = timer++;
	instack[u] = true;
	stk.push_back(u);
	for (int v : adj[u]) {
		if (tin[v] == -1) {
			dfs(v, u);
		}
		if (instack[v]) {
			low[u] = min(low[u], low[v]);
		}
	}
	if (tin[u] == low[u]) {
		cout << "SCC: ";
		while (true) {
			int v = stk.back();
			stk.pop_back();
            instack[v] = false;
			cout << v << ' ';
			if (v == u) break;
		}
		cout << '\n';
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
	}
	memset(tin, -1, sizeof(tin));
	timer = 0;
	for (int i = 1; i <= n; ++i) {
		if (tin[i] == -1) {
			dfs(i, -1);
		}
	}
}

/*
sample input:
8 10
1 2
2 3
3 4
4 1
2 5
5 6
6 7
7 5
8 3
8 6
*/
