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





const ll mod = 998244353;

void _SOLVE_() {

  ll pow2[200005];
  pow2[0] = 1;
  for (int i = 1; i < 200000; ++i) {
    pow2[i] = (2 * pow2[i-1]) % mod;
  }

  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  ll ans = 0;
  ll num1 = 0;

  for (int i = max(n, m) - 1; i >= 0; --i) {
    if (i < m && b[i] == '1') {
      ++num1;
    }
    if (i < n && a[i] == '1') {
      ans += pow2[i] * num1;
      ans %= mod;
    }
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
