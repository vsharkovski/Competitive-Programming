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



int R, C;
int Z[1002][1002];
int dp[1002][1002];

void _SOLVE_() {
  cin >> R >> C;
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cin >> Z[r][c];
    }
  }
  for (int c = 1; c <= C; ++c) {
    dp[1][c] = Z[1][1] + Z[1][c];
  }
  dp[1][1] = -1e9; // ne moze da skokne do pocetnata pozicija (samo od nea)
  for (int r = 2; r <= R; ++r) {
    int max1 = 0, max2 = 0, max1c = 1, max2c = 1;
    for (int c = 1; c <= C; ++c) {
      int curr = dp[r-1][c] + Z[r][c];
      if (curr >= max1) {
        max2 = max1;
        max2c = max1c;
        max1 = curr;
        max1c = c;
      } else if (curr > max2) {
        max2 = curr;
        max2c = c;
      }
    }
    for (int c = 1; c <= C; ++c) {
      if (c == max1c) {
        dp[r][c] = max(max1, max2 + Z[r][c]);
      } else {
        dp[r][c] = max1 + Z[r][c];
      }
    }
  }
  cout << dp[R][C] << endl;
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
