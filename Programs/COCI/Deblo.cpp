#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
 
const int maxn = 100010;
const int maxval = 3000000;
const int maxlog = 22;
 
int n;
vector<int> adj[maxn];
ll numpaths[maxlog];
int val[maxn][maxlog]; // whether i-th bit is on
int dp[maxn][maxlog][2];
 
void dfs(int u, int p) {
	for (int i = 0; i < maxlog; ++i) {
		dp[u][i][val[u][i]] += 1;
		numpaths[i] += val[u][i];
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		for (int i = 0; i < maxlog; ++i) {
			numpaths[i] += 1LL * dp[u][i][0] * dp[v][i][1];
			numpaths[i] += 1LL * dp[u][i][1] * dp[v][i][0];
			dp[u][i][0] += dp[v][i][0^val[u][i]];
			dp[u][i][1] += dp[v][i][1^val[u][i]];
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int u = 1; u <= n; ++u) {
		int x;
		cin >> x;
		for (int i = 0; i < maxlog; ++i) {
			val[u][i] = (x & (1 << i)) >> i;
		}
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dp, 0, sizeof(dp));
	dfs(1, -1);
	ll ans = 0;
	for (int b = 0; b < maxlog; ++b) {
		ans += numpaths[b] * (1 << b);
	}
	cout << ans << '\n';
}
