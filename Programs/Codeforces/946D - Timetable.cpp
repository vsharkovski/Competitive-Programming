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




int n, m, k;
int dp1[501][501];
int dp2[501][501];

void _SOLVE_() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    vector<int> lessons;
    for (int t = 0; t < m; ++t) {
      if (str[t] == '1') {
        lessons.push_back(t);
      }
    }
    int sz = lessons.size();
    dp1[i][0] = sz == 0 ? 0 : lessons[sz-1] - lessons[0] + 1;
    for (int l = 1; l <= k; ++l) {
      dp1[i][l] = dp1[i][0];
    }
    for (int l = sz; l <= k; ++l) {
      dp1[i][l] = 0;
    }
    for (int a = 0; a < sz; ++a) {
      for (int b = sz - 1; b >= a; --b) {
        int l = a + (sz - b - 1);
        dp1[i][l] = min(dp1[i][l], lessons[b] - lessons[a] + 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      dp2[i][j] = 1e9;
      for (int l = 0; l <= j; ++l) {
        dp2[i][j] = min(dp2[i][j], (i == 0 ? 0 : dp2[i-1][j-l]) + dp1[i][l]);
      }
    }
  }
  int ans = 1e9;
  for (int l = 0; l <= k; ++l) {
    ans = min(ans, dp2[n-1][l]);
  }
  cout << ans << endl;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
