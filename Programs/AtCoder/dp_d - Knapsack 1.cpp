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



int N, W;
int w[100], v[100];
static ll dp[101][100001];

ll dfs(int i, int wrem) {
  ll& res = dp[i][wrem];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (i < N) {
    res = max(res, dfs(i+1, wrem));
    if (w[i] <= wrem) {
      res = max(res, v[i] + dfs(i+1, wrem-w[i]));
    }
  }
  return res;
}

void Main() {
  cin >> N >> W;
  for (int i = 0; i < N; ++i) {
    cin >> w[i] >> v[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(0, W) << '\n';
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
