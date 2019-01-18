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
  int n, k;
  cin >> n >> k;
  vi h(n), dp(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    int mini = 1e9;
    for (int j = max(0, i-k); j < i; ++j) {
      mini = min(mini, dp[j] + abs(h[i] - h[j]));
    }
    dp[i] = mini;
  }
  cout << dp[n-1] << '\n';
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
