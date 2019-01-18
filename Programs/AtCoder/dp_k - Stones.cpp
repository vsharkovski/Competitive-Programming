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



int N, K;
int a[101];
bool dp[100001];

void Main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  fill(dp, dp+K+1, 0);
  for (int i = 0; i < N; ++i) {
    dp[a[i]] = 1;
  }
  for (int k = 1; k <= K; ++k) {
    for (int i = 0; i < N; ++i) {
      if (a[i] > k || dp[k]) break;
      dp[k] = !dp[k - a[i]];
    }
  }
  cout << (dp[K] ? "First\n" : "Second\n");
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
