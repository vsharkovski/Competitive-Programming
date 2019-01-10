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
vector<int> articulation_point;
vector<int> dfs_num, dfs_low, dfs_parent;
int dfsnumcalls, dfsroot, rootchildren;

void artpdfs(int u) {
  dfs_low[u] = dfs_num[u] = dfsnumcalls++;
  for (int v : G[u]) {
    if (dfs_num[v] == -1) {
      dfs_parent[v] = u;
      if (u == dfsroot) ++rootchildren;
      artpdfs(v);
      if (dfs_low[v] >= dfs_num[u]) {
        articulation_point[u] = 1;
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (dfs_parent[u] != v) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

void Main() {
  string line;
  while (cin >> V, V != 0) {
    getline(cin, line);
    G.assign(V+1, vector<int>());
    for (int i = 0; i < V; ++i) {
      getline(cin, line);
      if (line == "0") break;
      stringstream ss;
      int u, v;
      ss << line;
      ss >> u;
      while (ss >> v) {
        G[u].push_back(v);
        G[v].push_back(u);
      }
    }
    articulation_point.assign(V+1, 0);
    dfs_num.assign(V+1, -1);
    dfs_low.assign(V+1, 0);
    dfs_parent.assign(V+1, 0);
    dfsnumcalls = 0;
    for (int u = 1; u <= V; ++u) {
      if (dfs_num[u] == -1) {
        dfsroot = u;
        rootchildren = 0;
        artpdfs(u);
        articulation_point[u] = rootchildren > 1;
      }
    }
    int ans = 0;
    for (int u = 1; u <= V; ++u) {
      if (articulation_point[u]) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
