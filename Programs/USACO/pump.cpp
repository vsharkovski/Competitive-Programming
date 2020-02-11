
// Problem : Problem 1. Milk Pumping
// Contest : USACO 2019 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=969
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;

int n, m;
vector<pair<int, pii>> adj[N];
int dist[N][N];
vector<pii> states[N*N]; // states[dist] = list of (u, minf)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c, f;
		cin >> a >> b >> c >> f;
		adj[a].emplace_back(b, make_pair(c, f));
		adj[b].emplace_back(a, make_pair(c, f));
	}
	for (int i = 1; i <= n; ++i) {
		for (int f = 1; f < N; ++f) {
			dist[i][f] = 1e9;
		}
	}
	dist[1][N-1] = 0;
	states[0].emplace_back(1, N-1);
	for (int D = 0; D < N*N; ++D) {
		for (auto& state : states[D]) {
			int u = state.first, f = state.second;
			if (D > dist[u][f]) continue;
			for (auto& to : adj[u]) {
				int v = to.first;
				int c = to.second.first;
				int f1 = min(f, to.second.second);
				if (D+c < dist[v][f1]) {
					dist[v][f1] = D+c;
					states[D+c].emplace_back(v, f1);
				}
			}
		}
	}
	double ans = 0;
	for (int minf = 1; minf < N; ++minf) {
		if (dist[n][minf] != 1e9) {
			ans = max(ans, double(minf)/double(dist[n][minf]));
		}
	}
	ans *= 1e6;
	cout << int(ans) << '\n';
}
