#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
const int inf = 1e9;
const int S = 2010;
const int N = 3010;
const int M = 5010;
 
int smoney, n, m;
vector<int> adj[N];
 
struct Edge {
    int a, b, t, w;
    inline int other(int x) {
        return a == x ? b : a;
    }
} edges[M];
 
struct State {
    int u, d, t;
    State(int u, int d, int t) : u(u), d(d), t(t) {}
    bool operator > (const State& o) const {
        return t > o.t;
    }
};
priority_queue<State, vector<State>, greater<State>> pq;
 
int dist[N][S];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> smoney >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].t >> edges[i].w;
        adj[edges[i].a].push_back(i);
        adj[edges[i].b].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= smoney; ++j) {
            dist[i][j] = inf;
        }
    }
    dist[1][0] = 0;
    pq.emplace(1, 0, 0);
    while (!pq.empty()) {
        State z = pq.top();
        pq.pop();
        for (int ei : adj[z.u]) {
            int v = edges[ei].other(z.u);
            int d1 = z.d + edges[ei].w;
            int t1 = z.t + edges[ei].t;
            if (d1 <= smoney && t1 < dist[v][d1]) {
                dist[v][d1] = t1;
                pq.emplace(v, d1, t1);
            }
        }
    }
    int ans = inf;
    for (int j = 0; j <= smoney; ++j) {
        ans = min(ans, dist[n][j]);
    }
    if (ans == inf) ans = -1;
    cout << ans << '\n';
}
