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





int n, m;
int a[16][10000];
int mindiff[16][16];
int mindiffspecial[16][16];

int first;
int dp[(1<<16)+1][16];

int dfs(int msk, int pr) {
  int& res = dp[msk][pr];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (msk == (1 << n) - 1) {
    res = mindiffspecial[pr][first];
  } else {
    for (int i = 0; i < n; ++i) {
      if ((msk & (1 << i)) == 0) {
        res = max(res, min(mindiff[pr][i], dfs(msk | (1 << i), i)));
      }
    }
  }
  return res;
}

void Main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  if (n == 1) {
    int ans = 1e9;
    for (int i = 1; i < m; ++i) {
      ans = min(ans, abs(a[0][i] - a[0][i-1]));
    }
    cout << ans << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      int res = 1e9;
      int res2 = 1e9;
      for (int k = 0; k < m; ++k) {
        res = min(res, abs(a[i][k] - a[j][k]));
        if (k < m-1) {
          res2 = min(res2, abs(a[i][k] - a[j][k+1]));
        }
      }
      mindiff[i][j] = res;
      mindiffspecial[i][j] = res2;
    }
  }
  int ans = 0;
  for (first = 0; first < n; ++first) {
    memset(dp, -1, sizeof(dp));
    ans = max(ans, dfs(1 << first, first));
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
