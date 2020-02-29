
// Problem : Problem 2. Barn Painting
// Contest : USACO 2017 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=766
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % mod;
}

const int N = 100100;
const int C = 3;

int n, k;
vector<int> adj[N];
int initclr[N];
int dp[N][C];

int dfs(int u, int p, int pc) {
	int& res = dp[u][pc];
	if (res != -1) return res;
	res = 0;
	int adjcm = 0;
	if (p != -1) {
		adjcm |= (1 << pc);
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		if (initclr[v] != -1) {
			adjcm |= (1 << initclr[v]);
		}
	}
	for (int c = 0; c < C; ++c) {
		if (initclr[u] == c || (initclr[u] == -1 && !(adjcm & (1 << c)))) {
			int res2 = 1;
			for (int v : adj[u]) {
				if (v == p) continue;
				int res3 = dfs(v, u, c);
				res2 = mult(res2, res3);
			}
			res = add(res, res2);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		initclr[i] = -1;
		for (int j = 0; j < C; ++j) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < k; ++i) {
		int u, c;
		cin >> u >> c;
		initclr[u] = c-1;
	}
	int ans = dfs(1, -1, 0);
	cout << ans << '\n';
}
