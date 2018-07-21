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






const int EMPTY = 10, STICKER = 11, PILLAR = 12;

int ch2cell[200];
//char cell2ch[200];

//N, W, S, E
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};


int R, C;
int grid[105][105];

int d;
int r, c;
    

/*
void printgrid() {
  for (int i = 0; i <= R+1; ++i) {
    for (int j = 0; j <= C+1; ++j) {
      int x = grid[i][j];
      if (i != r || j != c) {
        cout << cell2ch[x] << ' ';
      } else {
        cout << 'R' << ' ';
      }
    }
    cout << '\n';
  }cout << '\n';
}
*/

void SOLVE() {

  memset(ch2cell, -1, sizeof(ch2cell));
//  memset(cell2ch, 0, sizeof(cell2ch));
  ch2cell['.'] = EMPTY;
  ch2cell['*'] = STICKER;
  ch2cell['#'] = PILLAR;
//  for (int i = 0; i < 190; ++i) if (ch2cell[i] != -1) cell2ch[ch2cell[i]] = (char)i;
//  cell2ch[0] = 'N';
//  cell2ch[1] = 'W';
//  cell2ch[2] = 'S';
//  cell2ch[3] = 'E';
  
  
  int slen;
  while (cin >> R >> C >> slen, R != 0 && C != 0) {

    for (int j = 0; j <= C+1; ++j) grid[0][j] = PILLAR;
    for (int j = 0; j <= C+1; ++j) grid[R+1][j] = PILLAR;
    for (int i = 0; i <= R+1; ++i) grid[i][0] = PILLAR;
    for (int i = 0; i <= R+1; ++i) grid[i][C+1] = PILLAR;
    
    
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        char ch;
        cin >> ch;
        if (ch2cell[ch] != -1) {
          grid[i][j] = ch2cell[ch];
        } else {
          r = i;
          c = j;
          if (ch == 'N') d = 0;
          else if (ch == 'S') d = 2;
          else if (ch == 'L') d = 3;
          else d = 1; 
        }
      }
    }
    
    int stickers = 0;

//    printgrid();
    
    char com;
    for (int i = 0; i < slen; ++i) {
      cin >> com;
//      cout << "executing " << com << ": ";
      if (com == 'D') {
//        cout << "d=" << cell2ch[d] << " -> ";
        d = (d-1+4) % 4;
//        cout << cell2ch[d] << '\n';
      } else if (com == 'E') {
//        cout << "d=" << cell2ch[d] << " -> ";
        d = (d+1) % 4;
//        cout << cell2ch[d] << '\n';
      } else {
        int r1 = r + dr[d], c1 = c + dc[d];
//        cout << "r=" << r << " c=" << c << " d=" << cell2ch[d] << " --> ";
        if (grid[r1][c1] != PILLAR) {
//          cout << " r=" << r1 << " c=" << c1 << " ";
          grid[r][c] = EMPTY;
          if (grid[r1][c1] == STICKER) {
            ++stickers;
            grid[r1][c1] = EMPTY;
//            cout << " {sticker}";
          }
          r = r1;
          c = c1;
//          cout << '\n';
        }
//        else {cout << "same\n";}
      }
//      printgrid();
    }

    cout << stickers << '\n';
//    cout << "---\n\n";



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














