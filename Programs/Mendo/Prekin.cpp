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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




struct Edge {
  int pr, u, w;
  Edge(int PR, int U, int W) : pr(PR), u(U), w(W) {}
  Edge() {}
  bool operator < (const Edge &rhs) const {
    return w > rhs.w;
  }
};

int V, E;
vector<vpi> G;
vector<Edge> mstedges;

vector<int> taken;
priority_queue<Edge> pq;

void process(int u) {
  taken[u] = 1;
  for (pi &to : G[u])
    if (taken[to.first] == 0)
      pq.emplace(u, to.first, to.second);
}

int prim(bool firsttime) {
  taken.assign(V+1, 0);
  int cost = 0;
  process(1);
  while (!pq.empty()) {
    Edge top = pq.top(); pq.pop();
    if (taken[top.u] == 0) {
      if (firsttime)
        mstedges.push_back(top);
      cost += top.w;
      process(top.u);
    }
  }
  for (int u = 1; u <= V; ++u)
    if (taken[u] == 0)
      return 1e9;
  return cost;
}

void _SOLVE_() {
  cin >> V >> E;
  G.assign(V+1, vpi());
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  int a = prim(true);
  int b = 1e9;
  for (Edge& e : mstedges) {
    int u = e.u, v = e.pr, w = e.w;
    G[u].erase(find(G[u].begin(), G[u].end(), pi(v, w)));
    G[v].erase(find(G[v].begin(), G[v].end(), pi(u, w)));
    b = min(b, prim(false));
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  cout << a << " " << b << endl;
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
