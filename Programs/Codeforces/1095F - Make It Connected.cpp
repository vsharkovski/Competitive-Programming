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





class DSU {
public:
  vector<int> p, rank;
  int n;
  DSU(int _n) : n(_n) {
    rank.assign(n, 0);
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (p[x] == x) ? x : (p[x] = get(p[x]));
  }
  inline bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x != y) {
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) {
          ++rank[y];
        }
      }
      return true;
    }
    return false;
  }
};

int n, m;
vector<ll> a;
int bestvtx;
vector<pair<ll, pi>> edges;

void Solution() {
  cin >> n >> m;
  a.resize(n+1);
  bestvtx = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] < a[bestvtx]) {
      bestvtx = i;
    }
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges.emplace_back(w, pi(u, v));
  }
  for (int u = 1; u <= n; ++u) {
    if (u != bestvtx) {
      edges.emplace_back(a[bestvtx] + a[u], pi(bestvtx, u));
    }
  }
  sort(edges.begin(), edges.end());
  DSU dsu(n+1);
  ll cost = 0;
  for (auto& e : edges) {
    ll w = e.first;
    int u = e.second.first, v = e.second.second;
    if (dsu.unite(u, v)) {
      cost += w;
    }
  }
  cout << cost << '\n';
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
