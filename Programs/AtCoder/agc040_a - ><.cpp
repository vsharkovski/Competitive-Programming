#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
const int maxn = 500010;
 
int n;
vector<int> adj[maxn];
int dp[maxn];
 
int dfs(int u) {
	if (dp[u] != -1) {
		return dp[u];
	}
	dp[u] = 0;
	for (int v : adj[u]) {
		dp[u] = max(dp[u], dfs(v) + 1);
	}
	return dp[u];
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	n = s.length() + 1;
	for (int i = 0; i < n-1; ++i) {
		if (s[i] == '<') {
			adj[i+1].push_back(i);
		} else {
			adj[i].push_back(i+1);
		}
	}
	for (int i = 0; i < n; ++i) {
		dp[i] = -1;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += dfs(i);
	}
	cout << ans << endl;
}
