#include <bits/stdc++.h>
 
#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)
 
using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
 
 
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 
 
 
 
 
const int BLK = -2, UNV = -1; 

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
int grid1[1001][1001];
char grid2[1001][1001];
vii blocks;

inline bool in(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C;
}

void bfs1(int sr, int sc, char ch) {
  grid1[sr][sc] = 0;
  queue<ii> q;
  q.push(ii(sr, sc));
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (in(r1, c1) && grid1[r1][c1] == UNV) {
        grid1[r1][c1] = grid1[r][c] + 1;
        grid2[r1][c1] = ch;
        q.push(ii(r1, c1));
      }
    }
  }
}

void Solve() {
  cin >> R >> C;
  int sr, sc, er, ec;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      grid1[r][c] = UNV;
      grid2[r][c] = 'x';
      char ch;
      cin >> ch;
      if (ch == '#') {
        grid1[r][c] = BLK;
        blocks.push_back(ii(r, c));
      } else if (ch == 'S') {
        sr = r, sc = c;
        grid2[r][c] = 'S';
      } else if (ch == 'E') {
        er = r, ec = c;
        grid2[r][c] = 'E';
      }
    }
  }

  bfs1(sr, sc, 'S');
  if (grid1[er][ec] != UNV) {
    cout << grid1[er][ec] << endl;  
    return;
  }
  
  bfs1(er, ec, 'E');
  
  int ans = -1;
  
  for (ii &b : blocks) {
    int r = b.first, c = b.second;
    int bsr = -1, bsc = -1, ber = -1, bec = -1;
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (in(r1, c1)) {
        if (grid2[r1][c1] == 'S' && (bsr == -1 || grid1[r1][c1] < grid1[bsr][bsc])) {
          bsr = r1, bsc = c1;
        } else if (grid2[r1][c1] == 'E' && (ber == -1 || grid1[r1][c1] < grid1[ber][bec])) {
          ber = r1, bec = c1;
        }
      }
    }
    if (bsr != -1 && ber != -1) {
      ans = max(ans, grid1[bsr][bsc] + 2 + grid1[ber][bec]);
    }
  }
  
  cout << ans << endl;
/*
  cout << endl;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cout << setw(2) << grid1[r][c] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cout << setw(2) << grid2[r][c] << " ";
    }
    cout << endl;
  }
*/


}
 
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}








