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
double k;
double dp[101][10];

void Solution() {
  cout << setprecision(5) << fixed;
  while (cin >> k >> n) {
    for (int j = 0; j <= k; ++j) {
      dp[0][j] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        dp[i][j] = dp[i-1][j];
        if (j > 0) dp[i][j] += dp[i-1][j-1];
        if (j < k) dp[i][j] += dp[i-1][j+1];
      }
    }
    double tight = 0;
    for (int j = 0; j <= k; ++j) {
      tight += dp[n-1][j];
    }
    double total = pow(k+1, n);
    double fraction = tight / total;
    double percent = 100 * fraction;
    cout << percent << '\n';
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
