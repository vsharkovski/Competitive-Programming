#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;



const ll mod = 1e9 + 7;

int R, C;
bool a[1001][1001];
ll dp[1001][1001];

ll dfs(int r, int c) {
  ll& res = dp[r][c];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (r+1 == R && c+1 == C) {
    res = 1;
  }
  if (r+1 < R && a[r+1][c] == 0) {
    res += dfs(r+1, c);
  }
  if (c+1 < C && a[r][c+1] == 0) {
    res += dfs(r, c+1);
  }
  res %= mod;
  return res;
}

void Main() {
  cin >> R >> C;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      char ch;
      cin >> ch;
      a[r][c] = ch == '#';
    }
  }
  memset(dp, -1, sizeof(dp));
  ll ans = dfs(0, 0);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
