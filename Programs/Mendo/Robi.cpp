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




int Y, X;
int N;
vpi blues;

int closest(int x, int y) {
  int res = 0, mind = 2e9;;
  for (int i = 0; i < N; ++i) {
    int d = abs(blues[i].first - x) + abs(blues[i].second - y);
    if (d < mind) {
      res = (1 << i);
      mind = d;
    } else if (d == mind) {
      res |= (1 << i);
    }
  }
  return res;
}

int rec(int x1, int y1, int x2, int y2) {
  int c = closest(x1, y1);
  if (c == closest(x2, y2) && c == closest(x1, y2) && c == closest(x2, y1)) {
    if (__builtin_popcount(c) <= 1) {
      return 0;
    } else {
      return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
  } else if (x1 <= x2 && y1 <= y2) {
    int x = (x1 + x2) / 2;
    int y = (y1 + y2) / 2;
    int res = 0;
    res += rec(x1, y1, x, y);
    res += rec(x+1, y1, x2, y);
    res += rec(x1, y+1, x, y2);
    res += rec(x+1, y+1, x2, y2);
    return res;
  }
  return 0;
}

void _SOLVE_() {
  cin >> Y >> X >> N;
  for (int i = 0; i < N; ++i) {
    int y, x;
    cin >> y >> x;
    blues.emplace_back(x, y);
  }
  cout << rec(1, 1, X, Y) << endl;
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
