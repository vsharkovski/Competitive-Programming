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




int hex2dec[200];

int R, C;
int grid[210][210];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void floodfill(int r, int c, int c1, int c2) {
  if (r < 0 || c < 0 || r >= R || c >= C) return;
  if (grid[r][c] != c1) return;
  grid[r][c] = c2;
  for (int d = 0; d < 4; ++d) floodfill(r + dr[d], c + dc[d], c1, c2);
}

int heirofill(int r, int c) {
  if (r < 0 || c < 0 || r >= R || c >= C) return 0;
  if (grid[r][c] == -1) return 0;
 
  int cnt = 0;
  
  if (grid[r][c] == 0) { //hole!
    floodfill(r, c, 0, -1);
    ++cnt;
  } else if (grid[r][c] == 1) {
    grid[r][c] = -1;
    for (int d = 0; d < 4; ++d) {
      cnt += heirofill(r + dr[d], c + dc[d]);
    }
  }
  
  return cnt;
}


void SOLVE() {

  for (char c = '0'; c <= '9'; ++c) hex2dec[(int)c] = c-'0';
  for (char c = 'a'; c <= 'f'; ++c) hex2dec[(int)c] = c-'a'+10;

  
  int TC = 1;
  
  while (cin >> R >> C, R != 0 && C != 0) {
  
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        char ch;
        cin >> ch;
        int x = hex2dec[(int)ch];
        grid[r][c*4+0] = (x>>3) & 1;
        grid[r][c*4+1] = (x>>2) & 1;
        grid[r][c*4+2] = (x>>1) & 1;
        grid[r][c*4+3] = (x>>0) & 1;
      }
    }
    
    C *= 4;
    
    // fill bg
    for (int c = 0; c < C; ++c) floodfill(0,   c, 0, -1);
    for (int c = 0; c < C; ++c) floodfill(R-1, c, 0, -1);
    for (int r = 0; r < R; ++r) floodfill(r,   0, 0, -1);
    for (int r = 0; r < R; ++r) floodfill(r, C-1, 0, -1);
    
    // count holes
    string ans = "";

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
      
        if (grid[r][c] == 1) {
          int holes = heirofill(r, c);
          if (holes == 0) ans +='W';
          else if (holes == 1) ans += 'A';
          else if (holes == 2) ans += 'K';
          else if (holes == 3) ans += 'J';
          else if (holes == 4) ans += 'S';
          else if (holes == 5) ans += 'D';
        }
      
        
      }
    }
    
    sort(all(ans));
    cout << "Case " << TC++ << ": " << ans << '\n';
  
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














