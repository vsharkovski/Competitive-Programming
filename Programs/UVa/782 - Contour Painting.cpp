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











int MAXR = 33, MAXC = 83;
int R, C;
char grid[35][85];

int dr[] = {-1, 0, 1,  0, -1, 1,  1, -1};
int dc[] = { 0, 1, 0, -1,  1, 1, -1, -1};
int _maxd = 4;

void floodfill(int r, int c, char c1, char c2) {
  if (r < 0 || r >= MAXR || c < 0 || c >= MAXC) return;
  if (grid[r][c] != c1) return;
  grid[r][c] = c2;
  for (int d = 0; d < _maxd; ++d) {
    floodfill(r + dr[d], c + dc[d], c1, c2);
  }
}


void SOLVE() {
  C = MAXC;
  
  int T;
  cin >> T;
  string line;
  
  bool FIRSTCASE = 1;
  
  while (T--) {
  
    R = 0;
    memset(grid, ' ', sizeof(grid));
    
    int starr = 0, starc = 0;
    
    while (getline(cin, line)) {
      if (!line.empty() && line[0] == '_') break;
      
      for (int j = 0; j < line.length(); ++j) {
        grid[1+R][1+j] = line[j];
        if (line[j] == '*') {
          starr = 1+R;
          starc = 1+j;
        }
      }
      
      ++R;
    }
    
    grid[starr][starc] = ' ';
    
    floodfill(starr, starc, ' ', 't');
    
    for (int r = 1; r <= R; ++r) {
      for (int c = 1; c < C; ++c) {
        if (grid[r][c] == 'X') {
          for (int d = 0; d < 4; ++d) {
            int r1 = r + dr[d], c1 = c + dc[d];
            if (grid[r1][c1] == 't') grid[r1][c1] = '#';
          }
        }
      }
    }

    for (int r = 0; r <= R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (grid[r][c] == 't') {
          floodfill(r, c, 't', ' ');
        }
      }
    }
    
    for (int i = FIRSTCASE ? 2 : 1; i <= R; ++i) {
      for (int j = C; j >= 1; --j) {
        if (grid[i][j] != ' ') {
          for (int k = 1; k <= j; ++k) {
            cout << grid[i][k];
          }
          break;
        }
      }
      cout << '\n';
    }

    cout << line << '\n';

    FIRSTCASE = 0;


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














