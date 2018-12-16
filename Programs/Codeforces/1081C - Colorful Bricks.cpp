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

ll n, m, k;
ll dp[2002][2002];

ll F(int i, int k1) {
  if (dp[i][k1] != -1) return dp[i][k1];
  ll res;
  if (i == n) {
    res = k1 == k;
  } else if (i == 0) {
    res = m * F(i+1, k1);
  } else if (k1 == k) {
    res = F(i+1, k1);
  } else {
    res = F(i+1, k1) + (m-1) * F(i+1, k1+1);
  }
  res %= mod;
  return dp[i][k1] = res;
}

void _SOLVE_() {
  cin >> n >> m >> k;
  for (int i = 0; i <= n; ++i) {
    for (int k0 = 0; k0 <= k; ++k0) {
      dp[i][k0] = -1;
    }
  }
  ll ans = F(0, 0);
  cout << ans << endl;
//  for (int i = 0; i <= n; ++i) {
//    for (int k0 = 0; k0 <= k; ++k0) {
//      cout << "i=" << i << " k1=" << k0 << " dp=" << dp[i][k0] << endl;
//    }
//  }
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
