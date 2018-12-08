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




int V, E, s, t;
bool M[1001][1001] = {};
vector<vi> G;
vector<vi> dist;
int ans = 0;

void _SOLVE_() {
  cin >> V >> E >> s >> t;
  G.assign(V+1, vi());
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
    M[u][v] = M[v][u] = 1;
  }
  dist.assign(V+1, vi(V+1, -1));
  for (int u = 1; u <= V; ++u) {
    dist[u][u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int k : G[v]) {
        if (dist[u][k] == -1) {
          dist[u][k] = dist[u][v] + 1;
          q.push(k);
        }
      }
    }
  }
  for (int u = 1; u <= V; ++u) {
    for (int v = u+1; v <= V; ++v) {
      if (M[u][v]) continue;
      int du = min(dist[s][u], dist[s][v] + 1);
      int dv = min(dist[s][v], dist[s][u] + 1);
      if (du + dist[u][t] >= dist[s][t] && dv + dist[v][t] >= dist[s][t]) {
        ++ans;
      }
    }
  }
  cout << ans << endl;
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
