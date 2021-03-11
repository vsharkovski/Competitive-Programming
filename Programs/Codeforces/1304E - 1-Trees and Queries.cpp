
// Problem : E. 1-Trees and Queries
// Contest : Codeforces Round #620 (Div. 2)
// URL : https://codeforces.com/contest/1304/problem/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int K = 17;

int n;
vector<int> adj[N];
int depth[N];
int P[N][K];

void dfs(int u, int p, int d) {
	depth[u] = d;
	P[u][0] = p;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, d+1);
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int j = K-1; j >= 0; --j) {
		if (depth[a] - (1<<j) >= depth[b]) {
			a = P[a][j];
		}
	}
	if (a == b) return a;
	for (int j = K-1; j >= 0; --j) {
		if (P[a][j] != -1 && P[a][j] != P[b][j]) {
			a = P[a][j], b = P[b][j];
		}
	}
	return P[a][0];
}

inline int dist(int a, int b) {
	return depth[a] + depth[b] - 2*depth[LCA(a, b)];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1, 0);
	for (int j = 1; j < K; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (P[i][j-1] == -1) {
				P[i][j] = -1;
			} else {
				P[i][j] = P[ P[i][j-1] ][j-1];
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		int aux;
		int cyclen = 1 + dist(x, y);
		// dist(a, b) + 2A = k
		aux = k - dist(a, b);
		if (aux >= 0 && aux % 2 == 0) {
			cout << "YES\n"; continue;
		}
		// dist(a, x) + 1 + dist(y, b) + 2A = k
		aux = k - 1 - dist(a, x) - dist(y, b);
		if (aux >= 0 && aux % 2 == 0) {
			cout << "YES\n"; continue;
		}
		// dist(a, x) + 1 cycle + 1 + dist(y, b) + 2A = k
		aux -= cyclen;
		if (aux >= 0 && aux % 2 == 0) {
			cout << "YES\n"; continue;
		}
		// dist(a, y) + 1 + dist(x, b) + 2A = k
		aux = k - 1 - dist(a, y) - dist(x, b);
		if (aux >= 0 && aux % 2 == 0) {
			cout << "YES\n"; continue;
		}
		// dist(a, y) + 1 cycle + 1 + dist(x, b) + 2A = k;
		aux -= cyclen;
		if (aux >= 0 && aux % 2 == 0) {
			cout << "YES\n"; continue;
		}
		cout << "NO\n";
	}
}
