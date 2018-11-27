#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



int V;
vector<vi> G;
vector<vpi> query;
vl toremove;
vl total;

void dfs(int u, int pr, int d, ll toadd) {
    toadd -= toremove[d];
    for (pi& p : query[u]) {
        toadd += p.second;
        toremove[d + p.first + 1] += p.second;
    }
    total[u] += toadd;
    for (int v : G[u]) {
        if (v != pr) {
            dfs(v, u, d + 1, toadd);
        }
    }
    for (pi& p : query[u]) {
        toadd -= p.second;
        toremove[d + p.first + 1] -= p.second;
    }
}


void _SOLVE_() {
    cin >> V;
    G.assign(V+1, vi());
    query.assign(V+1, vpi());
    total.assign(V+1, 0);
    toremove.assign(2*V+2, 0);
    for (int i = 0; i < V-1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int m;
    cin >> m;
    for (int i = 0 ; i < m; ++i) {
        int v, d, x;
        cin >> v >> d >> x;
        d = min(d, V);
        query[v].emplace_back(d, x);
    }
    dfs(1, 0, 0, 0);
    for (int u = 1; u <= V; ++u) {
        cout << total[u] << " ";
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
