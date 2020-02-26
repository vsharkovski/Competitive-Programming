
// Problem : Problem 1. Time is Mooney
// Contest : USACO 2020 January Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=993
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;
const ll inf = 1e18;

int n, m;
ll c;
ll value[N];
vector<int> adj[N];
ll dp[N][N];

ll dfs(int u, int t) {
	ll& res = dp[u][t];
	if (res != -1) return res;
	res = -inf;
	if (u == 1) {
		res = max(res, -c*t*t);
	}
	if (t+1 == N) {
		return res;
	}
	for (int v : adj[u]) {
		ll res2 = value[v] + dfs(v, t+1);
		if (res2 > res) {
			res = res2;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	#endif
	cin >> n >> m >> c;
	for (int i = 1; i <= n; ++i) {
		cin >> value[i];
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	memset(dp, -1, sizeof(dp));
	ll ans = dfs(1, 0);
	cout << ans << '\n';
}
