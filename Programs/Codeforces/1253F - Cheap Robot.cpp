#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*

at node u
d[u]: dist to closest central
always starts and ends at central
assume fuel = x = c - d[u], for some c (max capacity)
reaching node u means reaching it with x >= d[u],
since you should always be able to go to nearest central and back

move from u to v:
(c - d[u]) - w >= d[v]
c >= d[u] + d[v] + w
new weights to edges: d[u] + d[v] + w

new problem: shortest path from a to b,
in terms of max weight over edges used (= c required)

minimum spanning tree? Kruskal
then binary lifting on this tree for max weight on any path


*/

const int N = 100010;
const int K = 17;
const ll inf = 1e18;

int n, m, k, q;
vector<pll> adj1[N];
ll dist[N];

struct DSU {
    int p[N], rank[N];
    void init() {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            rank[i] = 1;
        }
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        p[y] = x;
        return true;
    }
} dsu;

vector<pll> adj2[N];
int depth[N];
int P[N][K];
ll maxw[N][K];

void dfs(int u, int p) {
    for (auto& to : adj2[u]) {
        int v = to.first;
        ll w = to.second;
        if (v != p) {
            depth[v] = depth[u] + 1;
            P[v][0] = u;
            maxw[v][0] = to.second;
            dfs(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> q;
    vector<pair<ll, pii>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].first = w;
        edges[i].second.first = u;
        edges[i].second.second = v;
        adj1[u].emplace_back(v, w);
        adj1[v].emplace_back(u, w);
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 1; i <= k; ++i) {
        pq.emplace(0, i);
        dist[i] = 0;
    }
    for (int i = k+1; i <= n; ++i) {
        dist[i] = inf;
    }
    while (!pq.empty()) {
        pll top = pq.top();
        pq.pop();
        ll d = top.first;
        int u = top.second;
        if (d > dist[u]) continue;
        for (auto& p : adj1[u]) {
            ll w = p.second;
            int v = p.first;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(d + w, v);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        edges[i].first += dist[edges[i].second.first] + dist[edges[i].second.second];
    }
    sort(edges.begin(), edges.end());
    dsu.init();
    for (auto& e : edges) {
        ll w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (dsu.unite(u, v)) {
            adj2[u].emplace_back(v, w);
            adj2[v].emplace_back(u, w);
        }
    }
    depth[1] = 0;
    P[1][0] = -1;
    maxw[1][0] = -inf;
    dfs(1, -1);
    for (int j = 1; j < K; ++j) {
        for (int u = 1; u <= n; ++u) {
            if (P[u][j-1] != -1) {
                P[u][j] = P[P[u][j-1]][j-1];
                maxw[u][j] = max(maxw[u][j-1], maxw[P[u][j-1]][j-1]);
            } else {
                P[u][j] = -1;
            }
        }
    }
    for (int Q = 0; Q < q; ++Q) {
        int a, b;
        cin >> a >> b;
//        cout << "Q=" << Q << " a=" << a << " b=" << b << endl;
        if (depth[a] < depth[b]) swap(a, b);
        ll mx = -inf;
        for (int j = K-1; j >= 0; --j) {
            if (depth[a] - (1<<j) >= depth[b]) {
                mx = max(mx, maxw[a][j]);
                a = P[a][j];
            }
        }
        if (a != b) {
            // b is not direct ancestor
            for (int j = K-1; j >= 0; --j) {
                if (P[a][j] != -1 && P[a][j] != P[b][j]) {
                    mx = max(mx, maxw[a][j]);
                    mx = max(mx, maxw[b][j]);
                    a = P[a][j];
                    b = P[b][j];
                }
            }
            // now both children to same node
            mx = max(mx, maxw[a][0]);
            mx = max(mx, maxw[b][0]);
        }
//        cout << "mx: ";
        cout << mx << endl;
    }
//    cout << "Done\n";
    return 0;
}
