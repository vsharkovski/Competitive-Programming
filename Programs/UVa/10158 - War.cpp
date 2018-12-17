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
};

dsu d(20002);
int n;

// the trick is that since there are 2 opposing sides,
// there is only one enemy to each group
// we can keep it like this
int enemyID(int x) {
  return x + 10000;
}

void setFriends(int x, int y) {
  if (d.get(x) == d.get(enemyID(y)) || d.get(y) == d.get(enemyID(x))) {
    cout << "-1\n";
  } else {
    d.unite(x, y);
    d.unite(enemyID(x), enemyID(y));
  }
}

void setEnemies(int x, int y) {
  if (d.get(x) == d.get(y) || d.get(enemyID(x)) == d.get(enemyID(y))) {
    cout << "-1\n";
  } else {
    d.unite(enemyID(x), y);
    d.unite(x, enemyID(y));
  }
}

void areFriends(int x, int y) {
  if (d.get(x) == d.get(y) && d.get(enemyID(x)) == d.get(enemyID(y))) {
    cout << "1\n";
  } else {
    cout << "0\n";
  }
}

void areEnemies(int x, int y) {
  if (d.get(x) == d.get(enemyID(y)) && d.get(y) == d.get(enemyID(x))) {
    cout << "1\n";
  } else {
    cout << "0\n";
  }
}

void _SOLVE_() {
  cin >> n;
  int c, x, y;
  while (cin >> c >> x >> y) {
    if (c == 1) {
      setFriends(x, y);
    } else if (c == 2) {
      setEnemies(x, y);
    } else if (c == 3) {
      areFriends(x, y);
    } else if (c == 4) {
      areEnemies(x, y);
    } else {
      break;
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
