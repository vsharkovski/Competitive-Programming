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
  int n;
  cin >> n;

  vector<int> a(n);
  int y = 1e9;
  int maxa = 0;

  cin >> a[0];
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    int d = abs(a[i] - a[i-1]);
    if (d == 0) {
      cout << "NO\n";
      return;
    } else if (d == 1) {

    } else {
      if (y == 1e9) {
        y = d;
      }
      if (d == y) {

      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i-1]) == 1 && min(a[i], a[i-1]) % y == 0) { //e.g y=3, 6->7
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n" << int(1e9) << " " << y << "\n";

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
