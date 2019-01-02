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
vector<vector<int>> G;
vector<int> a;
vector<ll> sum;
ll ans = 0, res = 0;

void dfs1(int u, int p, ll d) {
  res += d * a[u];
  sum[u] = a[u];
  for (int v : G[u]) {
    if (v != p) {
      dfs1(v, u, d + 1);
      sum[u] += sum[v];
    }
  }
//  cout << "a[" << u+1 << "] = " << a[u] << '\n';
//  cout << "sum[" << u+1 << "] = " << sum[u] << '\n';
}

void dfs2(int u, int p) {
  ans = max(ans, res);
//  cout << "res at " << u+1 << " = " << res << '\n';
  for (int v : G[u]) {
    if (v != p) {
      res -= sum[v];
      sum[u] -= sum[v];
      res += sum[u];
      sum[v] += sum[u];
      dfs2(v, u);
      sum[v] -= sum[u];
      res -= sum[u];
      sum[u] += sum[v];
      res += sum[v];
    }
  }
}

void Solution() {
  cin >> V;
  a.resize(V);
  sum.resize(V);
  G.assign(V, vector<int>());
  for (int i = 0; i < V; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < V-1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(0, -1, 0);
//  cout << '\n';
  dfs2(0, -1);
//  cout << '\n';
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}
