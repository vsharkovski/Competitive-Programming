#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int M;

inline int add(int x, int y) {
	x += y;
	if (x >= M) x -= M;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % M;
}

int N;
vector<vector<int>> adj;
vector<int> dp, ans;

void dfs1(int u, int p) {
	dp[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs1(v, u);
		dp[u] = mult(dp[u], add(dp[v], 1));
	}
	if (p != -1) {
		auto it = find(adj[u].begin(), adj[u].end(), p);
		adj[u].erase(it, it+1);
	}
}

void dfs2(int u, int produp) {
	ans[u] = mult(dp[u], produp);
	int numc = adj[u].size();
	vector<int> prefprod(numc), suffprod(numc);
	for (int i = 0; i < numc; ++i) {
		prefprod[i] = add(dp[adj[u][i]], 1);
		if (i) prefprod[i] = mult(prefprod[i], prefprod[i-1]);
	}
	for (int i = numc-1; i >= 0; --i) {
		suffprod[i] = add(dp[adj[u][i]], 1);
		if (i+1 < numc) suffprod[i] = mult(suffprod[i], suffprod[i+1]);
	}
	for (int i = 0; i < numc; ++i) {
		int newprod = produp;
		if (i) newprod = mult(newprod, prefprod[i-1]);
		if (i+1 < numc) newprod = mult(newprod, suffprod[i+1]);
		newprod = add(newprod, 1); // the option to exclude this branch
		dfs2(adj[u][i], newprod);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	adj.assign(N, vector<int>());
	for (int i = 0; i < N-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dp.resize(N);
	ans.resize(N);
	dfs1(0, -1);
	dfs2(0, 1);
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << '\n';
	}
}
