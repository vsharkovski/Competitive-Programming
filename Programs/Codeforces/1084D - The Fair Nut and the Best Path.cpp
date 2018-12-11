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



int V;
vi gas;
vector<vpi> G;
ll ans = 0;

ll dfs(int u, int p) {
  ll res1 = 0, res2 = 0;
  for (pi& to : G[u]) {
    int v = to.first, w = to.second;
    if (v != p) {
      ll res = -w + dfs(v, u);
      if (res >= res1) {
        res2 = res1;
        res1 = res;
      } else if (res > res2) {
        res2 = res;
      }
    }
  }
  ans = max(ans, res1 + gas[u] + res2);
  return res1 + gas[u];
}

void _SOLVE_() {
  cin >> V;
  gas.resize(V+1);
  G.assign(V+1, vpi());
  for (int u = 1; u <= V; ++u) {
    cin >> gas[u];
  }
  for (int i = 0; i < V-1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  dfs(1, 0);
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
