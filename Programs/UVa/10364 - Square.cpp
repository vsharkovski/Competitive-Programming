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




int M;
int sticks[20];
int sum, target;
int dp[1<<20];

int dfs(int m, int s) {
  if (dp[m] != -1) {
    return dp[m];
  }
  if (s > target) {
    return 0; // failed, but this state might be possible with
              // different s, so don't mark as impossible
  }
  if (s == target) {
    if (m + 1 == (1 << M)) {
      return dp[m] = 1; // success
    } else {
      s = 0; // it is still progress
    }
  }
  for (int i = 0; i < M; ++i) {
    if ((m & (1 << i)) == 0) {
      int success = dfs(m | (1 << i), s + sticks[i]);
      if (success) {
        return dp[m] = 1;
      }
    }
  }
  // finally, if we fail after trying everything
  return dp[m] = 0;
}

void Solution() {
  int T;
  cin >> T;
  while (T--) {
    cin >> M;
    sum = 0;
    for (int i = 0; i < M; ++i) {
      cin >> sticks[i];
      sum += sticks[i];
    }
    if (sum % 4 != 0) {
      cout << "no\n";
      continue;
    }
    target = sum / 4;
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, 0);
    cout << (ans ? "yes\n" : "no\n");
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}
