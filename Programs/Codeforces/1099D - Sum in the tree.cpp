#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;




int V;
vector<vector<int>> G;
vector<ll> s, a;
bool stop;

void dfs(int u, int p, int h) {
  if (stop) return;
  if (h % 2 == 1) {
    a[u] = (p == -1) ? s[u] : s[u] - s[p];
  } else {
    if (G[u].size() == 1) {
      a[u] = 0;
    } else {
      ll minchild = 1e18;
      for (int v : G[u]) {
        if (v == p) continue;
        minchild = min(minchild, s[v]);
      }
      a[u] = minchild - s[p];
      s[u] = s[p] + a[u];
    }
  }
//  cout << "s[" << u << "] = " << s[u] << " ;; a[" << u << "] = " << a[u] << '\n';
  if (a[u] < 0) {
    stop = true;
    return;
  }
  for (int v : G[u]) {
    if (v == p) continue;
    if (s[v] != -1 && s[v] < s[u]) {
//      cout << "stop: " << u << " -> " << v << '\n';
      stop = true;
      return;
    }
    dfs(v, u, h + 1);
  }
}

void Main() {
  cin >> V;
  G.resize(V);
  s.resize(V);
  a.resize(V);
  for (int u = 1; u < V; ++u) {
    int p;
    cin >> p;
    --p;
    G[u].push_back(p);
    G[p].push_back(u);
  }
  for (int u = 0; u < V; ++u) {
    cin >> s[u];
  }
  stop = false;
  dfs(0, -1, 1);
  if (stop) {
    cout << -1 << '\n';
  } else {
    ll sum = 0;
    for (int u = 0; u < V; ++u) {
      sum += a[u];
    }
    cout << sum << '\n';
  }
}


int main() {
  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
