
// Problem : Problem 3. Shortcut
// Contest : USACO 2019 January Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=899
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 10010;
const int inf = 1e9;

int n, m, T;
vector<pii> adj[N];
int cows[N];
// dijkstra
int dist[N];
int prevnode[N];
vector<int> adj2[N];
ll ans;

int dfs(int u) {
	int totcows = cows[u];
	for (int v : adj2[u]) {
		totcows += dfs(v);
	}
	if (dist[u] > T) {
		ans = max(ans, (ll)totcows * (dist[u] - T));
	}
	return totcows;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("shortcut.in", "r", stdin);
	freopen("shortcut.out", "w", stdout);
	#endif
	cin >> n >> m >> T;
	for (int i = 1; i <= n; ++i) {
		cin >> cows[i];
	}
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].emplace_back(b, t);
		adj[b].emplace_back(a, t);
	}
	for (int i = 1; i <= n; ++i) {
		//sort(adj[i].begin(), adj[i].end());
		dist[i] = inf;
		prevnode[i] = -1;
	}
	dist[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, 1);
	while (!pq.empty()) {
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto& to : adj[u]) {
			int v = to.first, w = to.second;
			if (d + w < dist[v]) {
				dist[v] = d + w;
				prevnode[v] = u;
				pq.emplace(d + w, v);
			}
			else if (d + w == dist[v]) {
				if (u < prevnode[v]) {
					prevnode[v] = u;
				}
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		int p = prevnode[u];
		if (p == -1) continue;
		adj2[p].push_back(u);
	}
	ans = 0;
	dfs(1);
	cout << ans << '\n';
}
