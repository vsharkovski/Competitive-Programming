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







const int UNVISITED = -1, BOMB = -2;

int R, C;
int grid[1001][1001];

int dr[4] = {-1, 0, 1,  0};
int dc[4] = { 0, 1, 0, -1};

void bfs(int sr, int sc) {
  queue<ii> q;
  q.push(ii(sr, sc));
  grid[sr][sc] = 0;
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (r1 >= 0 && r < R && c1 >= 0 && c < C && grid[r1][c1] == UNVISITED) {
        grid[r1][c1] = grid[r][c] + 1;
        q.push(ii(r1, c1));
      }
    }
  }
}


void SOLVE() {

  while (cin >> R >> C, R != 0 || C != 0) {

    memset(grid, UNVISITED, sizeof(grid));
    
    int bR;
    cin >> bR;
    while (bR--) {
      int r, numb;
      cin >> r >> numb;
      while (numb--) {
        int c;
        cin >> c;
        grid[r][c] = BOMB;
      }
    }

    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;
    bfs(sr, sc);
    
    cout << grid[er][ec] << endl;
    
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














