// Note: This solution is from usaco.guide

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
const int N = 100010;

struct Edge {
	int to, c;
	ll p;
};

int n, m;
map<int, vector<Edge>> graph[N]; // graph[node][edge color]
ll dist[N]; // d[node] = distance, entered through an edge that won't be touched again
map<int, ll> dist2[N]; // d2[node][edge color c] = distance, but entered through c, must exit through c by recoloring all adjacent (including the one we entered through)
map<int, ll> psum[N]; // csum[node][edge color] = sum of weights

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c, p;
		cin >> a >> b >> c >> p;
		graph[a][c].push_back({b, c, p});
		graph[b][c].push_back({a, c, p});
		psum[a][c] += p;
		psum[b][c] += p;
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
	}
	dist[1] = 0;
	using pqState = tuple<ll, int, int>; // d, u, c (color of back edge)
	priority_queue<pqState, vector<pqState>, greater<pqState>> pq;
	pq.emplace(0, 1, 0);
	while (!pq.empty()) {
		ll dist_node;
		int node, bkc; // node, back color
		tie(dist_node, node, bkc) = pq.top();
		pq.pop();
		if (bkc > 0) {
			// special case: dp2
			if (dist_node != dist2[node][bkc]) continue;
			for (Edge e : graph[node][bkc]) {
				// must exit through same colored edge and flip all others
				ll alt = dist_node + psum[node][bkc] - e.p;
				if (alt < dist[e.to]) {
					dist[e.to] = alt;
					pq.emplace(alt, e.to, 0);
				}
			}
		} else {
			if (dist_node != dist[node]) continue;
			for (auto& kvp : graph[node]) {
				for (Edge e : kvp.second) {
					ll alt;
					// case 1: don't recolor e, recolor all except e
					alt = dist_node + psum[node][e.c] - e.p;
					if (alt < dist[e.to]) {
						dist[e.to] = alt;
						pq.emplace(alt, e.to, 0);
					}
					// case 2: recolor only e and no other
					alt = dist_node + e.p;
					if (alt < dist[e.to]) {
						dist[e.to] = alt;
						pq.emplace(alt, e.to, 0);
					}
					// case 3: don't recolor e NOW, but must recolor all adjacent next node
					alt = dist_node;
					if (!dist2[e.to].count(e.c) || alt < dist2[e.to][e.c]) {
						dist2[e.to][e.c] = alt;
						pq.emplace(alt, e.to, e.c);
					}
				}
			}
		}
	}
	cout << (dist[n] == inf ? -1 : dist[n]) << '\n';
}
