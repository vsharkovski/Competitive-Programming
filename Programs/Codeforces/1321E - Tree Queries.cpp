
// Problem : E. Tree Queries
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200100;

int n;
vector<int> adj[N];
int par[N];
int timer;
int L[N], R[N];

void dfs(int u) {
	L[u] = ++timer;
	for (int v : adj[u]) {
		if (v == par[u]) continue;
		par[v] = u;
		dfs(v);
	}
	R[u] = timer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	timer = 0;
	par[1] = 1;
	dfs(1);
	while (q--) {
		int m;
		cin >> m;
		vector<pii> intervals(m);
		for (int i = 0; i < m; ++i) {
			int u;
			cin >> u;
			intervals[i] = make_pair(L[par[u]], R[par[u]]);
		}
		sort(intervals.begin(), intervals.end());
		bool good = true;
		for (int i = 0; i < m-1; ++i) {
			int l = intervals[i].first, r = intervals[i].second;
			int l2 = intervals[i+1].first, r2 = intervals[i+1].second;
			if (l <= l2 && r2 <= r) {
				continue;
			}
			good = false;
			break;
		}
		if (!good) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}
