#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




struct Coor {
  int r, c, l;
  Coor(int R, int C, int L) : r(R), c(C), l(L) {}
};

const int UNVISITED = -1, ROCK = -2;

int R, C, L;
int grid[35][35][35];

inline bool in(int r, int c, int l) {
  return l >= 0 && l < L && r >= 0 && r < R && c >= 0 && c < C;
}

int dr[] = {1,  0,  0, -1,  0,  0};
int dc[] = {0,  1,  0,  0, -1,  0};
int dl[] = {0,  0,  1,  0,  0, -1};

void bfs(int sr, int sc, int sl) {
  queue<Coor> q;
  q.push(Coor(sr, sc, sl));
  grid[sr][sc][sl] = 0;
  while (!q.empty()) {
    int r = q.front().r, c = q.front().c, l = q.front().l;
    q.pop(); 
    for (int d = 0; d < 6; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d], l1 = l + dl[d];
      if (in(r1, c1, l1) && grid[r1][c1][l1] == UNVISITED) {
        grid[r1][c1][l1] = grid[r][c][l] + 1;
        q.push(Coor(r1, c1, l1));
      }
    }
  }
}

void SOLVE() {

  while (cin >> R >> C >> L, L != 0 && R != 0 && C != 0) {
  
    memset(grid, UNVISITED, sizeof(grid));
  
    int sr = 0, sc = 0, sl = 0;
    int er = 1, ec = 1, el = 1;
    
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        for (int l = 0; l < L; ++l) {
          char ch;
          cin >> ch;
          if (ch == '#') {
            grid[r][c][l] = ROCK;
          } else {
            grid[r][c][l] = UNVISITED;
            if (ch == 'S') {
              sr = r;
              sc = c;
              sl = l;
            } else if (ch == 'E') {
              er = r;
              ec = c;
              el = l;
            }
          }
        }
      }
    }

    bfs(sr, sc, sl);
    if (grid[er][ec][el] == UNVISITED) {
      cout << "Trapped!\n";
    } else {
      cout << "Escaped in " << grid[er][ec][el] << " minute(s).\n";
    }
  
  
  
  }


}












int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  SOLVE();
}














