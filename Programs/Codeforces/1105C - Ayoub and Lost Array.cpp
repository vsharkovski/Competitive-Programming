#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




const ll mod = 1e9 + 7;

int n, l, r;
ll cnt[3];
ll dp[200005][3];

ll dfs(int i, int s) {
  ll& res = dp[i][s];
  if (res != -1) {
    return res;
  }
  if (i == n) {
    return res = 1;
  }
  res = 0;
  if (i+1 == n) {
    res += cnt[(3 - s) % 3] * dfs(i+1, 0);
    res %= mod;
  } else {
    for (int j = 0; j < 3; ++j) {
      res += cnt[j] * dfs(i+1, (s + j) % 3);
      res %= mod;
    }
  }
  return res;
}

void Main() {
  cin >> n >> l >> r;
  for (int j = 0; j < 3; ++j) {
    cnt[j] = 0;
    ll l1 = l, r1 = r;
    while (l1 % 3 != j && l1 <= 1e9) {
      ++l1;
    }
    while (r1 % 3 != j && r1 >= 0) {
      --r1;
    }
    if (l1 <= r1) {
      cnt[j] = (r1 - l1) / 3 + 1;
//      cout << "j=" << j << " cnt=" << cnt[j] << '\n';
    }
  }
  memset(dp, -1, sizeof(dp));
  ll ans = dfs(0, 0);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
