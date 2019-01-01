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





int n;
int t[102], b[102];
int dp[102][10002];

int dfs(int i, int j) {
  int& res = dp[i][j];
  if (res != -1) {
    return res;
  }
  if (i == n) {
    return res = 0;
  }
  res = t[i] + dfs(i + 1, j + b[i]);
  if (j > 0) {
    res = min(res, t[i] / 2 + dfs(i + 1, j - 1 + b[i]));
  }
  return res;
}

void Solution() {
  while (cin >> n, n != 0) {
    for (int i = 0; i < n; ++i) {
      cin >> t[i] >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    int res = dfs(0, 0);
    cout << res << '\n';
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
