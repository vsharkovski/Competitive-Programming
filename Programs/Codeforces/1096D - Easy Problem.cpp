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




int n;
string s;
ll a[100005];
ll dp[100005][1<<4];

ll F(int i, int m) {
  if (dp[i][m] != -1) return dp[i][m];
  ll res = 1e17;
  if (i == n) {
    res = 0;
  } else {
    if (s[i] == 'h' && m == (1 << 0) - 1) {
      res = min(res, F(i+1, m | (1 << 0)));
      res = min(res, a[i] + F(i+1, m));
    } else if (s[i] == 'a' && m == (1 << 1) -1 ) {
      res = min(res, F(i+1, m | (1 << 1)));
      res = min(res, a[i] + F(i+1, m));
    } else if (s[i] == 'r' && m == (1 << 2) - 1) {
      res = min(res, F(i+1, m | (1 << 2)));
      res = min(res, a[i] + F(i+1, m));
    } else if (s[i] == 'd' && m == (1 << 3) - 1) {
      res = min(res, a[i] + F(i+1, m));
    } else {
      res = min(res, F(i+1, m));
    }
  }
  return dp[i][m] = res;
}

void _SOLVE_() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  ll ans = F(0, 0);
  cout << ans << '\n';
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
