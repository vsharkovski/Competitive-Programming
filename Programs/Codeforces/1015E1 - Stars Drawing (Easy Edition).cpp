#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
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



struct Star {
  int r, c, sz;
  Star(int R, int C, int SZ) : r(R), c(C), sz(SZ) {}
};

char grid[101][101], grid2[101][101];
int n, m;

bool OK(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '*';
}

void SOLVE() {

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<Star> stars;

  for (int r = 1; r < n-1; ++r) {
    for (int c = 1; c < m-1; ++c) {
      if (grid[r][c] == '*' && OK(r-1, c) && OK(r+1, c) && OK(r, c-1) && OK(r, c+1)) {
        int sz = 1;
        while (OK(r-sz, c) && OK(r+sz, c) && OK(r, c-sz) && OK(r, c+sz))
          ++sz;
        stars.push_back(Star(r, c, sz));
      }
    }
  }

  for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) grid2[r][c] = '.';
  for (Star s : stars) {
    int r = s.r, c = s.c, sz = s.sz;
    while (sz--) {
      grid2[r-sz][c] = grid2[r+sz][c] = grid2[r][c-sz] = grid2[r][c+sz] = '*';
    }
  }

  bool same = 1;

  for (int r = 0; r < n && same; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] != grid2[r][c]) {
        same = 0;
        break;
      }
    }
  }
//
//  cout << "\ngrid1:\n";
//  for (int r = 0; r < n; ++r) {
//    for (int c = 0; c < m; ++c) {
//      cout << grid[r][c];
//    } cout << endl;
//  }
//  cout << "\ngrid2:\n";
//  for (int r = 0; r < n; ++r) {
//    for (int c = 0; c < m; ++c) {
//      cout << grid2[r][c];
//    } cout << endl;
//  }

  if (!same) {
    cout << -1; return;
  }

  cout << stars.size() << endl;
  for (Star s : stars) {
    cout << s.r+1 << " " << s.c+1 << " " << s.sz-1 << endl;
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






