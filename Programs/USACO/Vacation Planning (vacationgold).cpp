#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



typedef pair<ll, ll> pl;

const ll inf = 1e15;

int N, M, K, Q;
vector<pair<int, int>> G[20005], H[20005]; // H is reversed graph
vector<int> hubs;
ll dist1[205][20005]; // i-th hub to city
ll dist2[20005][205]; // city to i-th hub

void sssp1(int sid) {
    dist1[sid][hubs[sid]] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.emplace(0, hubs[sid]);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ll d = top.first;
        int u = top.second;
        if (d > dist1[sid][u]) continue;
        for (auto& to : G[u]) {
            int v = to.first;
            ll w = to.second;
            if (dist1[sid][u] + w < dist1[sid][v]) {
                dist1[sid][v] = dist1[sid][u] + w;
                pq.emplace(dist1[sid][v], v);
            }
        }
    }
}

void sssp2(int sid) {
    dist2[hubs[sid]][sid] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.emplace(0, hubs[sid]);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ll d = top.first;
        int u = top.second;
        if (d > dist2[u][sid]) continue;
        for (auto& to : H[u]) {
            int v = to.first;
            ll w = to.second;
            if (dist2[u][sid] + w < dist2[v][sid]) {
                dist2[v][sid] = dist2[u][sid] + w;
                pq.emplace(dist2[v][sid], v);
            }
        }
    }
}

void Main() {
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        G[u].emplace_back(v, d);
        H[v].emplace_back(u, d);
    }
    for (int i = 0; i < K; ++i) {
        int u;
        cin >> u;
        hubs.push_back(u);
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dist1[j][i] = inf;
            dist2[i][j] = inf;
        }
    }
    // get shortest path from every hub to every farm
    for (int i = 0; i < K; ++i) {
        sssp1(i);
    }
    // get shortest path from every farm to every hub (use reversed edges)
    for (int i = 0; i < K; ++i) {
        sssp2(i);
    }
    int numpossible = 0;
    ll totalcost = 0;
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        ll res = inf;
        for (int j = 0; j < K; ++j) {
            ll d = dist2[a][j] + dist1[j][b];
            res = min(res, d);
        }
        if (res < inf) {
            ++numpossible;
            totalcost += res;
        }
    }
    cout << numpossible << '\n' << totalcost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
        freopen("vacationgold.in", "r", stdin);
        freopen("vacationgold.out", "w", stdout);
    #endif
    Main();
    return 0;
}
