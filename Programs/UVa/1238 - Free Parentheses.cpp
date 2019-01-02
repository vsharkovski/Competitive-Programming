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



const int OFS = 3001;

int N, ans;
int x[31];
bool used[6002];
bool dp[31][31][6002];

// we only add parenthesis before negative numbers
// d = depth of parenthesis (if d is odd, signs are flipped)

void dfs(int i, int d, int s) {
  if (dp[i][d][s]) {
    return;
  }
  dp[i][d][s] = true;
  if (i == N) {
    if (used[OFS+s] == false) {
      ++ans;
      used[OFS+s] = true;
    }
    return;
  }
  if (d % 2 == 0) {
    s += x[i];
  } else {
    s -= x[i];
  }
  dfs(i + 1, d, s); // continue without adding parenthesis
  if (x[i] < 0) {
    dfs(i + 1, d + 1, s); // add open parenthesis
  }
  if (d > 0) {
    dfs(i + 1, d - 1, s); // add close parenthesis
  }
}

void Solution() {
  string s;
  while (getline(cin, s)) {
    N = 0;
    stringstream ss;
    char ch;
    int y;
    s = "+ " + s;
    ss << s;
    while (ss >> ch >> y) {
      if (ch == '-') y = -y;
      x[N] = y;
      ++N;
    }
    memset(used, 0, sizeof(used));
    memset(dp, 0, sizeof(dp));
    ans = 0;
    dfs(0, 0, 0);
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
