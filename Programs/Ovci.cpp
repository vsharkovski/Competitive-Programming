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
char grid[260][260];

int bro, brv;
int currbro, currbrv;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void floodfill(int r, int c) {
  if (r < 0 || r >= R || c < 0 || c >= C) return;
  if (grid[r][c] == '#') return;
  
  if (grid[r][c] == 'o') ++currbro;
  else if (grid[r][c] == 'v') ++currbrv;
  grid[r][c] = '#';
  
  for (int d = 0; d < 4; ++d) {
    floodfill(r + dr[d], c + dc[d]);
  }
}

void SOLVE() {

  cin >> R >> C;
  
  
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> grid[i][j];
    }
  }
  
  bro = brv = 0;
  
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (grid[i][j] != '#') {
        currbro = currbrv = 0;
        floodfill(i, j);
        if (currbro > currbrv) {
          bro += currbro;
        } else {
          brv += currbrv;
        }
      }
    }
  }
  
  cout << bro << ' ' << brv << endl;


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














