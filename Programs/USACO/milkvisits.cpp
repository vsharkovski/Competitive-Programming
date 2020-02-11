
// Problem : Problem 3. Milk Visits
// Contest : USACO 2019 December Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=968
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
const int K = 17;

int n, m;
int value[N];
vector<int> adj[N];

int depth[N];
int P[N][K];
int D[N][K];

void dfs(int u, int p, int d) {
	depth[u] = d;
	P[u][0] = p;
	D[u][0] = value[u];
	if (p != -1) D[u][0] |= value[p];
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, d+1);
	}
}

int maskToLCA(int a, int b) {
	int mask = value[a] | value[b];
	if (depth[a] < depth[b]) swap(a, b);
	for (int j = K-1; j >= 0; --j) {
		if (depth[a] - (1<<j) >= depth[b]) {
			mask |= D[a][j];
			a = P[a][j];
		}
	}
	if (a == b) return mask;
	for (int j = K-1; j >= 0; --j) {
		if (P[a][j] != -1 && P[a][j] != P[b][j]) {
			mask |= D[a][j];
			mask |= D[b][j];
			a = P[a][j];
			b = P[b][j];
		}
	}
	mask |= D[a][0];
	return mask;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		value[i] = ch == 'G' ? 1 : 2;
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(P, -1, sizeof(P));
	memset(D, 0, sizeof(D));
	dfs(1, -1, 0);
	for (int j = 1; j < K; ++j) {
		for (int i = 1; i <= n; ++i) {
			int p = P[i][j-1];
			if (p != -1) {
				P[i][j] = P[p][j-1];
				D[i][j] = D[i][j-1] | D[p][j-1];
			}
		}
	}
	while (m--) {
		int a, b;
		char ch;
		cin >> a >> b >> ch;
		int want = ch == 'G' ? 1 : 2;
		int mask = maskToLCA(a, b);
		if ((mask & want) == 0) {
			cout << '0';
		} else {
			cout << '1';
		}
	}
}
