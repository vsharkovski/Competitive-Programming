
// Problem : Problem 2. Directory Traversal
// Contest : USACO 2018 February Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=814
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;

int n;
vector<int> adj[N];
int nodeval[N];
int leaves[N];
ll totaldist, ans;

ll dfs1(int u) {
	ll res = 0;
	leaves[u] = adj[u].empty() ? 1 : 0;
	for (int v : adj[u]) {
		res += dfs1(v);
		res += (ll)leaves[v] * nodeval[v];
		leaves[u] += leaves[v];
	}
	return res;
}

void dfs2(int u) {
	ans = min(ans, totaldist);
	for (int v : adj[u]) {
		if (!adj[v].empty()) {
			totaldist -= (ll)leaves[v] * nodeval[v];
			totaldist += (ll)(leaves[1]-leaves[v]) * 3;
			dfs2(v);
			totaldist -= (ll)(leaves[1]-leaves[v]) * 3;
			totaldist += (ll)leaves[v] * nodeval[v];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("dirtraverse.in", "r", stdin);
	freopen("dirtraverse.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string name;
		cin >> name;
		nodeval[i] = name.length() + 1;
		int m;
		cin >> m;
		if (m == 0) {
			--nodeval[i];
		} else {
			while (m--) {
				int j;
				cin >> j;
				adj[i].push_back(j);
			}
		}
	}
	ans = 1e18;
	totaldist = dfs1(1);
	dfs2(1);
	cout << ans << '\n';
}
