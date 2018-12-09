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






void _SOLVE_() {
  int l, r, a;
  cin >> l >> r >> a;
  if (l == r) {
    cout << l + r + a - a%2 << endl;
  } else if (l < r) {
    if (l + a <= r) {
      cout << l + a + r - (r - l - a) << endl;
    } else {
      int x = r - l;
      l = r;
      a -= x;
      cout << l + r + a - a%2 << endl;
    }
  } else {
    if (r + a <= l) {
      cout << r + a + l - (l - r - a) << endl;
    } else {
      int x = l - r;
      r = l;
      a -= x;
      cout << r + l + a - a%2 << endl;
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
