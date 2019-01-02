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





int N;
int cost[3][12];
int dp[4][281][1<<12];

int dfs(int p, int t, int m) {
  int& res = dp[p][t][m];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (m != (1 << N) - 1) {
    for (int i = 0; i < N; ++i) {
      if ((m & (1 << i)) == 0) {
        for (int c = 0; c < 3; ++c) {
          if (c != p && cost[c][i] <= t) {
            res = max(res, 1 + dfs(c, t - cost[c][i], m | (1 << i)));
          }
        }
      }
    }
  }
  return res;
}

void Solution() {
  int T;
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> cost[i][j];
      }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(3, 280, 0) << '\n';
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
