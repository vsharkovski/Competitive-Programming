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
  int T;
  cin >> T;
  while (T--) {
    ll n, x, y, d;
    cin >> n >> x >> y >> d;
    if (abs(y - x) % d != 0) {
      if ((y - 1) % d != 0 && (n - y) % d != 0) {
        cout << "-1\n";
      } else if ((n - y) % d != 0) {
        cout << abs(x - 1) / d + ll((x - 1) % d != 0) + abs(y - 1) / d << endl;
      } else if ((y - 1) % d != 0) {
        cout << abs(n - x) / d + ll((n - x) % d != 0) + abs(n - y) / d << endl;
      } else {
        cout << min(abs(x - 1) / d + ll((x - 1) % d != 0) + abs(y - 1) / d,
                    abs(n - x) / d + ll((n - x) % d != 0) + abs(n - y) / d) << endl;
      }
    } else {
      cout << abs(y - x) / d << endl;
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
