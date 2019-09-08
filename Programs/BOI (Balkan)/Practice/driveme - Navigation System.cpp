#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int inf = 1e9;
const int maxn = 101;
const int maxk = 11;

int n, k, m, q;
vector<pii> out[maxn], in[maxn];
int dist[maxn][maxn][maxk];

struct State {
	int d, u, p;
	State(int d, int u, int p) : d(d), u(u), p(p) {}
	bool operator > (const State &o) const {
		return d < o.d;
	}
};

void dijkstra(int src, int dist[maxn][maxk]) {
	for (int i = 1; i <= n; ++i) {
		for (int p = 0; p <= k; ++p) {
			dist[i][p] = inf;
		}
	}
	dist[src][0] = 0;
	priority_queue<State, vector<State>, greater<State>> pq;
	pq.emplace(0, src, 0);
	while (!pq.empty()) {
		State top = pq.top();
		pq.pop();
		if (top.d > dist[top.u][top.p]) continue;
		for (auto& to : out[top.u]) {
			int v = to.first, w = to.second;
			if (top.d + w < dist[v][top.p]) {
				dist[v][top.p] = top.d + w;
				pq.emplace(top.d + w, v, top.p);
			}
		}
		if (top.p == k) continue;
		for (auto& to : in[top.u]) {
			int v = to.first, w = to.second;
			if (top.d + w < dist[v][top.p+1]) {
				dist[v][top.p+1] = top.d + w;
				pq.emplace(top.d + w, v, top.p + 1);
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("in.txt", "r", stdin);
	cin >> n >> m >> k >> q;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		out[u].emplace_back(v, w);
		in[v].emplace_back(u, w);
	}
	for (int i = 1; i <= n; ++i) {
		dijkstra(i, dist[i]);
	}
	while (q--) {
		int u, v, p;
		cin >> u >> v >> p;
		int res = inf;
		for (int i = 0; i <= p; ++i) {
			res = min(res, dist[u][v][i]);
		}
		if (res == inf) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << res << "\n";
		}
	}
}
