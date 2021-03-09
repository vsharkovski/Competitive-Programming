#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;

int n, m, ans;
vector<int> adj[N];
int dp[N];

int dfs(int u) {
	if (dp[u] != -1) return dp[u];
	dp[u] = 0;
	for (int v : adj[u]) {
		dp[u] = max(dp[u], 1+dfs(v));
	}
	ans = max(ans, dp[u]);
	return dp[u];
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
	for (int i = 1; i <= n; ++i) {
		dp[i] = -1;
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		dfs(i);
	}
	cout << ans << '\n';
}
