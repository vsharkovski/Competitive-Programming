#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
template <class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



const int UNVISITED = 0, EXPLORED = 1, VISITED = 2;

int V, E;
vector<vector<int>> G;
vector<pi> edges;
vector<int> dfs_num, dfs_low, dfs_status;
int dfscalls;

void dfs(int u, int p) {
  dfs_num[u] = dfs_low[u] = dfscalls++;
  dfs_status[u] = EXPLORED;
  for (int v : G[u]) {
    if (dfs_status[v] == UNVISITED) {
      edges.emplace_back(u, v);
      dfs(v, u);
      if (dfs_low[v] > dfs_num[u]) {
        // (u, v) is articulation bridge
        edges.emplace_back(v, u);
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (dfs_status[v] == EXPLORED) {
      if (v != p) {
        edges.emplace_back(u, v);
        dfs_low[u] = min(dfs_low[u], dfs_num[v]);
      }
    }
  }
  dfs_status[u] = VISITED;
}

void Main() {
  int Case = 1;
  while (cin >> V >> E, V != 0 || E != 0) {
    G.assign(V+1, vector<int>());
    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    edges.clear();
    dfs_num.assign(V+1, UNVISITED);
    dfs_low.assign(V+1, 0);
    dfscalls = 0;
    dfs_status.assign(V+1, UNVISITED);
    for (int u = 1; u <= V; ++u) {
      if (dfs_num[u] == UNVISITED) {
        dfs(u, 0);
      }
    }
    cout << Case++ << "\n\n";
    for (pi& e : edges) {
      cout << e.first << ' ' << e.second << '\n';
    }
    cout << "#\n";
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
