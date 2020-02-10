// Problem : E. A and B and Lecture Rooms
// Contest : Codeforces Round #294 (Div. 2)
// URL : https://codeforces.com/contest/519/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int K = 17;

int n;
vector<int> adj[N];

int sbsz[N];
int depth[N];
int P[N][K];

void dfs(int u, int p, int d) {
	depth[u] = d;
	sbsz[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, d+1);
		sbsz[u] += sbsz[v];
		P[v][0] = u;
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

int ancestor(int a, int d) {
	for (int j = K-1; j >= 0; --j) {
		if (d - (1 << j) >= 0) {
			d -= (1 << j);
			a = P[a][j];
		}
	}
	return a;
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
	memset(P, -1, sizeof(P));
	dfs(1, -1, 0);
	for (int j = 1; j < K; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (P[i][j-1] != -1) {
				P[i][j] = P[ P[i][j-1] ][j-1];
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << n << '\n';
			continue;
		}
		int l = LCA(a, b);
		int d = depth[a] + depth[b] - 2*depth[l];
		if (d % 2 != 0) {
			cout << 0 << '\n';
			continue;
		}
		if (depth[a] < depth[b]) swap(a, b);
		int ap = ancestor(a, d/2 - 1);
		int u = P[ap][0];
		//cout << "a=" << a << " b=" << b << " l=" << l << " u=" << u << " ap=" << ap << " ans=";
		if (u == l) {
			int bp = ancestor(b, d/2 - 1);
			cout << n - sbsz[ap] - sbsz[bp] << '\n';
		} else {
			cout << sbsz[u] - sbsz[ap] << '\n';
		}
	}
}
