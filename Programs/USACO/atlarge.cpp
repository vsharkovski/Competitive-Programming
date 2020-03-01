
// Problem : Problem 2. Cow at Large
// Contest : USACO 2018 January Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=790
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;

int n, k;
vector<int> adj[N];

pii dfs(int u, int p, int updist) {
	int ans = 0;
	int mindowndist = adj[u].size() == 1 ? 0 : n;
	for (int v : adj[u]) {
		if (v == p) continue;
		pii res = dfs(v, u, updist + 1);
		ans += res.first;
		mindowndist = min(mindowndist, 1 + res.second);
	}
	if (mindowndist <= updist) {
		ans = 1;
	}
	return pii(ans, mindowndist);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("atlarge.in", "r", stdin);
	freopen("atlarge.out", "w", stdout);
	#endif
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (adj[k].size() == 1) {
		cout << 1 << '\n';
		return 0;
	}
	int ans = dfs(k, -1, 0).first;
	cout << ans << '\n';
}
