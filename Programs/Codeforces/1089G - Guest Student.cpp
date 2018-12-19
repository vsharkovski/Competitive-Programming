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
  int T;
  cin >> T;
  while (T--) {

    int k;
    int a[7], in1w = 0;

    cin >> k;
    for (int i = 0; i < 7; ++i) {
      cin >> a[i];
      in1w += a[i];
    }

    int ans = 1e9;

    for (int i = 0; i < 7; ++i) {
      int w = max(k / in1w - 1, 0);
      int rem = k - w * in1w;
      int j = i;
      int last = 0;
      while (rem > 0) {
        rem -= a[j];
        ++last;
        ++j;
        j %= 7;
      }
      ans = min(ans, w * 7 + last);
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
