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



int EMPTY = 0, OVIS = 1, OUNV = 2;

int m, n;
int grid[105][105];

int dr[8] = {1, 1, 0, -1, -1, -1,  0,  1};
int dc[8] = {0, 1, 1 , 1,  0, -1, -1, -1};

void floodfill(int r, int c, char c1, char c2) {
  if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != c1) return;
  
  grid[r][c] = c2;
  for (int d = 0; d < 8; ++d) {
    floodfill(r + dr[d], c + dc[d], c1, c2);
  }
}



void SOLVE() {

  while (cin >> m, m != 0) {
    cin >> n;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        char ch;
        cin >> ch;
        grid[i][j] = ch == '*' ? EMPTY : OUNV;
      }
    }
    
    int numCC = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == OUNV) {
          ++numCC;
          floodfill(i, j, OUNV, OVIS);
        }
      }
    }
    
    cout << numCC << '\n';
    
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














