// Solution by: (1) Juan, (2) Vladimir

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18 + 10;
const int N = 20010;
const int M = 20010;
const int NP = 15;

ll primes[NP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll primes_prod[NP];

int n, m;
map<ll, int> node_id;
pair<ll, ll> edges[M];
vector<pair<int, int>> adj[N];
int gold[N];
int src_node, dest_node;

int calc_gold_for_node(ll x) {
    int ans = 0;
    while (ans < NP && primes_prod[ans] <= x) {
        ++ans;
    }
    return ans;
}

struct State {
    int node, gold;
    ll dist;
    State(int node, int gold, ll dist)
        : node(node), gold(gold), dist(dist) {}
    bool operator > (const State& other) const {
        if (dist != other.dist)
            return dist > other.dist;
        return gold < other.gold;
    }
};

ll yikestra() {
    ll dist[N];
    priority_queue<State, vector<State>, greater<State> > pq;
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    dist[src_node] = 0;
    pq.emplace(src_node, gold[src_node], 0);
    while (!pq.empty()) {
        State top = pq.top();
        pq.pop();
        if (top.node == dest_node) {
            return top.gold;
        }
        for (auto& edge : adj[top.node]) {
            int to = edge.first;
            ll w = edge.second;
            if (top.dist + w < dist[to]) {
                dist[to] = top.dist + w;
                pq.emplace(to, top.gold + gold[to], top.dist + w);
            }
        }
    }
    return inf;
}

int main() {
    primes_prod[0] = primes[0];
    for (int k = 1; k < NP; ++k) {
        primes_prod[k] = primes_prod[k-1] * primes[k];
    }
    cin >> n >> m;
    ll src_node_id = inf;
    ll dest_node_id = -1;
    for (int i = 0; i < n; ++i) {
        ll id;
        cin >> id;
        node_id[id] = i;
        gold[i] = calc_gold_for_node(id);
        // update src and dest
        if (id < src_node_id) {
            src_node = i;
            src_node_id = id;
        }
        if (id > dest_node_id) {
            dest_node = i;
            dest_node_id = id;
        }
    }
    for (int i = 0; i < m; ++i) {
        ll x, y;
        int d;
        cin >> x >> y >> d;
        int u = node_id[x], v = node_id[y];
        adj[u].emplace_back(v, d);
        adj[v].emplace_back(u, d);
    }
    ll ans = yikestra();
    cout << ans << endl;
}
