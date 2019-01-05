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




vector<vi> G;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numCC;

vi CCid;
vector<vi> CCnodes;
vector<set<int>> H, K;

int deepest;

// tarjan algorithm for strongly connected components
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
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
    ++numCC;
    while (1) {
      int v = S.back();
      S.pop_back();
      visited[v] = 0;
      CCid[v] = numCC;
      CCnodes[numCC].push_back(v);
      if (u == v) break;
    }
  }
}

// connect the SCCs (H: actual graph, K: bidirectional)
void dfs1(int u) {
  dfs_num[u] = 1;
  for (int v : G[u]) {
    H[CCid[u]].insert(CCid[v]);
    K[CCid[u]].insert(CCid[v]);
    K[CCid[v]].insert(CCid[u]);
    if (dfs_num[v] == -1) {
      dfs1(v);
    }
  }
}

// make sure that every SCC is reachable from another SCC
void dfs2(int u) {
  dfs_num[u] = 1;
  for (int v : K[u]) {
    if (v != u && dfs_num[v] == -1) {
      dfs2(v);
    }
  }
}

// find node farthest away from deepest node
int dfs3(int u, int d) {
  int maxd = d;
  for (int v : H[u]) {
    if (v != u && dfs_num[v] == -1) {
      maxd = max(maxd, dfs3(v, d + 1));
    } else {
      maxd = max(maxd, 1 + dfs_num[v]);
    }
  }
  return dfs_num[u] = maxd;
}

// find deepest node
void dfs4(int u, int d) {
  if (d > dfs_num[deepest]) {
    deepest = u;
  }
  dfs_num[u] = d;
  for (int v : H[u]) {
    if (v != u && dfs_num[v] == -1) {
      dfs4(v, d + 1);
    }
  }
}


void _SOLVE_() {

  int V, E;
  cin >> V >> E;

  G.assign(V+1, vi());
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
  }

  dfs_num.assign(V+1, -1);
  dfs_low.assign(V+1, 0);
  visited.assign(V+1, 0);
  dfsNumberCounter = numCC = 0;
  CCid.assign(V+1, 0);
  CCnodes.assign(V+1, vi());

  for (int u = 1; u <= V; ++u) {
    if (dfs_num[u] == -1) {
      tarjanSCC(u);
    }
  }

  H.assign(numCC + 1, set<int>());
  K.assign(numCC + 1, set<int>());

  dfs_num.assign(V+1, -1);
  for (int i = 1; i <= V; ++i) {
    if (dfs_num[i] == -1) {
      dfs1(i);
    }
  }

  dfs_num.assign(numCC+1, -1);
  dfs2(1);
  for (int i = 1; i <= numCC; ++i) {
    if (dfs_num[i] == -1) {
      cout << 0;
      return;
    }
  }

  int best = 1;
  dfs_num.assign(numCC+1, -1);

  for (int i = 1; i <= numCC; ++i) {
    if (dfs_num[i] == -1) {
      dfs3(i, 0);
      if (dfs_num[i] > dfs_num[best]) {
        best = i;
      }
    }
  }

  dfs_num.assign(numCC+1, -1);
  deepest = best;
  dfs4(best, 0);
  sort(CCnodes[deepest].begin(), CCnodes[deepest].end());

  cout << CCnodes[deepest].size() << '\n';
  for (int u : CCnodes[deepest]) {
    cout << u << ' ';
  }


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
