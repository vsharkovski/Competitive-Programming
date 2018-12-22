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





int V, E;
vector<int> G[1002];
bool visited[1002];

//find node with biggest distance from source
pi dfs1(int u, int p, int d) {
  visited[u] = 1;
  int bestnode = u, maxdist = d;
  for (int v : G[u]) {
    if (v != p) {
      pi res = dfs1(v, u, d+1);
      int node = res.first, dist = res.second;
      if (dist > maxdist) {
        maxdist = dist;
        bestnode = node;
      }
    }
  }
  return pi(bestnode, maxdist);
}

int center;
//find center of tree (diameter/2 -th node on the diameter)
int dfs2(int u, int p, int d, int dia, int end) {
  int res = (u == end);
  for (int v : G[u]) {
    if (v != p) {
      res += dfs2(v, u, d+1, dia, end);
    }
  }
  if (res > 0 && d == dia/2) center = u;
  return res;
}

void _SOLVE_() {
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  fill(visited, visited+V+1, 0);
  vector<int> centers;
  int maxdia = 0, bestcenter = 1;

  for (int u = 1; u <= V; ++u) {
    if (visited[u]) continue;
    pi p1 = dfs1(u, -1, 0);
    pi p2 = dfs1(p1.first, -1, 0);
    int dia = p2.second;
    dfs2(p2.first, -1, 0, dia, p1.first);
    centers.push_back(center);
    if (dia > maxdia) {
      maxdia = dia;
      bestcenter = center;
    }
  }

  //combine centers with the center of the tree with maximum diameter
  vector<pi> added;
  for (int center : centers) {
    if (center != bestcenter) {
      added.emplace_back(center, bestcenter);
      G[center].push_back(bestcenter);
      G[bestcenter].push_back(center);
    }
  }

  int diameter = dfs1(dfs1(1, -1, 0).first, -1, 0).second;
  cout << diameter << endl;
  for (pi& p : added) {
    cout << p.first << " " << p.second << endl;
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
