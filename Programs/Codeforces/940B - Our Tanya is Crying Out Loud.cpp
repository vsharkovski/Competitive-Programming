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
  ll n, k, A, B;
  cin >> n >> k >> A >> B;
  ll ans = 0;
  ll x = n;
  while (x != 1) {
    if (x < k || k == 1) {
      ans += (x - 1) * A;
      x = 1;
    } else {
      ll y = (x - (x % k)) / k;
      ll cost1 = (x % k) * A + B;
      ll cost2 = (x - (x - (x % k))/k) * A;
      ans += min(cost1, cost2);
      x = y;
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
