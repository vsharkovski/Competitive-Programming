#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





int R, C;
char grid[52][52];
int fr = 0, fc = 0;
int pr = -1, pc = -1;
int dist[52][52];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
inline bool in(int r, int c) {
  return r >= 1 && r <= R && c >= 1 && c <= C;
}

bool isclear(int r1, int c1, int r2, int c2, char me) {
  for (int r = r1; r <= r2; ++r)
    for (int c = c1; c <= c2; ++c)
      if (grid[r][c] != '.' && grid[r][c] != me && grid[r][c] != 'F')
        return false;
  return true;
}

int bfs(char me,  int sr, int sc) {
  memset(dist, -1, sizeof(dist));
  dist[sr][sc] = 0;
  queue<ii> q;
  q.emplace(sr, sc);
  while (!q.empty()) {
    ii top = q.front(); q.pop();
    int r = top.first, c = top.second;
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (!in(r1, c1) || !in(r1 + pr, c1 + pc)) continue;
      if (!isclear(r1, c1, r1 + pr, c1 + pc, me)) continue;
      if (dist[r1][c1] != -1) continue;
      dist[r1][c1] = dist[r][c] + 1;
      q.emplace(r1, c1);
    }
  }
  return dist[fr][fc];
}

void Solve() {
  cin >> C >> R;
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cin >> grid[r][c];
    }
  }
  int coords[3][2] = {};
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      if (grid[r][c] == 'F' && fr == 0) {
        fr = r, fc = c;
      } else if (grid[r][c] >= '1' && grid[r][c] <= '3') {
        int x = grid[r][c] - '0' - 1;
        if (coords[x][0] == 0) {
          coords[x][0] = r, coords[x][1] = c;
          if (pr == -1) {
            for (int r1 = r; r1 <= R; ++r1) {
              if (grid[r1][c] != grid[r][c]) break;
              ++pr;
            }
            for (int c1 = c; c1 <= C; ++c1) {
              if (grid[r][c1] != grid[r][c]) break;
              ++pc;
            }
          }
        }
      }
    }
  }
  int minres = 1e9, bestpiano = -1;
  for (int x = 0; x < 3 && coords[x][0] != 0; ++x) {
    int res = bfs(x + '0' + 1, coords[x][0], coords[x][1]);
    if (res != -1 && res < minres) {
      minres = res;
      bestpiano = x;
    }
  }
  cout << bestpiano + 1 << endl << minres << endl;
}



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
