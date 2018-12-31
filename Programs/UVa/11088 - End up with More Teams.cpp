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
int dp[1<<15];
int ability[15];

void Solution() {
  int Case = 1;
  cout << setprecision(2) << fixed;
  while (cin >> N, N != 0) {
    for (int i = 0; i < N; ++i) {
      cin >> ability[i];
    }
    fill(dp, dp+(1<<N), 0);
    for (int m = 0; m < (1 << N); ++m) {
      for (int i = 0; i < N; ++i) {
        if (m & (1 << i)) continue;
        for (int j = i+1; j < N; ++j) {
          if (m & (1 << j)) continue;
          for (int k = j+1; k < N; ++k) {
            if (m & (1 << k)) continue;
            int m1 = m | (1 << i) | (1 << j) | (1 << k);
            int sum = ability[i] + ability[j] + ability[k];
            dp[m1] = max(dp[m1], dp[m] + (sum >= 20));
          }
        }
      }
    }
    int res = dp[(1 << N) - 1];
    cout << "Case " << Case++ << ": " << res << '\n';
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
