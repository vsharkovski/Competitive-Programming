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





int N;
int T[32];
bool visited[302][302][31][8];
bool used[302][302];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int ans;

void dfs(int r, int c, int i, int d) {
  if (visited[r][c][i][d]) return;
  visited[r][c][i][d] = true;
  if (i == N) return;
  for (int j = 0; j < T[i]; ++j) {
    r += dr[d];
    c += dc[d];
    if (used[r][c] == false) {
      ++ans;
      used[r][c] = true;
    }
  }
  dfs(r, c, i + 1, (d + 7) % 8);
  dfs(r, c, i + 1, (d + 1) % 8);
}

void _SOLVE_() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }
  memset(visited, 0, sizeof(visited));
  memset(used, 0, sizeof(used));
  ans = 0;
  dfs(150, 150, 0, 0);
  cout << ans << endl;
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
