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





int R, C;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

inline bool in(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C;
}

class dsu {
public:
  vector<int> p, rank;
  dsu(int n) {
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
      if (rank[x] > rank[y]) p[y] = x; else p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
      return true;
    }
    return false;
  }
  inline int get(int r, int c) {
    return get(C * r + c);
  }
  inline bool unite(int r1, int c1, int r2, int c2) {
    return unite(C * r1 + c1, C * r2 + c2);
  }
};

void _SOLVE_() {
  int Q;
  cin >> Q;
  vector<int> queries(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> queries[i];
  }
  cin >> R >> C;
  dsu d(R*C);
  vector<vector<int>> alive(R, vector<int>(C, 0));
  vector<pair<int, pi>> cells;
  map<int, int> ans; //ans[year] = answer for problem
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      int o;
      cin >> o;
      cells.emplace_back(o-1, pi(r, c));
    }
  }
  sort(cells.begin(), cells.end());
  int numcc = 0;
  ans[2e9 + 1] = 0;
  for (int cid = R*C - 1; cid >= 0; --cid) {
    int year = cells[cid].first;
    int r = cells[cid].second.first;
    int c = cells[cid].second.second;
    bool alone = 1;
    alive[r][c] = 1;
    for (int d1 = 0; d1 < 4; ++d1) {
      int r1 = r + dr[d1], c1 = c + dc[d1];
      if (!in(r1, c1) || !alive[r1][c1]) continue;
      alone = 0;
      d.unite(r, c, r1, c1);
      for (int d2 = 0; d2 < 4; ++d2) {
        int r2 = r + dr[d2], c2 = c + dc[d2];
        if (d2 == d1 || !in(r2, c2) || !alive[r2][c2]) continue;
        if (d.get(r1, c1) != d.get(r2, c2)) {
          --numcc;
          d.unite(r1, c1, r2, c2);
        }
      }
    }
    if (alone) {
      ++numcc;
    }
    ans[year] = numcc;
//    cout << "year=" << year << " numcc=" << numcc << endl;
  }
  for (int year : queries) {
    cout << ans.lower_bound(year)->second << "\n";
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
