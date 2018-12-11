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
  vi a(n+2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 1e9;
  for (int x = 1; x <= n; ++x) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res += a[i]*2*(abs(x - i) + abs(i - 1) + abs(1 - x));
    }
    ans = min(ans, res);
  }
  cout << ans << endl;



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
