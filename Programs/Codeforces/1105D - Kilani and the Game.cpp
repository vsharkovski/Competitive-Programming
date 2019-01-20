#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
//template<class Key, class Compare = less<Key>>
//using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



struct State {
  int x, i, j, round, srcdist;
  State(int X, int I, int J, int ROUND, int SRCDIST) {
    x = X, i = I, j = J, round = ROUND, srcdist = SRCDIST;
  }
  State() {}
  bool operator < (const State& rhs) const {
    bool res;
    if (x == rhs.x) {
      if (round == rhs.round) {
        res = srcdist < rhs.srcdist;
      } else {
        res = round < rhs.round;
      }
    } else {
      if (round == rhs.round) {
        res = x < rhs.x;
      } else if (round + 1 == rhs.round) {
        res = 1;
      } else if (rhs.round + 1 == round) {
        res = 0;
      } else {
        return x < rhs.x;
      }
    }
    return !res;
  }
};

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

void Main() {
  int n, m, p;
  cin >> n >> m >> p;
  int speed[10];
  for (int i = 1; i <= p; ++i) {
    cin >> speed[i];
  }
  static int grid[1002][1002];
  static int FUCK[1002][1002] = {};
  priority_queue<State> pq;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      cin >> ch;
      if (ch == '.') {
        grid[i][j] = 0;
      } else if (ch == '#') {
        grid[i][j] = -1;
      } else {
        grid[i][j] = ch - '0';
        pq.emplace(ch - '0', i, j, 0, 0);
      }
    }
  }
  State top;
  while (!pq.empty()) {
    top = pq.top(); pq.pop();
//    cout << "x=" << top.x << " i=" << top.i << " j=" << top.j << " round=" << top.round << " srcdist=" << top.srcdist << '\n';
    ++FUCK[top.i][top.j];
    if (FUCK[top.i][top.j] == 3) continue;
    if (top.srcdist > 0) {
      pq.emplace(top.x, top.i, top.j, top.round+1, 0);
    }
    if (top.srcdist == speed[top.x]) continue;
    for (int d = 0; d < 4; ++d) {
      int i1 = top.i + di[d], j1 = top.j + dj[d];
      if (i1 < 0 || i1 == n || j1 < 0 || j1 == m) continue;
      if (grid[i1][j1] != 0) continue;
      grid[i1][j1] = top.x;
      pq.emplace(top.x, i1, j1, top.round, top.srcdist+1);
    }
  }
  int cnt[10] = {};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] >= 1) {
        ++cnt[grid[i][j]];
      }
    }
  }
  for (int i = 1; i <= p; ++i) {
    cout << cnt[i] << ' ';
  }
//  cout << '\n';
//  for (int i = 0; i < n; ++i) {
//    for (int j = 0; j < m; ++j) {
//      if (grid[i][j] == 0) cout << ".";
//      else if (grid[i][j] == -1) cout << "#";
//      else cout << grid[i][j];
//    }
//    cout << '\n';
//  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
