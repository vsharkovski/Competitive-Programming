#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

inline int mult(int a, int b) {
	return (ll)a * b % mod;
}

const int N = 1e5 + 10;

int n;
vector<int> adj[N];
int dp[N][2]; // dp[u][u_color]

void dfs(int u, int p) {
	dp[u][1] = 1;
	dp[u][0] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][1] = mult(dp[u][1], dp[v][0]);
		dp[u][0] = mult(dp[u][0], add(dp[v][0], dp[v][1]));
	}
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
	dfs(1, -1);
	cout << add(dp[1][0], dp[1][1]) << '\n';
}
