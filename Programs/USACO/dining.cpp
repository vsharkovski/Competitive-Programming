
// Problem : Problem 1. Fine Dining
// Contest : USACO 2018 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=861
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 50010;
const int inf = 1e9;

int n, m, k;
vector<pii> adj[N];
int yum[N];
int ndist[N];
int bdist[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}
	for (int i = 1; i <= n; ++i) {
		yum[i] = -1;
		ndist[i] = inf;
		bdist[i] = inf;
	}
	for (int i = 0; i < k; ++i) {
		int a, y;
		cin >> a >> y;
		yum[a] = max(yum[a], y);
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, n);
	ndist[n] = 0;
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		int d = top.first, u = top.second;
		if (d > ndist[u]) continue;
		for (auto& to : adj[u]) {
			int v = to.first, w = to.second;
			if (d + w < ndist[v]) {
				ndist[v] = d + w;
				pq.emplace(d + w, v);
			}
		}
	}
	for (int i = 1; i <= n-1; ++i) {
		if (yum[i] != -1) {
			bdist[i] = ndist[i] - yum[i];
			pq.emplace(bdist[i], i);
		}
	}
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		int d = top.first, u = top.second;
		if (d > bdist[u]) continue;
		for (auto& to : adj[u]) {
			int v = to.first, w = to.second;
			if (d + w < bdist[v]) {
				bdist[v] = d + w;
				pq.emplace(d + w, v);
			}
		}
	}
	for (int i = 1; i <= n-1; ++i) {
		if (ndist[i] >= bdist[i]) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}
