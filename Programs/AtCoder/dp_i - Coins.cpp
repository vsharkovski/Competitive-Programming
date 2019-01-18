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
  static double p[3000];
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  // dp[i][h] = probability of having h heads after throwing coins [0..i-1]
  static double dp[3000][3000];
  dp[0][0] = 1.0;
  for (int i = 0; i < n; ++i) {
    for (int h = 0; h <= i; ++h) {
      dp[i+1][h+1] += p[i]       * dp[i][h];
      dp[i+1][h]   += (1 - p[i]) * dp[i][h];
    }
  }
  double ans = 0;
  for (int h = n / 2 + (n % 2); h <= n; ++h) {
    ans += dp[n][h];
  }
  cout << setprecision(15) << ans << '\n';
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
