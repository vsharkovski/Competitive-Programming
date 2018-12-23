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
  vector<int> p, rank, size;
  DSU(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    rank.assign(n, 0);
    size.assign(n, 1);
  }
  inline int get(int x) {
    return p[x] == x ? x : (p[x] = get(p[x]));
  }
  inline bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x != y) {
      if (rank[x] > rank[y]) {
        p[y] = x;
        size[x] += size[y];
      } else {
        p[x] = y;
        size[y] += size[x];
        if (rank[x] == rank[y]) {
          ++rank[y];
        }
      }
      return true;
    }
    return false;
  }
};

void _SOLVE_() {
  int T;
  cin >> T;
  while (T--) {
    int V, E;
    cin >> V >> E;
    DSU d(V);
    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      d.unite(u, v);
    }
    int ans = 1;
    for (int u = 0; u < V; ++u) {
      ans = max(ans, d.size[u]);
    }
    cout << ans << endl;
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
