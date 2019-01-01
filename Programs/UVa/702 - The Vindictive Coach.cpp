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




// Because UVa's website is old and broken, I can't see my submissions
// Therefore I can't see if this passes or gets TLE
// On my computer it finishes in 42 seconds,
// so it will probably be less than 10 on their server(s)
// (the solution is correct)


int N, captain;
ll dp[2][21][1<<21];

ll dfs(int p, int i, int m) {
  ll& res = dp[p][i][m];
  if (res != -1) {
    return res;
  }
  if (m == (1 << N) - 1) {
    return res = 1;
  }
  res = 0;
  if (p == 0) {
    for (int j = i+1; j < N; ++j) {
      if (m & (1 << j)) continue;
      res += dfs(1, j, m | (1 << j));
    }
  } else {
    for (int j = 0; j < i; ++j) {
      if (m & (1 << j)) continue;
      res += dfs(0, j, m | (1 << j));
    }
  }
  return res;
}

// 42 seconds

void Solution() {
  while (cin >> N >> captain) {
    --captain, --N;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    if (captain == 0) {
      if (N <= 1) {
        ans += 1;
      } else {
        ans += dfs(1, 1, 1 << 1);
      }
    } else {
      for (int i = 0; i < captain; ++i) {
        ans += dfs(0, i, 1 << i);
      }
    }
    cout << ans << '\n';
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
