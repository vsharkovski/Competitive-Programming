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
int L, C;
int t[1001];
pi dp[1001][501];

inline int DI(int t) {
  if (t == 0) return 0;
  if (t <= 10) return -C;
  return (t - 10) * (t - 10);
}

pi dfs(int i, int j) {
  pi& res = dp[i][j];
  if (res.first != -1) {
    return res;
  }
  if (i == n) {
    return res = {0, DI(L - j)};
  }
  // end current lecture, start new one
  res = dfs(i + 1, t[i]);
  res.first += 1;
  res.second += DI(L - j);
  if (j + t[i] <= L) {
    // add to this lecture
    pi res2 = dfs(i + 1, j + t[i]);
    if (res2.first < res.first || (res2.first == res.first && res2.second < res.second)) {
      res = res2;
    }
  }
  return res;
}

void Solution() {
  int Case = 1;
  while (cin >> n, n != 0) {
    cin >> L >> C;
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= L; ++j) {
        dp[i][j] = {-1, -1};
      }
    }
    pi res = dfs(0, L); // j=L at start so to start new lecture
    if (Case > 1) cout << "\n";
    cout << "Case " << Case++ << ":\n";
    cout << "Minimum number of lectures: " << res.first << "\n";
    cout << "Total dissatisfaction index: " << res.second << "\n";
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
