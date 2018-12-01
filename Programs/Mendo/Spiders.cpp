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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



int N, K, S;
int t[1001];
int dp[1001][1001][11];

void _SOLVE_() {
  int T;
  cin >> T;
  while (T--) {
    cin >> N >> K >> S;
    for (int i = 1; i <= S; ++i)
      cin >> t[i];
    memset(dp, -1, sizeof(dp));
    dp[0][K][1] = 0;
    for (int s = 1; s <= S; ++s) {
      for (int k = 0; k <= K; ++k) {
        for (int i = 1; i <= N; ++i) {
          dp[s][k][i] = dp[s-1][k][i];
          if (k < K) {
            if (i > 1)
              dp[s][k][i] = max(dp[s][k][i], dp[s-1][k+1][i-1]);
            if (i < N)
              dp[s][k][i] = max(dp[s][k][i], dp[s-1][k+1][i+1]);
          }
          if (dp[s][k][i] != -1 && t[s] == i)
            dp[s][k][i] += 1;
        }
      }
    }
    int ans = 0;
    for (int k = 0; k <= K; ++k)
      for (int i = 1; i <= N; ++i)
        ans = max(ans, dp[S][k][i]);
    cout << ans << endl;
  }
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
