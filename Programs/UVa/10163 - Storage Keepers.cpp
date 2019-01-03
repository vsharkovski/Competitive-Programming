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




vector<int> divs[1001];

int N, M;
int P[31];
pi dp[101][31]; // (L, Y) dp[num. storages left][m-th person]

pi dfs(int n, int m) {
  pi& res = dp[n][m];
  if (res.first != -1) {
    return res;
  }
  if (n == 0) {
    return res = {10000, 0};
  }
  if (m == M) { // n > 0
    return res = {0, 0};
  }
  // ignore
  res = dfs(n, m + 1);
  // assign
  for (int k = 1; k <= min(n, P[m]); ++k) {
    pi opt = dfs(n - k, m + 1);
    opt.first = min(opt.first, P[m] / k); // L
    opt.second += P[m]; // Y
    if (opt.first > res.first || (opt.first == res.first && opt.second < res.second)) {
      res = opt;
    }
  }
  return res;
}

void Solution() {
  divs[1].push_back(1);
  for (int x = 2; x <= 1000; ++x) {
    for (int y = 1; y*y <= x; ++y) {
      if (x % y == 0) {
        divs[x].push_back(y);
        if (y*y != x) {
          divs[x].push_back(x/y);
        }
      }
    }
  }
  while (cin >> N >> M, N != 0 || M != 0) {
    for (int i = 0; i < M; ++i) {
      cin >> P[i];
    }
    sort(P, P+M);
    for (int n = 0; n <= N; ++n) {
      for (int m = 0; m <= M; ++m) {
        dp[n][m].first = -1;
      }
    }
    pi res = dfs(N, 0);
    cout << res.first << ' ' << res.second << '\n';
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
