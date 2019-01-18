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



int N;
ll a[3000];
ll dp[3003][3003][2];

ll dfs(int i, int j, int p) {
  ll& res = dp[i][j][p];
  if (res != -1) {
    return res;
  } else {
    if (p == 0) { // taro
      if (i == j) {
        return res = a[i];
      } else {
        return res = max(a[i] + dfs(i+1, j, 1), a[j] + dfs(i, j-1, 1));
      }
    } else { // jiro
      if (i == j) {
        return res = -a[i];
      } else {
        return res = min(-a[i] + dfs(i+1, j, 0), -a[j] + dfs(i, j-1, 0));
      }
    }
  }
}

void Main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  ll ans = dfs(0, N-1, 0);
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
