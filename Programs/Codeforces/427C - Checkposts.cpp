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




const ll mod = 1e9 + 7;

int V, E;
vector<vi> G;
vector<ll> cost;
ll bestcost, ways;

vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter;
  ++dfsNumberCounter;
  S.push_back(u);
  visited[u] = 1;
  for (int v : G[u]) {
    if (dfs_num[v] == -1) {
      tarjanSCC(v);
    }
    if (visited[v]) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }
  if (dfs_low[u] == dfs_num[u]) {
    ll best = 1e16;
    ll numbest = 1;
    while (1) {
      int v = S.back(); S.pop_back();
      visited[v] = 0;
      //
      if (cost[v] < best) {
        best = cost[v];
        numbest = 1;
      } else if (cost[v] == best) {
        ++numbest;
      }
      //
      if (v == u) {
        break;
      }
    }
    bestcost += best;
    ways = (ways * numbest) % mod;
  }
}

void _SOLVE_() {
  cin >> V;
  G.assign(V+1, vi());
  cost.resize(V+1);
  for (int i = 1; i <= V; ++i) {
    cin >> cost[i];
  }
  cin >> E;
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
  }
  dfs_num.assign(V+1, -1);
  dfs_low.assign(V+1, 0);
  visited.assign(V+1, 0);
  dfsNumberCounter = 0;
  bestcost = 0;
  ways = 1;
  for (int i = 1; i <= V; ++i) {
    if (dfs_num[i] == -1) {
      tarjanSCC(i);
    }
  }
  cout << bestcost << ' ' << ways << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
