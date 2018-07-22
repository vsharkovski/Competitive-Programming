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



// Problem type: floodfill, implementation  (a big one)



int R, C;
char grid[10][15];

void printgrid() {
  for (int i = R-1; i >= 0; --i) {
    for (int j = 0; j < C; ++j) {
      cout << grid[i][j];
    }
    cout << '\n';
  } cout << '\n';
}

int movenum;
int points;

int bcsz, bcr, bcc; //best cluster size, etc
char bccolor;
int ccbr, ccbc; //current cluster best row (for ball), etc

int dr[4] = {0,  0, 1, -1};
int dc[4] = {1, -1, 0,  0};

int floodfill(int r, int c, char c1, char c2) {
  if (r < 0 || r >= R || c < 0 || c >= C) return 0;
  if (grid[r][c] != c1) return 0;
  
  if (c < ccbc || (c == ccbc && r < ccbr)) {
    ccbc = c;
    ccbr = r;
  }
  
  grid[r][c] = c2;
  int sz = 1;
  for (int d = 0; d < 4; ++d) {
    sz += floodfill(r + dr[d], c + dc[d], c1, c2);
  }
  return sz;
}

void findBestCluster() {
  bcsz = bcr = bcc = 0;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      char ch = grid[r][c];
      if (ch == 'R' || ch == 'G' || ch == 'B') {
        ccbr = ccbc = 2e9;
        int sz = floodfill(r, c, ch, tolower(ch));
        if (sz > bcsz || (sz == bcsz && (ccbc < bcc || (ccbc == bcc && ccbr < bcr)))) {
          bcr = ccbr; bcc = ccbc; bcsz = sz;
          bccolor = ch;
        }
      }
    }
  }
}

void execMove() {
  int dodaj = (bcsz-2)*(bcsz-2);
  points += dodaj;
  floodfill(bcr, bcc, tolower(bccolor), '.');
  cout << "Move " << ++movenum << " at (" << bcr+1 << "," << bcc+1 << "): removed " << bcsz << " balls of color " << bccolor << ", got " << dodaj << " points.\n";
//  cout << "Grid before compress: \n";
//  printgrid();
}

void compress() {
  for (int j = 0; j < C; ++j) {
    for (int i = 0; i < R; ++i) {
      if (grid[i][j] != '.') {
        for (int k = i; k > 0 && grid[k-1][j] == '.'; --k) {
          swap(grid[k][j], grid[k-1][j]);
        }
      }
    }
  }
  for (int j = 0; j < C; ++j) {
    if (grid[0][j] != '.') {
      for (int k = j; k > 0 && grid[0][k-1] == '.'; --k) {
        for (int i = 0; i < R; ++i) {
          swap(grid[i][k], grid[i][k-1]);
        }
      }
    }
  }
//  cout << "Grid after compress: \n";
//  printgrid();
//  cout << '\n';
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (grid[i][j] != '.') {
        grid[i][j] = toupper(grid[i][j]);
      }
    }
  }
}

bool gameEnded() {
  return bcsz <= 1;
}

void SOLVE() {
  R = 10;
  C = 15;
  
  int T;
  cin >> T;
  for (int TC = 1; TC <= T; ++TC) {
  
    for (int r = R-1; r >= 0; --r) {
      for (int c = 0; c < C; ++c) {
        cin >> grid[r][c];
      }
    }
    
    cout << "Game " << TC << ":\n\n";
    
    points = 0;
    movenum = 0;
    
    while (1) {
      findBestCluster();
      if (gameEnded()) break;
      execMove();
      compress();
    }
  
    if (bcsz == 0) {
      points += 1000;
    }
  
    int remballs = 0;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (grid[r][c] != '.') ++remballs;
      }
    }
    
    cout << "Final score: " << points << ", with " << remballs << " balls remaining.\n";
    
    if (TC < T) cout << '\n';
  

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














