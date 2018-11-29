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





bool okdigit[10] = {};
int dp[5005];

int numdigits(int x) {
  int len = 0;
  while (x > 0) {
    if (!okdigit[x % 10]) {
      return -1;
    }
    x /= 10;
    ++len;
  }
  return len;
}

void _SOLVE_() {
  string s;
  int N;
  cin >> s >> N;
  for (char ch : s)
    okdigit[int(ch - '0')] = 1;
  fill(dp, dp+5002, 1e9);

  if (okdigit[0]) dp[0] = 1;
  for (int x = 1; x <= 5000; ++x) {
    int len = numdigits(x);
    if (len != -1) {
      dp[x] = min(dp[x], len);
    }
  }
  for (int x = 0; x <= 5000; ++x) {
    for (int y = 0; y <= 5000; ++y) {
      dp[min(x*y, 5000)] = min(dp[min(x*y, 5000)], dp[x] + 1 + dp[y]);
    }
  }
  for (int x = 0; x <= 5000; ++x) {
    for (int y = 0; y <= 5000; ++y) {
      dp[min(x+y, 5000)] = min(dp[min(x+y, 5000)], dp[x] + 1 + dp[y]);
    }
  }
  cout << dp[N] << endl;
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
