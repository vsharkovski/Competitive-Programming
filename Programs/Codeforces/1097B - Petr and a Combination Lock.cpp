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





void _SOLVE_() {
  int n;
  cin >> n;
  int a[16];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int m = 0; m < (1 << n); ++m) {
    int d = 0;
    for (int i = 0; i < n; ++i) {
      if (m & (1 << i)) {
        d += a[i];
      } else {
        d -= a[i];
      }
      d = (d + 360) % 360;
    }
    if (d == 0) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
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
