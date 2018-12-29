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






void _SOLVE_() {
  int n;
  cin >> n;
  int board[4][100][100];
  for (int i = 0; i < 4; ++i) {
    for (int r = 0; r < n; ++r) {
      string s;
      cin >> s;
      for (int c = 0; c < n; ++c) {
        board[i][r][c] = s[c] - '0';
      }
    }
  }
  int ans = 4 * n * n;
  int order[4] = {0, 1, 2, 3};
  for (int tlc = 0; tlc < 2; ++tlc) {
    do {
      int res = 0;
      for (int ii = 0; ii < 4; ++ii) {
        int i = order[ii];
        int topleft = ii % 2 == 0 ? 1 : 0;
        for (int r = 0; r < n; ++r) {
          for (int c = 0; c < n; ++c) {
            res += ((r + c) % 2 == 0) ? board[i][r][c] == topleft : board[i][r][c] != topleft;
          }
        }
      }
      ans = min(ans, res);
    } while (next_permutation(order, order+4));
  }
  cout << ans << "\n";
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
