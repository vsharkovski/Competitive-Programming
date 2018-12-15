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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




const ll mod = 998244353;
ll pow2[300005];

int V, E;
vector<vi> G;
vi color;

ll bfs(int src, int srcclr) {
  ll numblack = 0;
  queue<int> q;
  q.push(src);
  color[src] = srcclr;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (color[u] == 1) {
      ++numblack;
    }
    for (int v : G[u]) {
      if (color[v] == -1) {
        color[v] = 1 - color[u];
        q.push(v);
      } else if (color[v] == color[u]) {
        return -69;
      }
    }
  }
  return numblack;
}

void dfs(int u) {
  color[u] = -1;
  for (int v : G[u])
    if (color[v] != -1)
      dfs(v);
}

void _SOLVE_() {
  pow2[0] = 1;
  for (ll x = 1; x <= 300000; ++x) {
    pow2[x] = (pow2[x-1] * 2) % mod;
  }
  int T;
  cin >> T;
  while (T--) {
    cin >> V >> E;
    G.assign(V+1, vi());
    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    color.assign(V+1, -1);
    ll ans = 1;
    for (int u = 1; u <= V; ++u) {
      if (color[u] == -1) {
        ll res1 = bfs(u, 1);
        if (res1 == -69) {
          ans = 0;
          break;
        }
        dfs(u);
        ll res2 = bfs(u, 0);
        ans *= (pow2[res1] + pow2[res2]);
        ans %= mod;
      }
    }
    cout << ans << endl;
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
