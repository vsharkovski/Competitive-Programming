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







int N = 9;
char grid[10][10];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool foundx, foundo;

int floodfill(int r, int c, char c1, char c2) {
  if (r < 0 || c < 0 || r >= N || c >= N) return 0;
  if (grid[r][c] == 'X') {
    foundx = 1;
  } else if (grid[r][c] == 'O') {
    foundo = 1;
  } else if (grid[r][c] == c1) {
    int sz = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 4; ++d) {
      sz += floodfill(r + dr[d], c + dc[d], c1, c2);
    }
    return sz;
  }
  return 0;
}



void SOLVE() {
  int T;
  cin >> T;
  while (T--) {
  
    int px = 0, po = 0;
  
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        char ch;
        cin >> ch;
        grid[i][j] = ch;
        if (ch == 'X') ++px;
        else if (ch == 'O') ++po;
      }
    }
    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == '.') {
          foundx = foundo = 0;
          int sz = floodfill(i, j, '.', 't');
          if (foundx && !foundo) {
            px += sz;
          } else if (!foundx && foundo) {
            po += sz;
          }
        }
      }
    }
  
    cout << "Black " << px << " White " << po << endl;
  
  
  
  
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














