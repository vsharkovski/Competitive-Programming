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
vector<vi> G;
vi dfs_low, dfs_num, dfs_parent;
int dfsnumcalls, dfsroot, rootchildren;

void artpb(int u) {
  dfs_low[u] = dfs_num[u] = dfsnumcalls++;
  for (int v : G[u]) {
    if (dfs_num[v] == -1) {
      dfs_parent[v] = u;
      if (u == dfsroot) ++rootchildren;
      artpb(v);
      if (dfs_low[v] >= dfs_num[u]) {
        // u is articulation vertex (special case for u=root: rootchildren > 1)
      }
      if (dfs_low[v] > dfs_num[u]) {
        // edge (u, v) is articulation bridge
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (v != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

void Main() {

  dfsnumcalls = 0;
  dfs_num.assign(V, -1);
  dfs_low.assign(V, 0);
  dfs_parent.assign(V, 0);
  for (int i = 0; i < V; ++i) {
    if (dfs_num[i] == -1) {
      dfsroot = i;
      rootchildren = 0;
      artpb(i);
      // (special case) root is articulation vertex if rootchildren > 1
    }
  }



}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
