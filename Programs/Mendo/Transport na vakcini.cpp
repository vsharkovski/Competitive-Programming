#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int inf = 1e9;
const int N = 1100;

struct Edge {
    int v, dist, snow;
    Edge(int vv, int dd, int ss) : v(vv), dist(dd), snow(ss) {}
};

int n, m;
vector<Edge> adj[N];

int DJ(int minw) {
    int dist[N];
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
    }
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int d = top.first, u = top.second;
        if (d > dist[u]) continue;
        for (Edge& e : adj[u]) {
            if (e.snow >= minw && d + e.dist < dist[e.v]) {
                dist[e.v] = d + e.dist;
                pq.emplace(d + e.dist, e.v);
            }
        }
    }
    return dist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, dist, snow;
        cin >> a >> b >> dist >> snow;
        adj[a].emplace_back(b, dist, snow);
        adj[b].emplace_back(a, dist, snow);
    }
    int res01 = DJ(0);
    int res1 = DJ(1);
    cout << res01 << '\n';
    if (res01 == res1) {
        cout << "DA\n";
    } else {
        cout << "NE\n";
    }
}
