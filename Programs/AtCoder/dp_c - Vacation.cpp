#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;





void Main() {
  int n;
  cin >> n;
  static int a[100000][3];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
    }
  }
  static int dp[100000][3];
  for (int j = 0; j < 3; ++j) {
    dp[0][j] = a[0][j];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int bestprev = 0;
      for (int k = 0; k < 3; ++k) {
        if (k != j) {
          bestprev = max(bestprev, dp[i-1][k]);
        }
      }
      dp[i][j] = max(dp[i][j], bestprev + a[i][j]);
    }
  }
  int ans = 0;
  for (int j = 0; j < 3; ++j) {
    ans = max(ans, dp[n-1][j]);
  }
  cout << ans << '\n';
}


int main() {
  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
