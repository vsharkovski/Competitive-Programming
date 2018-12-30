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




int n, m;
string dirs;
char grid[52][52];
int sr, sc;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool good(int perm[4]) {
  int r = sr, c = sc;
  int i = 0;
  while (i < dirs.length() && r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#' && grid[r][c] != 'E') {
    int d = dirs[i] - '0';
    ++i;
    r += dr[perm[d]];
    c += dc[perm[d]];
  }
  if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'E') {
    return true;
  }
  return false;
}

void _SOLVE_() {
  cin >> n >> m;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      cin >> grid[r][c];
      if (grid[r][c] == 'S') {
        sr = r, sc = c;
      }
    }
  }
  cin >> dirs;
  int ans = 0;
  int perm[4] = {0, 1, 2, 3};
  do {
    if (good(perm)) {
      ++ans;
    }
  } while (next_permutation(perm, perm+4));
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
