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
const int UNVISITED = -1, VISITED = 0;


int R, C, n, b;

inline bool in(int r, int c) {
  return r >= 0 && c >= 0 && r < R && c < C;
}
  
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

void SOLVE() {

  int r, c;
  cin >> R >> C >> n >> b;
  
  int grid[R][C];
  memset(grid, -1, sizeof(grid));
  
  vii v(b);
  
  int mesec = 0;
  
  for (int i = 0; i < b; ++i) {
    cin >> r >> c;
    --r;
    --c;
    grid[r][c] = mesec;
    v[i] = ii(r, c);
  }
  
//  for (int x = 0; x < R; ++x) {
//    for (int y = 0; y < C; ++y) {
//      if (grid[x][y] == -1) cout << '.'; else cout << grid[x][y]; cout << ' ';
//    }
//    cout << '\n';
//  } cout << '\n';
  
  int I = 0, SZ;
  while (b < n) {
    ++mesec;  
    
    SZ = v.size();
    
    for (I = I; I < SZ && b < n; ++I) {
      
      r = v[I].first, c = v[I].second;
      
      for (int d = 0; d < 4; ++d) {
        int r1 = r + dr[d], c1 = c + dc[d];
        if (in(r1, c1) && grid[r1][c1] == -1) {
          grid[r1][c1] = mesec;
          ++b;
          v.push_back(ii(r1, c1));
        }
      }
    
    }
//      for (int x = 0; x < R; ++x) {
//        for (int y = 0; y < C; ++y) {
//          if (grid[x][y] == -1) cout << '.'; else cout << grid[x][y]; cout << ' ';
//        }
//        cout << '\n';
//      } cout << '\n';    
  }
  
  cout << mesec << endl;




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
