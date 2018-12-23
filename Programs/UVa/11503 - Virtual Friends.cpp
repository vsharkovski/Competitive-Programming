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

map<string, int> id;
int numids;

int getid(string& s) {
  return id.count(s) ? id[s] : (id[s] = numids++);
}

void _SOLVE_() {
  int T;
  cin >> T;
  while (T--) {
    int E;
    cin >> E;
    int V = 2*E + 2;
    DSU d(V);
    id.clear();
    numids = 0;
    for (int i = 0; i < E; ++i) {
      string ustr, vstr;
      cin >> ustr >> vstr;
      int u = getid(ustr), v = getid(vstr);
//      cout << ustr << " : " << u << " - " << v << " : " << vstr << endl;
      d.unite(u, v);
      cout << d.size[d.get(u)] << "\n";
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
  _SOLVE_();
}
