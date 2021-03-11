#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int MAXW = 51;
const ll inf = 1e16;

int n, m;
vector<pii> adj[N];
ll dist[N][2][MAXW];

void sssp(int src) {
    for (int i = 1; i <= n; ++i) {
        for (int p = 0; p < 2; ++p) {
            for (int bw = 0; bw < MAXW; ++bw) {
                dist[i][p][bw] = inf;
            }
        }
    }
    struct State {
        int u, p, bw;
        ll d;
        State(int u, int p, int bw, ll d)
            : u(u), p(p), bw(bw), d(d) {}
        bool operator < (const State& o) const {
            return d > o.d;
        }
    };
    priority_queue<State> pq;
    dist[src][0][0] = 0;
    pq.emplace(1, 0, 0, 0);
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.d > dist[cur.u][cur.p][cur.bw]) continue;
        for (auto edge : adj[cur.u]) {
            int v = edge.first, w = edge.second;
            ll newd = cur.d + w*w;
            int newbw = w;
            if (cur.p == 1) {
                newd += 2*cur.bw*w;
                newbw = 0;
            }
            if (newd < dist[v][1-cur.p][newbw]) {
                dist[v][1-cur.p][newbw] = newd;
                pq.emplace(v, 1-cur.p, newbw, newd);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}
    sssp(1);
    for (int i = 1; i <= n; ++i) {
        if (dist[i][0][0] == inf) {
            cout << -1 << ' ';
        } else {
            cout << dist[i][0][0] << ' ';
        }
    }
}
