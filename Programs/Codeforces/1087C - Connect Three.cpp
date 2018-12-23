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




int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
inline bool in(int x, int y) {
  return x >= 0 && x <= 1000 && y >= 0 && y <= 1000;
}

void _SOLVE_() {
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  int xx[3] = {xa, xb, xc};
  int yy[3] = {ya, yb, yc};
  vector<vi> dist[3];
  vector<vpi> previ[3];
  for (int i = 0; i < 3; ++i) {
    dist[i].assign(1005, vi(1005, 1e7));
    previ[i].assign(1005, vpi(1005));
  }
  queue<pair<pi, int>> q;
  q.emplace(pi(xa, ya), 0);
  q.emplace(pi(xb, yb), 1);
  q.emplace(pi(xc, yc), 2);
  dist[0][xa][ya] = dist[1][xb][yb] = dist[2][xc][yc] = 0;
  while (!q.empty()) {
    auto top = q.front(); q.pop();
    int x = top.first.first, y = top.first.second, i = top.second;
    for (int d = 0; d < 4; ++d) {
      int x1 = x + dx[d], y1 = y + dy[d];
      if (in(x1, y1) && dist[i][x1][y1] == 1e7) {
        dist[i][x1][y1] = dist[i][x][y] + 1;
        previ[i][x1][y1] = pi(x, y);
        q.emplace(pi(x1, y1), i);
      }
    }
  }
  int fx = 0, fy = 0, fd = dist[0][0][0] + dist[1][0][0] + dist[2][0][0];
  for (int x = 0; x <= 1000; ++x) {
    for (int y = 0; y <= 1000; ++y) {
      int d = dist[0][x][y] + dist[1][x][y] + dist[2][x][y];
      if (d < fd) {
        fd = d;
        fx = x;
        fy = y;
      }
    }
  }
  vector<vi> used(1005, vi(1005, 0));
  for (int i = 0; i < 3; ++i) {
    int x1 = fx, y1 = fy;
    while (x1 != xx[i] || y1 != yy[i]) {
      used[x1][y1] = 1;
      int x2 = previ[i][x1][y1].first, y2 = previ[i][x1][y1].second;
      x1 = x2, y1 = y2;
    }
    used[xx[i]][yy[i]] = 1;
  }
  vpi ans;
  for (int x = 0; x<=1000;++x) {
    for (int y = 0; y <= 1000; ++y) {
      if (used[x][y]) {
        ans.emplace_back(x, y);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto& p : ans) {
    cout << p.first << " " << p.second << endl;
  }
//  for (int i =0; i < 3; ++i) {
//  for (int x = 0; x <= 10; ++x) {
//    for (int y = 0; y <= 10; ++y) {
//      int z = min(dist[i][x][y], 10);
//      cout << setw(2) << z << " ";
//    }
//    cout << endl;
//  }
//  cout << endl;
//  }
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
