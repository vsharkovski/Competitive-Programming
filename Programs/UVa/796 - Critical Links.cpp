#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





int V;
vector<vi> G;
vector<pi> bridges;
vi dfs_num, dfs_low;
int dfscalls;

void artb(int u, int p) {
  dfs_num[u] = dfs_low[u] = dfscalls++;
  for (int v : G[u]) {
    if (dfs_num[v] == -1) {
      artb(v, u);
      if (dfs_low[v] > dfs_num[u]) {
        bridges.emplace_back(u, v);
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (v != p) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

void Main() {
  bool first = true;
  while (cin >> V) {
    G.assign(V+1, vi());
    for (int i = 0; i < V; ++i) {
      int u;
      cin >> u;
      string str;
      cin >> str;
      int m = 0;
      for (int j = 1; j < str.length() - 1; ++j) {
        m = 10*m + (str[j] - '0');
      }
      for (int j = 0; j < m; ++j) {
        int v;
        cin >> v;
        G[u].push_back(v);
      }
    }
    bridges.clear();
    dfs_num.assign(V+1, -1);
    dfs_low.assign(V+1, 0);
    dfscalls = 0;
    for (int u = 1; u <= V; ++u) {
      if (dfs_num[u] == -1) {
        artb(u, -1);
      }
    }
    if (first) {
      first = false;
    } else {
      cout << '\n';
    }
    cout << bridges.size() << " critical links\n";
    for (pi& e : bridges) {
      cout << e.first << " - " << e.second << '\n';
    }
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
