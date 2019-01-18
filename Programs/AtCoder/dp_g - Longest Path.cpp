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




int N, M;
vector<int> G[100000];
int dp[100000];

int dfs(int u) {
  int& res = dp[u];
  if (res != -1) {
    return res;
  }
  res = 0;
  for (int v : G[u]) {
    res = max(res, 1 + dfs(v));
  }
  return res;
}

void Main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(y);
  }
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, dfs(i));
  }
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
