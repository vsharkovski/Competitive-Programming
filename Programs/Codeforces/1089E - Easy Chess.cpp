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




int n, r, c;

void print() {
  cout << char(c + 'a' - 1) << r << " ";
}

void _SOLVE_() {
  cin >> n;
  int n0 = n;
  r = c = 1;
  bool vis[10][10] = {};
  vis[1][1] = 1;
  print();
  while (n > 2 && r < 7) {
    if (c == 1) {
      if (vis[r][c+1]) {
        ++r;
      } else {
        ++c;
      }
    } else if (c == 8) {
      if (vis[r][c-1]) {
        ++r;
      } else {
        --c;
      }
    } else {
      if (vis[r][c-1]) {
        ++c;
      } else {
        --c;
      }
    }
    vis[r][c] = 1;
    print();
    --n;
  }
  if (n == 2) {
    if (c == 8) {
      ++r;
      print();
      r = 8;
      print();
    } else {
      r = 8;
      print();
      c = 8;
      print();
    }
  } else if (n0 == 63) {
    cout << "h7 b7 g7 c7 f7 d7 e7 e8 a8 b8 c8 d8 f8 g8 h8";
  } else {
    while (n > 2) {
      if (r == 8) {
        if (vis[r-1][c]) {
          ++c;
        } else {
          --r;
        }
      } else {
        if (vis[r+1][c]) {
          ++c;
        } else {
          ++r;
        }
      }
      vis[r][c] = 1;
      print();
      --n;
    }
    if (r == 8) {
      ++c;
      print();
      c = 8;
      print();
    } else {
      c = 8;
      print();
      r = 8;
      print();
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
