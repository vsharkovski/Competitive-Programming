
// Problem : C. Linova and Kingdom
// Contest : Codeforces - Codeforces Round #635 (Div. 2)
// URL : https://codeforces.com/contest/1337/problem/C
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200010;

int n, k;
vector<int> adj[N];
vector<pii> data;

int dfs(int u, int p, int d) {
	int sbsz = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		sbsz += dfs(v, u, d+1);
	}
	data.emplace_back(-d + sbsz - 1, u);
	return sbsz;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1, 0);
	sort(data.begin(), data.end());
	ll ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += data[i].first;
	}
	cout << -ans << '\n';
}
