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






int R, C;
char grid[22][22];

int dr[] = {-1, 0, 1,  0};
int dc[] = { 0, 1, 0, -1};

int floodfill(int r, int c, char c1, char c2) {
  c= (c + C) % C;
  if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != c1) return 0;
  grid[r][c] = c2;
  int sz = 1;
  for (int d = 0; d < 4; ++d) {
    sz += floodfill(r + dr[d], c + dc[d], c1, c2);
  }
  return sz;
}






void SOLVE() {

  while (cin >> R >> C) {
  
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> grid[i][j];
      }
    }
    
    int x, y;
    cin >> x >> y;
    
    char LAND = grid[x][y];
    
    floodfill(x, y, LAND, 0);
    
    int maxsz = 0;
    
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == LAND) {
          maxsz = max(maxsz, floodfill(i, j, LAND, 0));
        }
      }
    }
  
    cout << maxsz << '\n';
  
  
  
  
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














