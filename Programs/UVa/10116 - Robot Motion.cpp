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



const int UNVISITED = -1;


int R, C, r, c;
char dirgrid[12][12];
int grid[12][12];


void SOLVE() {

  while (cin >> R >> C >> c, R != 0 && C != 0 && c != 0) {
    r = 0; --c;
  
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> dirgrid[i][j];
        grid[i][j] = UNVISITED;
      }
    }
    
    int steps = 0;
    int pr = r, pc = c;
    
    while (1) {
      if (r >= 0 && c >= 0 && r < R && c < C) {
        
        if (grid[r][c] == UNVISITED) {
          pr = r; pc = c;
        
          grid[r][c] = ++steps;
          
          char dir = dirgrid[r][c];
          if (dir == 'W') --c;
          else if (dir == 'S') ++r;
          else if (dir == 'E') ++c;
          else if (dir == 'N') --r;
          
        } else {
          cout << grid[r][c] - 1 << " step(s) before a loop of " << grid[pr][pc] - grid[r][c] + 1 << " step(s)\n";
          break;
        }
      } else {
        cout << steps << " step(s) to exit\n";
        break;
      }
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














