// Problem : J. Send the Fool Further! (easy)
// Contest : Helvetic Coding Contest 2017 online mirror (teams allowed, unrated)
// URL : https://codeforces.com/contest/802/problem/J
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 305;

int n;
vector<pii> adj[N];

int dfs(int u, int p) {
	int res = 0;
	for (auto& to : adj[u]) {
		int v = to.first, w = to.second;
		if (v == p) continue;
		res = max(res, w + dfs(v, u));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	cout << dfs(0, -1) << endl;
}
