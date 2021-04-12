#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;

const ll inf = 1e18;
const int N = 100100;

int n, m, S, T, U, V;
vector<pli> adj[N];
ll ans;
bool vis[N];
ll distU[N];
ll distV[N];
ll dist[N];
ll dpU[N];
ll dpV[N];

void dijkstra(int source, ll dist[N]) {
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
		vis[i] = false;
	}
	dist[source] = 0;
	pq.emplace(0, source);
	while (!pq.empty()) {
		int a = pq.top().second;
		pq.pop();
		if (vis[a]) continue;
		vis[a] = true;
		for (pli to : adj[a]) {
			ll alt = dist[a] + to.first;
			int b = to.second;
			if (alt < dist[b]) {
				dist[b] = alt;
				pq.emplace(alt, b);
			}
		}
	}
}

void dijkstra2() {
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
		vis[i] = false;
	}
	dist[S] = 0;
	dpU[S] = distU[S];
	dpV[S] = distV[S];
	pq.emplace(0, S);
	while (!pq.empty()) {
		int a = pq.top().second;
		pq.pop();
		if (vis[a]) continue;
		vis[a] = true;
		for (pli to : adj[a]) {
			ll alt = dist[a] + to.first;
			int b = to.second;
			if (alt < dist[b]) {
				dist[b] = alt;
				dpU[b] = min(distU[b], dpU[a]);
				dpV[b] = min(distV[b], dpV[a]);
				pq.emplace(alt, b);
			} else if (alt == dist[b]) {
				ll potU = min(distU[b], dpU[a]);
				ll potV = min(distV[b], dpV[a]);
				if (potU + potV <= dpU[b] + dpV[b]) {
					dpU[b] = potU;
					dpV[b] = potV;
				}
			}
		}
	}
	ans = min(ans, dpU[T] + dpV[T]);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m >> S >> T >> U >> V;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(w, b);
		adj[b].emplace_back(w, a);
	}
	dijkstra(U, distU);
	dijkstra(V, distV);
	ans = distV[U];
	for (int i = 0; i < 2; ++i) {
		dijkstra2();
		swap(S, T);
	}
	cout << ans << '\n';
}
