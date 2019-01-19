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



const ll mod = 1e9 + 7;

int n;
bool a[22][22];
ll dp[22][(1<<21)+1];

ll dfs(int i, int m) {
  ll& res = dp[i][m];
  if (res != -1) {
    return res;
  }
  if (i == n) {
    return res = 1;
  }
  res = 0;
  for (int j = 0; j < n; ++j) {
    if (a[i][j] && !(m & (1 << j))) {
      res += dfs(i+1, m | (1 << j));
      res %= mod;
    }
  }
  return res;
}

void Main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  ll ans = dfs(0, 0);
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
